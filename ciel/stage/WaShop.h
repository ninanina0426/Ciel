#pragma once
#include "Stage.h"

class WaShop :
	public Stage
{
public:
	WaShop();
	~WaShop();

	MAP_ID mMapID;
	int mMap[MAP_Y][MAP_X];

private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void) override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	int GetTMapChip(Vector2 pos)override;
	MAP_ID GetStageID(void) { return MAP_ID::WASHOP; };

	int layer1;
	int layer2;
	
	
};

