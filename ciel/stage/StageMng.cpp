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



	//カメラ追従
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

	//カメラ端
	if (mOffset.x_ > 2000)
	{
		mOffset.x_ = 2000;
	}
	if (mOffset.x_ < 0)
	{
		mOffset.x_ = 0;
	}
	if (mOffset.y_ < 0)
	{
		mOffset.y_ = 0;
	}
	if (mOffset.y_ > 2000)
	{
		mOffset.y_ = 2000;
	}


	if (CheckHitKey(KEY_INPUT_W))
	{
		stage_ = std::move(std::make_unique<WaMap>());
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
		stage_ = std::move(std::make_unique<CaveMap>());
	}

	stage_->Update(mOffset);

	
	
	/*if (mMapChange == true)
	{
		mMapChange = false;
	}*/
	//	/*stage_->GetSceneID(mNextMapID);*/
	//	mPlayer.SetPos(mNextPos);
	//}

	/*mPlayer.Update();*/

	if (mMapChange == true)
	{
		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//マップを切り替えることになった
			stage_ = std::move(std::make_unique<ForestInMap>());
		}
	}

	if (mMapChange == true)
	{
		if (lpMapMng.mMapID == MAP_ID::WA)
		{
			//マップを切り替えることになった
			stage_ = std::move(std::make_unique<WaShop>());
		}
	}

	if (mMapChange == true)
	{
		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった
			stage_ = std::move(std::make_unique<CaveShop>());
		}
	}

	if (mMapChange == true)
	{
		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった
			stage_ = std::move(std::make_unique<DarkTemple>());
		}
	}
	
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

bool StageMng::GetEvent(Vector2 pos)
{
	int chipID = stage_->GetMapChip(pos);
	//階段等でステージ切り替え
	if (chipID == 1407)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//マップを切り替えることになった
			
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 1400,400 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			
		}
	}

	if (chipID == 1929)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::WA)
		{
			//マップを切り替えることになった

			//mNextMapID = MAP_ID::WASHOP;
			mNextPos = { 500,500 };
			stage_ = std::move(std::make_unique<WaShop>());

		}
	}

	if (chipID == 103)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった

			mNextPos = { 500,500 };
			stage_ = std::move(std::make_unique<CaveShop>());

		}
	}

	if (chipID == 105)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった

			mNextPos = { 500,500 };
			stage_ = std::move(std::make_unique<DarkTemple>());
			return  
		}
	}


	return mMapChange;
}

Vector2 StageMng::GetPos(void)
{
	return mNextPos;
}

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
