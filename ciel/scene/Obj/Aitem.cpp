#include <DxLib.h>
#include"../../stage/StageMng.h"
#include"shop.h"
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

	

	//�����Ǘ��p

	mTama1 = false;
	mTama2 = false;
	mTama3 = false;
	mTama4 = false;
	mTama5 = false;

	mKinomi1 = false;
	mKinomi2 = false;
	mKinomi3 = false;
	mKinomi4 = false;
	mKinomi5 = false;

	mHaori = false;

	mRantan = false;

	mTama = 5;
	mKinomi = 5;
	
	mAitem = 10;


	mNumKinomi = 0;
	mApple = 0;
	mKinominoKusiyaki = 0;
	mFruitDrink = 0;
	mFishingRodS = 0;
	mRagBag = 0;
	mPickaxe = 0;

	mNum[0] ={0,0}; //posx

	mNum[1] = { 1355,675 }; //posx
	mNum[2] = { 785,1335 }; //posx
	mNum[3] = { 625,1275 }; //posx

	//��
	mNum[4] = { 1420,280 };
	mNum[5] = { 420,420 };
	mNum[6] = { 1585,1070 };
	mNum[7] = { 465,500 };
	mNum[8] = {};

	//�؂̎�
	mNum[9] = { 2536,1635 };
	mNum[10] = { 2805,780 };
	mNum[11] = { 155,930 };
	mNum[12] = { 560,160 };
	mNum[13] = { 2300,120 };

	i = 0;

	mShop = new shop();


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
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[9].y_ + 32 / 2) &&
			(mPos.y_ + mNum[9].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[9].x_ + 32 / 2) &&
			(mPos.x_ + mNum[9].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mKinomi != 0) && (mKinomi <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mKinomi -= 1;
					mNum[9] = mNum[0];
					mKinomi1 = true;

				}

			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[10].y_ + 32 / 2) &&
			(mPos.y_ + mNum[10].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[10].x_ + 32 / 2) &&
			(mPos.x_ + mNum[10].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mKinomi != 0) && (mKinomi <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mKinomi -= 1;
					mNum[10] = mNum[0];
					mKinomi2 = true;

				}

			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[11].y_ + 32 / 2) &&
			(mPos.y_ + mNum[11].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[11].x_ + 32 / 2) &&
			(mPos.x_ + mNum[11].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mKinomi != 0) && (mKinomi <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mKinomi -= 1;
					mNum[11] = mNum[0];
					mKinomi3 = true;

				}

			}
		}

		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[12].y_ + 32 / 2) &&
			(mPos.y_ + mNum[12].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[12].x_ + 32 / 2) &&
			(mPos.x_ + mNum[12].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mKinomi != 0) && (mKinomi <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mKinomi -= 1;
					mNum[12] = mNum[0];
					mKinomi4 = true;

				}

			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[13].y_ + 32 / 2) &&
			(mPos.y_ + mNum[13].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[13].x_ + 32 / 2) &&
			(mPos.x_ + mNum[13].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mKinomi != 0) && (mKinomi <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mKinomi -= 1;
					mNum[13] = mNum[0];
					mKinomi5 = true;

				}

			}
		}
		break;
	case MAP_ID::WA:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[7].y_ + 32 / 2) &&
			(mPos.y_ + mNum[7].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[7].x_ + 32 / 2) &&
			(mPos.x_ + mNum[7].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[7] = mNum[0];
					mTama4 = true;

				}

			}
		}
		
		break;
	case MAP_ID::WASHOP:
		
		break;
	case MAP_ID::CAVE:
		
		break;
	case MAP_ID::CAVESHOP:
		
		break;
	case MAP_ID::DARK:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[6].y_ + 32 / 2) &&
			(mPos.y_ + mNum[6].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[6].x_ + 32 / 2) &&
			(mPos.x_ + mNum[6].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[6] = mNum[0];
					mTama3 = true;

				}

			}
		}
		
		break;
	case MAP_ID::FORESTIN:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[4].y_ + 32 / 2) &&
			(mPos.y_ + mNum[4].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[4].x_  +32/ 2) &&
			(mPos.x_ + mNum[4].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[4] = mNum[0];
					mTama1 = true;
					
				}

			}
		}
		
		break;
	case MAP_ID::TEMPLE:
		
		break;
	case MAP_ID::TEMPLEIN:
		
		break;
	case MAP_ID::SWEETS:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[2].y_ + 32 / 2) &&
			(mPos.y_ + mNum[2].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[2].x_  +32/ 2) &&
			(mPos.x_ + mNum[2].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mAitem != 0) && (mAitem <= 10))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mNumKinomi += 1;
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
					mApple += 1;
					mAitem -= 1;
					mNum[3] = mNum[0];
					i = 3;
				}

			}
		}

		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[5].y_ + 32 / 2) &&
			(mPos.y_ + mNum[5].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[5].x_ + 32 / 2) &&
			(mPos.x_ + mNum[5].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 5))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[5] = mNum[0];
					mTama2 = true;
				}

			}
		}
		break;
	case MAP_ID::SWEETSOUT:
		//if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[1].y_ + 64 / 2) &&
		//	(mPos.y_ + mNum[1].y_ - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
		//	(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[1].x_ + 32 / 2) &&
		//	(mPos.x_ + mNum[1].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		//{
		//	if ((mAitem != 0) && (mAitem <= 10))
		//	{
		//		if (key_.getKeyDown(KEY_INPUT_F))
		//		{
		//			mNumKinomi += 1;
		//			mAitem -= 1;
		//			mNum[1] = mNum[0];
		//			i = 1;
		//		}

		//	}
		//}
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
		//�؂̎��P
		if (mKinomi != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[9].x_ - mMapoffset.x_ , mPos.y_ + mNum[9].y_ - mMapoffset.y_, mImage[1][mAnimCnt], true);
			}
		}

		//�؂̎�2
		if (mKinomi != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[10].x_ - mMapoffset.x_ , mPos.y_ + mNum[10].y_ - mMapoffset.y_, mImage[1][mAnimCnt], true);
			}
		}

		//�؂̎�3
		if (mKinomi != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[11].x_ - mMapoffset.x_ , mPos.y_ + mNum[11].y_ - mMapoffset.y_ , mImage[1][mAnimCnt], true);
			}
		}

		//�؂̎�4
		if (mKinomi != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[12].x_ - mMapoffset.x_, mPos.y_ + mNum[12].y_ - mMapoffset.y_ , mImage[1][mAnimCnt], true);
			}
		}

		//�؂̎�5
		if (mKinomi != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[13].x_ - mMapoffset.x_, mPos.y_ + mNum[13].y_ - mMapoffset.y_ , mImage[1][mAnimCnt], true);
			}
		}
		DrawFormatString(0, 190, GetColor(255, 255, 255), "�؂̎� = %d", mKinomi);
		break;
	case MAP_ID::WA:
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[7].x_ - mMapoffset.x_ , mPos.y_ + mNum[7].y_ - mMapoffset.y_, mImage[3][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::WASHOP:

		break;
	case MAP_ID::CAVE:

		break;
	case MAP_ID::CAVESHOP:

		break;
	case MAP_ID::DARK:
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[6].x_ - mMapoffset.x_, mPos.y_ + mNum[6].y_ - mMapoffset.y_ , mImage[3][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::FORESTIN:
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[4].x_ - mMapoffset.x_, mPos.y_ + mNum[4].y_ - mMapoffset.y_ , mImage[3][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::TEMPLE:

		break;
	case MAP_ID::TEMPLEIN:

		break;
	case MAP_ID::SWEETS:
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
 
			DrawGraph(mPos.x_ + mNum[5].x_ - mMapoffset.x_, mPos.y_ + mNum[5].y_ - mMapoffset.y_, mImage[3][mAnimCnt], true);

			}
		}
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


	DrawFormatString(0,150, GetColor(255, 255, 255), "num=%d", mAitem);
	DrawFormatString(0, 170, GetColor(255, 255, 255), "��=%d", mTama);
	

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

int Aitem::GetmKinomi(void)
{
	return mKinomi;
}

int Aitem::KnomiNum(void)
{
	return mNumKinomi;
}

int Aitem::AppleNum(void)
{
	return mApple;
}

int Aitem::KinominoKusiyakiNum(void)
{
	return mKinominoKusiyaki;
}

int Aitem::FruitDrinkNum(void)
{
	return mFruitDrink;
}

int Aitem::FishingRodSNum(void)
{
	return mFishingRodS;
}

int Aitem::RagBagNum(void)
{
	return mRagBag;
}

int Aitem::PickaxeNum(void)
{
	return mPickaxe;
}

int Aitem::mHaoriNum(void)
{
	return mHaoriN;
}

int Aitem::mRantanNum(void)
{
	return mRantanN;
}





