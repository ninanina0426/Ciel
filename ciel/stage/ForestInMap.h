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
	MAP_ID GetSceneID(void) { return MAP_ID::FORESTIN; };
};

