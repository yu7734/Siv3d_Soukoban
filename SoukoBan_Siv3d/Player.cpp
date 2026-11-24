#include "Player.h"
//#include "Block.h"

Player::Player(int x, int y) : Object(x, y) {
	texture = Texture{ U"example/Images/player_01.png" };
}

//移動処理
void Player::Move() {
	if (KeyLeft.down()) {
		direction = LEFT;
		nextPosition += GetNextVector(direction);//左に1マス移動
	}
	else if (KeyRight.down()) {
		direction = RIGHT;
		nextPosition += GetNextVector(direction);
	}
	else if (KeyUp.down()) {
		direction = UP;
		nextPosition += GetNextVector(direction);
	}
	else if (KeyDown.down()) {
		direction = DOWN;
		nextPosition += GetNextVector(direction);
	}
}

void Player::NextPosition(Grid<int32> csvPath, Array<Block>& blocks) {
	//移動先が壁の場合
	if (csvPath[nextPosition] == 1) {
		//nextPositionを現在の座標にする
		nextPosition = currentPosition;
	}
	for (int i = 0; i < blocks.size(); ++i) {
		//移動先がブロックの場合
		if (nextPosition == blocks[i].GetCurrentPosition()) {
			Point blockNext = nextPosition + GetNextVector(direction);

			//ブロックの先が押せない場合
			if (csvPath[blockNext] == 1 || blockNext == blocks[i].GetCurrentPosition()) {
				nextPosition = currentPosition;
			}
			//何も無い場合動かす
			else {
				blocks[i].SetCurrentPosition(blockNext);
				currentPosition = nextPosition;
			}
		}
	}

	//移動が発生する場合
	if (currentPosition != nextPosition) {
		//歩行の進歩を戻す
		currentPosition = nextPosition;
	}
}

int16 Player::GetDirection() { return direction; }
