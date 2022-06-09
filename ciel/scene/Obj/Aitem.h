#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"

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

	int Num();

	bool Getflg();

	int mAitem;
	

private:

	Vector2 mSize;
	int mImage[DIR_MAX][ITEM_ANIM_MAX];
	Vector2 mPos;		//キャラクターの地図上の座標

	int ItemAnimcount;

	Keyboard key_;

	Vector2 mNum[100];

	int i;
};

