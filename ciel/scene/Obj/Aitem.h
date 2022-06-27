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

	bool init(void);		//初期化
	Vector2 Update(Vector2 playerPos, Vector2 playerSize);		//更新
	void Draw(Vector2 mMapoffset);		//描画
	bool Release(void);		//開放
	Vector2 GetSize(void);
	Vector2 GetPos(void);

	int Money(int ru,bool flg);

	int wMoney(int ru, bool flg);

	int HaveMoney();

	void TotalAitem(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h, int sa, int skk, int sfd, int sfrs, int srb, int sp, int sk, int sr, int sh);


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

	//拾った判定
	bool mGet;

	int GetmKinomi(void);

	//shopに飛ばす
	int KnomiNum(void);
	int AppleNum(void);
	int KinominoKusiyakiNum(void);
	int FruitDrinkNum(void);
	int FishingRodSNum(void);
	int RagBagNum(void);
	int PickaxeNum(void);
	int mHaoriNum(void);
	int mRantanNum(void);
	int RiceNum(void);
	int DangoNum(void);
	int TeaNum(void);

	int GetTam(void);

	int mAitem;

	bool GetAitem();

private:

	Vector2 mSize;
	int mImage[DIR_MAX][ITEM_ANIM_MAX];
	Vector2 mPos;		//キャラクターの地図上の座標

	int ItemAnimcount;

	Keyboard key_;

	Vector2 mNum[100];

	int i;

	shop* mShop;

	//所持
	int mApple;
	int mKinominoKusiyaki;
	int mFruitDrink;
	int mFishingRodS;
	int mRagBag;
	int mPickaxe;
	int mHaoriN;
	int mRantanN;
	int mNumKinomi;
	int mRice;
	int mDango;
	int mTea;

	int Ru;
	int ssRu;
	int wwRu;

};

