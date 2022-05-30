#pragma once
#include "Stage.h"



class ForestInMap :
    public Stage
{
public:
	ForestInMap();
	~ForestInMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos)override;
	int GetMapChip(Vector2 pos) override;
	MAP_ID GetStageID(void) { return MAP_ID::FORESTIN; };


	

	int soil;
	int tree;
	int obj1;

};

