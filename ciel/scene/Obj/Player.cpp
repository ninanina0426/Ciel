#include <DxLib.h>
#include "Player.h"
#include"../../stage/StageMng.h"
#include "Quest.h"




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
	mSizeOffset.y_ = 0;
	mMoveSpeed = 3;
	mMoveDir = DIR_DOWN;
	mSize.x_ = 48;
	mSize.y_ = 48;
	mSizeOffset.x_ = mSize.x_ / 2;
	mSizeOffset.y_ = mSize.y_ / 2;
	flg = false;
	moveFlg = false;
	mFlg = false;

	Stamina_ = STAMINA;
	Energy_ = ENERGY;
	staminaFlg_ = false;
	qflg_ = false;
	staminacnt_ = 0;

	mAnmCnt = 0;
	moveAnmCnt = true;

	i = 0;

	num = 0;

	//ギミック
	mgPos.x_ = 580;
	mgPos.y_ = 285;
	mgSize.x_ = 96;
	mgSize.y_ = 96;
	gFlg = false;


	//グラフィックの読み込み

	if (LoadDivGraph("image/char/110.png", 48, 4, 12, 48, 48, &mImage1[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/char/107.png", 32, 4, 8, 32, 48, &mImage2[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/char/108.png", 32, 4, 8, 32, 48, &mImage3[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/char/花.png", 27, 1, 27, 32, 48, &mImageC[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/char/金.png", 27, 1, 27, 32, 48, &mImageI[0]) == -1)
	{
		return false;
	}
	if (LoadDivGraph("image/char/不.png", 27, 1, 27, 32, 48, &mImageS[0]) == -1)
	{
		return false;
	}

	//会話
	mImageChat[1] = LoadGraph("image/talk/c1.png",true);
	mImageChat[3] = LoadGraph("image/talk/i1.png",true);
	mImageChat[2] = LoadGraph("image/talk/s1.png",true);

	//ギミック
	mImageF= LoadGraph("image/ギミック/船.png", true);

	//効果音
	sHandle = LoadSoundMem("image/Sound/服.ogg");
	tHandle = LoadSoundMem("image/Sound/釣り.ogg");
	fHandle = LoadSoundMem("image/Sound/パパッ.ogg");
	oHandle = LoadSoundMem("image/Sound/水に浸かりながら歩く.ogg");
	
	return true;

}

Vector2 Player::Update(int chipId)
{
	keyDir = DIR_MAX;		//キー入力の方向
	Vector2 copyPos = mPos;

	mapID = lpMapMng.GetMapId();

	mChipId = chipId;
	mChiID = lpMapMng.GetChipID();

	key_.Update();

	//釣り
	if ((mChipId == 315) || (mChipId == 316) || (mChipId == 317) || (mChipId == 306) || (mChipId == 308) || (mChipId == 297) || (mChipId == 298) || (mChipId == 299) )
	{
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			if (i == 0)
			{
				i = 1;
				moveFlg = true;
				PlaySoundMem(tHandle, DX_PLAYTYPE_BACK);
			}
			else if (i == 1)
			{
				i = 0;
				moveFlg = false;
				
			}
		}
	}
	//浅瀬
	if ((mChipId == 896))
	{
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			if (i == 0)
			{
				i = 2;
				mFlg = true;
				PlaySoundMem(oHandle, DX_PLAYTYPE_BACK);
			}
			else if (i == 2)
			{
				i = 0;
				mFlg = false;
				DeleteSoundMem(oHandle);
				oHandle = LoadSoundMem("image/Sound/水に浸かりながら歩く.ogg");
			}
		}
	}

	if ((mAnmCnt / 10 > 30) && (moveAnmCnt == true))
	{
		if ((moveFlg == false) && (mFlg == false))
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
			

			//走る
			if (key_.getKeyDownHold(KEY_INPUT_LSHIFT) && Stamina_ != 0 && keyDir != DIR::DIR_MAX)
			{
				Stamina_--;
				mMoveSpeed = 5;
			}
			else
			{
				if (Stamina_ == 0)
				{
					staminaFlg_ = true;
				}
				if (staminaFlg_)
				{
					mMoveSpeed = 2;
					staminacnt_++;
				}
				if (staminacnt_ > 120)
				{
					staminacnt_ = 0;
					staminaFlg_ = false;
				}
				if (!staminaFlg_)
				{
					if (Stamina_ != STAMINA)
					{
						Stamina_++;
					}
					mMoveSpeed = 3;
				}
			}
		
			if (keyDir != DIR_MAX)
			{
				mMoveDir = keyDir;

				//プレイヤーのコピー
				if (mMoveDir == DIR_UP)
				{
					
					copyPos.y_ -= mMoveSpeed;
					if (copyPos.y_ < 0)
					{
						copyPos.y_ = 0;
					}

				}
				if (mMoveDir == DIR_DOWN)
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
				if (mMoveDir == DIR_RIGHT)
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

				if (mMoveDir == DIR_LEFT)
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

		
	}

	//ライムに乗る
	if (mapID == MAP_ID::SWEETS)
	{
		if ((mPos.x_ < 580) && (mPos.x_ > 490) && (mPos.y_ > 285) && (mPos.y_ < 310))
		{
			message_box();
		}
		if (gFlg == true)
		{
			if (key_.getKeyDown(KEY_INPUT_LEFT))
			{
				PlaySoundMem(oHandle, DX_PLAYTYPE_BACK);
			}
			if (key_.getKeyDown(KEY_INPUT_RIGHT))
			{
				PlaySoundMem(oHandle, DX_PLAYTYPE_BACK);
			}

			mgPos.x_ = mPos.x_;
			mgPos.y_ = 560;

			if (mgPos.x_ < 403)
			{
				mgPos.x_ = 403;

			}
			else if (mgPos.x_ > 510)
			{
				mgPos.x_ = 510;

			}
		}
		
	}
	//ライム
	if (mChiID == 4220 || mChiID == 4221 || mChiID == 4320 || mChiID == 4321)
	{
		gFlg = false;
		DeleteSoundMem(oHandle);
		oHandle = LoadSoundMem("image/Sound/水に浸かりながら歩く.ogg");
	}
	

	
	//最初の倒れている時
	if (mAnmCnt  == 150)
	{
		PlaySoundMem(sHandle, DX_PLAYTYPE_BACK);
	}

	if (mAnmCnt  == 270)
	{
		PlaySoundMem(fHandle, DX_PLAYTYPE_BACK);
	}

	if (mAnmCnt == 270)
	{
		mAnmCnt = 290;
		moveAnmCnt = false;
	}
	if (moveAnmCnt == false)
	{
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			moveAnmCnt = true;
			qflg_ = true;
		}
	}
	
	if (moveAnmCnt == true)
	{
		mAnmCnt++;
	}
	if (qflg_)
	{
		QuestIns.UpDate(qflg_, 1, copyPos, mSize, mapID);
	}
	if (QuestIns.CompFlg())
	{
		if (QuestIns.GetCont() > 570)
		{
			qflg_ = false;
		}
		
	}
	
	return mPos;

}


