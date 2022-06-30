#include <DxLib.h>
#include "GameScene.h"
#include"Obj/BGM.h"
#include"../scene/Input/Keyboard.h"
#include"Obj/Aitem.h"
#include"Obj/Npc.h"
#include"Obj/Chat.h"
#include"../stage/Layer.h"
#include "../stage/StageMng.h"
#include "EventScene.h"



GameScene::GameScene(PlayerID playerID)
{
    Init();
    mPlayer.plID_ = playerID;
    DrawOwnScn();
}

GameScene::~GameScene()
{
}


//アイテムのフラグ ---------------------------

bool GameScene::IsTama1(void)
{
    return mAitem->mTama1;
}

bool GameScene::IsTama2(void)
{
    return mAitem->mTama2;
}

bool GameScene::IsTama3(void)
{
    return mAitem->mTama3;
}

bool GameScene::IsTama4(void)
{
    return mAitem->mTama4;
}

bool GameScene::IsTama5(void)
{
    return mAitem->mTama5;
}

bool GameScene::IsKinomi1(void)
{
    return mAitem->mKinomi1;
}

bool GameScene::IsKinomi2(void)
{
    return mAitem->mKinomi2;
}

bool GameScene::IsKinomi3(void)
{
    return mAitem->mKinomi3;
}

bool GameScene::IsKinomi4(void)
{
    return mAitem->mKinomi4;
}

bool GameScene::IsKinomi5(void)
{
    return mAitem->mKinomi5;
}

bool GameScene::IsHaori(void)
{
    return mAitem->mHaori;
}

bool GameScene::IsRantan(void)
{
    return mAitem->mRantan;
}



bool GameScene::mEnd()
{
    return false;
}

//----------------------------------


uniquBaseScn GameScene::Update(uniquBaseScn own)
{
   /* if (CheckHitKey(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>(std::move(own));
    }*/

    //ポーズ機能
    key_.Update();
    if (mPose == false)
    {
        if (key_.getKeyDown(KEY_INPUT_ESCAPE))
        {
            mPose = true;
        }
    }
    else
    {
        if (key_.getKeyDown(KEY_INPUT_ESCAPE))
        {
            mPose = false;
           /* mMenu.init(this);*/
        }
    }
    if (key_.getKeyDown(KEY_INPUT_G))
    {
        return std::make_unique<EventScene>(std::move(own),mPlayer.plID_, mAitem->GetTam());
    }

    //時間
    nowTime_ = std::chrono::system_clock::now();		//現在の時間を取得
    auto elTime = nowTime_ - oldTime_;                  //時間の差をとる
    auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
    int delta = msec / 1000000.0; //秒に変換
    //delta = delta * 10;
    //一日の流れ
    int min = 60;    //一分間のフレーム数
    int Day = min * 5;      //一日の秒数

    //yuugata
    if (delta % Day == 120)
    {
        AMflg_ = false;
        PMflg_ = true;
        count_ = 0;
    }
    //yoru
    if (!AMflg_ && PMflg_ && delta % Day == 180)
    {
        Nightflg_ = true;
        PMflg_ = false;
        count_ = 0;
    }
    if (delta % Day == 0)
    {
        AMflg_ = true;
        PMflg_ = false;
        Nightflg_ = false;
        count_ = 0;
    }
    if (count_ <= 60)
    {
        count_++;
    }

    skycnt_++;
    
    DrawOwnScn();//個別のDraw処理な為必ず書く

    mMapOffset = lpMapMng.Update(PlayerPos);

    if ((mShop.SPose() == false)&&(mWshop.SPose() == false))
    {
        mPlayer.Update(lpMapMng.GetChipId());
    }

    PlayerPos = mPlayer.GetPos();

    PlayerSize = mPlayer.GetSiz();

    mNpc->Update(PlayerPos, PlayerSize, mChat->Getflg());

    mAitem->Update(PlayerPos, PlayerSize);
    mChat->Update(mNpc->Getflg(), mNpc->Num(), mShop.CanselFlg(), mShop.SPose(), mWshop.CanselFlg(), mWshop.SPose());

    //Waとsweetの両方で買えるアイテムがある場合に使う
    mAitem->TotalAitem(mShop.SsApple(), mShop.SsKinominoKusiyaki(), mShop.SsFruitDrink(), mShop.SsFishingRodS(), mShop.SsRagBag(), mShop.SsPickaxe(), mShop.SsKinomi(), mShop.SsRantan(), mShop.SsHaori(), mShop.SsRice(), mShop.SsDango(), mShop.SsTea(),
        mWshop.SsApple(), mWshop.SsKinominoKusiyaki(), mWshop.SsFruitDrink(), mWshop.SsFishingRodS(), mWshop.SsRagBag(), mWshop.SsPickaxe(), mWshop.SsKinomi(), mWshop.SsRantan(), mWshop.SsHaori(), mWshop.SsRice(), mWshop.SsDango(), mWshop.SsTea());


    mShop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum());
    mWshop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum());
   
  
    DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* PlayerPos = mPlayer.Update();*/

     /*mMenu.Update();*/
     if (mPose == true)
     {
         mMenu.Update();
     }

     bool AitemGet = mAitem->GetAitem();
     mShop.SsetAitem(AitemGet);
     mWshop.SsetAitem(AitemGet);

     mShop.Update(mChat->GetNum());

     mWshop.Update(mChat->GetNum());

     //mMenu.SetMenu(mShop.SsApple(), mShop.SsKinominoKusiyaki(), mShop.SsFruitDrink(), mShop.SsFishingRodS(), mShop.SsRagBag(), mShop.SsPickaxe(), mShop.SsKinomi(), mShop.SsRantan(), mShop.SsHaori());

    
     mShop.AMoney(mAitem->Money(mShop.SetMoney(),mShop.GetMoney()));


     mWshop.AMoney(mAitem->wMoney(mWshop.SetMoney(),mWshop.GetMoney()));

     int HaveMoney = mAitem->HaveMoney();

     mShop.sHaveMoney(HaveMoney);

     mWshop.sHaveMoney(HaveMoney);

      //フェードイン
     if (lpMapMng.fadeinFlg_)
     {
         if (fadein_.UpdataTrangetion())
         {
             lpMapMng.fadeinFlg_ = false;
         }
     }
    mBgm->Update(mMenu.OpBgm());


    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    auto mapID = lpMapMng.GetMapId();
    switch (mapID)
    {
    case MAP_ID::FOREST:
        skyflg_ = true;
        break;
    case MAP_ID::WA:
        skyflg_ = true;
        break;
    case MAP_ID::WASHOP:
        skyflg_ = false;
        break;
    case MAP_ID::CAVE:
        skyflg_ = false;
        break;
    case MAP_ID::CAVESHOP:
        skyflg_ = false;
        break;
    case MAP_ID::DARK:
        skyflg_ = false;
        break;
    case MAP_ID::FORESTIN:
        skyflg_ = false;
        break;
    case MAP_ID::TEMPLE:
        skyflg_ = true;
        break;
    case MAP_ID::TEMPLEIN:
        skyflg_ = false;
        break;
    case MAP_ID::SWEETS:
        skyflg_ = true;
        break;
    case MAP_ID::SWEETSOUT:
        skyflg_ = false;
        break;
    case MAP_ID::SWEETSSCHOOL:
        skyflg_ = false;
        break;
    case MAP_ID::TRANGETIONS:
        skyflg_ = false;
        break;
    case MAP_ID::MAX:
        break;
    default:
        break;
    }
    if (skyflg_&& AMflg_)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_);
        DrawBox(0, 0, 1080, 609, 0x4169e1, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (skyflg_ && PMflg_)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_-255);
        DrawBox(0, 0, 1080, 609, 0xff6347, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (skyflg_ && Nightflg_)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_-255);
        DrawBox(0, 0, 1080, 609, 0x191970, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    

    //マップ
    lpMapMng.Draw();

    mNpc->Draw(mMapOffset);

    mAitem->Draw(mMapOffset);

    //プレイヤー
	 mPlayer.Draw(mMapOffset);

     mLayer->Draw(mMapOffset);

     //時間帯
     TimeManeger();

     //デバッグ用
     auto elTime = nowTime_ - oldTime_;
     auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
     int delta = static_cast<int>(msec / 1000000.0); //秒に変換  
     //DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);

    
    

     mChat->Draw(mMapOffset);

     


     if (mPose == true)
     {
         mMenu.Draw();
     }

     mShop.Draw();

     mWshop.Draw();
    
     //フェードイン
     if (lpMapMng.fadeinFlg_)
     {
         fadein_.DrawOwnScn();
     }
    
}

