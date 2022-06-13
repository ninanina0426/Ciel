#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"

#define ITEM_ANIM_MAX 3




class Aitem
{
public:
	Aitem();
	~Aitem();

	bool init(void);		//������
	Vector2 Update(Vector2 playerPos, Vector2 playerSize);		//�X�V
	void Draw(Vector2 mMapoffset);		//�`��
	bool Release(void);		//�J��
	Vector2 GetSize(void);
	Vector2 GetPos(void);

	int Num();

	bool Getflg();

	int mAitem;
	

private:

	Vector2 mSize;
	int mImage[DIR_MAX][ITEM_ANIM_MAX];
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W

	int ItemAnimcount;

	Keyboard key_;

	Vector2 mNum[100];

	int i;
};

