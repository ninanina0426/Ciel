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
		mMapID = MAP_ID::WA;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		stage_ = std::move(std::make_unique<ForestMap>());
		mMapID = MAP_ID::FOREST;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		stage_ = std::move(std::make_unique<templeMap>());
		mMapID = MAP_ID::TEMPLE;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		stage_ = std::move(std::make_unique<CaveMap>());
		mMapID = MAP_ID::CAVE;
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

int StageMng::GetMapChipMng(Vector2 pos)
{
	return 0;
}


bool StageMng::cheakMapChip(Vector2 pos)
{
	return stage_->CheckMapChip(pos);
}

bool StageMng::GetEvent(Vector2 pos)
{
	int chipID = stage_->GetMapChip(pos);
	//階段等でステージ切り替え
	
	//FORESTからFORESTINへ
	if (chipID == 1407)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//マップを切り替えることになった
			
			mNextPos = { 1440,840 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			mMapID = MAP_ID::FORESTIN;
			
		}
	}

	//FORESTINからFORESTへ
	if (chipID == 337)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FORESTIN)
		{
			//マップを切り替えることになった

			mNextPos = { 1455,240 };
			stage_ = std::move(std::make_unique<ForestMap>());
			mMapID = MAP_ID::FOREST;

		}
	}

	//TEMPLEからTEMPLEINへ
	if (chipID == 470)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::TEMPLE)
		{
			//マップを切り替えることになった

			mNextPos = { 1425,1545 };
			stage_ = std::move(std::make_unique<TempleInMap>());
			mMapID = MAP_ID::TEMPLEIN;

		}
	}

	//TEMPLEからTEMPLEINへ
	if (chipID == 470)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::TEMPLE)
		{
			//マップを切り替えることになった

			mNextPos = { 1425,1545 };
			stage_ = std::move(std::make_unique<TempleInMap>());
			mMapID = MAP_ID::TEMPLEIN;

		}
	}

	//WAからWASHOPへ
	if (chipID == 1929)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::WA)
		{
			//マップを切り替えることになった

			mNextPos = { 1760,1895 };
			stage_ = std::move(std::make_unique<WaShop>());
			mMapID = MAP_ID::WASHOP;

		}
	}

	//WASHOPからWAへ
	if (chipID == 1595)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::WASHOP)
		{
			//マップを切り替えることになった

			mNextPos = { 2225,2245 };
			stage_ = std::move(std::make_unique<WaMap>());
			mMapID = MAP_ID::WA;

		}
	}

	//CAVEからCAVESHOPへ
	if (chipID == 103)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった

			mNextPos = { 1775,1640 };
			stage_ = std::move(std::make_unique<CaveShop>());
			mMapID = MAP_ID::CAVESHOP;
		}
	}

	//CAVESHOPからCAVEへ
	if (chipID == 75)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::CAVESHOP)
		{
			//マップを切り替えることになった

			mNextPos = { 2190,1030 };
			stage_ = std::move(std::make_unique<CaveMap>());
			mMapID = MAP_ID::CAVE;

		}
	}

	//CAVEからDARKTEMPLEへ
 	if (chipID == 105)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::CAVE)
		{
			//マップを切り替えることになった

			mNextPos = { 1600,2035 };
			stage_ = std::move(std::make_unique<DarkTemple>());
			mMapID = MAP_ID::DARK;
			
		}
	}

	//DARKTEMPLEからCAVEへ
	if (chipID == 240)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::DARK)
		{
			//マップを切り替えることになった

			mNextPos = { 1935,440 };
			stage_ = std::move(std::make_unique<CaveMap>());
			mMapID = MAP_ID::CAVE;

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
