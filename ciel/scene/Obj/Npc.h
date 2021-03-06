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
	WS_NPC,
	SN_NPC,
	SNC_NPC,
	SNS_NPC
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
	int mImage[16][16];		//æÌi[Ìæ
	int mImage1[16][16];		//æÌi[Ìæ
	int mImage2[16][16];		//æÌi[Ìæ
	int mImage3[16][16];		//æÌi[Ìæ
	int mImage4[16][16];		//æÌi[Ìæ
	int mImage5[16][16];		//æÌi[Ìæ
	int mImage6[16][16];		//æÌi[Ìæ
	int mImage7[12][12];		//æÌi[Ìæ
	


	DIR mMoveDir;		//LN^[Ìü«
	Vector2 mPos;		//LN^[Ìn}ãÌÀW
	Vector2 mSizeOffset;//LN^[ÌItZbgTCY@@¼ªÌl
	Vector2 mSize;		//LN^[æÌTCY
	int mMoveSpeed;		//LN^[Ú®Xs[h
	int mAnmCnt;

	NpcType mNpcType;

	NumType mNumType;

	Keyboard key_;

	int i;

	bool npcHit;

public:
	Npc();
	~Npc();

	bool init(void);		//ú»
	int Update(Vector2 playerPos, Vector2 playerSize,bool flg,int fis);		//XV
	void Draw(Vector2 offset);		//`æ
	bool Release(void);		//Jú
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
	//NGXgonEofftO
	bool qflg_ ;

	bool mQSmNpc1;

	bool mSoflg;

	int mPosBottom;	//LN^[Ì«³ÌYÀW
};

