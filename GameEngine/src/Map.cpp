/*
 * Map.cpp
 *
 *  Created on: 16 Feb 2022
 *      Author: Amass
 */

#include "Map.h"
#include "Game.h"
#include<fstream>
#include <iostream>

Map::Map()
{




}

Map::~Map()
{

}


void Map::loadMap(std::string path, int sizeX, int sizeY)
{
	char tile;
	int srcX, srcY;

	std::fstream mapFile;

	mapFile.open(path);
	

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{

			mapFile.get(tile);	//std::cout << tile << "\n";	// Map File correctly read
			srcY = atoi(&tile) * 32;

			mapFile.get(tile); //std::cout << tile << "\n";		// Map File correctly read
			srcX = atoi(&tile) * 32;

			Game::addTile(srcX, srcY, x * 64, y * 64);
			mapFile.ignore();
		}
	}

	mapFile.close();
}




