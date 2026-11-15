#include "Map.h"
#include "Player.h"
#include <vector>

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

	const size_t yCount = csv.rows();    //列数
	const size_t xCount = csv.columns(0);//行数(１列目と同じ数)

	//２次元配列
	Grid<int32> map;

	for (int y = 0; y < yCount; ++y) {
		for (int x = 0; x < xCount; ++x) {
			map[y][x] = csv.get<int32>(y, x);//指定した行・列の読み込み
		}
	}

	return map;
}
