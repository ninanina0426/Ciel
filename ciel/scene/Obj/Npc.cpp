#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "Npc.h"


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

	mQSoNpc1 = false;
	mQSoNpc2 = false;
	mQSmNpc1 = false;

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
		break;
	case NpcType::SM_NPC:
		break;
	case NpcType::SO_NPC:
		switch (mNumType)
		{
		case NumType::NPC_1:
			mMoveDir = DIR_UP;
			mSize.x_ = 32;
			mSize.y_ = 64;
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
		break;
	case NpcType::WS_NPC:
		break;
	default:
		break;
	}

	//ŽžŒv
	if (LoadDivGraph("image/npc/watch.png", 16, 4, 4, 32, 64, &mImage[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/npc/watch.png", 16, 4, 4, 32, 64, &mImage1[0][0]) == -1)
	{
		return false;
	}

	if (LoadDivGraph("image/102.png", 16, 4, 4, 32, 32, &mImage2[0][0]) == -1)
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

int Npc::Update(Vector2 playerPos,Vector2 playerSize,bool flg)
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
		break;
	case NpcType::SM_NPC:
		if ((playerPos.y_ - playerSize.y_ / 2 < mPos.y_ + 830 + 32 / 2) &&
			(mPos.y_ + 830 - 32 / 2 < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2 < mPos.x_ + 830 + 32 / 2) &&
			(mPos.x_ + 830 - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			mNumType = NumType::NPC_1;
			if (mSmNpc1 == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mSmNpc1 = true;
					i = 20;
				}
			}
			else
			{
				if (flg==false)
				{
					mSmNpc1 = false;
					i = 0;
					if (mQSmNpc1 == false)
					{
						mQSmNpc1 = true;
					}
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
					mSoNpc1 = true;
					i = 1;
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
		break;
	case NpcType::WS_NPC:
		break;
	default:
		break;
	}


	mAnmCnt++;

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
		break;
	case NpcType::SM_NPC:
		DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_ + 830, mPos.y_ - offset.y_ - mSizeOffset.y_ + 830, mImage2[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
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
		break;
	case NpcType::WS_NPC:
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
		
		break;
	case NpcType::WS_NPC:
		
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


