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

	mGet = false;

	//�����Ǘ��p

	mTama1 = false;
	mTama2 = false;
	mTama3 = false;
	mTama4 = false;
	mTama5 = false;
	mTama6 = false;

	mKinomi1 = false;
	mKinomi2 = false;
	mKinomi3 = false;
	mKinomi4 = false;
	mKinomi5 = false;

	Key = false;

	mHaori = false;


	mRantan = false;

	Takara = false;

	mTama = 6;
	mKinomi = 5;
	
	mtakara = 0;

	sAitem = 7;

	mAitem = 0;
	//����
	Ru = 0;


	mNumKinomi = 0;
	mApple = 0;
	mKinominoKusiyaki = 0;
	mFruitDrink = 0;
	mFishingRodS = 0;
	mRagBag = 0;
	mPickaxe = 0;
	mRice=0;
	mDango=0;
	mTea=0;
	mTamaN = 0;
	mKey = 0;
	mFish = 0;
	mStoneR = 0;
	mStoneB = 0;

	apple = 0;
	rantan = 0;
	mKinomis = 0;
	mTamaNum = 0;
	
	
	Flg = true;

	mNum[0] ={0,0}; //posx

	mNum[1] = { 1355,675 }; //posx
	mNum[2] = { 785,1335 }; //posx
	mNum[3] = { 625,1275 }; //posx
	mNum[20] = { 722,503 }; //posx
	mNum[21] = { 2476,1078 }; //posx
	mNum[22] = { 1282,1711 }; //posx
	mNum[23] = { 2632,1440 }; //posx
	mNum[24] = { 289,95 }; //posx

	//��
	mNum[4] = { 1420,280 };		//�X
	mNum[5] = { 553,565 };		//�َq
	mNum[6] = { 1585,1070 };	//���A
	mNum[7] = { 465,500 };		//�a
	mNum[8] = {1457,653};		//�_�a
	mNum[17] = {2990,120};		//��

	//�؂̎�
	mNum[9] = { 2536,1635 };
	mNum[10] = { 2805,780 };
	mNum[11] = { 155,930 };
	mNum[12] = { 560,160 };
	mNum[13] = { 2300,120 };

	//�����^��
	mNum[14] = { 1420,2144 };

	//��
	mNum[15] = {1425,1026};

	//��
	mNum[16] = { 337,1704 };

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
					mKinomis += 1;
					mGet = true;
					mAitem = 1;
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
					mKinomis += 1;
					mGet = true;
					mAitem = 1;
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
					mKinomis += 1;
					mGet = true;
					mAitem = 1;
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
					mKinomis += 1;
					mGet = true;
					mAitem = 1;
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
					mKinomis += 1;
					mGet = true;
					mAitem = 1;
				}

			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}

		//�����S
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[20].y_ + 32 / 2) &&
			(mPos.y_ + mNum[20].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[20].x_ + 32 / 2) &&
			(mPos.x_ + mNum[20].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					//sAitem -= 1;
					mNum[20] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

				}
			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[21].y_ + 32 / 2) &&
			(mPos.y_ + mNum[21].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[21].x_ + 32 / 2) &&
			(mPos.x_ + mNum[21].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					//sAitem -= 1;
					mNum[21] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

				}
			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[22].y_ + 32 / 2) &&
			(mPos.y_ + mNum[22].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[22].x_ + 32 / 2) &&
			(mPos.x_ + mNum[22].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					//sAitem -= 1;
					mNum[22] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

				}
			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[23].y_ + 32 / 2) &&
			(mPos.y_ + mNum[23].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[23].x_ + 32 / 2) &&
			(mPos.x_ + mNum[23].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					//sAitem -= 1;
					mNum[23] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

				}
			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[24].y_ + 32 / 2) &&
			(mPos.y_ + mNum[24].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[24].x_ + 32 / 2) &&
			(mPos.x_ + mNum[24].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					//sAitem -= 1;
					mNum[24] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

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
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[7] = mNum[0];
					mTama4 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}

		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
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
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[6] = mNum[0];
					mTama3 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}

		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}
		break;
	case MAP_ID::FORESTIN:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[14].y_ + 32 / 2) &&
			(mPos.y_ + mNum[14].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[14].x_ + 32 / 2) &&
			(mPos.x_ + mNum[14].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				rantan += 1;
				mNum[14] = mNum[0];
				mRantan = true;
				mGet = true;
				mAitem = 4;
			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[4].y_ + 32 / 2) &&
			(mPos.y_ + mNum[4].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[4].x_  +32/ 2) &&
			(mPos.x_ + mNum[4].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[4] = mNum[0];
					mTama1 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[16].y_ + 32 / 2) &&
			(mPos.y_ + mNum[16].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[16].x_ + 32 / 2) &&
			(mPos.x_ + mNum[16].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				mKey += 1;
				mNum[16] = mNum[0];
				Key = true;
				mGet = true;
				mAitem = 6;
			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}
		break;
	case MAP_ID::TEMPLE:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[8].y_ + 32 / 2) &&
			(mPos.y_ + mNum[8].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[8].x_ + 32 / 2) &&
			(mPos.x_ + mNum[8].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[8] = mNum[0];
					mTama6 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}
		break;
	case MAP_ID::TEMPLEIN:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[15].y_ + 32 / 2) &&
			(mPos.y_ + mNum[15].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[15].x_ + 32 / 2) &&
			(mPos.x_ + mNum[15].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if (mtakara == 0)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mtakara = 1;
					mNum[15] = mNum[0];
					Takara = true;
					mGet = true;
					mAitem = 5;
				}

			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}
		break;
	case MAP_ID::SWEETS:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[2].y_ + 32 / 2) &&
			(mPos.y_ + mNum[2].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[2].x_  +32/ 2) &&
			(mPos.x_ + mNum[2].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					sAitem -= 1;
					mNum[2] = mNum[0];
					i = 2;
					mGet = true;
					mAitem = 3;

				}
			}
		}
		
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[3].y_ + 32 / 2) &&
			(mPos.y_ + mNum[3].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[3].x_ + 32 / 2) &&
			(mPos.x_ + mNum[3].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((sAitem != 0) && (sAitem <= 7))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					apple += 1;
					sAitem -= 1;
					mNum[3] = mNum[0];
					i = 3;
					mGet = true;
					mAitem = 3;
				}
			}
		}
		
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[5].y_ + 32 / 2) &&
			(mPos.y_ + mNum[5].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[5].x_ + 32 / 2) &&
			(mPos.x_ + mNum[5].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[5] = mNum[0];
					mTama2 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}

		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}

		break;
	case MAP_ID::SWEETSOUT:
		
		break;
	case MAP_ID::SWEETSSCHOOL:
		break;
	case MAP_ID::SNOW:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + mNum[17].y_ + 32 / 2) &&
			(mPos.y_ + mNum[17].y_ - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + mNum[17].x_ + 32 / 2) &&
			(mPos.x_ + mNum[17].x_ - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if ((mTama != 0) && (mTama <= 6))
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mTama -= 1;
					mNum[17] = mNum[0];
					mTama2 = true;
					mGet = true;
					mAitem = 2;
					mTamaN += 1;
				}

			}
		}

		if (key_.getKeyDown(KEY_INPUT_F))
		{
		}
		else
		{
			mGet = false;
		}
		break;
	case MAP_ID::SNOWCAVE:
		break;
	case MAP_ID::SNOWSHOP:
	case MAP_ID::TRANGETIONS:
		
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}

	if (mHaoriN != 0)
	{
		mHaori = true;
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


		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[20].x_ - mMapoffset.x_, mPos.y_ + mNum[20].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[21].x_ - mMapoffset.x_, mPos.y_ + mNum[21].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[22].x_ - mMapoffset.x_, mPos.y_ + mNum[22].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[23].x_ - mMapoffset.x_, mPos.y_ + mNum[23].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		if (mAitem != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 7 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[24].x_ - mMapoffset.x_, mPos.y_ + mNum[24].y_ - mMapoffset.y_, mImage[0][mAnimCnt], true);
			}
		}
		//DrawFormatString(0, 190, GetColor(255, 255, 255), "�؂̎� = %d", mKinomi);
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
		if (rantan == 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[14].x_ - mMapoffset.x_, mPos.y_ + mNum[14].y_ - mMapoffset.y_, mImage[1][mAnimCnt], true);
			}
		}
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[4].x_ - mMapoffset.x_, mPos.y_ + mNum[4].y_ - mMapoffset.y_ , mImage[3][mAnimCnt], true);
			}
		}
		if (mKey == 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[16].x_ - mMapoffset.x_, mPos.y_ + mNum[16].y_ - mMapoffset.y_, mImage[1][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::TEMPLE:

		break;
	case MAP_ID::TEMPLEIN:
		if (Takara == 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[15].x_ - mMapoffset.x_-20, mPos.y_ + mNum[15].y_ - mMapoffset.y_-70, mImage[1][mAnimCnt], true);
			}
		}

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
	case MAP_ID::SNOW:
		//�L�[�A�C�e��
		if (mTama != 0)
		{
			int mAnimCnt = abs((ItemAnimcount / 15 % 4) - 2);
			if ((mAnimCnt >= 0) && (mAnimCnt < ITEM_ANIM_MAX))
			{
				DrawGraph(mPos.x_ + mNum[17].x_ - mMapoffset.x_, mPos.y_ + mNum[17].y_ - mMapoffset.y_, mImage[3][mAnimCnt], true);
			}
		}
		break;
	case MAP_ID::SNOWCAVE:
		break;
	case MAP_ID::SNOWSHOP:
	case MAP_ID::TRANGETIONS:

		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}
	//DrawFormatString(0,150, GetColor(255, 255, 255), "num=%d", apple);
	//DrawFormatString(0, 170, GetColor(255, 255, 255), "��=%d", mTama);
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

