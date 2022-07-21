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

	mImage[8] = LoadGraph("image/talk/temple.png");
	mImage[9] = LoadGraph("image/talk/temple.png");
	mImage[10] = LoadGraph("image/talk/temple.png");
	mImage[11] = LoadGraph("image/talk/temple.png");
	mImage[12] = LoadGraph("image/talk/temple.png");
	mImage[13] = LoadGraph("image/talk/temple.png");

	mImage[15] = LoadGraph("image/talk/temple.png");
	mImage[16] = LoadGraph("image/talk/temple.png");
	mImage[17] = LoadGraph("image/talk/3.png");
	mImage[18] = LoadGraph("image/talk/3.png");

	mImage[30] = LoadGraph("image/talk/30.png");
	mImage[31] = LoadGraph("image/talk/temple.png");
	mImage[32] = LoadGraph("image/talk/temple.png");
	mImage[33] = LoadGraph("image/talk/temple.png");
	mImage[34] = LoadGraph("image/talk/temple.png");
	mImage[35] = LoadGraph("image/talk/35.png");
	mImage[36] = LoadGraph("image/talk/temple.png");
	mImage[37] = LoadGraph("image/talk/temple.png");
	mImage[38] = LoadGraph("image/talk/temple.png");
	mImage[39] = LoadGraph("image/talk/temple.png");
	mImage[40] = LoadGraph("image/talk/40.png");
	mImage[41] = LoadGraph("image/talk/temple.png");
	mImage[42] = LoadGraph("image/talk/temple.png");
	mImage[43] = LoadGraph("image/talk/temple.png");
	mImage[44] = LoadGraph("image/talk/temple.png");
	mImage[45] = LoadGraph("image/talk/45.png");
	mImage[46] = LoadGraph("image/talk/temple.png");
	mImage[47] = LoadGraph("image/talk/temple.png");
	mImage[48] = LoadGraph("image/talk/temple.png");
	mImage[49] = LoadGraph("image/talk/temple.png");
	mImage[50] = LoadGraph("image/talk/50.png");
	mImage[51] = LoadGraph("image/talk/temple.png");
	mImage[52] = LoadGraph("image/talk/temple.png");
	mImage[53] = LoadGraph("image/talk/temple.png");
	mImage[54] = LoadGraph("image/talk/temple.png");
	mImage[55] = LoadGraph("image/talk/55.png");
	mImage[56] = LoadGraph("image/talk/temple.png");
	mImage[57] = LoadGraph("image/talk/temple.png");
	mImage[58] = LoadGraph("image/talk/temple.png");
	mImage[59] = LoadGraph("image/talk/temple.png");
	mImage[60] = LoadGraph("image/talk/temple.png");


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

	/*if (mNum == 100)
	{
		mNum = num - 1;
	}*/

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
				mNum = num - 1;
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
		case 8:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 13)
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
					mNum = 29;
				}

				if (mNum == 18)
				{
					mFlg = false;
					mNum = 0;

				}
			}

			if (wPose == true)
			{
				if (mNum == 29)
				{
					mNum = 29;
					mSNum = 29;
				}
				if (wshopFlg == false)
				{
					if (mNum == 17)
					{
						mNum = 29;
					}
				}
			}
			else
			{
				if (wshopFlg == true)
				{
					if (mNum == 29)
					{
						mNum = 17;
					}
				}

			}
			
		}
		break;
		case 30:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 34)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 35:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 39)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 40:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 44)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 45:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 49)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 50:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 54)
				{
					mFlg = false;
					mNum = 0;

				}

			}
		}
		break;
		case 55:
		{

			if (mNum == 100)
			{
				mNum = num - 1;
			}
			if (key_.getKeyDown(KEY_INPUT_F) && (mNum != 100))
			{

				mNum += 1;
				if (mNum == 59)
				{
					mFlg = false;
					mNum = 0;

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
		DrawGraph(mPos.x_ - offset.x_ + 1305, mPos.y_ - offset.y_ + 555 - 50, mImage[mNum], true);
		break;
	}
	case 4:
	{
		DrawGraph(mPos.x_ - offset.x_ + 750, mPos.y_ - offset.y_ + 1100 - 50, mImage[mNum], true);
		break;
	}
	case 8:
	{
		DrawGraph(mPos.x_ - offset.x_ + 1305, mPos.y_ - offset.y_ + 555 - 50, mImage[mNum], true);
		break;
	}
	case 15:
	{
		DrawGraph(mPos.x_ - offset.x_ + 1750, mPos.y_ - offset.y_ + 1650 - 50, mImage[mNum], true);
		break;
	}
	case 30:
	{
		DrawGraph(mPos.x_ - offset.x_ + 1535-32, mPos.y_ - offset.y_ + 2145-128 - 50, mImage[mNum], true);
		break;
	}
	case 35:
	{
		DrawGraph(mPos.x_ - offset.x_ + 286 - 32, mPos.y_ - offset.y_ + 1918 - 128 - 50, mImage[mNum], true);
		break;
	}
	case 40:
	{
		DrawGraph(mPos.x_ - offset.x_ + 128 - 32, mPos.y_ - offset.y_ + 800 - 128 - 50, mImage[mNum], true);
		break;
	}
	case 45:
	{
		DrawGraph(mPos.x_ - offset.x_ + 2879 - 32, mPos.y_ - offset.y_ + 769 - 128 - 50, mImage[mNum], true);
		break;
	}
	case 50:
	{
		DrawGraph(mPos.x_ - offset.x_ + 2400 - 32, mPos.y_ - offset.y_ + 100 - 128 - 50, mImage[mNum], true);
		break;
	}
	case 55:
	{
		DrawGraph(mPos.x_ - offset.x_ + 2591 - 32, mPos.y_ - offset.y_ + 129 - 128 - 50, mImage[mNum], true);
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



