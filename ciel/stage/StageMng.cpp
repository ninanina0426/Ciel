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

	mOffset = (mPlayer.GetPos() / Vector2{4,4}) * Vector2{2,3};
	
	flg = false;

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();		//ÇªÇÍÇºÇÍÇÃÉ}ÉbÉvÇï`âÊ
	
	DrawFormatString(0, 50, GetColor(255, 255, 255), "chipId=%d", mChipId);
	
}



Vector2 StageMng::Update(Vector2 mPlayerset)
{
	mMapOldID = mMapID;

	movePos = mPlayerset - mOffset; //playerÇÃPos

	OldPos = mPlayer.GetPos();

	key_.Update();

	if (OldPos != mPlayerset)
	{
		if (lpMapMng.mMapID == MAP_ID::SWEETS || lpMapMng.mMapID == MAP_ID::SWEETSOUT || lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
		{
			if (movePos.x_ > 200)
			{
				if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
				{
					mOffset.x_ += 4;
				}
			}
			if (movePos.x_ < 880)
			{
				if (key_.getKeyDownHold(KEY_INPUT_LEFT))
				{
					mOffset.x_ -= 4;
				}
			}
			if (movePos.y_ > 100)
			{
				if (key_.getKeyDownHold(KEY_INPUT_DOWN))
				{
					mOffset.y_ += 4;
				}
			}
			if (movePos.y_ < 509)
			{
				if (key_.getKeyDownHold(KEY_INPUT_UP))
				{
					mOffset.y_ -= 4;
				}
			}
		}
		else
		{
			if (movePos.x_ > 200)
			{
				if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
				{
					mOffset.x_ += 4;
				}
			}
			if (movePos.x_ < 500)
			{
				if (key_.getKeyDownHold(KEY_INPUT_LEFT))
				{
					mOffset.x_ -= 4;
				}
			}
			if (movePos.y_ > 100)
			{
				if (key_.getKeyDownHold(KEY_INPUT_DOWN))
				{
					mOffset.y_ += 4;
				}
			}
			if (movePos.y_ < 509)
			{
				if (key_.getKeyDownHold(KEY_INPUT_UP))
				{
					mOffset.y_ -= 4;
				}
			}
		}
	}
	if (lpMapMng.mMapID == MAP_ID::SWEETS || lpMapMng.mMapID == MAP_ID::SWEETSOUT || lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{
		//	//ÉJÉÅÉâí«è]
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 4;
		}
		if (movePos.x_ < 1370)
		{
			mOffset.x_ -= 4;

		}
		//ÉJÉÅÉââ∫à⁄ìÆêßå¿
		if (movePos.y_ < 450)
		{
			mOffset.y_ -= 4;

		}
		if (movePos.y_ > 400)
		{
			mOffset.y_ += 4;
		}
	}
	else
	{
		//ÉJÉÅÉâí«è]
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 4;
		}
		if (movePos.x_ < 800)
		{
			mOffset.x_ -= 4;

		}
		//ÉJÉÅÉââ∫à⁄ìÆêßå¿
		if (movePos.y_ < 400)
		{
			mOffset.y_ -= 4;

		}
		if (movePos.y_ > 380)
		{
			mOffset.y_ += 4;
		}
	}
	//ÉJÉÅÉâí[
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
		stage_ = std::move(std::make_unique<WaMap>());
		mMapID = MAP_ID::WA;
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

	//FORESTÇ©ÇÁFORESTINÇ÷
	if (lpMapMng.mMapID == MAP_ID::FOREST)
	{
		if (chipID == 1407)
		{
			mMapChange = true;
			mNextPos = { 1440,840 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<ForestInMap>());
			mMapID = MAP_ID::FORESTIN;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
	}
	//FORESTINÇ©ÇÁFORESTÇ÷
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

	//TEMPLEÇ©ÇÁTEMPLEINÇ÷
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
	//TEMPLEINÇ©ÇÁTEMPLEÇ÷
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

	//WAÇ©ÇÁWASHOPÇ÷
	if (lpMapMng.mMapID == MAP_ID::WA)
	{
		if (chipID == 1929 || chipID == 1930)
		{
			mMapChange = true;
			mNextPos = { 1760,1895 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<WaShop>());
			mMapID = MAP_ID::WASHOP;
		}
	}

	//WASHOPÇ©ÇÁWAÇ÷
	if (lpMapMng.mMapID == MAP_ID::WASHOP)
	{
		if (chipID == 1595)
		{
			mMapChange = true;
			//É}ÉbÉvÇêÿÇËë÷Ç¶ÇÈÇ±Ç∆Ç…Ç»Ç¡ÇΩ
			mNextPos = { 2225,2245 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<WaMap>());
			mMapID = MAP_ID::WA;
		}
	}

	
	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		//CAVEÇ©ÇÁCAVESHOPÇ÷
		if (chipID == 103)
		{
			mMapChange = true;
			mNextPos = { 1775,1640 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<CaveShop>());
			mMapID = MAP_ID::CAVESHOP;
		}

		//CAVEÇ©ÇÁDARKTEMPLEÇ÷
		if (chipID == 105)
		{
			mMapChange = true;
			mNextPos = { 1600,2035 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<DarkTemple>());
			mMapID = MAP_ID::DARK;

		}
	}

	//CAVESHOPÇ©ÇÁCAVEÇ÷
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
	

	//DARKTEMPLEÇ©ÇÁCAVEÇ÷
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

	//SWEETSÅ`
	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	{
		//SWEETSÇ©ÇÁCANDYÇ÷
		if (chipID == 2654 || chipID == 2655 || chipID == 2656)
		{
			mMapChange = true;
			mNextPos = { 820,300 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
		//SWEETSÇ©ÇÁCOOKIEÇ÷
		if (chipID == 2669 || chipID == 2670 || chipID == 2671)
		{
			mMapChange = true;
			mNextPos = { 665,1405 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}

		//SWEETSÇ©ÇÁGUMMYÇ÷
		if (chipID == 7006 || chipID == 7110 || chipID == 7011)
		{
			mMapChange = true;
			mNextPos = { 1045,1405 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
		//SWEETSÇ©ÇÁSWEETSSHOPÇ÷
		if (chipID == 2663 || chipID == 2664 || chipID == 2665)
		{
			mMapChange = true;
			mNextPos = { 1375,825 };
			mDir = DIR_UP;
			stage_ = std::move(std::make_unique<SweetsOutMap>());
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}

		//SWEETSÇ©ÇÁSWEETSSCHOOL1Ç÷
		if (chipID == 2660 || chipID == 2661 || chipID == 2662)
		{
			mMapChange = true;
			mNextPos = { 450,1565 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_UP;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}

		//ROOFTOPÇ©ÇÁSCHOOL3Ç÷
		if (chipID == 2307)
		{
			mMapChange = true;
			mNextPos = { 1505,210 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());
			mMapID = MAP_ID::SWEETSSCHOOL;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
	}
	//SWEETSSCHOOLÅ`
	if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{

		//äKíi(è„ÇË)
		if ((chipID == 7005 || chipID == 7006) && (800 > pos.x_))
		{
			mMapChange = true;
			mNextPos = { 495,770 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			flg = true;
			mDir = DIR_DOWN;
		}
		else if ((chipID == 7005 || chipID == 7006) && 1200 < pos.x_)
		{
			mMapChange = true;
			mNextPos = { 1230,360 };
			mMapID = MAP_ID::SWEETS;
			flg = true;
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());

		}
		else if ((chipID == 7005 || chipID == 7006))
		{

			mMapChange = true;
			mNextPos = { 860,215 };
			mDir = DIR_DOWN;

		}

		//äKíi(â∫ÇË)
		if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031) && 535 > pos.x_)
		{
			mMapChange = true;
			mNextPos = { 770,1275 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			flg = true;
			mDir = DIR_DOWN;
		}
		else if ((chipID == 7028 || chipID == 7029 || chipID == 7030 || chipID == 7031))
		{
			mMapChange = true;
			mNextPos = { 1135,740 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			flg = true;
			mDir = DIR_DOWN;
		}

		//SCHOOL1Ç©ÇÁSWEETSÇ÷
		if ((chipID == 6924 || chipID == 6925 || chipID == 6926 || chipID == 6927))
		{
			mMapChange = true;
			mNextPos = { 1290,645 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;
			mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
	}

	//SWEETSOUTÅ`
	if (lpMapMng.mMapID == MAP_ID::SWEETSOUT)
	{
		if (chipID == 8335)
		{
			mMapChange = true;
			mNextPos = { 930,1440 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8334)
		{
			mMapChange = true;
			mNextPos = { 1060,1440 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8435)
		{
			mMapChange = true;
			mNextPos = { 1445,1040 };
			mDir = DIR_DOWN;
			stage_ = std::move(std::make_unique<SweetsMap>());
			mMapID = MAP_ID::SWEETS;

		}
		if (chipID == 8434)
		{
			mMapChange = true;
			mNextPos = { 715,485 };
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

