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

	if (chipID == 1407)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//マップを切り替えることになった
			mNextPos = { 1440,840 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			//切り替えを単体として考える。時間で切り替え？？？？？
			mNextPos = { 1400,400 };
			mMapID = MAP_ID::FORESTIN;
			//stage_ = std::move(std::make_unique<FadeInStage>(std::move(stage_), std::make_unique<ForestInMap>()));
		}
	}
	//sweetw
	if (chipID == 2654 || chipID == 2655 || chipID == 2656)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 820,305 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
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
	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	{
		//マップを切り替えることになった
		/*mNextMapID = MAP_ID::FORESTIN;*/
		mNextPos = { 665,1395 };
		stage_ = std::move(std::make_unique<SweetsOutMap>());
		mMapID = MAP_ID::SWEETSOUT;
	}
	
	if (chipID == 7006 || chipID == 7110 || chipID == 7011)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 1045,1405 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}
	}
	if (chipID == 2663 || chipID == 2664 || chipID == 2665)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 1375,825 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
		}
	}
	if (chipID == 2660 || chipID == 2661 || chipID == 2662)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 450,1585 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
			mMapID = MAP_ID::SWEETSSCHOOL;
		}
	}
	if (chipID == 7005 || chipID == 7006)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 495,740 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			flg = true;
			mDir = DIR_LEFT;
		}
	}
	if ((chipID == 7005 || chipID == 7006) && pos.x_ > 965)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
		{
			mNextPos = { 860,215 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			flg = true;
			mDir = DIR_DOWN;
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
	MAP_ID mChipID;

	mChipID= lpMapMng.mMapID;

	return  mChipID;
}



StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}

