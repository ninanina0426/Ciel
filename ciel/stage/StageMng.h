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
	void Update(Vector2 mPlayerset);
	bool Release(void);
	int GetMapChipMng(Vector2 pos);
	bool cheakMapChip(Vector2 pos);
	void GetEvent(Vector2 pos);
	Vector2 mOffset;
	MAP_ID mMapID;
	int mChipImage[10000];
private:
	StageMng();
	~StageMng();

	Player* mPlayer;

	uniquStage stage_;		//ステージ管理

	 //マップの変更処理
	bool mMapChange;
	MAP_ID mNextMapID;
	Vector2 mNextPos;

	friend Stage;
};

