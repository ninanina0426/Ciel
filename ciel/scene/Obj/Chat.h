#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
class Npc;

class Chat
{
private:
	int mImage[100];
	int mNum;

	Vector2 mPos;		//キャラクターの地図上の座標
	int mAnmCnt;

	bool mFlg;

	bool finalC_;
	int mNumType;

	Keyboard key_;

	Npc*mNpc;

	int mSNum;

	bool shopFlg;
public:
	Chat();
	~Chat();

	bool GetfinalC(void);
	bool init(void);		//初期化
	bool Update(bool flg,int num,bool sflg, bool sPose);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放

	bool Getflg();

	int GetNum(void);
};

