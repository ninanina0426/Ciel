#pragma once
#include <DxLib.h>
#include "../common/Vector2.h"
#include"../scene/Obj/Player.h"
#include"../scene/Input/Keyboard.h"
#include "transitionStage/FadeInStage.h"
#include "Stage.h"


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
	Vector2 Update(Vector2 mPlayerset,int ai,bool flg,bool keyf,int tamaFlg);
	bool Release(void);
	int GetMapChipMng(Vector2 pos);
	bool cheakMapChip(Vector2 pos);
	bool GetEvent(Vector2 pos);
	bool GetMapChange(Vector2 pos);
	Vector2 mOffset;
	MAP_ID mMapOldID;
	MAP_ID mMapID;
	DIR mDir;

	int mChipId;
	int mTchipId;

	int mChipImage[10000];
	bool mMapChange;

	bool fadeinFlg_;
	DIR GetDir(void);

	Vector2 GetPos(void);
	MAP_ID GetMapId(void);
	MAP_ID GetMapIdOld(void);

	int GetChipId(void);
	int GetChipID(void);
	int GetDamage(void);
	

	bool qeopd_ = false;
	bool Tama_Use[6];		//菓　和　森　洞　雪
private:
	StageMng();
	~StageMng();

	Player mPlayer;

	uniquStage stage_;		//ステージ管理
	FadeInStage fadein_;
	bool fl_;
	int id_;

	Vector2 movePos;

	Vector2 OldPos;

	Keyboard key_;

	int chipID;

	int Damage_;

	 //マップの変更処理

	MAP_ID mNextMapID;
	Vector2 mNextPos;
	int aitem;
	bool mflg;
	bool opendir_;
	bool follFlag_;
	int damCnt_;
	bool keyFlag_;

	bool flyMap[5];
	int Tama_;
	
	bool back;

	friend Stage;
};

