#include <DxLib.h>
#include "BaseScene.h"

BaseScene::BaseScene()
{
	//Init();ここで呼ぶと継承先で呼び忘れても大丈夫
	SetDrawScreen(DX_SCREEN_BACK);//明示的にどのスクリーンなのか
	GetDrawScreenSize(&screenSize_.x_, &screenSize_.y_);//描画先のサイズ取得
	sceneScrID_ = MakeScreen(screenSize_.x_, screenSize_.y_, true);
}

BaseScene::~BaseScene()
{
	
}

void BaseScene::Draw()
{
	DrawGraph(0, 0, sceneScrID_, true);//それぞれのシーンを描画
}


