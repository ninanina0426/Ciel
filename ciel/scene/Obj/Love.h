#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
#include"../../stage/Stage.h"
#include"Player.h"

class Love
{
private:

	int mImage[48];		//�摜�̊i�[�̈�
	int mImageChat[100];	//

	int mImageF;
	
	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mPlayer;

	Keyboard key_;

	Vector2 mNum[100];		//�e�L������pos

	int chiID;

	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;

	//���ʉ�
	int sHandle;


	MAP_ID mapID;

	DIR keyDir;

	bool moveFlg;

	//�����蔻��
	bool hitflg;

	//��b

	//����
	int lApple;
	int lKinominoKusiyaki;
	int lFruitDrink;
	int lRice;
	int lDango;
	int lTea;
	int lFish;
	
	//�D���x
	int FR;

public:
	Love();
	~Love();

	bool init();		//������
	Vector2 Update(Vector2 playerPos, Vector2 playerSize,DIR playerDir,int num);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
	void SetDIR(DIR dir);
	Vector2 GetPos(void);

	bool Hit();
	bool MoveFR();

};

