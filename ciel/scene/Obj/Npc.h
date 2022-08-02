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
	NPC_5,
	NPC_6
};


class Npc
{
private:
	int mImage[16][16];		//画像の格納領域
	int mImage1[16][16];		//画像の格納領域
	int mImage2[16][16];		//画像の格納領域
	int mImage3[16][16];		//画像の格納領域
	int mImage4[16][16];		//画像の格納領域
	int mImage5[16][16];		//画像の格納領域
	int mImage6[16][16];		//画像の格納領域
	int mImage7[12][12];		//画像の格納領域
	


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

	bool npcHit;

public:
	Npc();
	~Npc();

	bool init(void);		//初期化
	int Update(Vector2 playerPos, Vector2 playerSize,bool flg,int fis);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);

	bool NpcHit();

	int Num();

	bool Getflg();

	bool GetQflg();

	bool mSoNpc1;
	bool mSoNpc2;

	bool mFmNpc1;
	bool mFmNpc2;
	bool mFmNpc3;
	bool mFmNpc4;
	bool mFmNpc5;
	bool mFmNpc6;

	bool mSmNpc1;

	bool mWmNpc1;
	bool mWsNpc1;

	bool mQSoNpc1;
	bool mQSoNpc2;

	bool mQWmNpc1;

	
	int qnum_;
	//クエストon・offフラグ
	bool qflg_ ;

	bool mQSmNpc1;

	bool mSoflg;

	int mPosBottom;	//キャラクターの足元のY座標
};

