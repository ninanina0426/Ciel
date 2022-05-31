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

//�A�C�e���̃t���O ---------------------------
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

    //�|�[�Y�@�\
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

    //����
    nowTime_ = std::chrono::system_clock::now();		//���݂̎��Ԃ��擾
    auto elTime = nowTime_ - oldTime_;                  //���Ԃ̍����Ƃ�
    auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
    int delta = msec / 1000000.0; //�b�ɕϊ�

    //����̗���
    int min = 60;    //�ꕪ�Ԃ̃t���[����
    int Day = min*10;      //����̕b��

    if (delta % Day == 300)
    {
        AMflg_ = false;
        PMflg_ = true;
        count_ = 0;
    }
    if (!AMflg_ && PMflg_ && delta % Day == 420)
    {
        Nightflg_ = true;
        PMflg_ = false;
        count_ = 0;
    }
   /* if (PMflg_ && !AMflg_ && delta % Day == 121)
    {
        AMflg_ = true;
        Nightflg_ = false;
        count_ = 0;
    }*/

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

    PlayerPos = mPlayer.GetPos();

    mMapOffset = lpMapMng.Update(PlayerPos);

    mPlayer.Update();

    DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* PlayerPos = mPlayer.Update();*/

    /* mAitem->Update();*/

     /*mMenu.Update();*/


    return std::move(own);
}

void GameScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    //�}�b�v
    lpMapMng.Draw();

    //�v���C���[
	 mPlayer.Draw(GameScene::mMapOffset);
    
     //���ԑ�
     TimeManeger();

     //�f�o�b�O�p
     auto elTime = nowTime_ - oldTime_;
     auto msec = std::chrono::duration_cast<std::chrono::microseconds>(elTime).count();
     int delta = msec / 1000000.0; //�b�ɕϊ�  
     //DrawFormatString(0, 100, 0xffffff, "deltaTime:%d", delta);
    /* mAitem->Draw(mMapOffset);*/

    /* mMenu.Draw();*/
    
}

bool GameScene::Init(void)
{
    // �|�[�Y�t���O
        mPose = false;

    mAitem = new Aitem();

    mMenu.init(this);

    //���Ԍn������
    evening_ = LoadGraph("./image/yukoku.png");
    night_ = LoadGraph("./image/yoru.png");
    nowTime_ = std::chrono::system_clock::now();
    oldTime_ = nowTime_;
    AMflg_ = true;
    PMflg_ = false;
    Nightflg_ = false;
    count_ = 0;


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


