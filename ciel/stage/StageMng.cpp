#include "StageMng.h"
#include "SweetsMap.h"
#include"../scene/Obj/Player.h"
#include"SweetsOutMap.h"
#include"SweetsSchoolMap.h"
#include "ForestMap.h"
#include "templeMap.h"
#include "TempleInMap.h"
#include "ForestInMap.h"
//#include "transitionStage/FadeInStage.h"

bool StageMng::Init()
{
	stage_ = std::make_unique<SweetsMap>();

	mMapID = MAP_ID::SWEETS;

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


	if (CheckHitKey(KEY_INPUT_A))
	{
		stage_ = std::move(std::make_unique<ForestMap>());
		mMapID = MAP_ID::FOREST;
		
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		stage_ = std::move(std::make_unique<TempleInMap>());
		mMapID = MAP_ID::TEMPLEIN;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		stage_ = std::move(std::make_unique<SweetsMap>());
		mMapID = MAP_ID::SWEETS;
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

	//if (mMapChange == true)
	//{
	//	if (lpMapMng.mMapID == MAP_ID::FOREST)
	//	{
	//		//マップを切り替えることになった
	//		stage_ = std::move(std::make_unique<ForestInMap>());
	//		mMapID = MAP_ID::FORESTIN;
	//	}
	//}
	
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
	//ステージ切り替え
	if (chipID == 1407)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//マップを切り替えることになった
			
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 1400,400 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			//stage_=std::move(std::make_unique<FadeInStage>(std::move(stage_), std::make_unique<ForestInMap>()));
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
			
		}
	}
	if (chipID == 2669 || chipID == 2670 || chipID == 2671)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 665,1395 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());
		}
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
		}
	}
	if (chipID == 2660 || chipID == 2661 || chipID == 2662)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::SWEETS)
		{
			//マップを切り替えることになった
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 450,1585};
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
		}
	}

	return mMapChange;
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
