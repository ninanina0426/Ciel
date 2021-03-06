#pragma once
#include "Stage.h"
class templeMap :
    public Stage
{
public:
	templeMap();
	~templeMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos)override;
	int GetMapChip(Vector2 pos) override;
	int GetTMapChip(Vector2 pos)override;
	MAP_ID GetStageID(void) { return MAP_ID::TEMPLE; };

	/*int mMap1[MAP_Y][MAP_X];
	int mMap2[MAP_Y][MAP_X];
	int mMap3[MAP_Y][MAP_X];
	int mMap4[MAP_Y][MAP_X];
	int mMap5[MAP_Y][MAP_X];*/

	int obj1_;
	int wall_;
	int temple_;
	int pillar_;
	int soil_;

};


