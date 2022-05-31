#pragma once
#include "Stage.h"

class CaveShop :
	public Stage
{
public:
	CaveShop();
	~CaveShop();

	MAP_ID mMapID;
	int mMap[MAP_Y][MAP_X];

private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void) override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	MAP_ID GetStageID(void) { return MAP_ID::CAVESHOP; };

	int layer1;
	int layer2;
	
};