void Player::Draw(Vector2 offset)
{
	
	//ライム
	if (mapID == MAP_ID::SWEETS)
	{
		if (gFlg == true)
		{
			DrawGraph(mgPos.x_ - offset.x_ - 48, mgPos.y_ - offset.y_ - 48, mImageF, true);
		}

		if (gFlg == false)
		{
			DrawGraph(580 - offset.x_ - 79, 285 - offset.y_ - 48, mImageF, true);
		}
	}
	

	if (plID_ == PlayerID::iti)
	{
		if (moveAnmCnt == false)
		{
			DrawGraph(mPos.x_ - offset.x_ - 63, mPos.y_ - offset.y_ - 80, mImageChat[3], true);
		}
		if (mAnmCnt< 270)
		{
			DrawGraph(mPos.x_ - offset.x_ - 16, mPos.y_ - offset.y_ - 24, mImageI[mAnmCnt / 10], true);
		}
		else
		{
			if (i == 0)
			{
				if (keyDir == DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - 24, mPos.y_ - offset.y_ - 24, mImage1[mMoveDir * DIR_MAX], true);
				}
				else if (keyDir != DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - 24, mPos.y_ - offset.y_ - 24, mImage1[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
				}
				
			}
			else if (i == 1)
			{
				DrawGraph(mPos.x_ - offset.x_ - 24, mPos.y_ - offset.y_ - 24, mImage1[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
			}
			else if (i == 2)
			{
				DrawGraph(mPos.x_ - offset.x_ - 24, mPos.y_ - offset.y_ - 24, mImage1[(4+num) * DIR_MAX + ((mAnmCnt / 10) % 4)], true);
			}
			
		}
		
		
	}
	if (plID_ == PlayerID::Soy)
	{
		if (moveAnmCnt == false)
		{
			DrawGraph(mPos.x_ - offset.x_ - 63, mPos.y_ - offset.y_ - 80, mImageChat[2], true);
		}
		if (mAnmCnt< 270)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImageS[mAnmCnt / 10], true);
		}
		else
		{
			if (i == 0)
			{
				if (keyDir == DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage2[mMoveDir * DIR_MAX], true);
				}
				else if (keyDir != DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage2[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
				}
			}
			else if (i == 1)
			{
				DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage2[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
			}
		}
	}
	if (plID_ == PlayerID::Calendula)
	{
		if (moveAnmCnt == false)
		{
			DrawGraph(mPos.x_ - offset.x_-63 , mPos.y_ - offset.y_ -80, mImageChat[1], true);
		}
		if (mAnmCnt< 270)
		{
			DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImageC[mAnmCnt/10], true);
		}
		else
		{
			if (i == 0)
			{
				if (keyDir == DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage3[mMoveDir * DIR_MAX], true);
				}
				else if (keyDir != DIR_MAX)
				{
					DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage3[mMoveDir * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
				}
			}
			else if (i == 1)
			{
				DrawGraph(mPos.x_ - offset.x_ - mSizeOffset.x_, mPos.y_ - offset.y_ - 24, mImage3[num * DIR_MAX + ((mAnmCnt / 8) % 4)], true);
			}
		}
		
	}

	DrawFormatString(0, 0, GetColor(0,0,255), "playerPos=(%d,%d)", mPos.x_, mPos.y_);
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "playerPos=(%d,%d)", mgPos.x_, mgPos.y_);
	//DrawFormatString(0, 30, 0xff0000, "playerID:%d", plID_);
	/*DrawFormatString(0, 30, 0xff0000, "chipID:%d", mChiID);*/
	//DrawFormatString(0, 300, 0xff0000, "スタミナ%d", Stamina_);

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

int Player::GetStamina(void)
{
	return Stamina_;
}

void Player::message_box() 
{
	int flag;
	flag = MessageBox(
		NULL,
		TEXT("移動する？(元の場所には戻れません)"),
		TEXT("選択"),
		MB_YESNO | MB_ICONQUESTION);
	if (flag == IDYES)
	{
		gFlg = true;
		mPos.x_ = 455;
		mPos.y_ = 550;
	}
	
}



