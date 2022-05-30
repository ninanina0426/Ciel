#pragma once
#include "Stage.h"


class WaMap :
	public Stage
{
public:
	WaMap();
	~WaMap();

	void SetMap(MAP_ID mapID);
	MAP_ID mMapID;


private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos) override;
	int GetMapChip(Vector2 pos) override;
	MAP_ID GetSceneID(void) { return MAP_ID::WA; };

	int layer1;
	int layer2;
	int layer3;
	int layer4;
};

