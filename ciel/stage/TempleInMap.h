#pragma once
#include "Stage.h"
class Player;

class TempleInMap :
    public Stage
{
public:
	TempleInMap();
	~TempleInMap();
private:
	void Update(Vector2 offset) override;
	void DrawOwnScn() override;
	bool Init(void)override;
	bool CheckMapChip(Vector2 pos)override;
	int GetMapChip(Vector2 pos) override;
	MAP_ID GetStageID(void) { return MAP_ID::TEMPLEIN; };

	Player* mPlayer;
};

