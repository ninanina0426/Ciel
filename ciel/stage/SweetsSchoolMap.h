#pragma once
#include "Stage.h"
class SweetsSchoolMap :
    public Stage
{
public:
	SweetsSchoolMap();
	~SweetsSchoolMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos)override;
	MAP_ID GetSceneID(void) { return MAP_ID::SWEETSSCHOOL; };
};

