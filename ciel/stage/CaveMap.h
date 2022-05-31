#pragma once
#include "Stage.h"

class CaveMap :
	public Stage
{
public:
	CaveMap();
	~CaveMap();

	MAP_ID mMapID;
	void SetMap(MAP_ID mapID);
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void) override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	MAP_ID GetStageID(void) { return MAP_ID::CAVE; };

	int layer1;
	int layer2;
	int layer3;
	
};
