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
	int mImage[16][16];		//�摜�̊i�[�̈�
	int mImage1[16][16];		//�摜�̊i�[�̈�
	int mImage2[16][16];		//�摜�̊i�[�̈�
	int mImage3[16][16];		//�摜�̊i�[�̈�
	int mImage4[16][16];		//�摜�̊i�[�̈�
	int mImage5[16][16];		//�摜�̊i�[�̈�
	int mImage6[16][16];		//�摜�̊i�[�̈�
	int mImage7[12][12];		//�摜�̊i�[�̈�
	


	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;

	NpcType mNpcType;

	NumType mNumType;

	Keyboard key_;

	int i;

	bool npcHit;

public:
	Npc();
	~Npc();

	bool init(void);		//������
	int Update(Vector2 playerPos, Vector2 playerSize,bool flg,int fis);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
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
	//�N�G�X�gon�Eoff�t���O
	bool qflg_ ;

	bool mQSmNpc1;

	bool mSoflg;

	int mPosBottom;	//�L�����N�^�[�̑�����Y���W
};

