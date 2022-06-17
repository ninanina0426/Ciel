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
	stage_ = std::make_unique<templeMap>();
	fadeinFlg_ = false;
	mMapID = MAP_ID::TEMPLE;
	fl_ = false;
	mOffset = mPlayer.GetPos()-Vector2{540,0};
	
    return true;
}

void StageMng::Draw()
{
	
	stage_->DrawOwnScn();		//���ꂼ��̃}�b�v��`��


	if (lpMapMng.fadeinFlg_)
	{
		fadein_.DrawOwnScn();
	}

	/*DrawFormatString(0, 50, GetColor(255, 255, 255), "chipId=%d", mChipId);
	DrawFormatString(0, 80, GetColor(255, 0, 0), "offset=(%d,%d)", mOffset.x_,mOffset.y_);*/

	
}



Vector2 StageMng::Update(Vector2 mPlayerset)
{
	mMapOldID = mMapID;

	movePos = mPlayerset - mOffset; //player��Pos

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
		//	//�J�����Ǐ]
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 2;
		}
		if (movePos.x_ < 1370)
		{
			mOffset.x_ -= 2;
		}
		//�J�������ړ�����
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
		//�J�����Ǐ]
		if (movePos.x_ > 500)
		{
			mOffset.x_ += 2;
		}
		if (movePos.x_ < 800)
		{
			mOffset.x_ -= 2;

		}
		//�J�������ړ�����
		if (movePos.y_ < 400)
		{
			mOffset.y_ -= 2;

		}
		if (movePos.y_ > 380)
		{
			mOffset.y_ += 2;
		}
	}
	//�J�����[
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

	//�t�F�[�h�C��
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


	//FOREST����FORESTIN��
	if (lpMapMng.mMapID == MAP_ID::FOREST)
	{
		if (chipID == 1407)
		{
			mMapChange = true;
			mNextPos = { 1440,840 };
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::FORESTIN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			//mOffset = mNextPos / (Vector2{ 4,4 }) * Vector2 { 2, 3 };
		}
		if (chipID == 2269)
		{
			mMapChange = true;
			//�}�b�v��؂�ւ��邱�ƂɂȂ���
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
			mMapID = MAP_ID::TEMPLE;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<templeMap>());
		}
	}
	//FORESTIN����FOREST��
	if (lpMapMng.mMapID == MAP_ID::FORESTIN)
	{
		if (chipID == 337)
		{
			mMapChange = true;
			mNextPos = { 1455,240 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::FOREST;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<ForestMap>());


		}
	}
	//TEMPLE����TEMPLEIN��
	if (lpMapMng.mMapID == MAP_ID::TEMPLE)
	{
		if (chipID == 470)
		{
			mMapChange = true;
			mNextPos = { 1425,1545 };
			mDir = DIR_UP;
			mMapID = MAP_ID::TEMPLEIN;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<TempleInMap>());

		}
	}
	//TEMPLEIN����TEMPLE��
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
	//WA����WASHOP��
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
	//WASHOP����WA��
	if (lpMapMng.mMapID == MAP_ID::WASHOP)
	{
		if (chipID == 1595)
		{
			mMapChange = true;
			//�}�b�v��؂�ւ��邱�ƂɂȂ���
			mNextPos = { 2225,2245 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::WA;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<WaMap>());

		}
	}	
	if (lpMapMng.mMapID == MAP_ID::CAVE)
	{
		//CAVE����CAVESHOP��
		if (chipID == 103)
		{
			mMapChange = true;
			mNextPos = { 1775,1640 };
			mDir = DIR_UP;
			mMapID = MAP_ID::CAVESHOP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<CaveShop>());

		}

		//CAVE����DARKTEMPLE��
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
	//CAVESHOP����CAVE��
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
	//DARKTEMPLE����CAVE��
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
	//SWEETS�`
	if (lpMapMng.mMapID == MAP_ID::SWEETS)
	{
		//SWEETS����CANDY��
		if (chipID == 2654 || chipID == 2655 || chipID == 2656)
		{
			mMapChange = true;
			mNextPos = { 820,300 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}
		//SWEETS����COOKIE��
		if (chipID == 2669 || chipID == 2670 || chipID == 2671)
		{
			mMapChange = true;
			mNextPos = { 665,1405 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}

		//SWEETS����GUMMY��
		if (chipID == 7006 || chipID == 7110 || chipID == 7011)
		{
			mMapChange = true;
			mNextPos = { 1065,1410 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}
		//SWEETS����SWEETSSHOP��
		if (chipID == 2663 || chipID == 2664 || chipID == 2665)
		{
			mMapChange = true;
			mNextPos = { 1375,825 };
			mDir = DIR_UP;
			mMapID = MAP_ID::SWEETSOUT;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsOutMap>());

			
		}

		//SWEETS����SWEETSSCHOOL1��
		if (chipID == 2660 || chipID == 2661 || chipID == 2662)
		{
			mMapChange = true;
			mNextPos = { 450,1565 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_UP;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());

			
		}

		//ROOFTOP����SCHOOL3��
		if (chipID == 2307)
		{
			mMapChange = true;
			mNextPos = { 1505,210 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::SWEETSSCHOOL;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<SweetsSchoolMap>());

			
		}
		//Sweets����temple��
		if (chipID == 4220|| chipID == 4221 || chipID == 4320 || chipID == 4321)
		{
			mMapChange = true;
			//�}�b�v��؂�ւ��邱�ƂɂȂ���
			mNextPos = { 1645,715 };
			mDir = DIR_DOWN;
			mMapID = MAP_ID::TEMPLE;
			mOffset = mNextPos - Vector2{ 540,300 };
			stage_ = std::move(std::make_unique<templeMap>());

			
		}
	}
	//SWEETSSCHOOL�`
	if (lpMapMng.mMapID == MAP_ID::SWEETSSCHOOL)
	{

		//�K�i(���)
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
			mNextPos = { 860,215 };
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}

		//�K�i(����)
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
			mNextPos = { 1135,740 };
			mMapID = MAP_ID::SWEETSSCHOOL;
			mDir = DIR_DOWN;
			mOffset = mNextPos - Vector2{ 540,300 };
		}

		//SCHOOL1����SWEETS��
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
	//SWEETSOUT�`
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

	return mMapChange;
}

