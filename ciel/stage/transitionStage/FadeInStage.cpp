#include <DxLib.h>
#include "FadeInStage.h"

FadeInStage::FadeInStage()
{
    count_ = 0;
	Init();
    DrawOwnScn();
}

FadeInStage::~FadeInStage()
{
	
}

bool FadeInStage::UpdataTrangetion(void)
{
	if (count_ > 510)
	{
		count_ = 0;
		cnt_ = 0;
	}
	DrawOwnScn();
	
	count_ += 5;
	if (flg_)
	{
		cnt_ +=5;
	}
	return (count_ > 510);
}

void FadeInStage::Init()
{
	id_ = LoadGraph("./image/fade.png");
	count_ = 0;
	flg_ = false;
}

void FadeInStage::DrawOwnScn(void)
{
	/*SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();*/
	//DrawGraph(0, 0, id_, false);
	if (count_ < 256)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
		DrawGraph(0, 0, id_, false);
		
	}
	else
	{
		flg_ = true;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255- cnt_);
		DrawGraph(0, 0, id_, false);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

int FadeInStage::GetCnt(void)
{
	return count_;
}

void FadeInStage::Setcnt(int num)
{
	count_ = num;
	cnt_ = num;
}



