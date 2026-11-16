#pragma once
# include <Siv3D.hpp>
# include <vector>
class Map {
public:
	Map();
	//~Map();

	void DrawMap();

	static int Get_MAP_CHIP_SIZE();

	void LoadCSV(FilePathView path);

	Point Get_Player_Start();
protected:
	static constexpr int MAP_CHIP_SIZE = 64;   //マップチップの画像サイズ

	Point m_Player_Start;//スタート時のプレイヤーの座標

	Array<Texture> m_MapChip_Images;//画像
	Grid<int32> m_map_Layer;		//マップデータの２次元配列
};
