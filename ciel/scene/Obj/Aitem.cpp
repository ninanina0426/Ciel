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

	//所持管理用
	mTama1 = true;
	mTama2 = true;
	mTama3 = true;
	mTama4 = true;
	mTama5 = true;

	mKinomi1 = true;
	mKinomi2 = true;
	mKinomi3 = true;
	mKinomi4 = true;
	mKinomi5 = true;

	mHaori = true;

	mRantan = true;
	

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

		//キーアイテム
		if (mTama1 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 430, mPos.y_ - 10 - mMapoffset.y_ + 420, mImage[3][mAnimCnt], true);
			}
		}


	}

	if (mapID == MAP_ID::SWEETSOUT)
	{
		
	}

	if (mapID == MAP_ID::FOREST)
	{
		//木の実１
		if (mKinomi1 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 2535, mPos.y_ - 10 - mMapoffset.y_ + 1635, mImage[1][mAnimCnt], true);
			}
		}

		//木の実2
		if (mKinomi2 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 2805, mPos.y_ - 10 - mMapoffset.y_ + 780, mImage[1][mAnimCnt], true);
			}
		}

		//木の実3
		if (mKinomi3 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 155, mPos.y_ - 10 - mMapoffset.y_ + 930, mImage[1][mAnimCnt], true);
			}
		}

		//木の実4
		if (mKinomi4 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 560, mPos.y_ - 10 - mMapoffset.y_ + 160, mImage[1][mAnimCnt], true);
			}
		}

		//木の実5
		if (mKinomi5 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 2300, mPos.y_ - 10 - mMapoffset.y_ + 120, mImage[1][mAnimCnt], true);
			}
		}
	}

	if (mapID == MAP_ID::FORESTIN)
	{
		//キーアイテム
		if (mTama2 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 1430, mPos.y_ - 10 - mMapoffset.y_ + 290, mImage[3][mAnimCnt], true);
			}
		}
	}

	if (mapID == MAP_ID::CAVE)
	{
		
	}

	if (mapID == MAP_ID::DARK)
	{
		//キーアイテム
		if (mTama3 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 1595, mPos.y_ - 10 - mMapoffset.y_ + 1070, mImage[3][mAnimCnt], true);
			}
		}
	}
	
	if (mapID == MAP_ID::WA)
	{
		//キーアイテム
		if (mTama4 == true)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ - 10 - mMapoffset.x_ + 475, mPos.y_ - 10 - mMapoffset.y_ + 510, mImage[3][mAnimCnt], true);
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





