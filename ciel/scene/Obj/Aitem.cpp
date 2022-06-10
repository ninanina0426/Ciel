#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "Aitem.h"


Aitem::Aitem()
{
	init();
}

Aitem::~Aitem()
{
}

bool Aitem::init()
{
	
	ItemAnimcount = 0;
	mPos.x_ = 0;
	mPos.y_ = 0;
	mSize.x_ = 32;
	mSize.y_ = 32;

	//èäéùä«óùóp
	mAitem = 10;

	mNum[0] ={0,0}; //posx
	mNum[1] = { 1355,675 }; //posx
	mNum[2] = { 785,1335 }; //posx
	mNum[3] = { 625,1275 }; //posx

	i = 0;

	if (LoadDivGraph("image/item.png", 12, 3, 4, mSize.x_, mSize.y_, &mImage[0][0]) == -1)
	{
		return false;
	}
	return true;
}

Vector2 Aitem::Update(Vector2 playerPos, Vector2 playerSize)
{
	MAP_ID mapID = lpMapMng.GetMapId();

	Vector2 pPos = playerPos;
	Vector2 pSize = playerSize;

	key_.Update();

	switch (mapID)
	{
	case MAP_ID::FOREST:
		
		break;
	case MAP_ID::WA:
		
		break;
	case MAP_ID::WASHOP:
		
		break;
	case MAP_ID::CAVE:
		
		break;
	case MAP_ID::CAVESHOP:
		
		break;
	case MAP_ID::DARK:
		
		break;
	case MAP_ID::FORESTIN:
		
		break;
	case MAP_ID::TEMPLE:
		
		break;
	case MAP_ID::TEMPLEIN:
		
		break;
	case MAP_ID::SWEETS:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[2].y_ + 32 / 2) &&
			(mPos.y_ + mNum[2].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[2].x_ + 32 / 2) &&
			(mPos.x_ + mNum[2].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mAitem != 0) && (mAitem <= 10))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mAitem -= 1;
					mNum[2] = mNum[0];
					i = 2;
				}

			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[3].y_ + 32 / 2) &&
			(mPos.y_ + mNum[3].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[3].x_ + 32 / 2) &&
			(mPos.x_ + mNum[3].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mAitem != 0) && (mAitem <= 10))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mAitem -= 1;
					mNum[3] = mNum[0];
					i = 3;
				}

			}
		}
		break;
	case MAP_ID::SWEETSOUT:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[1].y_ + 64 / 2) &&
			(mPos.y_ + mNum[1].y_ - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[1].x_ + 32 / 2) &&
			(mPos.x_ + mNum[1].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mAitem != 0) && (mAitem <= 10))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mAitem -= 1;
					mNum[1] = mNum[0];
					i = 1;
				}

			}
		}
		break;
	case MAP_ID::SWEETSSCHOOL:
		break;
	case MAP_ID::TRANGETIONS:
		
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}


	ItemAnimcount++;

	return mPos;
}

void Aitem::Draw(Vector2 mMapoffset)
{
	MAP_ID mapID = lpMapMng.GetMapId();

	switch (mapID)
	{
	case MAP_ID::FOREST:
	
		break;
	case MAP_ID::WA:
		
		break;
	case MAP_ID::WASHOP:
		
		break;
	case MAP_ID::CAVE:
		
		break;
	case MAP_ID::CAVESHOP:
		
		break;
	case MAP_ID::DARK:
		
		break;
	case MAP_ID::FORESTIN:
		
		break;
	case MAP_ID::TEMPLE:
		
		break;
	case MAP_ID::TEMPLEIN:
		
		break;
	case MAP_ID::SWEETS:
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[2].x_ - mMapoffset.x_, mPos.y_ + mNum[2].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[3].x_ - mMapoffset.x_, mPos.y_ + mNum[3].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::SWEETSOUT:
		
		break;
	case MAP_ID::SWEETSSCHOOL:
		
		break;
	case MAP_ID::TRANGETIONS:

		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}


	DrawFormatString(0,200, GetColor(255, 255, 255), "num=%d", mAitem);
	
}

bool Aitem::Release(void)
{
	return false;
}

Vector2 Aitem::GetSize(void)
{
	return mSize;
}

Vector2 Aitem::GetPos(void)
{
	return mPos;
}

int Aitem::Num()
{
	return i;
}

bool Aitem::Getflg()
{

	return true;
}





