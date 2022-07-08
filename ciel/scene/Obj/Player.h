#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
#include"../../stage/Stage.h"


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

//体力系定数
constexpr int STAMINA = 500;
constexpr int ENERGY = 100;

class Player
{
private:
	

	/*GameScene* mParent;*/
	/*GameScene* mParent;*/

	int mImage1[48];		//画像の格納領域
	int mImage2[48];		//画像の格納領域
	int mImage3[48];		//画像の格納領域

	int mImageTI[24];		//画像の格納領域
	int mImageTS[24];		//画像の格納領域

	int mImageC[27];		//
	int mImageI[27];		//
	int mImageS[27];		//
	int mImageChat[100];	//

	int mImageF;
	//int mImage4[32];		//画像の格納領域
	//int mImage5[32];		//画像の格納領域
	//int mImage6[32];		//画像の格納領域

	DIR mMoveDir;		//キャラクターの向き
	Vector2 mPos;		//キャラクターの地図上の座標
	Vector2 mPlayer;

	Keyboard key_;
	
	int i;
	int num;
	int move;

	int tCnt;
	int ttCnt;

	bool moveAnmCnt;

	//釣り
	bool moveFlg;
	//浅瀬
	bool mFlg;
	//つるはし
	bool tFlg;

	int mChipId;
	int mChiID;

	Vector2 mDamyPos;

	Vector2 mSizeOffset;//キャラクターのオフセットサイズ　　半分の値
	Vector2 mSize;		//キャラクター画像のサイズ
	int mMoveSpeed;		//キャラクター移動スピード
	int mAnmCnt;

	//効果音
	int sHandle;
	int tHandle;
	int fHandle;
	int oHandle;
	int ttHandle;

	//ギミック
	Vector2 mgPos;
	Vector2 mgSize;
	bool gFlg;
	MAP_ID mapID;

	void message_box();

	DIR keyDir;

public:
	Player();
	~Player();

	int mPosBottom;	//キャラクターの足元のY座標

	bool flg;

	bool init(PlayerID playerid);		//初期化
	Vector2 Update(int chipid);		//更新
	void Draw(Vector2 offset);		//描画
	bool Release(void);		//開放
	DIR GetDIR(void);
	void SetDIR(DIR dir);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);

	int GetStamina(void);

	int Stamina_;		//スタミナ管理
	int Energy_;		//エネルギー管理
	bool staminaFlg_;	//スタミナのフラグ
	int staminacnt_;

	bool qflg_;
	

	PL_ST state_;
	PlayerID plID_;
	
};


