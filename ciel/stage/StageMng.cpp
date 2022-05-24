#include "StageMng.h"
#include "SweetsMap.h"
#include"../scene/Obj/Player.h"
#include"SweetsOutMap.h"
#include"SweetsSchoolMap.h"
#include "ForestMap.h"
#include "WaMap.h"
#include "WaShop.h"
#include "CaveShop.h"
#include "CaveMap.h"
#include "DarkTemple.h"
#include "templeMap.h"
#include "TempleInMap.h"
#include "ForestInMap.h"




bool StageMng::Init()
{
	stage_ = std::make_unique<SweetsMap>();

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();		//それぞれのマップを描画
}

Vector2 StageMng::Update(Vector2 mPlayerset)
{
	// 背景（カメラ）の操作
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mOffset.x_ += 3;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mOffset.x_ -= 3;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mOffset.y_ -= 3;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mOffset.y_ += 6;
	}


	if (mPlayerset.x_ - mOffset.x_ > 520)

	{
		mOffset.x_ += 2;
	}

	if (mPlayerset.x_ - mOffset.x_ < 900)
	{
		mOffset.x_ -= 2;

	}
	//カメラ下移動制限
	if (mPlayerset.y_ - mOffset.y_ < 400)
	{
		mOffset.y_ -= 2;

	}
	if (mPlayerset.y_ - mOffset.y_ > 1400)
	{
		mOffset.y_ += 2;
	}

	if (mOffset.x_ > 530)
	{
		mOffset.x_ = 530;
	}
	if (mOffset.x_ < 0)
	{
		mOffset.x_ = 0;
	}
	if (mOffset.y_ < 0)
	{
		mOffset.y_ = 0;
	}
	if (mOffset.y_ > 1000)
	{
		mOffset.y_ = 1000;
	}


	if (CheckHitKey(KEY_INPUT_A))
	{
		stage_ = std::move(std::make_unique<ForestMap>());
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		stage_ = std::move(std::make_unique<TempleInMap>());
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		stage_ = std::move(std::make_unique<ForestInMap>());
	}

	stage_->Update(mOffset);
	return mOffset;


	

}

bool StageMng::Release(void)
{
	for (int i = 0; i < CHIP_IMAGE_MAX; i++)
	{
		DeleteGraph(mChipImage[i]);
	}
	return true;
}


bool StageMng::cheakMapChip(Vector2 pos)
{
	return stage_->CheckMapChip(pos);
}

void StageMng::GetEvent(Vector2 pos)
{
	//int chipID = lpMapMng.cheakMapChip(pos);
	////階段等でステージ切り替え
	//if (chipID == 15)
	//{
	//	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	//	{
	//		//マップを切り替えることになった
	//		mMapChange = true;
	//		mNextMapID = MAP_ID::SWEETSOUT;
	//		mNextPos = { 1 * 32 + 32 / 2,1 * 32 + 32 / 2, };
	//	}
	//	else if (lpMapMng.mMapID == MAP_ID::SWEETSOUT)
	//	{
	//		mMapChange = true;
	//		mNextMapID = MAP_ID::SWEETS;
	//		mNextPos = { 3 * 32 + 32 / 2,3 * 32 + 32 / 2, };
	//	}

	//}

	/*return chipID;*/
}

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
