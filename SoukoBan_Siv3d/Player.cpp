#include "Player.h"
#include "Map.h"

Player::Player(int x, int y) : Object(x, y) {
	texture = Texture{ U"example/Images/player_01.png" };
}

//移動処理
void Player::Move() {
	if (KeyLeft.down()) {
		x -= 1;//左に1マス移動
	}
	else if (KeyRight.down()) {
		x += 1;
	}
	else if (KeyUp.down()) {
		y -= 1;
	}
	else if (KeyDown.down()) {
		y += 1;
	}
}
