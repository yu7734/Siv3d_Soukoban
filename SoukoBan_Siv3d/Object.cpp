#include "Object.h"
#include "Map.h"

Object::Object(int x, int y) : currentPosition{x, y},
	nextPosition{currentPosition.x, currentPosition.y},
	rect{ currentPosition.x * Map::Get_MAP_CHIP_SIZE(),
	currentPosition.y * Map::Get_MAP_CHIP_SIZE(),
	Map::Get_MAP_CHIP_SIZE() } {
}

void Object::Draw() {
	texture.draw(currentPosition.x * Map::Get_MAP_CHIP_SIZE(),
				 currentPosition.y * Map::Get_MAP_CHIP_SIZE());
}

void Object::CheckMove(int dir) {
	
	

}

void Object::Next_Position(Direction_Type dir) {
	
}
