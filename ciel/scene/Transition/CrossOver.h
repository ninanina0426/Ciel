#pragma once
#include "TransitionScene.h"

class CrossOver :
	public TransitionScene
{
public:
	CrossOver(uniquBaseScn beforScene, uniquBaseScn nextScene);
	~CrossOver();
private:
	bool UpdataTransition(void) override;;
	void DrawOwnScn(void) override;;
	int count_;
};

