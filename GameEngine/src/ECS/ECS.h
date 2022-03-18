/*
 * ECS.h
 *
 *  Created on: 16 Feb 2022
 *      Author: Amass
 */

#ifndef ECS_H_
#define ECS_H_

#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include <bitset>



class Component;
class Entity;
class Manager;

using ComponentID = std::size_t;
using Group = std::size_t;

ComponentID getNewComponentTypeID() {
	static ComponentID lastComponent = 0u;
	return lastComponent++;
}

template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getNewComponentTypeID();
	return typeID;
}

constexpr std::size_t maxComponents = 32;
constexpr std::size_t maxGroups = 32;

using ComponentBitset = std::bitset<maxComponents>;
using GroupBitset = std::bitset<maxGroups>;

using ComponentArray = std::array<Component*, maxComponents>;

class Component
{

public:
	Entity* entity;

	virtual void cpnInit() {}
	virtual void cpnUpdate(){}
	virtual void cpnDraw(){}

	virtual ~Component() {}

};

class Entity
{
	Manager& manager;

	bool entActive = true;
	std::vector<std::unique_ptr<Component>> components;

	ComponentArray componentArr;
	ComponentBitset componentBitSet;
	GroupBitset groupBitset;

public:

	Entity(Manager& mManager) : manager(mManager){}

	void entUpdate()
	{
		for (auto& c : components) c->cpnUpdate();
	}

	void entDraw()
	{
		for (auto& c : components) c->cpnDraw();
	}

	bool IsActive() const	{	return entActive;	}

	void entDestroy()	{entActive = false;}

	bool hasGroup(Group mGroup)
	{
		return groupBitset[mGroup];
	}

	void addGroup(Group mGroup);
	void delGroup(Group mGroup)
	{
		groupBitset[mGroup] = false;
	}

	template <typename T> bool hasComponent() const
	{
		return componentBitSet[getComponentTypeID<T>()];
	}

	template <typename T, typename... TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
	T* c(new T(std::forward<TArgs>(mArgs)...));
	c->entity = this;
	std::unique_ptr<Component> uPtr{ c };
	components.emplace_back(std::move(uPtr));

	componentArr[getComponentTypeID<T>()] = c;
	componentBitSet[getComponentTypeID<T>()] = true;

	c->cpnInit();

	return *c;
	}

	template <typename T> T& getComponent() const
	{
		auto ptr(componentArr[getComponentTypeID<T>()]);

		return *static_cast<T*>(ptr);
	}
};
class Manager
{
	std::vector<std::unique_ptr<Entity>> entities;
	std::array<std::vector<Entity*>, maxGroups> groupedEntities;

public:
	void manUpdate()
	{
		for (auto& e : entities) e->entUpdate();
	}

void manDraw()
{
	for (auto& e : entities) e->entDraw();
}

void manRefresh()
{
	for (auto i(0u); i < maxGroups; i++)
	{
		auto& v(groupedEntities[i]);
		v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity* mEntity)
			{
				return !mEntity->IsActive() || !mEntity->hasGroup(i);
			}
		), std::end(v));
	}

	entities.erase(std::remove_if(std::begin(entities), std::end(entities),

						[](const std::unique_ptr<Entity> &mEntity)	{return !mEntity->IsActive(); }
							),
								std::end(entities));


}

void AddToGroup(Entity* mEntity, Group mGroup)
{
	groupedEntities[mGroup].emplace_back(mEntity);
}

std::vector<Entity*>& getGroup(Group mGroup)
{
	return groupedEntities[mGroup];
}

Entity& addEntity()
{
	Entity* e = new Entity(*this);
	std::unique_ptr<Entity> uPtr{ e };
	entities.emplace_back(std::move(uPtr));
	return *e;
}

};






#endif /* ECS_H_ */
