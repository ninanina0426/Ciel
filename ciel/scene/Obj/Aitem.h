#pragma once
#include "../../common/Vector2.h"


#define ITEM_ANIM_MAX 3

enum DIR_A		//向き管理用
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

	bool init(void);		//初期化
	Vector2 Update(void);		//更新
	void Draw(Vector2 mMapoffset);		//描画
	bool Release(void);		//開放
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
	Vector2 mPos;		//キャラクターの地図上の座標

	int ItemAnimcount;
};

