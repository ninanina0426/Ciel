#include <DxLib.h>
#include "EventScene.h"
#include "Transition/FadeInOut.h"

EventScene::EventScene(uniquBaseScn gameScene, PlayerID playerID, int aitem)
{
    gameScene_ = std::move(gameScene);
    player_.plID_ = playerID;
    aitem_ = aitem;
    Init();
}

EventScene::~EventScene()
{
}

uniquBaseScn EventScene::Update(uniquBaseScn own)
{
   /* if (CheckHitKey(KEY_INPUT_F))
    {
        flg_ = true;
    }*/
    if (mNum >= 70)
    {
        if (CheckHitKey(KEY_INPUT_F))
        {
            flg_ = true;
            mNum = 0;
        }
    }
    //フラグがtrueになったらゲームシーンに返す
    if (flg_)
    {
        StopSoundMem(rany);
        StopSoundMem(li_);
        return std::make_unique<FadeInOut>(std::move(own), std::move(gameScene_));
    }
    DrawOwnScn();
    //動画が終わったら
    if (GetMovieStateToGraph(move1_) == 0)
    {
        flg_ = true;
    }

    movePos = mPos - mOffset;
    //プレイヤーの操作
    if (mNum < 70)
    {
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            mPos.y_ += 3;
            dir = 2;
            mNum += 1;
        }
        else if (CheckHitKey(KEY_INPUT_UP))
        {
            mPos.y_ -= 3;
            dir = 0;
            mNum += 1;
        }
        else if (CheckHitKey(KEY_INPUT_LEFT))
        {
            mPos.x_ -= 3;
            dir = 3;
            mNum += 1;
        }
        else if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            mPos.x_ += 3;
            dir = 1;
            mNum += 1;
        }
    }
    
    //カメラ
    if (movePos.x_ > 200)
    {
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            mOffset.x_ += 3;
        }
    }
    if (movePos.x_ < 880)
    {
        if (CheckHitKey(KEY_INPUT_LEFT))
        {
            mOffset.x_ -= 1;
        }
    }
    if (movePos.y_ > 100)
    {
        if (CheckHitKey(KEY_INPUT_DOWN))
        {
            mOffset.y_ += 3;
        }
    }
    if (movePos.y_ < 509)
    {
        if (CheckHitKey(KEY_INPUT_UP))
        {
            mOffset.y_ -= 3;
        }
    }
    //	//カメラ追従
    if (movePos.x_ > 500)
    {
        mOffset.x_ += 2;
    }
    if (movePos.x_ < 1370)
    {
        mOffset.x_ -= 2;
    }
    if (movePos.y_ < 450)
    {
        mOffset.y_ -= 2;
    }
    if (movePos.y_ > 400)
    {
        mOffset.y_ += 2;
    }
    //カメラ端
    if (mOffset.x_ > 500)
    {
        mOffset.x_ = 500;
    }
    if (mOffset.x_ < 0)
    {
        mOffset.x_ = 0;
    }
    if (mOffset.y_ < 0)
    {
        mOffset.y_ = 0;
    }
    if (mOffset.y_ > 950)
    {
        mOffset.y_ = 950;
    }

    if (mPos.y_ < 585)
    {
        mPos.y_ = 585;
    }
    if (mPos.y_ > 1365)
    {
        mPos.y_ = 1365;
    }
    if (mPos.x_ < 402)
    {
        mPos.x_ = 402;
    }
    if (mPos.x_ > 936)
    {
        mPos.x_=936;
    }
    Event(aitem_);

    animcnt_++;
    Cnt++;
    return std::move(own);
}

void EventScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    auto plID = player_.plID_;
    switch (plID)
    {
    case PlayerID::Jack:
        break;
    case PlayerID::Calendula:
        break;
    case PlayerID::Soy:
        break;
    case PlayerID::Max:
        break;
    default:
        break;
    }
    //DrawBox(0, 0, 1080, 609, 0xffabcf, true);
    player_.Draw(Vector2{100,100});
   // DrawExtendGraph(0, 0, 1080,609,move1_, false);
}

