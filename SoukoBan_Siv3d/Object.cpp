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

void Object::NextPosition(Grid<int32> csv) {
	//移動先が壁の場合
	if (csv[nextPosition] == 1) {
		//nextPositionを現在の座標にする
		nextPosition = currentPosition;
	}

	//移動が発生する場合
	if (currentPosition != nextPosition) {
		//歩行の進歩を戻す
		currentPosition = nextPosition;
	}
}
