#pragma once
#include "../BaseScene.h"

enum class Fede
{
	CrossOver,
	FadeInOut,
	Max
};
class TransitionScene :
	public BaseScene
{
public:
	TransitionScene(){};
	TransitionScene(uniquBaseScn beforScene, uniquBaseScn nextScene);
	TransitionScene(shareBaseScn beforScene, uniquBaseScn nextScene);
	~TransitionScene();
private:
	virtual bool UpdataTransition(void) = 0;
	SceneID GetSceneID() override;;
	uniquBaseScn Update(uniquBaseScn own) override;
	void DrawOwnScn(void)override {};
	bool Init(void) override;;


protected:
	uniquBaseScn beforScene_;
	uniquBaseScn nextScene_;

	shareBaseScn beforScene_S;
	

};