bool EventScene::Init(void)
{
    flg_ = false;
    shFlg_ = false;

    Cnt = 0;

    mPos = {500,600};
    mOffset = { 0,0 };
    dir = 2;
    mNum=0;
   
    //aitem_ = new Aitem;
    sea_ = LoadGraph("./image/move/umi.png");
    rany_= LoadGraph("./image/move/rany.png");
    cloud_ = LoadGraph("./image/move/ame.png");
    rany = LoadSoundMem("image/Sound/rain.ogg");
    li_ = LoadSoundMem("image/Sound/li.ogg");

    LoadDivGraph("./image/move/air.png", 12, 3, 4, AirplneSize, AirplneSize, &airplan_[0][0], true);
    LoadDivGraph("./image/move/煙.png", 12, 3, 4, 352, 256, *kemuri_, true);

    if (LoadDivGraph("image/char/110.png", 48, 4, 12, 48, 48, &mImageP[0]) == -1)
    {
        return false;
    }
    if (LoadDivGraph("image/char/金.png", 27, 1, 27, 32, 48, &mImagePD[0]) == -1)
    {
        return false;
    }

    //soy
    LoadDivGraph("./image/char/過去S2.png", 16, 4, 4, 48, 48, &mImageS[0]);
    LoadDivGraph("./image/char/過去S.png", 16, 4, 4, 48, 48, &mImageST[0]);
    LoadDivGraph("./image/char/過去S3.png", 16, 4, 4, 48, 48, &mImageSF[0]);
    LoadDivGraph("./image/npc/例.png", 16, 4, 4, 32, 48, &mImageMob[0]);
    mImageMap=LoadGraph("image/soy.png");
    mImageMap1=LoadGraph("image/soy1.png");



    mImageC[0] = LoadGraph("image/talk/temple.png");
    mImageC[1] = LoadGraph("image/talk/temple.png");
    mImageC[2] = LoadGraph("image/talk/temple.png");
    mImageC[3] = LoadGraph("image/talk/temple.png");

    house_ = LoadGraph("image/1108s.png");
    //move1_ = LoadGraph("./image/move/video.avi");
    PlayMovieToGraph(move1_);
    return true;
}

SceneID EventScene::GetSceneID(void)
{
    return SceneID::EVENT;
}

