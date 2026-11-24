#pragma once
#include "Object.h"
#include "Block.h"

class Player : public Object {
public:
	Player(int x, int y);

	void Move() override;

	void NextPosition(Grid<int32> csv, Array<Block>& blocks);

	int16 GetDirection();
};
