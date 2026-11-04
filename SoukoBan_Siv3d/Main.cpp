# include <Siv3D.hpp> // Siv3D v0.6.16
# include <memory>
# include "Map.h"
# include "Player.h"
# include "Block.h"

void Main()
{
	auto map = std::make_unique<Map>();//インスタンスを安全に生成
	auto player = std::make_unique<Player>(map->Get_Player_Start().x, map->Get_Player_Start().y);
	auto block = std::make_unique<Block>(2, 1);

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	while (System::Update())
	{
		map->DrawMap();
		player->Draw();
		block->Draw();

		player->Move();
	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
