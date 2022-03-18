/*
 * Map.h
 *
 *  Created on: 16 Feb 2022
 *      Author: Amass
 */

#ifndef MAP_H_
#define MAP_H_

#include<string>


class Map {

/*SDL_Texture* trajectory;
SDL_Texture* trajectory1;
SDL_Rect sourceRect, destRect;

int mapHolder[20][25];
*/

public:

	Map();
	~Map();

static void loadMap(std::string path, int sizeX, int sizeY);

};



#endif /* MAP_H_ */
