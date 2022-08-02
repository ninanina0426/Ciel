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
	void DrawOwnScn() override;		//各シーンのDraw
	bool Init(void) override;
	SceneID GetSceneID(void) override;
	void Event(int num);
private:
	Player player_;
	int aitem_;
	uniquBaseScn gameScene_;


	bool flg_;		//イベントが終わった
	int Cnt;

	int mImageP[48];
	int mImagePD[27];
	int mImagePC[15];
	int mImageNC[10];
	int mImageN;

	//グラフィック系
	int airplan_[4][3];
	int sea_;
	int cloud_;
	int animcnt_;
	int house_;
	//ムービー系
	int move1_;
	int rany_;
	int kemuri_[4][3];

	//サウンド
	bool shFlg_;
	int rany;
	int li_;
};

