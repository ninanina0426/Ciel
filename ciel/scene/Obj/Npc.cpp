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

	mNpcType = NpcType::TM_NPC;

	mFmflg = false;
	mWmflg = false;
	mWsflg = false;
	mCmflg = false;
	mCsflg = false;
	mDtflg = false;
	mFiflg = false;
	mTmflg = false;
	mTiflg = false;
	mSmflg = false;
	mSoflg = false;
	mSsflg = false;
	mTiflg = false;

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
		mMoveDir = DIR_UP;
		mSize.x_ = 32;
		mSize.y_ = 64;
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

	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.y_ / 2;

	mMoveSpeed = 0;

	mMoveDir = DIR_DOWN;

	mAnmCnt = 0;


	return true;;
}

Vector2 Npc::Update(Vector2 playerPos,Vector2 playerSize,bool flg)
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
		mNpcType = NpcType::TM_NPC;
		break;
	case MAP_ID::SWEETS:
		mNpcType = NpcType::SM_NPC;
		break;
	case MAP_ID::SWEETSOUT:
		mNpcType = NpcType::SO_NPC;
		if ((playerPos.y_ - playerSize.y_ / 2< mPos.y_ + 675 + 64 / 2 ) &&
			(mPos.y_ + 675 - 64 / 2  < playerPos.y_ + playerSize.y_ / 2) &&
			(playerPos.x_ - playerSize.x_ / 2< mPos.x_ + 1355 + 32 / 2) &&
			(mPos.x_ + 1355 - 32 / 2 < playerPos.x_ + playerSize.x_ / 2))
		{
			if (mSoflg == false)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					mSoflg = true;
					i = 1;
				}
			}
			else
			{
				mSoflg = flg;
			}
		}
		break;
	case MAP_ID::SWEETSSCHOOL:
		mNpcType = NpcType::SS_NPC;
		break;
	case MAP_ID::TRANGETIONS:
		mNpcType = NpcType::TI_NPC;
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}

	mAnmCnt++;

	return mPos;
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
		break;
	case NpcType::SO_NPC:
		DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_+1355, mPos.y_ - offset.y_ - mSizeOffset.y_+605, mImage[0][mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
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
		return mCmflg;
		break;
	case NpcType::CS_NPC:
		return mCsflg;
		break;
	case NpcType::DT_NPC:
		return mDtflg;
		break;
	case NpcType::FI_NPC:
		return mFiflg;
		break;
	case NpcType::FM_NPC:
		return mFmflg;
		break;
	case NpcType::SM_NPC:
		return mSmflg;
		break;
	case NpcType::SO_NPC:
		return mSoflg;
		break;
	case NpcType::SS_NPC:
		return mSsflg;
		break;
	case NpcType::TI_NPC:
		return mTiflg;
		break;
	case NpcType::TM_NPC:
		return mTmflg;
		break;
	case NpcType::WM_NPC:
		return mWmflg;
		break;
	case NpcType::WS_NPC:
		return mWsflg;
		break;
	default:
		break;
	}
}


