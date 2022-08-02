#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "Npc.h"
#include "Quest.h"


Npc::Npc()
{
	init();
}

Npc::~Npc()
{
}

bool Npc::init(void)
{

	mNpcType = NpcType::SO_NPC;

	mSoNpc1 = false;
	mSoNpc2 = false;
	mSmNpc1 = false;
	mWsNpc1 = false;
	mFmNpc1 = false;
	mFmNpc2 = false;
	mFmNpc3 = false;
	mFmNpc4 = false;
	mFmNpc5 = false;
	mFmNpc6 = false;

	mWmNpc1 = false;


	mQSoNpc1 = false;
	mQSoNpc2 = false;
	mQSmNpc1 = false;

	mQWmNpc1 = false;

	
	qnum_ = 0;
	qflg_ = false;

	npcHit = false;

	mPos.x_ = 0;
	mPos.y_ = 0;


	switch (mNpcType)
	{
	case NpcType::CM_NPC:
		mMoveDir = DIR_UP;
		mSize.x_ = 32;
		mSize.y_ = 32;
		break;
	case NpcType::CS_NPC:
		break;
	case NpcType::DT_NPC:
		break;
	case NpcType::FI_NPC:
		break;
	case NpcType::FM_NPC:
		mMoveDir = DIR_UP;
		mSize.x_ = 32;
		mSize.y_ = 32;
		break;
	case NpcType::SM_NPC:
		break;
	case NpcType::SO_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			mMoveDir = DIR_UP;
			mSize.x_ = 64;
			mSize.y_ = 128;
			break;
		case NumType::NPC_2:
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::SS_NPC:
		break;
	case NpcType::TI_NPC:
		break;
	case NpcType::TM_NPC:
		break;
	case NpcType::WM_NPC:
		mMoveDir = DIR_UP;
		mSize.x_ = 32;
		mSize.y_ = 32;
		break;
	case NpcType::WS_NPC:
		break;
	default:
		break;
	}

	//時計
	if (LoadDivGraph("image/npc/watch.png", 16, 4, 4, 32, 64, &mImage[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/npc/watch.png", 16, 4, 4, 32, 64, &mImage1[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/npc/woodL.png", 16, 4, 4, 64,128, &mImage3[0][0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/npc/woodR.png", 16, 4, 4, 64, 128, &mImage4[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/char/107.png", 16, 4, 4, 32, 48, &mImage5[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/npc/cat.png", 12, 3, 4, 32, 32, &mImage7[0][0]) == -1)
	{
		return false;
	}


	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.y_ / 2;

	mMoveSpeed = 0;

	mMoveDir = DIR_DOWN;

	mAnmCnt = 0;


	return true;;
}

int Npc::Update(Vector2 playerPos,Vector2 playerSize,bool flg ,int fis)
{
	MAP_ID mapID = lpMapMng.GetMapId();

	Vector2 pPos = playerPos;
	Vector2 pSize = playerSize;

	key_.Update();

	switch (mapID)
	{
	case MAP_ID::FOREST:
		mNpcType = NpcType::FM_NPC;
		break;
	case MAP_ID::WA:
		mNpcType = NpcType::WM_NPC;
		break;
	case MAP_ID::WASHOP:
		mNpcType = NpcType::WS_NPC;
		break;
	case MAP_ID::CAVE:
		mNpcType = NpcType::CM_NPC;
		break;
	case MAP_ID::CAVESHOP:
		mNpcType = NpcType::CS_NPC;
		break;
	case MAP_ID::DARK:
		mNpcType = NpcType::DT_NPC;
		break;
	case MAP_ID::FORESTIN:
		mNpcType = NpcType::FI_NPC;
		break;
	case MAP_ID::TEMPLE:
		mNpcType = NpcType::TM_NPC;
		break;
	case MAP_ID::TEMPLEIN:
		mNpcType = NpcType::TI_NPC;
		break;
	case MAP_ID::SWEETS:
		mNpcType = NpcType::SM_NPC;
		break;
	case MAP_ID::SWEETSOUT:
		mNpcType = NpcType::SO_NPC;
		break;
	case MAP_ID::SWEETSSCHOOL:
		mNpcType = NpcType::SS_NPC;
		break;
	case MAP_ID::TRANGETIONS:
		
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}

	
	switch (mNpcType)
	{
	case NpcType::CM_NPC:
		break;
	case NpcType::CS_NPC:
		break;
	case NpcType::DT_NPC:
		break;
	case NpcType::FI_NPC:
		break;
	case NpcType::FM_NPC:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 2145 +128 / 2) &&
			(mPos.y_ + 2145 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 1535 + 64 / 2) &&
			(mPos.x_ + 1535 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_1;
			if (mFmNpc1 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc1 = true;
					i = 30;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc1 = false;
					i = 0;
				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 1918 + 128 / 2) &&
			(mPos.y_ + 1918 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 286 + 64 / 2) &&
			(mPos.x_ + 286 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_2;
			if (mFmNpc2 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc2 = true;
					i = 35;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc2 = false;
					i = 0;
				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 800 + 128 / 2) &&
			(mPos.y_ + 800 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 128 + 64 / 2) &&
			(mPos.x_ + 128 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_3;
			if (mFmNpc3 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc3 = true;
					i = 40;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc3 = false;
					i = 0;
				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 769 + 128 / 2) &&
			(mPos.y_ + 769 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 2879 + 64 / 2) &&
			(mPos.x_ + 2879 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_4;
			if (mFmNpc4 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc4 = true;
					i = 45;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc4 = false;
					i = 0;
				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 100 + 128 / 2) &&
			(mPos.y_ + 100 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 2400 + 64 / 2) &&
			(mPos.x_ + 2400 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_5;
			if (mFmNpc5 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc5 = true;
					i = 50;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc5 = false;
					i = 0;
				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 129 + 128 / 2) &&
			(mPos.y_ + 129 - 128 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 2591 + 64 / 2) &&
			(mPos.x_ + 2591 - 64 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_6;
			if (mFmNpc6 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mFmNpc6 = true;
					i = 55;
				}
			}
			else
			{
				if (flg == false)
				{
					mFmNpc6 = false;
					i = 0;
				}

			}

		}
		break;
	case NpcType::SO_NPC:
	{
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 675 + 64 / 2) &&
			(mPos.y_ + 675 - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 1355 + 32 / 2) &&
			(mPos.x_ + 1355 - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_1;
			if (mSoNpc1 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					if (mSoNpc1 == false)
					{
						if (key_.getKeyDown(KEY_INPUT_F))
						{
							mSoNpc1 = true;
							if (mQSoNpc1 == false)
							{
								i = 8;
							}
							else
							{
								i = 1;
							}

						}
					}
					
				}
			}
			else
			{
				if (flg == false)
				{
					mSoNpc1 = false;
					i = 0;
					if (mQSoNpc1 == false)
					{
						mQSoNpc1 = true;
					}

				}

			}

		}
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 1200 + 64 / 2) &&
			(mPos.y_ + 1200 - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 800 + 32 / 2) &&
			(mPos.x_ + 800 - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_2;
			if (mSoNpc2 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mSoNpc2 = true;
					i = 4;
				}
				if (mQSoNpc2 )
				{
					qnum_ = 0;
				}
			}
			else
			{
				if (flg == false)
				{
					mSoNpc2 = false;
					i = 0;
					if (mQSoNpc2 == false)
					{
						mQSoNpc2 = true;
						qflg_ = mQSoNpc2;
						qnum_ = 2;
					}
					
				}
			}
		}
	}
	break;
	case NpcType::SS_NPC:
		break;
	case NpcType::TI_NPC:
		break;
	case NpcType::TM_NPC:
		break;
	case NpcType::WM_NPC:
	{
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 573 + 64 / 2) &&
			(mPos.y_ + 573 - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 994 + 32 / 2) &&
			(mPos.x_ + 994 - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{

			mNumType = NumType::NPC_1;
			npcHit = true;
			if (mWmNpc1 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mWmNpc1 = true;
					i = 60;
				}
				if (mQWmNpc1)
				{
					qnum_ = 0;
				}
			}
			else
			{
				if (flg == false)
				{
					mWmNpc1 = false;
					i = 0;
					if (mQWmNpc1 == false)
					{
						mQWmNpc1 = true;
						qflg_ = mQWmNpc1;
						qnum_ = 3;
					}
					
				}
			}
		}
		else
		{
			npcHit = false;
		}
		break;
	}
	case NpcType::WS_NPC:
	{
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 1750 + 64 / 2) &&
			(mPos.y_ + 1750 - 64 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 1825 + 22) &&
			(mPos.x_ + 1825 - 22 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_1;
			npcHit = true;
			if (mWsNpc1 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mWsNpc1 = true;
					i = 15;
				}
			}
			else
			{
				if (flg == false)
				{
					mWsNpc1 = false;
					i = 0;
				}
			}
		}
		else
		{
			npcHit = false;
		}
		break;
	}
	default:
		break;
	}

	mAnmCnt++;
	//クエスト
	QuestIns.UpDate(qflg_, qnum_, playerPos,playerSize, mapID,fis);

	return i;

}

void Npc::Draw(Vector2 offset)
{
	switch (mNpcType)
	{
	case NpcType::CM_NPC:
		break;
	case NpcType::CS_NPC:
		break;
	case NpcType::DT_NPC:
		break;
	case NpcType::FI_NPC:
		break;
	case NpcType::FM_NPC:
		DrawGraph(mPos.x_ - offset.x_ - 32 + 1535, mPos.y_ - offset.y_ - 64 + 2145, mImage4[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - 32 + 286, mPos.y_ - offset.y_ - 64 + 1918, mImage3[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - 32 + 128, mPos.y_ - offset.y_ - 64 + 800, mImage4[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - 32 + 2879, mPos.y_ - offset.y_ - 64 + 769, mImage3[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - 32 + 2400, mPos.y_ - offset.y_ - 64 + 100, mImage4[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - 32 + 2591, mPos.y_ - offset.y_ - 64 + 129, mImage3[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		break;
	case NpcType::SM_NPC:
		/*DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + 830, mPos.y_ - offset.y_ - mSizeOffset.y_ + 830, mImage2[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);*/
		break;
	case NpcType::SO_NPC:
		DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + 1355, mPos.y_ - offset.y_ - mSizeOffset.y_ + 605, mImage[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + 800, mPos.y_ - offset.y_ - mSizeOffset.y_ + 1200, mImage1[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		break;
	case NpcType::SS_NPC:
		break;
	case NpcType::TI_NPC:
		break;
	case NpcType::TM_NPC:
		break;
	case NpcType::WM_NPC:
		DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + 994, mPos.y_ - offset.y_ - mSizeOffset.y_ + 573, mImage7[0][0], true);
		break;
	case NpcType::WS_NPC:
		DrawGraph(mPos.x_ - offset.x_ - 32 + 1825, mPos.y_ - offset.y_ - 64 + 1750, mImage5[0][3], true);
		break;
	default:
		break;
	}



}

bool Npc::Release(void)
{
	for (int i = 0; i < 16; i++)
	{
		DeleteGraph(mImage[i][i]);
	}
	return true;
}

DIR Npc::GetDIR(void)
{
	return mMoveDir;
}

Vector2 Npc::GetSiz(void)
{
	return mSize;
}

Vector2 Npc::GetPos(void)
{
	return mPos;
}

bool Npc::NpcHit()
{
	return npcHit;
}

int Npc::Num()
{
	return i;
}

bool Npc::Getflg()
{
	switch (mNpcType)
	{
	case NpcType::CM_NPC:
		
		break;
	case NpcType::CS_NPC:
		
		break;
	case NpcType::DT_NPC:
		
		break;
	case NpcType::FI_NPC:
		
		break;
	case NpcType::FM_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mFmNpc1;
			break;
		case NumType::NPC_2:
			return mFmNpc2;
			break;
		case NumType::NPC_3:
			return mFmNpc3;
			break;
		case NumType::NPC_4:
			return mFmNpc4;
			break;
		case NumType::NPC_5:
			return mFmNpc5;
			break;
		case NumType::NPC_6:
			return mFmNpc6;
			break;
		default:
			break;
		}
		break;
	case NpcType::SM_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mSmNpc1;
			break;
		case NumType::NPC_2:
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::SO_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mSoNpc1;
			break;
		case NumType::NPC_2:
			return mSoNpc2;
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::SS_NPC:
		
		break;
	case NpcType::TI_NPC:
		
		break;
	case NpcType::TM_NPC:
		
		break;
	case NpcType::WM_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mWmNpc1;
			break;
		case NumType::NPC_2:
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::WS_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mWsNpc1;
			break;
		case NumType::NPC_2:
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		
		break;
	default:
		break;
	}

}

bool Npc::GetQflg()
{
	switch (mNpcType)
	{
	case NpcType::CM_NPC:

		break;
	case NpcType::CS_NPC:

		break;
	case NpcType::DT_NPC:

		break;
	case NpcType::FI_NPC:

		break;
	case NpcType::FM_NPC:

		break;
	case NpcType::SM_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mQSmNpc1;
			break;
		case NumType::NPC_2:
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::SO_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			return mQSoNpc1;
			break;
		case NumType::NPC_2:
			return mQSoNpc2;
			break;
		case NumType::NPC_3:
			break;
		case NumType::NPC_4:
			break;
		case NumType::NPC_5:
			break;
		default:
			break;
		}
		break;
	case NpcType::SS_NPC:

		break;
	case NpcType::TI_NPC:

		break;
	case NpcType::TM_NPC:

		break;
	case NpcType::WM_NPC:

		break;
	case NpcType::WS_NPC:

		break;
	default:
		break;
	}
}


