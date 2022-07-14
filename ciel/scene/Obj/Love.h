#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
#include"../../stage/Stage.h"
#include"Player.h"

class Love
{
private:

	int mImage[48];		//画像の格納領域
	int mImageChat[100];	//

	int mImageF;
	
	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mPlayer;

	Keyboard key_;

	Vector2 mNum[100];		//各キャラのpos

	int chiID;

	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;

	//効果音
	int sHandle;


	MAP_ID mapID;

	DIR keyDir;

	bool moveFlg;

	//当たり判定
	bool hitflg;

	//会話

	//所持
	int lApple;
	int lKinominoKusiyaki;
	int lFruitDrink;
	int lRice;
	int lDango;
	int lTea;
	int lFish;
	
	//好感度
	int FR;

public:
	Love();
	~Love();

	bool init();		//初期化
	Vector2 Update(Vector2 playerPos, Vector2 playerSize,DIR playerDir,int num);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	void SetDIR(DIR dir);
	Vector2 GetPos(void);

	bool Hit();
	bool MoveFR();

};

