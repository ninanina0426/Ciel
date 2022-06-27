#include <DxLib.h>
#include"../../stage/StageMng.h"
#include"Npc.h"
#include "Chat.h"

Chat::Chat()
{
	init();
}

Chat::~Chat()
{
}

bool Chat::GetfinalC(void)
{
	return finalC_;
}

bool Chat::init(void)
{

	mPos.x_ = 0;
	mPos.y_ = 0;

	mImage[1] = LoadGraph("image/talk/10.png");
	mImage[2] = LoadGraph("image/talk/2.png");
	mImage[3] = LoadGraph("image/talk/3.png");
	mImage[4] = LoadGraph("image/talk/temple.png");
	mImage[5] = LoadGraph("image/talk/temple.png");
	mImage[15] = LoadGraph("image/talk/temple.png");
	mImage[16] = LoadGraph("image/talk/temple.png");
	mImage[17] = LoadGraph("image/talk/3.png");
	mImage[18] = LoadGraph("image/talk/3.png");

	mNum = 100;

	mFlg = false;
	finalC_ = false;
	mSNum = 0;

	mNpc = new Npc();

	return true;
}

bool Chat::Update(bool flg, int num,bool sflg,bool sPose, bool wflg, bool wPose)
{
	mFlg = flg;

	shopFlg = sflg;
	wshopFlg = wflg;

	key_.Update();

	

	if ((mFlg == true))
	{
		mNumType = num;

		switch (mNumType)
		{
		case 1:
		{
			if (mNum == 100)
			{
				finalC_ = true;
				mNum = num - 1;
			}
			if ((key_.getKeyDown(KEY_INPUT_F)) && (mNum != 100) && (sPose == false))
			{

				mNum += 1;
				if (mNum == 2)
				{
					mSNum = 4;
					mNum = 20;
				}
				
				if (mNum == 4)
				{
					mFlg = false;
					mNum = 0;

				}
			}

			if (sPose == true)
			{
				if (mNum == 20)
				{
					mNum = 20;
					mSNum = 20;
				}
				if (shopFlg == false)
				{
					if (mNum == 3)
					{
						mNum = 20;
					}
				}
			}
			else 
			{
				if (shopFlg == true)
				{
					if (mNum == 20)
					{
						mNum = 3;
					}
				}
				
			}
		}
		break;
		case 4:
		{

			if (mNum == 100)
			{
				mNum = num;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 6)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 15:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if ((key_.getKeyDown(KEY_INPUT_F)) && (mNum != 100) && (wPose == false))
			{

				mNum += 1;
				if (mNum == 16)
				{
					mSNum = 15;
					mNum = 30;
				}

				if (mNum == 18)
				{
					mFlg = false;
					mNum = 0;

				}
			}

			if (wPose == true)
			{
				if (mNum == 30)
				{
					mNum = 30;
					mSNum = 30;
				}
				if (wshopFlg == false)
				{
					if (mNum == 17)
					{
						mNum = 30;
					}
				}
			}
			else
			{
				if (wshopFlg == true)
				{
					if (mNum == 20)
					{
						mNum = 17;
					}
				}

			}
			
		}
		break;
		default:
			break;
		}
	}
	else if(mFlg==false)
	{
		mNum = 100;
		/*mFlg = false;*/
		mSNum = 0;
	}
	

	return mFlg;
}

void Chat::Draw(Vector2 offset)
{
	switch (mNumType)
	{
	case 1:
	{
		DrawGraph(mPos.x_ - offset.x_ + 1305, mPos.y_ - offset.y_ + 555, mImage[mNum], true);
		break;
	}
	case 4:
	{
		DrawGraph(mPos.x_ - offset.x_ + 750, mPos.y_ - offset.y_ + 1100, mImage[mNum], true);
		break;
	}
	case 15:
	{
		DrawGraph(mPos.x_ - offset.x_ + 1750, mPos.y_ - offset.y_ + 1650, mImage[mNum], true);
		break;
	}
	default:
		break;
	}

	DrawFormatString(0, 70, GetColor(0,0,255), "Chat:%d", mNum);

	
}

bool Chat::Release(void)
{
	return false;
}

bool Chat::Getflg()
{
	return mFlg;
}

int Chat::GetNum(void)
{
	return mSNum;
}



