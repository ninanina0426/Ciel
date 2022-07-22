#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
class Npc;

class Chat
{
private:
	int mImage[100];
	int mNum;

	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	int mAnmCnt;

	bool mFlg;

	bool finalC_;
	int mNumType;

	Keyboard key_;

	Npc*mNpc;

	int mSNum;

	bool shopFlg;
	bool wshopFlg;
public:
	Chat();
	~Chat();

	bool GetfinalC(void);
	bool init(void);		//������
	bool Update(bool flg,int num,bool sflg, bool sPose, bool wflg, bool wPose);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��

	bool Getflg();

	int GetNum(void);
	
};

