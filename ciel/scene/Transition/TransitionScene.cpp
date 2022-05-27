#include <DxLib.h>
#include "TransitionScene.h"


TransitionScene::TransitionScene(uniquBaseScn beforScene, uniquBaseScn nextScene)
{
	beforScene_ = std::move(beforScene);
	nextScene_ = std::move(nextScene);
}

TransitionScene::~TransitionScene()
{
}

uniquBaseScn TransitionScene::Update(uniquBaseScn own)
{
	
	if (UpdataTransition())
	{
		return std::move(nextScene_);
	}
		
	return std::move(own);
}

SceneID TransitionScene::GetSceneID()
{
	return SceneID::TRANSTION;
}

bool TransitionScene::Init()
{
	return true;
}
