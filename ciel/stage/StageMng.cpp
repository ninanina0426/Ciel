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
#include "SnowMap.h"
#include "SnowCaveMap.h"
#include "SnowShopMap.h"
#include "../scene/Obj/Quest.h"



bool StageMng::Init()
{
	stage_ = std::make_unique<DarkTemple>();
	fadeinFlg_ = false;
	mMapID = MAP_ID::DARK;
	fl_ = false;
	aitem = 0;
	mflg = false;
	mOffset = mPlayer.GetPos()-Vector2{540,0};
	Damage_ = 0;
	follFlag_ = false;
	damCnt_ = 0;
	/*mOffset = {0,0};*/
	

	flyMap[0]=false;
	flyMap[1]=false;
	flyMap[2]=false;
	flyMap[3]=false;
	flyMap[4]=false;

	back = false;
	
	Tama_Use[0] = false;
	Tama_Use[1] = false;
	Tama_Use[2] = false;
	Tama_Use[3] = false;
	Tama_Use[4] = false;
	Tama_Use[5] = false;

	rimFlg_ = false;

    return true;
}

void StageMng::Draw()
{
	
	stage_->DrawOwnScn();		//それぞれのマップを描画


	if (lpMapMng.fadeinFlg_)
	{
		fadein_.DrawOwnScn();
	}

	/*DrawFormatString(0, 50, GetColor(255, 255, 255), "chipId=%d", mChipId);
	DrawFormatString(0, 80, GetColor(255, 0, 0), "offset=(%d,%d)", mOffset.x_,mOffset.y_);*/

	
}



