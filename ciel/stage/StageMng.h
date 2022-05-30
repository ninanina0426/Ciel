#pragma once
#include <DxLib.h>
#include "../common/Vector2.h"
#include"../scene/Obj/Player.h"
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
	Vector2 Update(Vector2 mPlayerset);
	bool Release(void);
	int GetMapChipMng(Vector2 pos);
	bool cheakMapChip(Vector2 pos);
	bool GetEvent(Vector2 pos);
	Vector2 mOffset;
	MAP_ID mMapID;
	DIR mDir;

	int mChipId;

	int mChipImage[10000];
	bool mMapChange;
	DIR GetDir(void);

	Vector2 GetPos(void);
	MAP_ID GetMapId(void);
private:
	StageMng();
	~StageMng();

	Player mPlayer;

	uniquStage stage_;		//ステージ管理

	

	 //マップの変更処理

	MAP_ID mNextMapID;
	Vector2 mNextPos;

	bool flg;

	friend Stage;
};

