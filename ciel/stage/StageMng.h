#pragma once
#include <DxLib.h>
#include "../common/Vector2.h"
#include"../scene/Obj/Player.h"
#include"../scene/Input/Keyboard.h"
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
	Vector2 Update(Vector2 mPlayerset);
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
	bool mMapChange;;
	DIR GetDir(void);

	Vector2 GetPos(void);
	MAP_ID GetMapId(void);
	MAP_ID GetMapIdOld(void);

	int GetChipId(void);

private:
	StageMng();
	~StageMng();

	Player mPlayer;

	uniquStage stage_;		//�X�e�[�W�Ǘ�

	Vector2 movePos;

	Vector2 OldPos;

	Keyboard key_;

	int chipID;

	 //�}�b�v�̕ύX����

	MAP_ID mNextMapID;
	Vector2 mNextPos;

	friend Stage;
};

