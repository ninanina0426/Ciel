#pragma once
#include "Stage.h"
class SweetsOutMap :
    public Stage
{
public:
	SweetsOutMap();
	~SweetsOutMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos)override;
	int GetMapChip(Vector2 pos) override;
	int GetTMapChip(Vector2 pos)override;
	MAP_ID GetStageID(void) { return MAP_ID::SWEETSOUT; };

	int layer1;
	int layer2;
	int layer3;
	
};

