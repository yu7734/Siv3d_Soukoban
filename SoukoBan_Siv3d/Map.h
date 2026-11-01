#pragma once
//# include <Siv3D.hpp>
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

	enum CHIP_Data { F, W, B, G, P }; //床、壁、箱、ゴール、プレイヤー（分かりやすいように1文字で）
	std::vector<Texture> m_MapChip_Images;//画像
	std::vector<std::vector<CHIP_Data>> m_map;//マップデータの２次元配列
};
