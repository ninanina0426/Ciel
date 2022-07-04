#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"

class Masuku
{
private:
	int mImage;
	int mImage2;
	int mImageChat;

	int i;
	bool mFlg;

	int mAnmMum;

	int Rantan;

	Vector2 mPos;
	Vector2 mSize;

	Keyboard key_;

public:
	Masuku();
	~Masuku();

	bool init(void);		//初期化
	void Update(Vector2 playerPos, int r);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放

	bool Flg();

};

