#pragma once
//# include <Siv3D.hpp>
# include <vector>
class Map {
public:
	Map();
	//~Map();

	void DrawMap();

	static int Get_MAP_CHIP_SIZE();

	Point Get_Player_Start();
protected:
	static const int MAP_CHIP_SIZE = 64;   //マップチップの画像サイズ
	int m_mapChip_Width;				   //マップの横幅
	int m_mapChip_Height;                  //マップの縦幅

	Point m_Player_Start;//スタート時のプレイヤーの座標

	enum TILE_Data { F, W, G, B, P}; //床、壁、ゴール（分かりやすいように1文字で）
	std::vector<Texture> m_MapChip_Images;//画像
	std::vector<std::vector<int>> m_map;//マップデータの２次元配列
};
