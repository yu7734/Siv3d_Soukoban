#pragma once
# include <Siv3D.hpp>
# include <vector>

class Map {
public:
	Map();
	//~Map();

	void DrawMap();
protected:
	static const int MAP_CHIP_SIZE = 64;   //マップチップの画像サイズ
	int m_mapChip_Width;				   //マップの横幅
	int m_mapChip_Height;                  //マップの縦幅

	enum CHIP_Data { Floor, Wall, Block, Goal };
	std::vector<Texture> m_MapChip_Images;//画像
	std::vector<std::vector<int>> m_map;
};
