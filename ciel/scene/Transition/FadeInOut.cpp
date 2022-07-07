#include <DxLib.h>
#include "FadeInOut.h"

FadeInOut::FadeInOut(uniquBaseScn beforScene, uniquBaseScn nextScene)
	:TransitionScene(std::move(beforScene), std::move(nextScene))
{
	count_ = 0;
	DrawOwnScn();
}

FadeInOut::~FadeInOut()
{
}

bool FadeInOut::UpdataTransition(void)
{
	DrawOwnScn();
	count_ += 5;



	return (count_ > 510);
}

void FadeInOut::DrawOwnScn(void)
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();
	if (count_<256)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - count_);
		beforScene_->Draw();
	}
	else
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_-255);
		nextScene_->Draw();
	}

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
