#pragma once
#include "Stage.h"

class ForestMap :
    public Stage
{
public:
	ForestMap();
	~ForestMap();
private:
	void Update(Vector2 offset) override;
	 void DrawOwnScn() override;
	 bool Init(void)override;
	 int GetMapChip(Vector2 pos) override;
	 MAP_ID GetSceneID(void) { return MAP_ID::FOREST; };

	 int mMap1[MAP_Y][MAP_X];
	 int mMap2[MAP_Y][MAP_X];
	 int mMap3[MAP_Y][MAP_X];
	 int mMap4[MAP_Y][MAP_X];
};

