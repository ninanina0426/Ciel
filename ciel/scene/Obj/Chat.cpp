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

	mImage[1] = LoadGraph("image/talk/1.png");
	mImage[2] = LoadGraph("image/talk/2.png");
	mImage[3] = LoadGraph("image/talk/3.png");
	mImage[4] = LoadGraph("image/talk/4.png");

	mNum = 0;

	mFlg = false;
	finalC_ = false;

	mNpc = new Npc();

	return true;
}

bool Chat::Update(bool flg, int num)
{
	mFlg = flg;

	key_.Update();

	if (mFlg ==true)
	{
		if (mNum == 0)
		{
			mNum = num;
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			mNum += 1;
			if (mNum ==4)
			{
				mFlg = false;
				finalC_ = true;
				mNum = 0;
			}
			
		}
	}

	return mFlg;
}

void Chat::Draw(Vector2 offset)
{
	DrawGraph(mPos.x_ - offset.x_  + 1305, mPos.y_ - offset.y_ + 555, mImage[mNum], true);
}

bool Chat::Release(void)
{
	return false;
}

