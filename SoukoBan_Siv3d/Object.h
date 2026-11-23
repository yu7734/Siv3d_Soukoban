#pragma once
# include <Siv3D.hpp>

enum Direction_Type { UP, DOWN, LEFT, RIGHT };//進む向きを列挙定数に

class Object {
public:
	Object(int x, int y);

	virtual void Move() = 0;
	void CheckMove(int dir);
	virtual void NextPosition(Grid<int32> csv);
	void Draw(); //描画

	Point GetCurrentPosition();//座標変数のゲッター
protected:
	Point nextPosition; //移動先の座標
	Point currentPosition; //現在の座標
	Rect rect;
	Texture texture;//画像

};
