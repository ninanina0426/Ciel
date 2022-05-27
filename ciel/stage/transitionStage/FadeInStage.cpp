#include <DxLib.h>
#include "FadeInStage.h"

FadeInStage::FadeInStage(uniquStage beforStage, uniquStage nextStage):
    TraStage(std::move(beforStage),std::move(nextStage))
{
    count_ = 0;
    DrawOwnScn();
}

FadeInStage::~FadeInStage()
{
}

void FadeInStage::Update(Vector2 offset)
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
		beforStage_->Draw();
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_ - 255);
		nextStage_->Draw();
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