bool StageMng::GetMapChange(Vector2 pos)
{
	if (lpMapMng.mMapID == MAP_ID::TEMPLE)
	{
		//�X�C�[�c�}�b�v��
		if (pos.x_ >= 1380 && pos.x_ < 1450 &&
			pos.y_ >= 730 && pos.y_ < 760)
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
					mNextPos = { 820,1520 };
					mDir = DIR_UP;
					mMapID = MAP_ID::SWEETS;
					mOffset = mNextPos - Vector2{ 540,0 };
					stage_ = std::move(std::make_unique<SweetsMap>());
				}

			}
		}
		//�a�}�b�v��
		if (pos.x_ >= 1440 && pos.x_ < 1480 &&
			pos.y_ >= 835 && pos.y_ < 860)
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
					mNextPos = { 25, 2400 };
					mDir = DIR_RIGHT;
					mMapID = MAP_ID::WA;
					mOffset = mNextPos - Vector2{ 540,300 };
					stage_ = std::move(std::make_unique<WaMap>());
				}
			}
		}
		//�X�}�b�v��
		if (pos.x_ >= 1825 && pos.x_ < 1855 &&
			pos.y_ >= 835 && pos.y_ < 860)
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
					mNextPos = { 1630, 2590 };
					mDir = DIR_UP;
					mMapID = MAP_ID::FOREST;
					mOffset = mNextPos - Vector2{ 540,300 };
					stage_ = std::move(std::make_unique<ForestMap>());
				}
			}
		}
		//���A�}�b�v��
		if (pos.x_ >= 1890 && pos.x_ < 1920 &&
			pos.y_ >= 730 && pos.y_ < 760)
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
					mNextPos = { 1600, 3050 };
					mDir = DIR_UP;
					mMapID = MAP_ID::CAVE;
					mOffset = mNextPos - Vector2{ 540,300 };
					stage_ = std::move(std::make_unique<CaveMap>());
				}
			}
		}
		//��}�b�v��
		if (pos.x_ >= 1825 && pos.x_ < 1855 &&
			pos.y_ >= 640 && pos.y_ < 660)
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
					mNextPos = { 1600, 3050 };
					mDir = DIR_UP;
					mMapID = MAP_ID::CAVE;
					mOffset = mNextPos - Vector2{ 540,300 };
					stage_ = std::move(std::make_unique<CaveMap>());
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

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}

