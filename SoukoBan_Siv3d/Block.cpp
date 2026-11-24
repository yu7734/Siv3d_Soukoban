#include "Block.h"

Block::Block(int x, int y) : Object(x, y) {
	texture = Texture{ U"example/Images/block_01.png" };
}

void Block::Move() {
	
}