void EventScene::Event(int num)
{
    auto evetype = static_cast<EventType>(abs(num-6));
    auto plID = player_.plID_;
   
    switch (evetype)
    {
    case EventType::PROLOGUE:
        DrawGraph(0, -1300+animcnt_, sea_, false);
        DrawExtendGraph(500, 350, 500 + AirplneSize * 3, 350 + AirplneSize * 3, airplan_[3][(animcnt_ / 5) % 3], true);

        if (animcnt_ > 76)
        {
            DrawGraph(0, 0, cloud_, true);
            DrawGraph(0, -1380 + animcnt_ * 10, rany_, true);
            DrawGraph(0, -2760 + animcnt_ * 10, rany_, true);
            DrawGraph(0, -4140 + animcnt_ * 10, rany_, true);
            DrawGraph(0, -5520 + animcnt_ * 10, rany_, true);
            if (animcnt_ < 78)
            {
                shFlg_ = true;
            }
           
            if ((animcnt_ / 5) % 15 == 0)
            {
                DrawBox(0, 0, 1080, 609, 0xffffff, true);
            }
            if (animcnt_ > 300)
            {
                DrawGraph(390, 190, kemuri_[1][(animcnt_ / 5) % 3], true);
            }
           
        }
        if (animcnt_ > 500)
        {
            flg_ = true;
        }
        if (shFlg_)
        {
            PlaySoundMem(rany, DX_PLAYTYPE_BACK);
            PlaySoundMem(li_, DX_PLAYTYPE_BACK);
            shFlg_ = false;
        }
        
        break;
    case EventType::STORY_1:
        switch (plID)
        {
        case PlayerID::Jack:
            DrawExtendGraph(0, 0, 1080, 600, house_, true);
            DrawGraph(370, 320, mImageP[8], true);
            if (Cnt >= 100)
            {
                DrawGraph(330, 260, mImageC[0], true);
            }
            if (Cnt >= 200)
            {
                DeleteGraph(mImageC[0], true);
                DrawGraph(330, 260, mImageC[1], true);
            }
            break;
        case PlayerID::Calendula:
            break;
        case PlayerID::Soy:
            DrawGraph(0-mOffset.x_, 0-mOffset.y_, mImageMap1, true);
            if (mNum < 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageS[dir * 4 + ((animcnt_ / 8) % 4)], true);
            }
            if (mNum >= 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageS[dir * 4], true);
                DrawGraph(mPos.x_ - mOffset.x_-50, mPos.y_ - mOffset.y_ - 100, mImageC[0], true);
            }
            //DrawFormatString(0, 500, GetColor(0, 0, 255), "playerPos=(%d,%d)", mPos.x_, mPos.y_);
            break;
        default:
            break;
        }
        //DrawString(400, 300, "エピソード1", 0xffffff, true);
        break;

    case EventType::STORY_2: 
        switch (plID)
        {
        case PlayerID::Jack:
            DrawExtendGraph(0, 0, 1080, 600, house_, true);
            DrawGraph(370, 320, mImagePD[0], true);
            if (Cnt >= 100)
            {
                DrawGraph(330, 260, mImageC[2], true);
            }
            if (Cnt >= 200)
            {
                DeleteGraph(mImageC[2], true);
                DrawGraph(330, 260, mImageC[3], true);
            }
            break;
        case PlayerID::Calendula:
            break;
        case PlayerID::Soy:
            DrawGraph(0 - mOffset.x_, 0 - mOffset.y_, mImageMap1, true);

            DrawGraph(500 - mOffset.x_, 600 - mOffset.y_, mImageSF[1 * 4], true);
            DrawGraph(570 - mOffset.x_, 580 - mOffset.y_, mImageMob[1 * 4], true);
            if (mNum >= 1)
            {
                DrawGraph(570 - mOffset.x_ - 60, 600 - mOffset.y_ - 100, mImageC[0], true);
                DrawGraph(500 - mOffset.x_ - 40, 600 - mOffset.y_ - 100, mImageC[0], true);
            }
            break;
        default:
            break;
        }
        //DrawString(400, 300, "エピソード2", 0xffffff, true);
        break;

    case EventType::STORY_3:
        switch (plID)
        {
        case PlayerID::Jack:
            DrawGraph(0, 0, mImageP[8], true);
            break;
        case PlayerID::Calendula:
            break;
        case PlayerID::Soy:
            DrawGraph(0 - mOffset.x_, 0 - mOffset.y_, mImageMap, true);
            if (mNum < 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageST[dir * 4 + ((animcnt_ / 8) % 4)], true);
            }
            if (mNum >= 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageST[dir * 4], true);
                DrawGraph(mPos.x_ - mOffset.x_ - 50, mPos.y_ - mOffset.y_ - 100, mImageC[0], true);
            }
            break;
        default:
            break;
        }
       /* DrawString(400, 300, "エピソード3", 0xffffff, true);*/
        break;
    case EventType::STORY_4:
        switch (plID)
        {
        case PlayerID::Jack:
            DrawGraph(0, 0, mImageP[8], true);
            break;
        case PlayerID::Calendula:
            break;
        case PlayerID::Soy:
            DrawGraph(0 - mOffset.x_, 0 - mOffset.y_, mImageMap, true);
            DrawGraph(500,600, mImageSF[1 * 4], true);
            DrawGraph(550, 600, mImageMob[3 * 4], true);
            DrawGraph(550- 40,600- 100, mImageC[0], true);
            DrawGraph(500- 60,600- 100, mImageC[0], true);
            break;
        default:
            break;
        }
        /*DrawString(400, 300, "エピソード4", 0xffffff, true);*/
        break;
    case EventType::STORY_5:
        switch (plID)
        {
        case PlayerID::Jack:
            DrawGraph(0, 0, mImageP[8], true);
            break;
        case PlayerID::Calendula:
            break;
        case PlayerID::Soy:
            DrawGraph(0 - mOffset.x_, 0 - mOffset.y_, mImageMap, true);
            if (mNum < 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageSF[dir * 4 + ((animcnt_ / 8) % 4)], true);
            }
            if (mNum >= 70)
            {
                DrawGraph(mPos.x_ - mOffset.x_ - 24, mPos.y_ - mOffset.y_ - 24, mImageSF[dir * 4], true);
                DrawGraph(mPos.x_ - mOffset.x_ - 50, mPos.y_ - mOffset.y_ - 100, mImageC[0], true);
            }
            break;
        default:
            break;
        }
        /*DrawString(400, 300, "エピソード5", 0xffffff, true);*/
        break;
    default:
        break;
    }
}
