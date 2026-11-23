#pragma once
# include <Siv3D.hpp>

class Map {
public:
	Map();
	//~Map();

	void DrawMap();

	static int Get_MAP_CHIP_SIZE();

	Grid<int32> LoadCSV(FilePathView path);

	Point Get_Player_Start();
	Array<Point> Get_Block_Start();
protected:
	static constexpr int MAP_CHIP_SIZE = 64;   //マップチップの画像サイズ

	Point m_Player_Start;	   //スタート時のプレイヤーの座標
	Array<Point> m_Block_Start;//スタート時の箱の座標

	Array<Texture> m_MapChip_Images;//画像
	Grid<int32> m_map_Layer;		//マップデータの２次元配列
};