Vector2 StageMng::Update(Vector2 mPlayerset, int ai, bool flg,bool keyf,int tamaFlg)
{
	mMapOldID = mMapID;

	aitem = ai;

	mflg = flg;

	keyFlag_ = keyf;

	movePos = mPlayerset - mOffset; //playerのPos

	OldPos = mPlayer.GetPos();

	key_.Update();
	
	Damage_ = 0;

	Tama_ = tamaFlg;
	
	rimFlg_ = false;

	if (OldPos != mPlayerset)
	{
		if (lpMapMng.mMapID == MAP_ID::SWEETS || lpMapMng.mMapID == MAP_ID::SWEETSOUT || lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
		{
			if (movePos.x_ > 200)
			{
				if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
				{
					mOffset.x_ += 3;
				}
			}
			if (movePos.x_ < 880)
			{
				if (key_.getKeyDownHold(KEY_INPUT_LEFT))
				{
					mOffset.x_ -= 1;
				}
			}
			if (movePos.y_ > 100)
			{
				if (key_.getKeyDownHold(KEY_INPUT_DOWN))
				{
					mOffset.y_ += 3;
				}
			}
			if (movePos.y_ < 509)
			{
				if (key_.getKeyDownHold(KEY_INPUT_UP))
				{
					mOffset.y_ -= 3;
				}
			}
		}
		else
		{
			if (movePos.x_ > 200)
			{
				if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
				{
					mOffset.x_ += 3;
				}
			}
			if (movePos.x_ < 500)
			{
				if (key_.getKeyDownHold(KEY_INPUT_LEFT))
				{
					mOffset.x_ -= 1;
				}
			}
			if (movePos.y_ > 100)
			{
				if (key_.getKeyDownHold(KEY_INPUT_DOWN))
				{
					mOffset.y_ += 3;
				}
			}
			if (movePos.y_ < 509)
			{
				if (key_.getKeyDownHold(KEY_INPUT_UP))
				{
					mOffset.y_ -= 3;
				}
			}
		}
	}
	if (lpMapMng.mMapID == MAP_ID::SWEETS || lpMapMng.mMapID == MAP_ID::SWEETSOUT || lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{
		//	//カメラ追従
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 2;
		}
		if (movePos.x_ < 1370)
		{
			mOffset.x_ -= 2;
		}
		//カメラ下移動制限
		if (movePos.y_ < 450)
		{
			mOffset.y_ -= 2;
		}
		if (movePos.y_ > 400)
		{
			mOffset.y_ += 2;
		}
	}
	else
	{
		//カメラ追従
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 2;
		}
		if (movePos.x_ < 800)
		{
			mOffset.x_ -= 2;

		}
		//カメラ下移動制限
		if (movePos.y_ < 400)
		{
			mOffset.y_ -= 2;

		}
		if (movePos.y_ > 380)
		{
			mOffset.y_ += 2;
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
		if (mOffset.x_ > 2100)
		{
			mOffset.x_ = 2100;
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
	
	if (follFlag_)
	{
		Damage_ ++;
		damCnt_++;
	}
	else
	{
		damCnt_ = 0;
	}
	if (damCnt_>10)
	{
		Damage_ = 0;
		follFlag_ = false;
	}
	stage_->Update(mOffset);

	//フェードイン
	if (fadeinFlg_)
	{
		if (fadein_.UpdataTrangetion())
		{
			fadeinFlg_ = false;
		}
	}

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

	chipID = stage_->GetMapChip(pos);

	mTchipId = stage_->GetTMapChip(pos);


	//FORESTからFORESTINへ
	if (lpMapMng.mMapID == MAP_ID::FOREST)
	{

		if (chipID == 2269)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::TEMPLE;
			stage_ = std::move(std::make_unique<templeMap>());
		}
		if (chipID == 62)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 337,1650 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FORESTIN;
			follFlag_ = true;
			stage_ = std::move(std::make_unique<ForestInMap>());
		}
		if (mTchipId == 843 && pos.y_ > 1969)
		{
			mMapChange = true;
			mNextPos = { 1426,2773 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FORESTIN;
			stage_ = std::move(std::make_unique<ForestInMap>());
			//mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
		if (mTchipId == 843 && pos.y_ < 1720)
		{
			mMapChange = true;
			mNextPos = { 2484,1926 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FORESTIN;
			stage_ = std::move(std::make_unique<ForestInMap>());
			//mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
	}
	//FORESTINからFORESTへ
	if (lpMapMng.mMapID == MAP_ID::FORESTIN)
	{
		if (pos.y_>870&&pos.y_<895&& mTchipId==337)
		{
			mMapChange = true;
			mNextPos = { 1455,240 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::FOREST;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<ForestMap>());
		}
		if (chipID ==2520)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 465,2010 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FOREST;
			stage_ = std::move(std::make_unique<ForestMap>());
		}
		if (chipID == 2521)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 1584,1720 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FOREST;
			stage_ = std::move(std::make_unique<ForestMap>());
		}
		
		if (chipID == 137)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 119,1940 };
			mDir = DIR_RIGHT;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FOREST;
			stage_ = std::move(std::make_unique<ForestMap>());
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
			mMapID = MAP_ID::TEMPLE;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<templeMap>());

		}
	}
	//WAからWASHOPへ
	if (lpMapMng.mMapID == MAP_ID::WA)
	{
		if (chipID == 1929 || chipID == 1930)
		{
			mMapChange = true;
			mNextPos = { 1760,1895 };
			mDir = DIR_UP;
			mMapID = MAP_ID::WASHOP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<WaShop>());

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
			mMapID = MAP_ID::WA;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<WaMap>());

		}
	}	
	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		
		//CAVEからCAVESHOPへ
		if (chipID == 103)
		{
			mMapChange = true;
			mNextPos = { 1775,1640 };
			mDir = DIR_UP;
			mMapID = MAP_ID::CAVESHOP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<CaveShop>());

		}
		
		//CAVEからDARKTEMPLEへ
		if (chipID == 105)
		{
			mMapChange = true;
			mNextPos = { 1600,2035 };
			mDir = DIR_UP;
			mMapID = MAP_ID::DARK;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<DarkTemple>());


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
			mMapID = MAP_ID::CAVE;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<CaveMap>());

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
			mMapID = MAP_ID::CAVE;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<CaveMap>());


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
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}
		//SWEETSからCOOKIEへ
		if (chipID == 2669 || chipID == 2670 || chipID == 2671)
		{
			mMapChange = true;
			mNextPos = { 665,1405 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}

		//SWEETSからGUMMYへ
		if (chipID == 7006 || chipID == 7110 || chipID == 7011)
		{
			mMapChange = true;
			mNextPos = { 1065,1410 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}
		//SWEETSからSWEETSSHOPへ
		if (chipID == 2663 || chipID == 2664 || chipID == 2665)
		{
			mMapChange = true;
			mNextPos = { 1375,825 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}

		//SWEETSからSWEETSSCHOOL1へ
		if (chipID == 2660 || chipID == 2661 || chipID == 2662)
		{
			mMapChange = true;
			mNextPos = { 450,1565 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());

			
		}

		//ROOFTOPからSCHOOL3へ
		if (chipID == 2307)
		{
			mMapChange = true;
			mNextPos = { 1505,210 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::SWEETSSCHOOL;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());

			
		}
		//Sweetsからtempleへ
		if (chipID == 4220|| chipID == 4221 || chipID == 4320 || chipID == 4321)
		{
			rimFlg_ = true;
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::TEMPLE;
			mOffset = mNextPos - Vector2{ 540,300 };
			StopSoundMem(mPlayer.oHandle);
			stage_ = std::move(std::make_unique<templeMap>());

			
		}
	}
	//SWEETSSCHOOL～
	if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{

		//階段(上り)
		if ((chipID == 7005 || chipID == 7006) && (800 > pos.x_))
		{
			mMapChange = true;
			mNextPos = { 495,770 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}
		else if ((chipID == 7005 || chipID == 7006) && 1200 < pos.x_)
		{
			mMapChange = true;
			mNextPos = { 1230,360 };
			mMapID = MAP_ID::SWEETS;
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());

		}
		else if ((chipID == 7005 || chipID == 7006))
		{

			mMapChange = true;
			mNextPos = { 860,240 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}

		//階段(下り)
		if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031) && 535 > pos.x_)
		{
			mMapChange = true;
			mNextPos = { 770,1275 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}
		else if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031))
		{
			mMapChange = true;
			mNextPos = { 1135,758 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}

		//SCHOOL1からSWEETSへ
		if ((chipID == 6924 || chipID == 6925 || chipID == 6926 || chipID == 6927))
		{
			mMapChange = true;
			mNextPos = { 1290,645 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::SWEETS;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());
		}
	}
	//SWEETSOUT～
	if (lpMapMng.mMapID == MAP_ID::SWEETSOUT)
	{
		if (chipID == 8335)
		{
			mMapChange = true;
			mNextPos = { 930,1440 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8334)
		{
			mMapChange = true;
			mNextPos = { 1060,1440 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8435)
		{
			mMapChange = true;
			mNextPos = { 1445,1040 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8434)
		{
			mMapChange = true;
			mNextPos = { 715,485 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
	}


	//雪～
	if (lpMapMng.mMapID == MAP_ID::SNOW)
	{

		if (chipID == 859 && 2400 < pos.x_)
		{
			mMapChange = true;
			mNextPos = { 1985,1830 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowCaveMap>());
			mMapID = MAP_ID::SNOWCAVE;

		}
		else if (chipID == 859)
		{
			mMapChange = true;
			mNextPos =  { 1150, 1900 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowCaveMap>());
			mMapID = MAP_ID::SNOWCAVE;
		}

		//雪から雪ショップへ
		if (mTchipId == 411 && 800 < pos.x_ && 900 > pos.x_)
		{
			mMapChange = true;
			mNextPos = { 1450,1580 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowShopMap>());
			mMapID = MAP_ID::SNOWSHOP;

		}
		if (mTchipId == 412 && 800 < pos.x_ && 900 > pos.x_)
		{
			mMapChange = true;
			mNextPos = { 1450,1580 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowShopMap>());
			mMapID = MAP_ID::SNOWSHOP;

		}

	}

	//雪の洞窟から雪へ
	if (lpMapMng.mMapID == MAP_ID::SNOWCAVE)
	{
		if (mTchipId == 127 && 1900 < pos.x_)
		{
			mMapChange = true;
			mNextPos = { 2450,2740 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowMap>());
			mMapID = MAP_ID::SNOW;

		}
		else if (mTchipId == 127)
		{
			mMapChange = true;
			mNextPos = { 800, 2600 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowMap>());
			mMapID = MAP_ID::SNOW;
		}

	}

	//雪ショップから雪へ
	if (lpMapMng.mMapID == MAP_ID::SNOWSHOP)
	{

		if (chipID == 1740 && 1400 < pos.x_ && 1470 > pos.x_)
		{
			mMapChange = true;
			mNextPos = { 670,890 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SnowMap>());
			mMapID = MAP_ID::SNOW;

		}
	}
	
	return mMapChange;
}

bool StageMng::GetMapChange(Vector2 pos)
{
	////デバッグ用--------------------------------------------------------------------
	//if (CheckHitKey(KEY_INPUT_W))
	//{
	//	mMapChange = true;
	//	mNextPos = { 553,565 };
	//	mDir = DIR_UP;
	//	mMapID = MAP_ID::SWEETS;
	//	mOffset = mNextPos - Vector2{ 540,0 };
	//	stage_ = std::move(std::make_unique<SweetsMap>());
	//}
	//if (CheckHitKey(KEY_INPUT_A))
	//{
	//	mMapChange = true;
	//	mNextPos = { 1420,280 };
	//	mDir = DIR_UP;
	//	mMapID = MAP_ID::FORESTIN;
	//	mOffset = mNextPos - Vector2{ 540,300 };
	//	stage_ = std::move(std::make_unique<ForestInMap>());
	//}
	//if (CheckHitKey(KEY_INPUT_S))
	//{
	//	mMapChange = true;
	//	mNextPos = { 1200,600 };
	//	mDir = DIR_DOWN;
	//	mOffset = mNextPos - Vector2{ 540,300 };
	//	mMapID = MAP_ID::TEMPLEIN;
	//	stage_ = std::move(std::make_unique<TempleInMap>());
	//}
	//if (CheckHitKey(KEY_INPUT_D))
	//{
	//	mMapChange = true;
	//	mNextPos = { 400, 2990 };
	//	mDir = DIR_RIGHT;
	//	mMapID = MAP_ID::SNOW;
	//	mOffset = mNextPos - Vector2{ 2990,120 };
	//	stage_ = std::move(std::make_unique<SnowMap>());
	//}
	//if (CheckHitKey(KEY_INPUT_E))
	//{
	//	mMapChange = true;
	//	mNextPos = { 25, 2400 };
	//	mDir = DIR_RIGHT;
	//	mMapID = MAP_ID::WA;
	//	mOffset = mNextPos - Vector2{ 465,500 };
	//	stage_ = std::move(std::make_unique<WaMap>());
	//}
	//if (CheckHitKey(KEY_INPUT_R))
	//{
	//	mMapChange = true;
	//	mNextPos = { 1585,1070 };
	//	mDir = DIR_UP;
	//	mMapID = MAP_ID::DARK;
	//	mOffset = mNextPos - Vector2{ 540,300 };
	//	stage_ = std::move(std::make_unique<DarkTemple>());
	//}
	
	//---------------------------------------------------------------------------


	if (lpMapMng.mMapID == MAP_ID::TEMPLE)
	{

		//TEMPLEからTEMPLEINへ
		if (lpMapMng.mMapID == MAP_ID::TEMPLE)
		{
			if (pos.y_ < 581 && aitem != 0)//chipID == 470
			{
				if (!opendir_)
				{
					if (key_.getKeyDown(KEY_INPUT_F))
					{
						opendir_ = true;
					}
				}
				else
				{
					if (key_.getKeyDown(KEY_INPUT_F))
					{
						opendir_ = false;
						qeopd_ = true;
					}
				}
				if (opendir_)
				{
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
					DrawBox(0, 250, 1080, 400, 0x000000, true);
					SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
					DrawString(300, 280, "汝　願ひかなふるなら　言ふにしたがいて　くすしきたま　たいまつる\n \n　　　　　　　　こなたかなたに　それ　散りぼふ\n　\n　　　　　　　　　　　汝　たま　刈りつめ　", 0xffffff);


				}
			}
			else
			{
				opendir_ = false;
			}

			if (pos.y_ < 581 && aitem == 0)//chipID == 470
			{
				mMapChange = true;
				mNextPos = { 1425,1545 };
				mDir = DIR_UP;
				mMapID = MAP_ID::TEMPLEIN;
				mOffset = mNextPos - Vector2{ 540,300 };
				stage_ = std::move(std::make_unique<TempleInMap>());

			}
		}
		if (QuestIns.questCmpFlg[0] == QuestState::COMP)
		{
			//スイーツマップへ
			if (pos.x_ >= 1380 && pos.x_ < 1450 &&
				pos.y_ >= 730 && pos.y_ < 760)
			{
				if (Tama_ != 10 && !flyMap[0])
				{
					if (!back)
					{
						auto f = MessageBox(NULL, TEXT("玉の力を使いますか？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
						if (f == IDYES)
						{
							flyMap[0] = true;
							fadeinFlg_ = true;
							fadein_.Setcnt(0);
							Tama_Use[Tama_] = true;
						}
						else if (f == IDNO)
						{
							back = true;
						}
					}

					if (back)
					{
						mMapChange = true;
						mNextPos = { pos.x_,770 };
						back = false;
					}


				}
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (flyMap[0])
					{
						fadeinFlg_ = true;
						fadein_.Setcnt(0);
					}
				}
				if (fadeinFlg_)
				{
					if (fadein_.GetCnt() > 255)
					{
						mMapChange = true;
						mNextPos = { 820,1520 };
						mDir = DIR_UP;
						mMapID = MAP_ID::SWEETS;
						mOffset = mNextPos - Vector2{ 540,0 };
						stage_ = std::move(std::make_unique<SweetsMap>());
					}

				}
			}
			//和マップへ
			if (pos.x_ >= 1440 && pos.x_ < 1480 &&
				pos.y_ >= 835 && pos.y_ < 860)
			{
				if (Tama_ != 10 && !flyMap[1])
				{
					if (!back)
					{
						auto f = MessageBox(NULL, TEXT("玉の力を使いますか？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
						if (f == IDYES)
						{
							flyMap[1] = true;
							fadeinFlg_ = true;
							fadein_.Setcnt(0);
							Tama_Use[Tama_] = true;
						}
						else if (f == IDNO)
						{
							back = true;
						}
					}
				}
				if (back)
				{
					mMapChange = true;
					mNextPos = { pos.x_,870 };
					back = false;
				}
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (flyMap[1])
					{
						fadeinFlg_ = true;
						fadein_.Setcnt(0);
					}

				}
				if (fadeinFlg_)
				{
					if (fadein_.GetCnt() > 255)
					{
						mMapChange = true;
						mNextPos = { 25, 2400 };
						mDir = DIR_RIGHT;
						mMapID = MAP_ID::WA;
						mOffset = mNextPos - Vector2{ 540,300 };
						stage_ = std::move(std::make_unique<WaMap>());
					}
				}
			}
			//森マップへ
			if (pos.x_ >= 1825 && pos.x_ < 1855 &&
				pos.y_ >= 835 && pos.y_ < 860)
			{
				if (Tama_ != 10 && !flyMap[2])
				{
					if (!back && flyMap[0])
					{
						auto f = MessageBox(NULL, TEXT("玉の力を使いますか？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
						if (f == IDYES)
						{
							flyMap[2] = true;
							fadeinFlg_ = true;
							fadein_.Setcnt(0);
							Tama_Use[Tama_] = true;
						}
						else if (f == IDNO)
						{
							back = true;
						}
					}
				}
				if (back)
				{
					mMapChange = true;
					mNextPos = { pos.x_,870 };
					back = false;
				}
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (flyMap[2])
					{
						fadeinFlg_ = true;
						fadein_.Setcnt(0);
					}
				}
				if (fadeinFlg_)
				{
					if (fadein_.GetCnt() > 255)
					{
						mMapChange = true;
						mNextPos = { 1630, 2590 };
						mDir = DIR_UP;
						mMapID = MAP_ID::FOREST;
						mOffset = mNextPos - Vector2{ 540,300 };
						stage_ = std::move(std::make_unique<ForestMap>());
					}
				}
			}
			//洞窟マップへ
			if (pos.x_ >= 1890 && pos.x_ < 1920 &&
				pos.y_ >= 730 && pos.y_ < 760)
			{
				if (Tama_ != 10 && !flyMap[3])
				{
					if (!back && flyMap[2])
					{
						auto f = MessageBox(NULL, TEXT("玉の力を使いますか？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
						if (f == IDYES)
						{
							flyMap[3] = true;
							fadeinFlg_ = true;
							fadein_.Setcnt(0);
							Tama_Use[Tama_] = true;
						}
						else if (f == IDNO)
						{
							back = true;
						}
					}
				}
				if (back)
				{
					mMapChange = true;
					mNextPos = { pos.x_,770 };
					back = false;
				}
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (flyMap[3])
					{
						fadeinFlg_ = true;
						fadein_.Setcnt(0);
					}
				}
				if (fadeinFlg_)
				{
					if (fadein_.GetCnt() > 255)
					{
						mMapChange = true;
						mNextPos = { 1600, 3050 };
						mDir = DIR_UP;
						mMapID = MAP_ID::CAVE;
						mOffset = mNextPos - Vector2{ 540,300 };
						stage_ = std::move(std::make_unique<CaveMap>());
					}
				}
			}
			//雪マップへ
			if (pos.x_ >= 1825 && pos.x_ < 1855 &&
				pos.y_ >= 640 && pos.y_ < 660)
			{
				if (Tama_ != 10 && !flyMap[4])
				{
					if (!back)
					{
						auto f = MessageBox(NULL, TEXT("玉の力を使いますか？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
						if (f == IDYES)
						{
							flyMap[4] = true;
							fadeinFlg_ = true;
							fadein_.Setcnt(0);
							Tama_Use[Tama_] = true;
						}
						else if (f == IDNO)
						{
							back = true;
						}
					}

					if (back)
					{
						mMapChange = true;
						mNextPos = { pos.x_,670 };
						back = false;
					}
				}
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (flyMap[4])
					{
						fadeinFlg_ = true;
						fadein_.Setcnt(0);
					}
				}
				if (fadeinFlg_)
				{
					if (fadein_.GetCnt() > 255)
					{
						mMapChange = true;
						mNextPos = { 400, 2990 };
						mDir = DIR_RIGHT;
						mMapID = MAP_ID::SNOW;
						mOffset = mNextPos - Vector2{ 540,300 };
						stage_ = std::move(std::make_unique<SnowMap>());
					}
				}
			}
		}
	}

	if (lpMapMng.mMapID == MAP_ID::WA)
	{
		if (pos.x_ < 20 && pos.y_ > 2275 && pos.y_ < 2495)
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				fadeinFlg_ = true;
				fadein_.Setcnt(0);
			}
			if (fadeinFlg_)
			{
				if (fadein_.GetCnt() > 255)
				{
					mMapChange = true;
					mNextPos = { 1645,715 };
					mDir = DIR_DOWN;
					mOffset = mNextPos - Vector2{ 540,300 };
					mMapID = MAP_ID::TEMPLE;
					stage_ = std::move(std::make_unique<templeMap>());
					
				}

			}

		}
	}

	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		//ランタンが無くて進めない
		if (mflg == true)
		{
			mMapChange = true;
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::TEMPLE;
			stage_ = std::move(std::make_unique<templeMap>());
		}

		if (pos.y_ > 3160 )
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				fadeinFlg_ = true;
				fadein_.Setcnt(0);
			}
			if (fadeinFlg_)
			{
				if (fadein_.GetCnt() > 255)
				{
					mMapChange = true;
					mNextPos = { 1645,715 };
					mDir = DIR_DOWN;
					mOffset = mNextPos - Vector2{ 540,300 };
					mMapID = MAP_ID::TEMPLE;
					stage_ = std::move(std::make_unique<templeMap>());

				}

			}

		}
	}
	if (lpMapMng.mMapID == MAP_ID::FOREST)
	{
		//
		if (pos.x_ > 1445 && pos.x_ < 1468 && pos.y_ < 230)
		{
			if (!opendir_)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					opendir_ = true;
				}
			}
			else
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					opendir_ = false;
					qeopd_ = true;
				}
			}
			if (opendir_)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
				DrawBox(0, 250, 1080, 400, 0x000000, true);
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
				DrawString(450, 280, "鍵がかかっている。", 0xffffff);


			}
			if (keyFlag_)
			{
				mMapChange = true;
				mNextPos = { 1440,840 };
				mDir = DIR_UP;
				mOffset = mNextPos - Vector2{ 540,300 };
				mMapID = MAP_ID::FORESTIN;
				stage_ = std::move(std::make_unique<ForestInMap>());
			}
		}
		else
		{
			opendir_ = false;
		}


		if (chipID == 2269)
		{
			mMapChange = true;
			//マップを切り替えることになった
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::TEMPLE;
			stage_ = std::move(std::make_unique<templeMap>());
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
	return mMapID;
}

MAP_ID StageMng::GetMapIdOld(void)
{
	return mMapOldID;
}

int StageMng::GetChipId(void)
{
	return mTchipId;
}

int StageMng::GetChipID(void)
{
	return chipID;
}

int StageMng::GetDamage(void)
{
	return Damage_;
}



StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}

