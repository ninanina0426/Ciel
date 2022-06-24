#pragma once
#include "BaseScene.h"
#include "Obj/Player.h"

class Aitem;

#define AirplneSize (32)

enum class EventType
{
	PROLOGUE,
	STORY_1,
	STORY_2,
	STORY_3,
	STORY_4,
	STORY_5,
};



class EventScene :
    public BaseScene
{
public:
	EventScene() {};
	EventScene(uniquBaseScn gameScene, PlayerID playerID, int aitem);
	~EventScene();


	uniquBaseScn Update(uniquBaseScn own)override;
	void DrawOwnScn() override;		//�e�V�[����Draw
	bool Init(void) override;
	SceneID GetSceneID(void) override;
	void Event(int num);
private:
	Player player_;
	int aitem_;
	uniquBaseScn gameScene_;
	bool flg_;		//�C�x���g���I�����

	//�O���t�B�b�N�n
	int airplan_[4][3];
	int sea_;
	int cloud_;
	int animcnt_;
	//���[�r�[�n
	int move1_;
};

