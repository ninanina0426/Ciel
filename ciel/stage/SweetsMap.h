#pragma once
#include "Stage.h"


class SweetsMap :
    public Stage
{
public:
	SweetsMap();
	~SweetsMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	MAP_ID GetSceneID(void) { return MAP_ID::SWEETS; };

};

