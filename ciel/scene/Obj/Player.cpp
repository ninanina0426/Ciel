#include <DxLib.h>
#include "Player.h"
#include"../../stage/StageMng.h"




Player::Player()
{
	init(PlayerID::Max);
}

Player::~Player()
{
}

bool Player::init(PlayerID playerid)
{
	/*mParent = parent;*/
	mPos.x_ = 1590;
	mPos.y_ = 2915;

	/*mPos.x_ = 785;
	mPos.y_ = 1400;*/

	//playerの種別関係
	if (plID_ != PlayerID::Max)
	{
		plID_ = playerid;
		state_ = PL_ST::NON;
	}
	mSizeOffset.x_ = 0;
	mSizeOffset.y_= 0;
	mMoveSpeed = 3;
	mMoveDir = DIR_DOWN;
	mSize.x_ = 32;
	mSize.y_ = 32;
	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.y_ / 2;
	flg = false;
	moveFlg = false;
	
	Stamina_ = STAMINA;
	Energy_ = ENERGY;

	mAnmCnt = 0;

	i = 0;

	num = 0;


	//グラフィックの読み込み

	if (LoadDivGraph("image/106.png", 32, 4, 8, 32, 48, &mImage1[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/107.png", 32, 4, 8, 32, 48, &mImage2[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/108.png", 32, 4, 8, 32, 48, &mImage3[0]) == -1)
	{
		return false;
	}

	

	return true;

}

Vector2 Player::Update(int chipId)
{
	DIR keyDir = DIR_MAX;		//キー入力の方向
	Vector2 copyPos = mPos;

	MAP_ID mapID = lpMapMng.GetMapId();

	mChipId = chipId;

	key_.Update();


	if (key_.getKeyDownHold(KEY_INPUT_LSHIFT)&& Stamina_!=0)
	{
		Stamina_--;
		mMoveSpeed = 5;
	}
	else
	{
		if (Stamina_ != STAMINA)
		{
			Stamina_++;
		}
		mMoveSpeed = 3;
	}
	//デバッグ用
	/*if (key_.getKeyDownHold(KEY_INPUT_Q))
	{
		mPos = { 0,0 };
	}*/

	if ((mChipId == 315) || (mChipId == 316) || (mChipId == 317) || (mChipId == 306) || (mChipId == 308) || (mChipId == 297) || (mChipId == 298) || (mChipId == 299))
	{
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			if (i == 0)
			{
				i = 1;
				moveFlg = true;
			}
			else if (i == 1)
			{
				i = 0;
				moveFlg = false;
			}
		}
	}

	if (moveFlg == false)
	{
		//プレイヤーの操作
		if (key_.getKeyDownHold(KEY_INPUT_DOWN))
		{
			keyDir = DIR_DOWN;
			num = 6;
		}
		if (key_.getKeyDownHold(KEY_INPUT_UP))
		{
			keyDir = DIR_UP;
			num = 4;
		}
		if (key_.getKeyDownHold(KEY_INPUT_LEFT))
		{
			keyDir = DIR_LEFT;
			num = 7;
		}
		if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
		{
			keyDir = DIR_RIGHT;
			num = 5;
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

				if (mapID == MAP_ID::SWEETS || mapID == MAP_ID::SWEETSOUT || mapID == MAP_ID::SWEETSSCHOOL)
				{
					if (copyPos.y_ > 1600)
					{
						copyPos.y_ = 1600;
					}
				}
				else
				{
					if (copyPos.y_ > 3200)
					{
						copyPos.y_ = 3200;
					}
				}
			}
			if (keyDir == DIR_RIGHT)
			{
				copyPos.x_ += mMoveSpeed;		//プレイヤーのマップ上の移動


				if (mapID == MAP_ID::SWEETS || mapID == MAP_ID::SWEETSOUT || mapID == MAP_ID::SWEETSSCHOOL)
				{
					if (copyPos.x_ > 1600)
					{
						copyPos.x_ = 1600;
					}

				}
				else
				{
					if (copyPos.x_ > 3200)
					{
						copyPos.x_ = 3200;

					}
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


			//移動チップに当たっている時
			if (lpMapMng.GetEvent(copyPos) == true)
			{
				//切り替え先のSetposをもらう
				copyPos = lpMapMng.GetPos();
				mMoveDir = lpMapMng.GetDir();
				lpMapMng.mMapChange = false;

			}
			else if (lpMapMng.GetEvent(copyPos) == false)
			{
				lpMapMng.GetEvent(copyPos);
			}

			

			//当たり判定
			if (lpMapMng.cheakMapChip(copyPos))
			{
				mPos = copyPos;
			}

			/*mDamyPos = copyPos;*/

		}
		if (lpMapMng.GetMapChange(copyPos) == true)
		{
			//切り替え先のSetposをもらう
			copyPos = lpMapMng.GetPos();
			mMoveDir = lpMapMng.GetDir();
			lpMapMng.mMapChange = false;

			mPos = copyPos;
		}
		
	
	}

	
	mAnmCnt++;


	return mPos;


}


void Player::Draw(Vector2 offset)
{
	if (plID_ == PlayerID::iti)
	{
		if (i == 0)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage1[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
		else if (i == 1)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage1[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
	}
	if (plID_ == PlayerID::Soy)
	{
		if (i == 0)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
		else if (i == 1)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage2[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
	}
	if (plID_ == PlayerID::Calendula)
	{
		if (i == 0)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
		else if (i == 1)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage3[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
		}
		
	}
	

	DrawFormatString(0, 0, GetColor(255, 255, 255), "playerPos=(%d,%d)", mPos.x_, mPos.y_);
	DrawFormatString(0, 30, 0xff0000, "playerID:%d", plID_);
	DrawFormatString(0, 300, 0xff0000, "スタミナ%d", Stamina_);

}

bool Player::Release(void)
{
	for (int i = 0; i < 16; i++)
	{
		DeleteGraph(mImage1[i]);
	}
	return true;
}

DIR Player::GetDIR(void)
{
	return mMoveDir;
}

void Player::SetDIR(DIR dir)
{
	mMoveDir = dir;
}

void Player::SetPos(Vector2 pos)
{
	mPos = pos;
}

Vector2 Player::GetSiz(void)
{
	return mSize;
}

Vector2 Player::GetPos(void)
{
	return mPos;
}




