#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
#include"Player.h"
class shop;

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

	int Money(int ru,bool flg);



	bool mTama1;
	bool mTama2;
	bool mTama3;
	bool mTama4;
	bool mTama5;

	bool mKinomi1;
	bool mKinomi2;
	bool mKinomi3;
	bool mKinomi4;
	bool mKinomi5;

	

	
	bool mHaori;

	bool mRantan;

	int Num();

	bool Getflg();


	int mTama;
	int mKinomi;

	//�E��������
	bool mGet;

	int GetmKinomi(void);

	//shop�ɔ�΂�
	int KnomiNum(void);
	int AppleNum(void);
	int KinominoKusiyakiNum(void);
	int FruitDrinkNum(void);
	int FishingRodSNum(void);
	int RagBagNum(void);
	int PickaxeNum(void);
	int mHaoriNum(void);
	int mRantanNum(void);

	int mAitem;

	bool GetAitem();

private:

	Vector2 mSize;
	int mImage[DIR_MAX][ITEM_ANIM_MAX];
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W

	int ItemAnimcount;

	Keyboard key_;

	Vector2 mNum[100];

	int i;

	shop* mShop;

	//����
	int mApple;
	int mKinominoKusiyaki;
	int mFruitDrink;
	int mFishingRodS;
	int mRagBag;
	int mPickaxe;
	int mHaoriN;
	int mRantanN;
	int mNumKinomi;

	int Ru;

};

