#pragma once
#include "Stage.h"
#include"../scene/Input/Keyboard.h"
#include"../scene/Obj/Player.h"


class SweetsMap :
    public Stage
{
public:
	SweetsMap();
	~SweetsMap();

	MAP_ID mMapID;
	int mMap[MAP_Y][MAP_X];
	
	

private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	int GetTMapChip(Vector2 pos)override;
	MAP_ID GetStageID(void) { return MAP_ID::SWEETS; };

	Player mPlayer;

	Keyboard key_;

	int x;

	int layer1;
	int layer2;
	int layer3;
	int layer4;

};

