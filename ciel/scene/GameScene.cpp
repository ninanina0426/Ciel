#include <DxLib.h>
#include "GameScene.h"
#include"../scene/Obj/Player.h"
#include "../stage/StageMng.h"



GameScene::GameScene(/*SceneMng* manager*/)
{
    Init();
    DrawOwnScn();
}

GameScene::~GameScene()
{
}

int GameScene::GetEvent(Vector2 pos)
{
	int chipID = lpMapMng.GetMapChip(pos);
	/*int chipID = mSweetsMap->GetMapChip(pos);*/
	//階段等でステージ切り替え
	//if (chipID == 15)
	//{
	//	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	//	{
	//		//マップを切り替えることになった
	//		mMapChange = true;
	//		mNextMapID = MAP_ID::SWEETSOUT;
	//		mNextPos = { 1 * 32 + 32 / 2,1 * 32 + 32 / 2, };
	//	}
	//	else if (lpMapMng.mMapID == MAP_ID::SWEETSOUT)
	//	{
	//		mMapChange = true;
	//		mNextMapID = MAP_ID::SWEETS;
	//		mNextPos = { 3 * 32 + 32 / 2,3 * 32 + 32 / 2, };
	//	}

	//}

	return chipID;
}

uniquBaseScn GameScene::Update(uniquBaseScn own)
{
    /*if (CheckHitKey(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>(std::move(own));
    }*/
    DrawOwnScn();//個別のDraw処理な為必ず書く
    lpMapMng.Update();

    mPlayer->Update();

    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    lpMapMng.Draw();

	 mPlayer->Draw(mMapOffset);
}

bool GameScene::Init(void)
{

    mPlayer = new Player();
    mPlayer->init(this);

	return true;
}
