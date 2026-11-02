#include "Player.h"

Player::Player(int x, int y) : Object(x, y) {
	texture = Texture{ U"example/Images/player_01.png" };
}
