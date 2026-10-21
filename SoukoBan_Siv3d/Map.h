#pragma once
# include <Siv3D.hpp>

class Map {
public:
	Map();
	~Map();

	void DrawMap();
protected:
	const int MAP_CHIP_SIZE = 64;
	static const int m_mapChip_Width = 10;
	static const int m_mapChip_Height = 10;

	enum CHIP_Data { Floor, Wall, Goal };
	//TextureAsset m_MapChip_Images[]{};
	int m_mapChip_data[m_mapChip_Height][m_mapChip_Width];
};
