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
	void DrawOwnScn() override;		//�e�V�[����Draw
	bool Init(void) override;
	SceneID GetSceneID(void) override;

private:
	uniquBaseScn gameScene_;
	bool flg_;		//�C�x���g���I�����

	int move1_;
};

