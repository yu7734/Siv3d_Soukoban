#include "Map.h"
#include <vector>

Map::Map() {
	//テクスチャを登録
	m_MapChip_Images.push_back(Texture{ U"example/Images/ground_06.png" });
	m_MapChip_Images.push_back(Texture{ U"example/Images/block_06.png" });
	m_MapChip_Images.push_back(Texture{ U"example/Images/ground_03.png" });

	//マップデータ
	m_map = {
		{ W,W,W,W,W },
		{ W,F,F,G,W },
		{ W,F,F,F,W },
		{ W,W,W,W,W }
	};

	//幅を取得(static_castを使ってintに変更(32bit))
	m_mapChip_Height = static_cast<int>(m_map.size());
	m_mapChip_Width  = static_cast<int>(m_map[0].size());
}

//マップ描画関数
void Map::DrawMap() {
	//床を描画した後、床以外を描画する
	for (int y = 0; y < m_mapChip_Height; ++y) {
		for (int x = 0; x < m_mapChip_Width; ++x) {
			int c_map = m_map[y][x];
			m_MapChip_Images[F].draw(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE);
			if (c_map == F) continue;
			m_MapChip_Images[c_map].draw(x * MAP_CHIP_SIZE, y * MAP_CHIP_SIZE);
		}
	}
}

int Map::Get_MAP_CHIP_SIZE() { return MAP_CHIP_SIZE; }
