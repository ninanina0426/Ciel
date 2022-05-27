#pragma once
#include "../Stage.h"

enum class FadeStage
{
	FadeIn,
	Max
};
class TraStage:
	Stage
{
public:
	TraStage() {};
	TraStage(uniquStage beforStage, uniquStage nextStage);
	 ~TraStage();
private:
	 //void Update(Vector2 offset) override;
	 virtual bool UpdataTrangetion(void) = 0;
	 uniquStage Update(uniquStage own);
	 //void DrawOwnScn() override;		
	 bool Init(void) override;
	 bool CheckMapChip(Vector2 pos) override;  
	 int GetMapChip(Vector2 pos) override;
	 MAP_ID GetStageID(void) override;
protected:
	uniquStage beforStage_;
	uniquStage nextStage_;
};

