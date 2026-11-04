#include "Map.h"
#include "Player.h"
#include <vector>

Map::Map() {
	//テクスチャを登録
	m_MapChip_Images.push_back(Texture{ U"example/Images/ground_06.png" });
	m_MapChip_Images.push_back(Texture{ U"example/Images/block_06.png" });
	m_MapChip_Images.push_back(Texture{ U"example/Images/ground_03.png" });

	//マップデータ
	m_map = {
		{ W,W,W,W,W },
		{ W,F,B,G,W },
		{ W,F,F,P,W },
		{ W,W,W,W,W }
	};

	//幅を取得(static_castを使ってintに変更(32bit))
	m_mapChip_Height = static_cast<int32>(m_map.size());
	m_mapChip_Width  = static_cast<int32>(m_map[0].size());

	for (int y = 0; y < m_mapChip_Height; ++y) {
		for (int x = 0; x < m_mapChip_Width; ++x) {
			int& c_map = m_map[y][x];
			if (c_map == P) { m_Player_Start = Point{ x, y };  c_map = F; }
			else if (c_map == B) { c_map = F; }
		}
	}
}

//マップ描画関数
void Map::DrawMap() {
	//マップを描画
	for (int y = 0; y < m_mapChip_Height; ++y) {
		for (int x = 0; x < m_mapChip_Width; ++x) {
			int c_map = m_map[y][x];
			if      (c_map == W) m_MapChip_Images[W].draw(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE);
			else if (c_map == G) m_MapChip_Images[G].draw(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE);
			else	             m_MapChip_Images[F].draw(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE);
		}
	}
}

int Map::Get_MAP_CHIP_SIZE() { return MAP_CHIP_SIZE; }
Point Map::Get_Player_Start() { return this->m_Player_Start; }
