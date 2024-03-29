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
    if ((mShop.SPose() == false) && (mWshop.SPose() == false))
    {
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
    }

    /*if (key_.getKeyDown(KEY_INPUT_G))
    {
        return std::make_unique<EventScene>(std::move(own), mPlayer.plID_, mAitem->GetTam());
    }*/

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
            StopSoundMem(mPlayer.oHandle);
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
    if (endFlg_)
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
    //暗躍エンド
    if (cave_ > 400)
    {
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_6", mPlayer.plID_));
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
        mMapOffset = lpMapMng.Update(PlayerPos, mAitem->GetTam(), mMasuku->Flg(),mAitem->GetKey(), TamaPow());
        mPlayer.Update(lpMapMng.GetChipId(), ui_.eveflg_, mLove->Hit(),mMenus.En(),mPose,mNpc->NpcHit(),mAitem->FishingRodSNum(),mAitem->PickaxeNum());

    }

    if (lpMapMng.rimFlg_)
    {
        mPlayer.gFlg = false;
    }
    PlayerPos = mPlayer.GetPos();

    PlayerSize = mPlayer.GetSiz();

    mNpc->Update(PlayerPos, PlayerSize, mChat->Getflg(),mAitem->FishNum());

    mLove->Update(PlayerPos, PlayerSize,mPlayer.GetDIR(),mMenus.NumHave());

    mAitem->Update(PlayerPos, PlayerSize);
    mChat->Update(mNpc->Getflg(), mNpc->Num(), mShop.CanselFlg(), mShop.SPose(), mWshop.CanselFlg(), mWshop.SPose());


    //Waとsweetの両方で買えるアイテムがある場合に使う
    mAitem->TotalAitem(mShop.SsApple(), mShop.SsKinominoKusiyaki(), mShop.SsFruitDrink(), mShop.SsFishingRodS(), mShop.SsRagBag(), mShop.SsPickaxe(), mShop.SsKinomi(), mShop.SsRantan(), mShop.SsHaori(), mShop.SsRice(), mShop.SsDango(), mShop.SsTea(),mShop.SsFish(), mShop.SsStoneR(),mShop.SsStoneB(),
        mWshop.SsApple(), mWshop.SsKinominoKusiyaki(), mWshop.SsFruitDrink(), mWshop.SsFishingRodS(), mWshop.SsRagBag(), mWshop.SsPickaxe(), mWshop.SsKinomi(), mWshop.SsRantan(), mWshop.SsHaori(), mWshop.SsRice(), mWshop.SsDango(), mWshop.SsTea(), mWshop.SsFish(), mWshop.SsStoneR(), mWshop.SsStoneB(),
        mMenus.AppleE(), mMenus.KinominoKusiyakiE(), mMenus.FruitDrinkE(), mMenus.FishingRodSE(), mMenus.RagBagE(), mMenus.PickaxeE(), mMenus.KnomiE(), mMenus.mRantanE(), mMenus.mHaoriE(), mMenus.RiceE(), mMenus.DangoE(), mMenus.TeaE(),mMenus.FishE(),mMenus.StoneRE(),mMenus.StoneBE(),
        mLove->Apple(),mLove->KinominoKusiyaki(),mLove->FruitDrink(),mLove->Rice(),mLove->Dango(),mLove->Tea() , mPlayer.GetRed(), mPlayer.GetFish(),mPlayer.GetBule(),QuestIns.GetHaori(),QuestIns.Getfish());


   
    mShop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(), mAitem->FishNum(), mAitem->StoneRNum(), mAitem->StoneBNum());
    mWshop.SetAitem(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(), mAitem->FishNum(), mAitem->StoneRNum(), mAitem->StoneBNum());
   
    //DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* PlayerPos = mPlayer.Update();*/

   

    bool AitemGet = mAitem->GetAitem();
    mShop.SsetAitem(AitemGet);
    mWshop.SsetAitem(AitemGet);

    if ((mPose == false))
    {
        mShop.Update(mChat->GetNum());
        mWshop.Update(mChat->GetNum());
    }

    mMenus.SetMenu(mAitem->AppleNum(), mAitem->KinominoKusiyakiNum(), mAitem->FruitDrinkNum(), mAitem->FishingRodSNum(), mAitem->RagBagNum(), mAitem->PickaxeNum(), mAitem->KnomiNum(), mAitem->mRantanNum(), mAitem->mHaoriNum(), mAitem->RiceNum(), mAitem->DangoNum(), mAitem->TeaNum(), mAitem->TamNum(), mAitem->KeyNum(), mAitem->FishNum(), mAitem->StoneRNum(), mAitem->StoneBNum());
   
    if ((mShop.SPose() == false) && (mWshop.SPose() == false))
    {
        mMenus.Update(mLove->NumH(), mPose);
    }
   
    mShop.AMoney(mAitem->Money(mShop.SetMoney(), mShop.GetMoney()));


    mWshop.AMoney(mAitem->wMoney(mWshop.SetMoney(), mWshop.GetMoney()));

    auto r = QuestIns.getru_;
    auto q = QuestIns.questCmpFlg[1]==QuestState::COMP;

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

        if (mMasuku->MoveFlg())
        {
            CaveState();
        }
       
    }
    if (mAitem->Takara == 1 && !moveFlg_)
    {
        EndMV();
    }
    if (moveFlg_)
    {
        if (mPlayer.GetPos().y_ < 1026 && lpMapMng.GetMapId()==MAP_ID::TEMPLEIN && key_.getKeyDown(KEY_INPUT_F))
        {
            auto f = MessageBox(NULL, TEXT("かえりますか？"), TEXT(""), MB_YESNO | MB_ICONINFORMATION);
            if (f == IDYES)
            {
                endFlg_ = true;
            }
            else if (f == IDNO)
            {
                
            }
        }
    }

    mMasuku->Update(PlayerPos, mAitem->mRantanNum(),mMenus.NumHave());

    ui_.Upadate(&mPlayer, mMapOffset,mMenus.NumHave(),abs(5-mAitem->mKinomi),mAitem->FishNum(),mPlayer.aitemFlag_,mPlayer.aitemNum_);
   
  

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

     
     if ((mPose == true) && ((mShop.SPose() == false) && (mWshop.SPose() == false)))
     {
         mMenus.Draw(mPlayer.GetType(), mAitem->HaveMoney(), mPlayer.EnergyNum(), mPlayer.StaminaNum());
     }
     

     mChat->Draw(mMapOffset);

     mMasuku->Draw(mMapOffset);

     ui_.Draw(AMflg_,PMflg_,Nightflg_);

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
    LoadDivGraph("./image/warp.png", 26, 2, 13, 320, 240, warp[0], true);

    nowTime_ = std::chrono::system_clock::now();
    oldTime_ = nowTime_;
    AMflg_ = true;
    PMflg_ = false;
    Nightflg_ = false;
    count_ = 0;
    skycnt_ = 255;
    detTime_ = 0;
    cnt_ = 0;

    boxmove_ = 0;

    endFlg_ = false;
    moveFlg_ = false;
    endcnt_ = 0;
    efff_ = false;
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



