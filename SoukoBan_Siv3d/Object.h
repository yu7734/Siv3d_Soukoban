//#pragma once
//# include <Siv3D.hpp>
//
//enum Direction_Type { UP, DOWN, LEFT, RIGHT };//進む向きを列挙定数に
//
//class Object {
//public:
//	Object(int x, int y);
//
//	virtual void Move() = 0;
//	void CheckMove(int dir);
//	void Next_Position(Direction_Type dir);
//	void Draw(); //描画
//
//	int GetX(); int GetY();//座標変数のゲッター
//	//座標変数のセッター
//	void SetX(int set_x);
//	void SetY(int set_y);
//protected:
//	int x, y; //座標
//	int nx, ny; //移動先の座標
//	int current_X, current_Y; //現在の座標
//	Rect rect;
//	Texture texture;//画像
//
//};
