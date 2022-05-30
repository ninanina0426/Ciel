#pragma once
#include "TraStage.h"
class FadeInStage :
    public TraStage
{
public:
	FadeInStage(uniquStage beforStage, uniquStage nextStage);
	~FadeInStage();
private:
	bool UpdataTrangetion(void) override;
	void DrawOwnScn(void) override;
	int count_;
};

