#include "Object.h"
#include "Map.h"

Object::Object(int x, int y) : x(x), y(y),
	rect{ x * Map::Get_MAP_CHIP_SIZE(), y * Map::Get_MAP_CHIP_SIZE(), Map::Get_MAP_CHIP_SIZE() } {
}

void Object::Draw() {
	texture.draw(x * Map::Get_MAP_CHIP_SIZE(), y * Map::Get_MAP_CHIP_SIZE());
}
