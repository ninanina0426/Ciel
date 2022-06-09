#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"


enum DIR		//向き管理用
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

//キャラ状態
enum class PL_ST
{
	NON,		//キャラ未選択
	ALIVE,		//生存
	MAX
};

//キャラ種類
enum class PlayerID
{
	iti,
	Calendula,
	Soy,
	Max
};

class Player
{
private:
	

	/*GameScene* mParent;*/
	/*GameScene* mParent;*/

	int mImage1[16];		//画像の格納領域
	int mImage2[16];		//画像の格納領域
	int mImage3[16];		//画像の格納領域

	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mPlayer;

	Keyboard key_;
	

	Vector2 mDamyPos;

	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;
public:
	Player();
	~Player();

	int mPosBottom;	//キャラクターの足元のY座標

	bool flg;

	bool init(PlayerID playerid);		//初期化
	Vector2 Update(void);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	void SetDIR(DIR dir);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);

	PL_ST state_;
	PlayerID plID_;
	
};

