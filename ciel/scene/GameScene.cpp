#include <DxLib.h>
#include "GameScene.h"
#include "../stage/StageMng.h"

GameScene::GameScene()
{
    Init();
    DrawOwnScn();
}

GameScene::~GameScene()
{
}

uniquBaseScn GameScene::Update(uniquBaseScn own)
{
    /*if (CheckHitKey(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>(std::move(own));
    }*/
    DrawOwnScn();//個別のDraw処理な為必ず書く
    lpMapMng.Update();
    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    lpMapMng.Draw();
}

bool GameScene::Init(void)
{
	return true;
}
