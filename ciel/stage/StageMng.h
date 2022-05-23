#pragma once
#include <DxLib.h>
#include "../common/Vector2.h"
#include "Stage.h"

class Player;

#define lpMapMng StageMng::GetInstance()


class StageMng
{
public:
	static StageMng& GetInstance()
	{
		static StageMng s_Instance;
		return s_Instance;
	}
	
	bool Init();
	void Draw();
	void Update(void);
	bool Release(void);
	
	Vector2 mOffset;
	MAP_ID mMapID;
	int mMap[MAP_Y][MAP_X];
	int mChipImage[10000];
	int GetMapChip(Vector2 pos);
private:
	StageMng();
	~StageMng();

	Player* mPlayer;

	uniquStage stage_;		//ステージ管理

	friend Stage;
};

