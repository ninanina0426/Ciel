#pragma once
#include "Stage.h"

class ForestMap :
    public Stage
{
public:
	ForestMap();
	~ForestMap();

	void SetMap(MAP_ID mapID);
	MAP_ID mMapID;
private:
	void Update(Vector2 offset) override;
	 void DrawOwnScn() override;
	 bool Init(void)override;
	 bool CheckMapChip(Vector2 pos)override;
	 int GetMapChip(Vector2 pos) override;
	 MAP_ID GetStageID(void) { return MAP_ID::FOREST; };

	 int mMap1[MAP_Y][MAP_X];
	 int mMap2[MAP_Y][MAP_X];
	 int mMap3[MAP_Y][MAP_X];
	 int mMap4[MAP_Y][MAP_X];
	 int BGM_;
};

