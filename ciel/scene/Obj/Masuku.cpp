#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "Masuku.h"

Masuku::Masuku()
{
    init();
}

Masuku::~Masuku()
{
}

bool Masuku::init(void)
{
    mImage = LoadGraph("image/マスク/85.png");
    mImage2 = LoadGraph("image/マスク/0.png");

    mImageChat= LoadGraph("image/マスク/10.png");

    mPos = { 0,0 };

    mSize = { 1080,609 };

    mFlg = false;

    i = 0;

    mAnmMum = 0;

    Rantan = 0;

    return true;
}

void Masuku::Update(Vector2 playerPos, int r)
{
    mPos = playerPos;

    Rantan = r;

    key_.Update();

    MAP_ID mapID = lpMapMng.GetMapId();

    if (mapID == MAP_ID::CAVE)
    {
        if ((Rantan == 0))
        {
            if (mAnmMum == 50)
            {
                i = 1;
            }
            if (mFlg == false)
            {
                if (key_.getKeyDown(KEY_INPUT_F))
                {
                    i += 1;
                }
            }

            if ((i == 2))
            {
                mFlg = true;
            }

        }
  
        mAnmMum++;
    }

    if (Rantan == 1)
    {
        mFlg = false;
    }
    
   
}

void Masuku::Draw(Vector2 offset)
{
    MAP_ID mapID = lpMapMng.GetMapId();

    if (mapID == MAP_ID::CAVE)
    {
        if (Rantan == 1)
        {
            DrawGraph(mPos.x_ - offset.x_ - mSize.x_, mPos.y_ - offset.y_ - mSize.y_, mImage, true);
        }
        else if (Rantan == 0)
        {
            DrawGraph(mPos.x_ - offset.x_ - mSize.x_, mPos.y_ - offset.y_ - mSize.y_, mImage2, true);
            if (i == 1)
            {
                DrawGraph(mPos.x_ - offset.x_ - 540, mPos.y_ - offset.y_ - 400, mImageChat, true);
            }
        }
        
    }

}

bool Masuku::Release(void)
{
    return false;
}

bool Masuku::Flg()
{
    return mFlg;
}
