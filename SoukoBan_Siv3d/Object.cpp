//#include "Object.h"
//#include "Map.h"
//
//Object::Object(int x, int y) : x(x), y(y),
//	rect{ x * Map::Get_MAP_CHIP_SIZE(), y * Map::Get_MAP_CHIP_SIZE(), Map::Get_MAP_CHIP_SIZE() } {
//}
//
//void Object::Draw() {
//	texture.draw(x * Map::Get_MAP_CHIP_SIZE(), y * Map::Get_MAP_CHIP_SIZE());
//}
//
//void Object::CheckMove(int dir) {
//	current_X = x; current_Y = y;
//
//}
//
//void Object::Next_Position(Direction_Type dir) {
//	switch (dir)
//	{
//	case UP:
//		ny -= 1;
//		break;
//	case DOWN:
//		ny += 1;
//		break;
//	case LEFT:
//		nx -= 1;
//		break;
//	case RIGHT:
//		nx += 1;
//		break;
//	}
//}
//
//int Object::GetX() { return x; }
//int Object::GetY() { return y; }
//void Object::SetX(int set_x) { this->x = set_x; }
//void Object::SetY(int set_y) { this->y = set_y; }
