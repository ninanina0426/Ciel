#include <DxLib.h>
#include "Player.h"
#include"../../scene/GameScene.h"

bool Player::init(GameScene* parent)
{
	mParent = parent;

	mPos.x_ = 260;
	mPos.y_ = 175;

	
	mSizeOffset.x_ = 0;
	mSizeOffset.y_= 0;
	mMoveSpeed = 5;
	mMoveDir = DIR_DOWN;
	mSize.x_ = 32;
	mSize.y_ = 32;
	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.y_ / 2;

	mAnmCnt = 0;

	if (LoadDivGraph("image/100.png", 16, 4, 4, 32, 32, &mImage[0]) == -1)
	{
		return false;
	}

	return true;

}

Vector2 Player::Update(void)
{
	DIR keyDir = DIR_MAX;		//キー入力の方向
	Vector2 copyPos = mPos;

	//プレイヤーの操作
	if (CheckHitKey(KEY_INPUT_H))
	{
		keyDir = DIR_DOWN;
	}
	if (CheckHitKey(KEY_INPUT_Y))
	{
		keyDir = DIR_UP;
	}
	if (CheckHitKey(KEY_INPUT_G))
	{
		keyDir = DIR_LEFT;
	}
	if (CheckHitKey(KEY_INPUT_J))
	{
		keyDir = DIR_RIGHT;
	}

	if (keyDir != DIR_MAX)
	{
		mMoveDir = keyDir;


		//プレイヤーのコピー
		if (keyDir == DIR_UP)
		{
			copyPos.y_ -= mMoveSpeed;
			if (copyPos.y_ < 0)
			{
				copyPos.y_ = 0;
			}

		}

		if (keyDir == DIR_DOWN)
		{
			copyPos.y_ += mMoveSpeed;
			if (copyPos.y_ > MAP_Y * 32)
			{
				copyPos.y_ = MAP_Y * 32;
			}

		}

		if (keyDir == DIR_RIGHT)
		{
			copyPos.x_ += mMoveSpeed;		//プレイヤーのマップ上の移動
			if (copyPos.x_ > MAP_X * 32)
			{
				copyPos.x_ = MAP_X * 32;
			}

		}

		if (keyDir == DIR_LEFT)
		{
			copyPos.x_ -= mMoveSpeed;
			if (copyPos.x_ < 0)
			{
				copyPos.x_ = 0;
			}

		}

		/*mPos = copyPos;*/
		mPos = copyPos;

		//移動範囲を行う
		switch (mParent->GetEvent(copyPos))
		{

		
			mMoveSpeed = 5;

		case 1:
			//mMoveSpeed = 5;

			mPos = copyPos;
			break;
		default:
			break;
		}
	}

	mAnmCnt++;

    return mPos;
}

void Player::Draw(Vector2 offset)
{
	DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - mSizeOffset.y_, mImage[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "playerPos=(%d,%d)", mPos.x_, mPos.y_);
}

bool Player::Release(void)
{
	for (int i = 0; i < 16; i++)
	{
		DeleteGraph(mImage[i]);
	}
	return true;
}

DIR Player::GetDIR(void)
{
	return mMoveDir;
}

void Player::SetPos(Vector2 pos)
{
	mPos = pos;
}

Vector2 Player::GetSiz(void)
{
	return mSize;
}