int GameScene::TamaPow(void)
{
 
    chengF_ = 10;


    if (mAitem->mTama1&&!lpMapMng.Tama_Use[2])
    {
        chengF_ = 2;
        
    }
    if (mAitem->mTama2 && !lpMapMng.Tama_Use[0])
    {
        chengF_ = 0;
    }
    if (mAitem->mTama3 && !lpMapMng.Tama_Use[3])
    {
        chengF_ = 3;
    }
    if (mAitem->mTama4 && !lpMapMng.Tama_Use[1])
    {
        chengF_ = 1;
    }
    if (mAitem->mTama5 && !lpMapMng.Tama_Use[4])
    {
        chengF_ = 4;
    }
    if (mAitem->mTama6 && !lpMapMng.Tama_Use[5])
    {
        chengF_ = 5;
    }

    
    return chengF_;
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

void GameScene::CaveState(void)
{
    auto map = lpMapMng.GetMapId();
    if (map == MAP_ID::CAVE)
    {
        cave_++;

        if (cave_ > 300)
        {
            DrawString(500, 300, "何か聞こえる・・・・", 0xffffff, true);
        }
    }

}


void GameScene::EndMV(void)
{

    if (!moveFlg_)
    {
        DrawBox(0, 0, 1080, 609, 0x000000, true);
        DrawString(400, 250, "Cielの秘宝を手に入れました\n      かえりますか？", 0xffffff, true);
        DrawString(330, 370, "はい", 0xffffff, true);
        DrawString(730, 370, "いいえ", 0xffffff, true);



        Vector2 boxPos = { 300,350 };
        if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            if (boxmove_ == 400)
            {
                boxmove_ = 0;
            }
        }
        if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            if (boxmove_ == 0)
            {
                boxmove_ = 400;
            }
        }
        DrawBox(boxPos.x_ + boxmove_, boxPos.y_, boxPos.x_ + 100 + boxmove_, boxPos.y_ + 50, 0xffffff, false);
        if (key_.getKeyDown(KEY_INPUT_RETURN) && boxmove_ == 0)
        {
            mPose = true;
            efff_ = true;
        }
        else if (key_.getKeyDown(KEY_INPUT_RETURN) && boxmove_ == 400)
        {
            moveFlg_ = true;
        }
        if (efff_)
        {
            endcnt_++;
            DrawBox(0, 0, 1080, 609, 0x000000, true);
            
            DrawExtendGraph(0, 0, 1080, 609, *warp[(endcnt_ / 10)%26], true);

            if (endcnt_ > 100)
            {
                endFlg_ = true;
            }
        }
    }
    

}

