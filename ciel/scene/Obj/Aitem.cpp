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
	//parent->Draw();		//ゲームシーンのドローってこと

	ItemAnimcount = 0;

	mPos.x_ = 0;
	mPos.y_ = 0;
	mSize.x_ = 32;
	mSize.y_ = 32;

	mKami1 = true;
	mKami2 = true;
	mKami3 = true;
	mKami4 = true;
	mKami5 = true;

	mTma = true;
	mMasinngan = true;
	mHoutai = true;
	mHeal = true;
	mKey = true;
	mbook = true;
	mMagazinn = true;

	if (LoadDivGraph("image/item.png", 12, 3, 4, mSize.x_, mSize.y_, &mImage[0][0]) == -1)
	{
		return false;
	}
	return true;
}

Vector2 Aitem::Update(void)
{
	ItemAnimcount++;

	return mPos;
}

void Aitem::Draw(Vector2 mMapoffset)
{
	MAP_ID mapID = lpMapMng.GetMapId();

	if (mapID == MAP_ID::SWEETS)
	{
		if (mKami1 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mKami2 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 50, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
	}
	if (mapID == MAP_ID::SWEETSOUT)
	{
		if (mKami3 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 100, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mKami4 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 150, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
	}
	if (mapID == MAP_ID::FOREST)
	{
		if (mKami5 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 200, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mTma == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 250, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
	}
	if (mapID == MAP_ID::CAVE)
	{
		if (mMasinngan == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 300, mPos.y_ - 10 - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mHoutai == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_, mPos.y_ - 10 - mMapoffset.y_ + 50, mImage[0][mAnimCnt], true);
			}
		}
		if (mHeal == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 50, mPos.y_ - 10 - mMapoffset.y_ + 50, mImage[0][mAnimCnt], true);
			}
		}
		if (mKey == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 100, mPos.y_ - 10 - mMapoffset.y_ + 50, mImage[0][mAnimCnt], true);
			}
		}
		if (mbook == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 150, mPos.y_ - 10 - mMapoffset.y_ + 50, mImage[0][mAnimCnt], true);
			}
		}
		if (mMagazinn == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 200, mPos.y_ - 10 - mMapoffset.y_ + 50, mImage[0][mAnimCnt], true);
			}
		}
	}
	
	
	
	
	
}

bool Aitem::Release(void)
{
	return false;
}

Vector2 Aitem::GetSize(void)
{
	return mSize;
}