int Aitem::Money(int ru, bool flg)
{
	int sRu = Ru;

	if (flg == true)
	{
		Ru = sRu + ru;
	}

	return Ru;
}

int Aitem::wMoney(int ru, bool flg)
{
	int wRu = Ru;

	if (flg == true)
	{
		Ru = wRu + ru;
	}

	return Ru;
}

int Aitem::qMoney(int ru, bool flg)
{
	int qRu = Ru;

	if (Flg == true)
	{
		if (flg == true)
		{
			Ru = qRu + ru;
			Flg = false;
		}
	}
	if (Flg == false)
	{
		if (flg == false)
		{
			Flg = true;
		}
	}
	
	return Ru;
}



int Aitem::HaveMoney()
{
	return Ru;
}


void Aitem::TotalAitem(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h, int ri, int d, int t, int f, int ssr, int sb, int sa, int skk, int sfd, int sfrs, int srb, int sp, int sk, int sr, int sh, int sri, int sd, int st, int sf, int sssr, int ssb, int ma, int mkk, int mfd, int mfrs, int mrb, int mp, int mk, int mr, int mh, int mri, int md, int mt, int mf, int msr, int msb ,int la, int lkk, int lfd, int lri, int ld, int lt, int je, int fis,int bul, int haori, int givfhi)
{

	mNumKinomi=k+sk+mk+ mKinomis;
	mApple = apple + a + sa-ma+la;
	mKinominoKusiyaki=kk+skk-mkk+lkk;
	mFruitDrink=fd+sfd-mfd+lfd;
	mFishingRodS=frs+sfrs-mfrs;
	mRagBag=rb+srb-mrb;
	mPickaxe=p+sp-mp;
	mHaoriN=h+sh+haori-mh;
	mRantanN=r+sr+rantan-mr;
	mRice = ri+sri-mri+lri;
	mDango = d+sd-md+ld;
	mTea = t+st-mt+lt;
	mFish = f + sf+fis-givfhi - mf;
	mStoneR = ssr + sssr+je - msr;
	mStoneB = sb + ssb+bul - msb;
	mTamaNum = mTamaN;
	

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

int Aitem::RiceNum(void)
{
	return mRice;
}

int Aitem::DangoNum(void)
{
	return mDango;
}

int Aitem::TeaNum(void)
{
	return mTea;
}

int Aitem::TamNum(void)
{
	return mTamaNum;
}

int Aitem::KeyNum(void)
{
	return mKey;
}

int Aitem::FishNum(void)
{
	return mFish;
}

int Aitem::StoneRNum(void)
{
	return mStoneR;
}

int Aitem::StoneBNum(void)
{
	return mStoneB;
}

int Aitem::GetKey(void)
{
	return mKey;
}

int Aitem::GetTam(void)
{
	return mTama;
}

int Aitem::SetAitem(void)
{
	return mAitem;
}

bool Aitem::GetAitem()
{
	return mGet;
}