bool GameScene::Init(void)
{

    // ポーズフラグ
    mPose = false;

    mAitem = new Aitem();

    mMenu.init(this);

    mShop.init();
    mWshop.init();

    //時間系初期化
    evening_ = LoadGraph("./image/yukoku.png");
    night_ = LoadGraph("./image/yoru.png");
    nowTime_ = std::chrono::system_clock::now();
    oldTime_ = nowTime_;
    AMflg_ = true;
    PMflg_ = false;
    Nightflg_ = false;
    count_ = 0;
    skycnt_ = 255;

    mBgm = new BGM();

    mNpc = new Npc();

    mChat = new Chat();

    mLayer = new Layer();

   	return true;

}

void GameScene::TimeManeger(void)
{
    //時間のレイヤーを適応するか
    auto mapID = lpMapMng.GetMapId();
    bool Flg = false;
    switch (mapID)
    {
    case MAP_ID::FOREST:
        Flg = true;
        break;
    case MAP_ID::WA:
        Flg = true;
        break;
    case MAP_ID::WASHOP:
        break;
    case MAP_ID::CAVE:
        break;
    case MAP_ID::CAVESHOP:
        break;
    case MAP_ID::DARK:
        break;
    case MAP_ID::FORESTIN:
        break;
    case MAP_ID::TEMPLE:
        Flg = true;
        break;
    case MAP_ID::TEMPLEIN:
        break;
    case MAP_ID::SWEETS:
        Flg = true;
        break;
    case MAP_ID::SWEETSOUT:
        break;
    case MAP_ID::SWEETSSCHOOL:
        break;
    case MAP_ID::TRANGETIONS:
        break;
    case MAP_ID::MAX:
        break;
    default:
        break;
    }

    //朝方
    if (AMflg_ && Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,60 - count_-1);
        DrawGraph(0, 0, night_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    //夕方
    if (PMflg_&& Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
        DrawGraph(0, 0, evening_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    //夜
    if (Nightflg_ && Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 60-count_);
        DrawGraph(0, 0, evening_, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_+1);
        DrawGraph(0, 0, night_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}


