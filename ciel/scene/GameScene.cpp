#include <DxLib.h>
#include "GameScene.h"
#include"../scene/Obj/BGM.h"
#include"../scene/Input/Keyboard.h"
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
    key_.Update();
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


    //BGM---------------------------------------------
    //if (key_.getKeyDownHold(KEY_INPUT_DOWN))
    //{
    //    x += 1;
    //    if (x > 100)
    //    {
    //        x = 100;
    //    }
    //}
    //if (key_.getKeyDownHold(KEY_INPUT_UP))
    //{
    //    x -= 1;
    //    if (x < 0)
    //    {
    //        x = 0;
    //    }
    //}
    //int move = 255 * x;

    //// 音量の設定
    //ChangeVolumeSoundMem(move/100, SHandle);
    //---------------------------------------------------------

    DrawOwnScn();//個別のDraw処理な為必ず書く

    PlayerPos = mPlayer.GetPos();

    mMapOffset = lpMapMng.Update(PlayerPos);

    mPlayer.Update();
   /* PlayerPos = mPlayer.Update();*/
 
   /* mAitem->Update();*/

    mMenu.Update();

    mBgm->Update(mMenu.OpBgm());

   
    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    lpMapMng.Draw();

	 mPlayer.Draw(GameScene::mMapOffset);

    /* mAitem->Draw(mMapOffset);*/

     mMenu.Draw();
    
}

bool GameScene::Init(void)
{
	//lpMapMng.Init();
    /* mPlayer = new Player();
    mPlayer->init(this);*/

    //BGM--------------------------------------------
   // x = 0;
   // SHandle = LoadSoundMem("bgm/yume.mp3");
   // PlaySoundMem(SHandle, DX_PLAYTYPE_BACK);
   ///* DeleteSoundMem(SHandle);*/
    //-----------------------------------------------


    // ポーズフラグ
    mPose = false;

    mAitem = new Aitem();

    mMenu.init(this);

    mBgm = new BGM();

   	return true;
}
