#include <DxLib.h>
#include "CrossOver.h"

CrossOver::CrossOver(uniquBaseScn beforScene, uniquBaseScn nextScene)
	:TransitionScene( std::move(beforScene), std::move(nextScene))
{
	count_ = 0;
	DrawOwnScn();

}

CrossOver::~CrossOver()
{
}

bool CrossOver::UpdataTransition(void)
{
	DrawOwnScn();
	/*count_++;
	if (count_ >= 254)
	{
		return true;
	}
	return false;*/
	return (++count_ > 255);//”äŠr‰‰ŽZŽq
}

void CrossOver::DrawOwnScn(void)//crosover
{
	SetDrawScreen(sceneScrID_);
	ClsDrawScreen();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - count_);
	beforScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
	nextScene_->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
