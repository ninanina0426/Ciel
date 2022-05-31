#include <DxLib.h>
#include "FadeInStage.h"

FadeInStage::FadeInStage()
{
    count_ = 0;
    DrawOwnScn();
}

FadeInStage::~FadeInStage()
{
}

bool FadeInStage::UpdataTrangetion(void)
{
	DrawOwnScn();
	count_ += 5;

	return (count_ > 510);
}

void FadeInStage::DrawOwnScn(void)
{
	SetDrawScreen(DX_SCREEN_BACK);
	ClsDrawScreen();
	if (count_ < 256)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - count_);
		DrawBox(0, 0, 1080, 609, 0x000000, true);
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_ - 255);
		//DrawBox(0, 0, 1080, 609, 0x000000, true);
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
