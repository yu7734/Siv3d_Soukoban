#include "Map.h"


//コンストラクタ
Map::Map() : m_MapChip_Images
{ Texture{ U"example/Images/ground_06.png" },
  Texture{ U"example/Images/block_06.png" },
  Texture{ U"example/Images/ground_03.png"} }
{

}

//CSVファイルからint32の２次元配列を読み込む
Grid<int32> Map::LoadCSV(FilePathView path) {
	CSV csv{ path }; //CSVファイル読み込み

	//読み込み失敗したら
	if (not csv) {
		throw Error{ U"filed to load'{}'"_fmt(path) };//エラー
	}

	const size_t yCount = csv.rows();    //行数
	const size_t xCount = csv.columns(0);//列数(１行目と同じ数)

	m_map_Layer.resize(xCount, yCount);
	m_Block_Start.clear();

	for (int y = 0; y < yCount; ++y) {
		for (int x = 0; x < xCount; ++x) {
			m_map_Layer[y][x] = csv.get<int32>(y, x);//指定した行・列の読み込み

			if (m_map_Layer[y][x] == 3) {
				m_Player_Start = { x, y };
				m_map_Layer[y][x] = 0;
			}
			if (m_map_Layer[y][x] == 4) {
				m_Block_Start << Point{ x, y };
				m_map_Layer[y][x] = 0;
			}
		}
	}
	return m_map_Layer;
}

//マップ描画
void Map::DrawMap() {
	
	for (int y = 0; y < static_cast<int32> (m_map_Layer.height()); ++y) {
		for (int x = 0; x < static_cast<int32>(m_map_Layer.width()); ++x) {
			//マップチップの描画座標
			const Point pos{ (x * Map::MAP_CHIP_SIZE), (y * Map::MAP_CHIP_SIZE) };
			m_MapChip_Images[0].draw(pos);//床を描画

			const int32 imap = m_map_Layer[y][x];
			if (imap != 0) { //床以外を描画
				m_MapChip_Images[imap].draw(pos);
			}
		}
	}
}

int Map::Get_MAP_CHIP_SIZE() {
	return MAP_CHIP_SIZE;
}

Point Map::Get_Player_Start() {
	return { m_Player_Start.x, m_Player_Start.y };
}

Array<Point> Map::Get_Block_Start() {
	return m_Block_Start;
}
