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

    mPos = { 0,0 };

    mSize = { 1080,609 };

    return true;
}

void Masuku::Update(Vector2 playerPos)
{
   
    mPos = playerPos;

}

void Masuku::Draw(Vector2 offset, int r)
{
    MAP_ID mapID = lpMapMng.GetMapId();

    if (mapID == MAP_ID::CAVE)
    {
        if (r == 1)
        {
            DrawGraph(mPos.x_ - offset.x_ - mSize.x_, mPos.y_ - offset.y_ - mSize.y_, mImage, true);
        }
        else if (r == 0)
        {
            DrawGraph(mPos.x_ - offset.x_ - mSize.x_, mPos.y_ - offset.y_ - mSize.y_, mImage2, true);
        }
        
    }

}

bool Masuku::Release(void)
{
    return false;
}
