#pragma once
#include "Stage.h"


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
	MAP_ID GetSceneID(void) { return MAP_ID::SWEETS; };

	int layer1;
	int layer2;
	int layer3;
	int layer4;

};

