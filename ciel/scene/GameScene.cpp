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
#include "Obj/Quest.h"
#include"Obj/Masuku.h"
#include"Obj/Love.h"
#include "Transition/FadeInOut.h"
#include "EndScene.h"
#include "Obj/Quest.h"

GameScene::GameScene(PlayerID playerID)
{
    Init();
    mPlayer.plID_ = playerID;
    DrawOwnScn();
}

GameScene::~GameScene()
{
    game.reset();
    delete mBgm;
    delete mNpc;
    delete mChat;
    delete mLayer;
    delete mMasuku;
    delete mLove;
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

bool GameScene::IsTama6(void)
{
    return  mAitem->mTama6;
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
    return mAitem->Takara;
}

//----------------------------------


uniquBaseScn GameScene::Update(uniquBaseScn own)
{
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
        return std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam());
    }

    if (IsTama1() && !movefl[0])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[0] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }

    }
    if (IsTama2() && !movefl[1])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[1] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }
    }
    if (IsTama3() && !movefl[2])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[2] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }
    }
    if (IsTama4() && !movefl[3])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[3] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }
    }
    if (IsTama5() && !movefl[4])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[4] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }
    }
    if (IsTama6() && !movefl[5])
    {
        ui_.eveflg_ = true;
        if (key_.getKeyDown(KEY_INPUT_F))
        {
            ui_.eveflg_ = false;
            game = std::make_shared <GameScene>(mPlayer.plID_);
            movefl[5] = true;
            return std::make_unique<FadeInOut>(game, std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam()));
        }
    }

    //凍死エンド
    if (detTime_ >700)
    {
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_1", mPlayer.plID_));

    }
    //trueエンド
    if (mAitem->Takara==1)
    {
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_2", mPlayer.plID_));
    }
    //loveエンド
    if (mLove->eFlg==true)
    {
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_4", mPlayer.plID_));
    }
    //餓死エンド
    if (ded_>700)
    {
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_5", mPlayer.plID_));
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
    cnt_++;
    //yuugata
    if (delta % Day == 120)
    {
        AMflg_ = false;
        PMflg_ = true;
        count_ = 0;
        skycnt_ = 0;
    }
    //yoru
    if (!AMflg_ && PMflg_ && delta % Day == 180)
    {
        Nightflg_ = true;
        PMflg_ = false;
        count_ = 0;
        skycnt_ = 0;
    }
    if (delta % Day == 0)
    {
        AMflg_ = true;
        PMflg_ = false;
        Nightflg_ = false;
        count_ = 0;
        skycnt_ = 0;
    }
    if (count_ <= 60)
    {
        count_++;
    }
    skycnt_++;
    //一日の消費カロリー
    switch (mPlayer.plID_)
    {
    case PlayerID::Jack:
        if (cnt_ %600==0)
        {
            //20heru
            mPlayer.Energy_ -= 1;
        }
        break;
    case PlayerID::Calendula:
        if (cnt_ % 2400 == 0)
        {
            //5
            mPlayer.Energy(1);
        }
        break;
    case PlayerID::Soy:
        if (cnt_ % 1200 == 0)
        {
            //10
            mPlayer.Energy(1);
        }
            break;
    default:
        break;
    }
    
    
    DrawOwnScn();//個別のDraw処理な為必ず書く

    if ((mShop.SPose() == false) && (mWshop.SPose() == false)&&(ui_.eveflg_==false))
    {
        mMapOffset = lpMapMng.Update(PlayerPos, mAitem->GetTam(), mMasuku->Flg());
        mPlayer.Update(lpMapMng.GetChipId(), ui_.eveflg_, mLove->Hit(),mMenus.En(),mPose,mNpc->NpcHit());

    }

    PlayerPos = mPlayer.GetPos();

    PlayerSize = mPlayer.GetSiz();

    mNpc->Update(PlayerPos, PlayerSize, mChat->Getflg());

    mLove->Update(PlayerPos, PlayerSize,mPlayer.GetDIR(),mMenus.NumHave());

    mAitem->Update(PlayerPos, PlayerSize);
    mChat->Update(mNpc->Getflg(), mNpc->Num(), mShop.CanselFlg(), mShop.SPose(), mWshop.CanselFlg(), mWshop.SPose());


    //Waとsweetの両方で買えるアイテムがある場合に使う
    mAitem->TotalAitem(mShop.SsApple(), mShop.SsKinominoKusiyaki(), mShop.SsFruitDrink(), mShop.SsFishingRodS(), mShop.SsRagBag(), mShop.SsPickaxe(), mShop.SsKinomi(), mShop.SsRantan(), mShop.SsHaori(), mShop.SsRice(), mShop.SsDango(), mShop.SsTea(),mShop.SsFish(), mShop.SsStoneR(),mShop.SsStoneB(),
        mWshop.SsApple(), mWshop.SsKinominoKusiyaki(), mWshop.SsFruitDrink(), mWshop.SsFishingRodS(), mWshop.SsRagBag(), mWshop.SsPickaxe(), mWshop.SsKinomi(), mWshop.SsRantan(), mWshop.SsHaori(), mWshop.SsRice(), mWshop.SsDango(), mWshop.SsTea(), mWshop.SsFish(), mWshop.SsStoneR(), mWshop.SsStoneB(),
        mMenus.AppleE(), mMenus.KinominoKusiyakiE(), mMenus.FruitDrinkE(), mMenus.FishingRodSE(), mMenus.RagBagE(), mMenus.PickaxeE(), mMenus.KnomiE(), mMenus.mRantanE(), mMenus.mHaoriE(), mMenus.RiceE(), mMenus.DangoE(), mMenus.TeaE(),mMenus.FishE(),mMenus.StoneRE(),mMenus.StoneBE(),
        mLove->Apple(),mLove->KinominoKusiyaki(),mLove->FruitDrink(),mLove->Rice(),mLove->Dango(),mLove->Tea() , mPlayer.GetRed(), mPlayer.GetFish(),mPlayer.GetBule(),QuestIns.GetHaori());



    mShop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(),mAitem->FishNum(),mAitem->StoneRNum(),mAitem->StoneBNum());
    mWshop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(), mAitem->FishNum(), mAitem->StoneRNum(), mAitem->StoneBNum());

    DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* PlayerPos = mPlayer.Update();*/

   

    bool AitemGet = mAitem->GetAitem();
    mShop.SsetAitem(AitemGet);
    mWshop.SsetAitem(AitemGet);

    mShop.Update(mChat->GetNum());

    mWshop.Update(mChat->GetNum());

    mMenus.SetMenu(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(), mAitem->TeaNum(), mAitem->KeyNum(), mAitem->FishNum(),mAitem->StoneRNum(),mAitem->StoneBNum());
   
    mMenus.Update(mLove->NumH(),mPose);

    mShop.AMoney(mAitem->Money(mShop.SetMoney(), mShop.GetMoney()));


    mWshop.AMoney(mAitem->wMoney(mWshop.SetMoney(), mWshop.GetMoney()));

    auto r = QuestIns.GetRu();
    auto q = QuestIns.CompFlg();

    mAitem->qMoney(r, q);

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
    
    
   

    if (!mPose)
    {
        if (!IsHaori())
        {
            ColdState();
        }

        if (mPlayer.GetSEnergy() <= 0)
        {
            DeadState();
        }
        else
        {
            ded_ = 0;
        }
    }
    
    mMasuku->Update(PlayerPos, mAitem->mRantanNum(),mMenus.NumHave());

    ui_.Upadate(mPlayer, mMapOffset);
   
  

    mBgm->Update(mMenus.OpBgm(),ui_.eveflg_);

    
    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    auto mapID = lpMapMng.GetMapId();

    auto elTime = nowTime_ - oldTime_;
    auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
    int delta = static_cast<int>(msec / 1000000.0); //秒に変換  
   // delta = delta * 20;
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
        DrawGraph(0, 0, you_, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_);
        DrawGraph(0, 0, asa_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (skyflg_ && PMflg_)
    {
        DrawGraph(0, 0, asa_, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_);
        DrawGraph(0, 0, yuu_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    if (skyflg_ && Nightflg_)
    {
        DrawGraph(0, 0, yuu_, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, skycnt_);
        DrawGraph(0, 0, you_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
    
    

    //マップ
    lpMapMng.Draw();

    mNpc->Draw(mMapOffset);

    mAitem->Draw(mMapOffset);

    mLove->Draw(mMapOffset);

     

    
     //DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    
    
     //プレイヤー
     mPlayer.Draw(mMapOffset);

     mLayer->Draw(mMapOffset);
     
     //時間帯
     TimeManeger();

     if (mPose == true)
     {
         mMenus.Draw(mPlayer.GetType(),mAitem->HaveMoney(),mPlayer.EnergyNum(),mPlayer.StaminaNum());
     }

     

     mChat->Draw(mMapOffset);

     mShop.Draw();

     mWshop.Draw();

    
    
     mMasuku->Draw(mMapOffset);

     ui_.Draw();

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

    mMenus.init();

    mShop.init();
    mWshop.init();

    //時間系初期化
    evening_ = LoadGraph("./image/yukoku.png");
    night_ = LoadGraph("./image/yoru.png");
    asa_ = LoadGraph("./image/move/朝.png");
    yuu_ = LoadGraph("./image/move/夕.png");
    you_ = LoadGraph("./image/move/夜.png");
    ice_ = LoadGraph("./image/ui/ice.png");


    nowTime_ = std::chrono::system_clock::now();
    oldTime_ = nowTime_;
    AMflg_ = true;
    PMflg_ = false;
    Nightflg_ = false;
    count_ = 0;
    skycnt_ = 255;
    detTime_ = 0;
    cnt_ = 0;

    for (int i = 0; i < 6; i++)
    {
        movefl[i] = false;
    }

    mBgm = new BGM();

    mNpc = new Npc();

    mChat = new Chat();

    mLayer = new Layer();

    mMasuku = new Masuku();

    mLove = new Love();

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

void GameScene::ColdState(void)
{
    auto map = lpMapMng.GetMapId();
    if (map == MAP_ID::SNOW || map == MAP_ID::SNOWCAVE)
    {
        detTime_++;

        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawExtendGraph(0, 0, 1080, 610, ice_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

        if (detTime_ > 200)
        {
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, (detTime_/2)-50);
            DrawBox(0, 0, 1080, 609, 0x000000, true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            if (detTime_ > 600)
            {
                DrawString(500, 300, "さむい・・・・", 0xffffff, true);
            }
        }
        
    }
}

void GameScene::DeadState(void)
{
    ded_++;
    if (ded_ > 200)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, (ded_ / 2) - 50);
        DrawBox(0, 0, 1080, 609, 0x000000, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (ded_ > 600)
        {
            DrawString(400, 300, "お腹・・・空いた・・・もうダメ・・・・・・", 0xffffff, true);
        }
    }
}


