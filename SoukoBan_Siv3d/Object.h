#pragma once
# include <Siv3D.hpp> 

class Object {
public:
	Object(int x, int y);

	//virtual void Move();
	void Draw();
protected:
	int x, y; //座標
	int nx, ny; //移動先の座標
	Rect rect;
	Texture texture;//画像

};
