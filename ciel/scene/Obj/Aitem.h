#pragma once
#include "../../common/Vector2.h"


#define ITEM_ANIM_MAX 3

enum DIR_A		//�����Ǘ��p
{
	DIR_A_UP,
	DIR_A_RIGHT,
	DIR_A_DOWN,
	DIR_A_LEFT,
	DIR_A_MAX
};


class Aitem
{
public:
	Aitem();
	~Aitem();

	bool init(void);		//������
	Vector2 Update(void);		//�X�V
	void Draw(Vector2 mMapoffset);		//�`��
	bool Release(void);		//�J��
	Vector2 GetSize(void);

	bool mKami1;
	bool mKami2;
	bool mKami3;
	bool mKami4;
	bool mKami5;

	bool mTma;
	bool mMasinngan;
	bool mHoutai;
	bool mHeal;
	bool mKey;
	bool mbook;
	bool mMagazinn;



private:

	Vector2 mSize;
	int mImage[DIR_A_MAX][ITEM_ANIM_MAX];
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W

	int ItemAnimcount;
};

