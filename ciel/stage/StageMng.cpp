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

	mMapID = MAP_ID::SWEETS;
	
	flg = false;

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();		//それぞれのマップを描画
	
	DrawFormatString(0, 50, GetColor(255, 255, 255), "chipId=%d", mChipId);
	
}



Vector2 StageMng::Update(Vector2 mPlayerset)
{
	mMapOldID = mMapID;

	// 背景（カメラ）の操作
	if (cheakMapChip(mPlayer.GetPos()))
	{
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
			mOffset.y_ += 6;
		}

		//カメラ追従
		if (flg == false)
		{

			if (mPlayerset.x_ - mOffset.x_ > 500)

			{
				mOffset.x_ += 2;
			}

			if (mPlayerset.x_ - mOffset.x_ < 1370)
			{
				mOffset.x_ -= 2;

			}
			//カメラ下移動制限
			if (mPlayerset.y_ - mOffset.y_ < 500)
			{
				mOffset.y_ -= 2;

			}
			if (mPlayerset.y_ - mOffset.y_ > 200)
			{
				mOffset.y_ += 2;
			}
		}
		else
		{

			mOffset = Vector2{ mPlayerset.x_ / 2,mPlayerset.y_ / 2 };
			flg = false;
		}
	}
	//カメラ端
	if (lpMapMng.mMapID == MAP_ID::SWEETS || lpMapMng.mMapID == MAP_ID::SWEETSOUT || lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{
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
	}
	else
	{
		if (mOffset.x_ > 2130)
		{
			mOffset.x_ = 2130;
		}
		if (mOffset.x_ < 0)
		{
			mOffset.x_ = 0;
		}
		if (mOffset.y_ < 0)
		{
			mOffset.y_ = 0;
		}
		if (mOffset.y_ > 2600)
		{
			mOffset.y_ = 2600;
		}

	}


	if (CheckHitKey(KEY_INPUT_W))
	{
		stage_ = std::move(std::make_unique<SweetsMap>());
		mMapID = MAP_ID::SWEETS;
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

	mChipId = stage_->GetMapChip(mPlayerset);

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
	
	//FORESTからFORESTINへ
	if (lpMapMng.mMapID == MAP_ID::FOREST)
	{
		if (chipID == 1407)
		{
			mMapChange = true;
			mNextPos = { 1440,840 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<ForestInMap>());
			mMapID = MAP_ID::FORESTIN;

		}
	}

	//FORESTINからFORESTへ
	if (lpMapMng.mMapID == MAP_ID::FORESTIN)
	{
		if (chipID == 337)
		{
			mMapChange = true;
			mNextPos = { 1455,240 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<ForestMap>());
			mMapID = MAP_ID::FOREST;

		}
	}

	//TEMPLEからTEMPLEINへ
	if (lpMapMng.mMapID == MAP_ID::TEMPLE)
	{
		if (chipID == 470)
		{
			mMapChange = true;
			mNextPos = { 1425,1545 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<TempleInMap>());
			mMapID = MAP_ID::TEMPLEIN;
		}
	}

	//TEMPLEINからTEMPLEへ
	if (lpMapMng.mMapID == MAP_ID::TEMPLEIN)
	{
		if (chipID == 2633 && pos.x_ > 1390 && pos.x_ < 1460)
		{
			mMapChange = true;
			mNextPos = { 1650,590 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<templeMap>());
			mMapID = MAP_ID::TEMPLE;
		}
	}

	//WAからWASHOPへ
	if (lpMapMng.mMapID == MAP_ID::WA)
	{
		if (chipID == 1929)
		{
			mMapChange = true;
			mNextPos = { 1760,1895 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<WaShop>());
			mMapID = MAP_ID::WASHOP;
		}
	}

	//WASHOPからWAへ
	if (lpMapMng.mMapID == MAP_ID::WASHOP)
	{
		if (chipID == 1595)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 2225,2245 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<WaMap>());
			mMapID = MAP_ID::WA;
		}
	}

	//CAVEからCAVESHOPへ
	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		if (chipID == 103)
		{
			mMapChange = true;
			mNextPos = { 1775,1640 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<CaveShop>());
			mMapID = MAP_ID::CAVESHOP;
		}
	}

	//CAVESHOPからCAVEへ
	if (lpMapMng.mMapID == MAP_ID::CAVESHOP)
	{
		if (chipID == 75)
		{
			mMapChange = true;
			mNextPos = { 2190,1000 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<CaveMap>());
			mMapID = MAP_ID::CAVE;
		}
	}

	//CAVEからDARKTEMPLEへ
	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		if (chipID == 105)
		{
			mMapChange = true;
			mNextPos = { 1600,2035 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<DarkTemple>());
			mMapID = MAP_ID::DARK;
		}
	}
	
	//DARKTEMPLEからCAVEへ
	if (lpMapMng.mMapID == MAP_ID::DARK)
	{
		if (chipID == 240 || chipID == 241 || chipID == 242)
		{
			mMapChange = true;
			mNextPos = { 1935,430 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<CaveMap>());
			mMapID = MAP_ID::CAVE;
		}
	}
	
	//SWEETS～
	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	{

		//SWEETSからCANDYへ
		if (chipID == 2654 || chipID == 2655 || chipID == 2656)
		{
			mMapChange = true;
			mNextPos = { 820,300 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}

		//SWEETSからCOOKIEへ
		if (chipID == 2669 || chipID == 2670 || chipID == 2671)
		{
			mMapChange = true;
			mNextPos = { 665,1405 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}

		//SWEETSからGUMMYへ
		if (chipID == 7006 || chipID == 7110 || chipID == 7011)
		{
			mMapChange = true;
			mNextPos = { 1045,1405 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}

		//SWEETSからSWEETSSHOPへ
		if (chipID == 2663 || chipID == 2664 || chipID == 2665)
		{
			mMapChange = true;
			mNextPos = { 1375,825 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}

		//SWEETSからSWEETSSCHOOL1へ
		if (chipID == 2660 || chipID == 2661 || chipID == 2662)
		{
			mMapChange = true;
			mNextPos = { 450,1550 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
			mMapID = MAP_ID::SWEETSSCHOOL;
		}

		//ROOFTOPからSCHOOL3へ
		if (chipID == 2307)
		{
			mMapChange = true;
			mNextPos = { 1505,210 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
			mMapID = MAP_ID::SWEETSSCHOOL;
		}
	}

	//SWEETSSCHOOL～
	if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{

		//SCHOOL1からSCHOOL2へ
		if (chipID == 7005 || chipID == 7006)
		{
			mMapChange = true;
			mNextPos = { 495,740 };
			mDir = DIR_DOWN;
		}

		//SCHOOL2からSCHOOL3へ
		if ((chipID == 7005 || chipID == 7006) && pos.x_ > 1000)
		{
			mMapChange = true;
			mNextPos = { 860,215 };
			mDir = DIR_DOWN;
		}

		//SCHOOL3からROOFTOPへ
		if ((chipID == 7005 || chipID == 7006) && pos.x_ > 1200)
		{
			mMapChange = true;
			mNextPos = { 1225,350 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;
		}

		//SCHOOL3からSCHOOL2へ
		if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031) && pos.x_ > 800)
		{
			mMapChange = true;
			mNextPos = { 1140,730 };
			mDir = DIR_DOWN;
		}

		//SCHOOL2からSCHOOL1へ
		if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031) && pos.x_ > 400 && pos.x_ < 700)
		{
			mMapChange = true;
			mNextPos = { 770,1260 };
			mDir = DIR_DOWN;
		}

		//SCHOOL1からSWEETSへ
		if ((chipID == -1) && pos.y_ > 1580 && pos.x_ > 400 && pos.x_ < 500)
		{
			mMapChange = true;
			mNextPos = { 1290,645 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;
		}
	}

	return mMapChange;
}

DIR StageMng::GetDir(void)
{
	return mDir;
}

Vector2 StageMng::GetPos(void)
{
	return mNextPos;
}

MAP_ID StageMng::GetMapId(void)
{
	/*MAP_ID mChipID;

	mChipID= lpMapMng.mMapID;

	return  mChipID;*/
	return mMapID;
}

MAP_ID StageMng::GetMapIdOld(void)
{
	return mMapOldID;
}



StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}

