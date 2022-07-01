#pragma once
#include "Stage.h"

class SnowMap :
	public Stage
{
public:
	SnowMap();
	~SnowMap();

	MAP_ID mMapID;
	void SetMap(MAP_ID mapID);
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void) override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	int GetTMapChip(Vector2 pos)override;
	MAP_ID GetStageID(void) { return MAP_ID::SNOW; };

	int layer1;
	int layer2;
	int layer3;

};