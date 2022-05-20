#include "StageMng.h"
#include "ForestMap.h"
#include "waMap.h"

bool StageMng::Init()
{
	stage_ = std::make_unique<waMap>();
    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();
}

void StageMng::Update(void)
{
	// 背景（カメラ）の操作
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mOffset.x_ += 4;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mOffset.x_ -= 4;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mOffset.y_ -= 4;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mOffset.y_ += 4;
	}

	stage_->Update(mOffset);
	
}

bool StageMng::Release(void)
{
	for (int i = 0; i < CHIP_IMAGE_MAX; i++)
	{
		DeleteGraph(mChipImage[i]);
	}
	return true;
}

int StageMng::GetMapChip(Vector2 pos)
{
    //①マップ座標(pos)をマップ配列のindexに変換す
//	//②マップ配列に入っているマップチップ番号を返す。
    return mMap[pos.y_ / 32][pos.x_ / 32];
}

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
