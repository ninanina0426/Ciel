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
	MAP_ID GetSceneID(void) { return MAP_ID::SWEETSOUT; };

};

