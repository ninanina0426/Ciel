#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"


enum class NpcType
{
	CM_NPC,
	CS_NPC,
	DT_NPC,
	FI_NPC,
	FM_NPC,
	SM_NPC,
	SO_NPC,
	SS_NPC,
	TI_NPC,
	TM_NPC,
	WM_NPC,
	WS_NPC
};


class Npc
{
private:
	int mImage[16][16];		//画像の格納領域

	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;

	NpcType mNpcType;

	Keyboard key_;

	int i;

	
public:
	Npc();
	~Npc();

	bool init(void);		//初期化
	Vector2 Update(Vector2 playerPos, Vector2 playerSize,bool flg);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);

	int Num();

	bool Getflg();

	bool mCmflg;
	bool mCsflg;
	bool mDtflg;
	bool mFiflg;
	bool mFmflg;
	bool mSmflg;
	bool mSoflg;
	bool mSsflg;
	bool mTiflg;
	bool mTmflg;
	bool mWmflg;
	bool mWsflg;

	int mPosBottom;	//キャラクターの足元のY座標
};

