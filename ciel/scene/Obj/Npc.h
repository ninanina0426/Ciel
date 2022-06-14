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

enum class NumType
{
	NPC_1,
	NPC_2,
	NPC_3,
	NPC_4,
	NPC_5
};


class Npc
{
private:
	int mImage[16][16];		//画像の格納領域
	int mImage1[16][16];		//画像の格納領域
	int mImage2[16][16];		//画像の格納領域

	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;

	NpcType mNpcType;

	NumType mNumType;

	Keyboard key_;

	int i;

public:
	Npc();
	~Npc();

	bool init(void);		//初期化
	int Update(Vector2 playerPos, Vector2 playerSize,bool flg);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);

	int Num();

	bool Getflg();

	bool GetQflg();

	bool mSoNpc1;
	bool mSoNpc2;

	bool mSmNpc1;

	bool mQSoNpc1;
	bool mQSoNpc2;

	bool mQSmNpc1;

	int mPosBottom;	//キャラクターの足元のY座標
};

