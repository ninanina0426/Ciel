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


//�A�C�e���̃t���O ---------------------------

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

    //�|�[�Y�@�\
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
        return std::make_unique<EventScene>(std::move(own));
    }

    //����
    nowTime_ = std::chrono::system_clock::now();		//���݂̎��Ԃ��擾
    auto elTime = nowTime_ - oldTime_;                  //���Ԃ̍����Ƃ�
    auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
    int delta = msec / 1000000.0; //�b�ɕϊ�

    //����̗���
    int min = 60;    //�ꕪ�Ԃ̃t���[����
    int Day = min * 5;      //����̕b��

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


    DrawOwnScn();//�ʂ�Draw�����ȈוK������

    mMapOffset = lpMapMng.Update(PlayerPos);

    if (mShop.SPose() == false)
    {
        mPlayer.Update(lpMapMng.GetChipId());
    }

    PlayerPos = mPlayer.GetPos();

    PlayerSize = mPlayer.GetSiz();

    mNpc->Update(PlayerPos, PlayerSize, mChat->Getflg());

    mAitem->Update(PlayerPos, PlayerSize);
    mChat->Update(mNpc->Getflg(), mNpc->Num(), mShop.CanselFlg(), mShop.SPose());
   
    DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* PlayerPos = mPlayer.Update();*/

     /*mMenu.Update();*/
     if (mPose == true)
     {
         mMenu.Update();
     }


     mShop.Update(mChat->GetNum());

      //�t�F�[�h�C��
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

    //�}�b�v
    lpMapMng.Draw();

    mNpc->Draw(mMapOffset);

    //�v���C���[
	 mPlayer.Draw(mMapOffset);

     mLayer->Draw(mMapOffset);

     //���ԑ�
     TimeManeger();

     //�f�o�b�O�p
     auto elTime = nowTime_ - oldTime_;
     auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
     int delta = static_cast<int>(msec / 1000000.0); //�b�ɕϊ�  
     //DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);

     mAitem->Draw(mMapOffset);
    

     mChat->Draw(mMapOffset);

     


     if (mPose == true)
     {
         mMenu.Draw();
     }

     mShop.Draw(mAitem->KnomiNum(), mAitem->AppleNum());
    
     //�t�F�[�h�C��
     if (lpMapMng.fadeinFlg_)
     {
         fadein_.DrawOwnScn();
     }
    
}

bool GameScene::Init(void)
{

    // �|�[�Y�t���O
    mPose = false;

    mAitem = new Aitem();

    mMenu.init(this);

    mShop.init(this);

    //���Ԍn������
    evening_ = LoadGraph("./image/yukoku.png");
    night_ = LoadGraph("./image/yoru.png");
    nowTime_ = std::chrono::system_clock::now();
    oldTime_ = nowTime_;
    AMflg_ = true;
    PMflg_ = false;
    Nightflg_ = false;
    count_ = 0;

    mBgm = new BGM();

    mNpc = new Npc();

    mChat = new Chat();

    mLayer = new Layer();

   	return true;

}

void GameScene::TimeManeger(void)
{
    //���Ԃ̃��C���[��K�����邩
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

    //����
    if (AMflg_ && Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA,60 - count_-1);
        DrawGraph(0, 0, night_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    //�[��
    if (PMflg_&& Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
        DrawGraph(0, 0, evening_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }

    //��
    if (Nightflg_ && Flg)
    {
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 60-count_);
        DrawGraph(0, 0, evening_, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_+1);
        DrawGraph(0, 0, night_, true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    }
}


