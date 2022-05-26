#include <DxLib.h>
#include "GameScene.h"
#include"../scene/Obj/Aitem.h"
#include "../stage/StageMng.h"



GameScene::GameScene(/*SceneMng* manager*/)
{
    Init();
    DrawOwnScn();
}

GameScene::~GameScene()
{
}

//アイテムのフラグ ---------------------------
bool GameScene::IsKami1(void)
{
    return mAitem->mKami1;
}

bool GameScene::IsKami2(void)
{
    return mAitem->mKami2;
}

bool GameScene::mKami3(void)
{
    return mAitem->mKami3;
}

bool GameScene::mKami4(void)
{
    return mAitem->mKami4;
}

bool GameScene::mKami5(void)
{
    return mAitem->mKami5;
}

bool GameScene::mTma(void)
{
    return mAitem->mTma;
}

bool GameScene::mMasinngan(void)
{
    return mAitem->mMasinngan;
}

bool GameScene::mHoutai(void)
{
    return mAitem->mHoutai;
}

bool GameScene::mHeal(void)
{
    return mAitem->mHeal;
}

bool GameScene::mKey(void)
{
    return mAitem->mKey;
}

bool GameScene::mbook(void)
{
    return mAitem->mbook;
}

bool GameScene::mMagazinn(void)
{
    return mAitem->mMagazinn;
}

bool GameScene::mEnd()
{
    return false;
}

//----------------------------------


uniquBaseScn GameScene::Update(uniquBaseScn own)
{
    /*if (CheckHitKey(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>(std::move(own));
    }*/
    //ポーズ機能
    if (mPose == false)
    {
        if (CheckHitKey(KEY_INPUT_F))
        {
            mPose = true;
        }
    }
    else
    {
        if (CheckHitKey(KEY_INPUT_F))
        {
            mPose = false;
            mMenu.init(this);
        }
    }

    DrawOwnScn();//個別のDraw処理な為必ず書く

    mMapOffset = lpMapMng.Update(PlayerPos);

    PlayerPos = mPlayer.Update();

   /* mAitem->Update();*/

    /*mMenu.Update();*/

   
    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    lpMapMng.Draw();

	 mPlayer.Draw(GameScene::mMapOffset);

    /* mAitem->Draw(mMapOffset);*/

    /* mMenu.Draw();*/
    
}

bool GameScene::Init(void)
{
	//lpMapMng.Init();
   
    //ポーズフラグ
    mPose = false;

    mAitem = new Aitem();

    mMenu.init(this);

	return true;
}
