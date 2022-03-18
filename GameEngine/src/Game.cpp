/*
 * Game.cpp
 *
 *  Created on: 10 Feb 2022
 *      Author: Amass
 */

#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Collision.h"
#include "Vector2D.h"
#include "ECS/Components.h"


#include <iostream>



//double Game::counter = 0;

SDL_Renderer* Game::globalRenderer = nullptr;
SDL_Event Game::event;
std::vector<CollisionComponent*> Game::globalColliders;

bool Game::isRunning = false;


//GameObjects* enemy;
Map* trajectory;	

const char* mapFile = "assets/level.png";

Manager manager;
auto& Player(manager.addEntity());
//auto& wall(manager.addEntity());


enum groupLabels : std::size_t
{
	groupMap,
	groupPC,
	groupNPC,
	groupColliders
};

auto& tiles(manager.getGroup(groupMap));
auto& player(manager.getGroup(groupPC));
auto& objects(manager.getGroup(groupNPC));

Game::Game():m_Window(nullptr), m_Texture(nullptr) /*m_Buffer(nullptr), sinWave_x(0), sinWave_y(0),*/  {
	isRunning = true;

}

Game::~Game() {

}

void Game::init(const char* title, int x, int y, int winWIDTH, int winHEIGHT, bool isFullscreen)
{
	int				 		flag = 0;
		if(isFullscreen)	flag = SDL_WINDOW_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{


						std::cout << "Initialisation successful" << std::endl;

					m_Window = SDL_CreateWindow(title, x, y, winWIDTH, winHEIGHT, flag);

		if(m_Window)	std::cout << "Window Created" << std::endl;

					globalRenderer = SDL_CreateRenderer(m_Window, -1, 0);
if(globalRenderer)		SDL_SetRenderDrawColor(globalRenderer, 0, 0, 0, 255);


				//	m_Buffer = new Uint32[WINDOW_WIDTH*WINDOW_HEIGHT];

	isRunning = true;
	}else isRunning = false;


	//player = new GameObjects("assets/Bowling ball character.png", x, y);
//	enemy = new GameObjects("assets/Bowling ball enemy.png", x, y);

	trajectory = new Map();

	//====================ECS implements=========================

	

	/*wall.addComponent<TransformComponent>(500.0f, 100.0f, 320, 16, 1);
	wall.addComponent<SpriteComponent>("assets/wall.png");
	wall.addComponent<CollisionComponent>("wall");
	wall.addGroup(groupNPC);*/


	Player.addComponent<TransformComponent>();
	Player.addComponent<SpriteComponent>("assets/2indices Ball_ssh.png", true);
	Player.addComponent<KeyboardController>();
	Player.addComponent<CollisionComponent>("player");
	Player.addGroup(groupPC);

	Map::loadMap("assets/DirtnGrassMap.map", 10, 10);




	//m_Texture = TextureManager::loadTexture("assets/Bowling ball character.png", globalRenderer);



}


void Game::addTile(int srcX, int srcY, int xpos, int ypos)
{
	auto& tile(manager.addEntity());
	tile.addComponent<TileComponent>(srcX, srcY, xpos, ypos, mapFile);
	tile.addGroup(groupMap);
	
}

void Game::clean()
{
	//delete []m_Buffer;

	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(globalRenderer);
	SDL_DestroyTexture(m_Texture);



	SDL_Quit();
//==============COUT=============
	std::cout << "Memory cleaned" << std::endl;

}


void Game::render()
{
	SDL_RenderClear(globalRenderer);
// Set renderer

	//SDL_RenderCopy(globalRenderer, m_Texture, NULL, &destR);
//trajectory->drawMap();

	for (auto& t : tiles) { t->entDraw(); }
	for (auto& p : player) { p->entDraw(); }
	for (auto& o : objects) { o->entDraw(); }


//	player->render();
//	enemy->render();



	SDL_RenderPresent(globalRenderer);

}

void Game::update()
{
	//counter++;

//SDL_UpdateTexture(m_Texture, NULL, m_Buffer, WINDOW_WIDTH*sizeof(Uint32));
//sinWave_x = (unsigned int)((1+sin(counter * 0.01)) * (WINDOW_WIDTH/2));
//sinWave_y = (unsigned int)((1+sin(counter * 0.01)) * (WINDOW_HEIGHT/2));
//player->update(sinWave_x, sinWave_y);
//enemy->update(sinWave_x + 64, sinWave_y + 64);

manager.manRefresh();
manager.manUpdate();

Vector2D pVelocity = Player.getComponent<TransformComponent>().velocity;
		int	pSpeed = Player.getComponent<TransformComponent>().speed;

	for (auto t : tiles)
		{
			t->getComponent<TileComponent>().destR.x += -(pVelocity.m_x * pSpeed);
			t->getComponent<TileComponent>().destR.y += -(pVelocity.m_y * pSpeed);

		}


	/*for( auto cc : globalColliders)
	{
		Collision::collidersAABB(Player.getComponent<CollisionComponent>(), *cc);

	}*/

//if(Player.getComponent<TransformComponent>().position.m_x > 100) Player.getComponent<SpriteComponent>().SetTex("assets/Bowling ball enemy.png");
//else Player.getComponent<SpriteComponent>().SetTex("assets/Bowling ball character.png");


// trajectory->loadMap(edit trajectory);

}

void Game::handleEvent()
{

SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}


/*void Game::modColor(Uint8 red, Uint8 green, Uint8 blue)	// errors with buffer
{
	Uint32 color = 0;

color += 0xff;
color <<= 8;

color += blue;
color <<= 8;

color += green;
color <<= 8;

color += red;
color <<= 8;
	for (int i =0; i<WINDOW_WIDTH*WINDOW_HEIGHT; i++)
	{
		m_Buffer[i] = color;
	}
}
*/

