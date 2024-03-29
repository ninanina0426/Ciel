
#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "Love.h"



Love::Love()
{
    init();
}

Love::~Love()
{
}

bool Love::init()
{

    //グラフィックの読み込み
    if (LoadDivGraph("image/npc/例.png", 16, 4, 4, 32, 48, &mImage[0]) == -1)
    {
        return false;
    };

    mImageChat[0] = LoadGraph("image/talk/l11.png");
    mImageChat[1] = LoadGraph("image/talk/l12.png");
    mImageChat[2] = LoadGraph("image/talk/l13.png");
    mImageChat[3] = LoadGraph("image/talk/l14.png");
    mImageChat[4] = LoadGraph("image/talk/l15.png");
    mImageChat[5] = LoadGraph("image/talk/l16.png");
    mImageChat[6] = LoadGraph("image/talk/l17.png");
    mImageChat[7] = LoadGraph("image/talk/l18.png");
    mImageChat[8] = LoadGraph("image/talk/l19.png");
    mImageChat[9] = LoadGraph("image/talk/l10.png");

    mImageChat[30] = LoadGraph("image/talk/l1.png");
    mImageChat[29] = LoadGraph("image/talk/l2.png");
    mImageChat[28] = LoadGraph("image/talk/l3.png");
    mImageChat[27] = LoadGraph("image/talk/c1.png");
    mImageChat[26] = LoadGraph("image/talk/c1.png");
    mImageChat[25] = LoadGraph("image/talk/c1.png");
    mImageChat[24] = LoadGraph("image/talk/c1.png");
    mImageChat[23] = LoadGraph("image/talk/c1.png");
    mImageChat[22] = LoadGraph("image/talk/c1.png");
    mImageChat[20] = LoadGraph("image/talk/l4.png");
    mImageChat[19] = LoadGraph("image/talk/l5.png");
    mImageChat[18] = LoadGraph("image/talk/l5.png");
    mImageChat[17] = LoadGraph("image/talk/l5.png");

    mPos = { 0,0 };
    mSize = { 32,48 };
    mSizeOffset.x_ = mSize.x_ / 2;
    mSizeOffset.y_ = mSize.y_ / 2;
    mMoveDir = DIR_UP;
    mAnmCnt = 0;

    FR = 0;

    numC = 0;

    eFlg = false;

    moveFlg = false;
    hitflg = false;

    //プレゼント
    lApple=0;
    lKinominoKusiyaki=0;
    lFruitDrink=0;
    lRice=0;
    lDango=0;
    lTea=0;
    lFish=0;

    mNum[0] = { 0,0 };
    mNum[1] = { 754,2030 };

    return true;
}

Vector2 Love::Update(Vector2 playerPos, Vector2 playerSize, DIR playerDir, int num)
{
    keyDir = DIR_MAX;		//キー入力の方向

    key_.Update();

    mapID = lpMapMng.GetMapId();

    chiID = lpMapMng.GetChipID();

    HaveNum = num;

    
    if (mapID == MAP_ID::WA)
    {
        if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[1].y_ + 32 / 2) &&
            (mPos.y_ + mNum[1].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
            (playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[1].x_ + 32 / 2) &&
            (mPos.x_ + mNum[1].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
        {
            if (numC == 0)
            {
                if (key_.getKeyDown(KEY_INPUT_F))
                {
                    moveFlg = true;
                    numC = 1;

                    if (HaveNum == 0)
                    {
                        chat = GetRand(10);
                    }

                    if (HaveNum == 1)
                    {
                        lApple -= 1;
                        FR += 10;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 2)
                    {
                        lRice -= 1;
                        FR += 10;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 3)
                    {
                        lKinominoKusiyaki -= 1;
                        FR += 15;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 4)
                    {
                        lDango -= 1;
                        FR += 15;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 5)
                    {
                        lFruitDrink -= 1;
                        FR += 20;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 6)
                    {
                        lTea -= 1;
                        FR += 10;
                        HaveNum = 20;
                        chat = 17;
                    }
                    else if (HaveNum == 0)
                    {
                        FR += 5;
                    }
                }

                hitflg = true;
            }
            else if (numC == 27)
            {
                message_box();
            }
            else if (numC == 18)
            {
                eFlg = true;
            }
            else if (numC != 0)
            {
                if (key_.getKeyDown(KEY_INPUT_F))
                {
                    numC -= 1;
                    chat -= 1;
                }
            }

        }
        else
        {
            numC = 0;
            hitflg = false;
        }

        if (HaveNum == 20)
        {
            HaveNum = 100;
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {
        }
        else
        {
            moveFlg = false;
        }

        if (moveFlg == true)
        {
            if (playerDir == DIR_DOWN)
            {
                mMoveDir = DIR_LEFT;
            }
            if (playerDir == DIR_UP)
            {
                mMoveDir = DIR_UP;
            }
            if (playerDir == DIR_LEFT)
            {
                mMoveDir = DIR_DOWN;
            }
            if (playerDir == DIR_RIGHT)
            {
                mMoveDir = DIR_RIGHT;
            }
        }

        //好感度max
        if (FR == 200)
        {
            numC = 30;
            FR = 205;
            chat = 30;
        }
    }
   


    mAnmCnt++;
    return Vector2();
}

void Love::Draw(Vector2 offset)
{
    if (mapID == MAP_ID::WA)
    {
        if (numC!=0)
        {
            DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + mNum[1].x_-50, mPos.y_ - offset.y_ - mSizeOffset.y_ + mNum[1].y_-100, mImageChat[chat], true);
        }
        DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + mNum[1].x_, mPos.y_ - offset.y_ - mSizeOffset.y_ + mNum[1].y_, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
    }

    //DrawFormatString(0, 300, 0xff0000, "好感度%d", FR);
}

bool Love::Release(void)
{
    return false;
}

void Love::SetDIR(DIR dir)
{
}

Vector2 Love::GetPos(void)
{
    return mPos;
}

bool Love::Hit()
{
    return hitflg;
}

bool Love::MoveFR()
{
    return moveFlg;
}

int Love::NumH()
{
    return HaveNum;
}

int Love::Apple()
{
    return lApple;
}

int Love::KinominoKusiyaki()
{
    return lKinominoKusiyaki;
}

int Love::FruitDrink()
{
    return lFruitDrink;
}

int Love::Rice()
{
    return lRice;
}

int Love::Dango()
{
    return lDango;
}

int Love::Tea()
{
    return lTea;
}

int Love::Fish()
{
    return lFish;
}

void Love::message_box()
{
    int flag;
    flag = MessageBox(
        NULL,
        TEXT("受け入れますか？（endに移行します）"),
        TEXT("選択"),
        MB_YESNO | MB_ICONQUESTION);
    if (flag == IDYES)
    {
        numC = 20;
        chat = 20;
    }
}


