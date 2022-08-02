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

	bool moveFlg;

	bool Rantan0;

	Vector2 mPos;
	Vector2 mSize;

	Keyboard key_;

public:
	Masuku();
	~Masuku();

	bool init(void);		//‰Šú‰»
	void Update(Vector2 playerPos, int r, int ra);		//XV
	void Draw(Vector2 offset);		//•`‰æ
	bool Release(void);		//ŠJ•ú

	bool Flg();

	bool MoveFlg();
};

