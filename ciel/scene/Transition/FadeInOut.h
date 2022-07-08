#pragma once
#include "TransitionScene.h"

class FadeInOut :
	public TransitionScene
{
public:
	FadeInOut(uniquBaseScn beforScene, uniquBaseScn nextScene);
	FadeInOut(shareBaseScn beforScene, uniquBaseScn nextScene);
	~FadeInOut();
private:
	bool UpdataTransition(void) override;;
	void DrawOwnScn(void) override;
	int count_;

	bool flg_;
};

