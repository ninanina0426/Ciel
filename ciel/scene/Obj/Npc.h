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
	int mImage[16][16];		//�摜�̊i�[�̈�

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;

	NpcType mNpcType;

	Keyboard key_;

	int i;

	
public:
	Npc();
	~Npc();

	bool init(void);		//������
	Vector2 Update(Vector2 playerPos, Vector2 playerSize,bool flg);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
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

	int mPosBottom;	//�L�����N�^�[�̑�����Y���W
};

