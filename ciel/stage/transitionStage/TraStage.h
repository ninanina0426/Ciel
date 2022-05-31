#pragma once
#include "../Stage.h"

enum class FadeStage
{
	FadeIn,
	Max
};

class TraStage
{
public:
	TraStage() {};
	//TraStage(uniquStage beforStage, uniquStage nextStage);
	 ~TraStage();
	 virtual bool UpdataTrangetion(void) = 0;
	 virtual void DrawOwnScn(void) = 0;
private:
	
	 void Update(uniquStage own);		
	 bool Init(void) ;

	 bool ChangeFlg_;
	
protected:
	/*uniquStage beforStage_;
	uniquStage nextStage_;*/
};

