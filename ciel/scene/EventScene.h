#pragma once
#include "BaseScene.h"
class EventScene :
    public BaseScene
{
public:
	EventScene() {};
	EventScene(uniquBaseScn gameScene);
	~EventScene();


	uniquBaseScn Update(uniquBaseScn own)override;
	void DrawOwnScn() override;		//各シーンのDraw
	bool Init(void) override;
	SceneID GetSceneID(void) override;

private:
	uniquBaseScn gameScene_;
	bool flg_;		//イベントが終わった

	int move1_;
};

