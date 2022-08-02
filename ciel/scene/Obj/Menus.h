#pragma once
#include "../../common/Vector2.h"
#include "../Input/Keyboard.h"
#include"Player.h"


class Menus
{
public:

	enum class MENUS_SELECT
	{
		MENU_ID,
		MENU_AITEM,
		MENU_HINT,
		MENU_OPTION,
		MENU_END,
		MENU_MAX
	};

	enum class AITEMS_SELECT
	{
		AITEM_ID,
		AITEM_IMPORTANT,
		AITEM_HEAL,
		AITEM_MAX
	};


	Menus();
	~Menus();

	bool init(void);		//èâä˙âª
	void Update(int num,bool flg);		//çXêV
	void Draw(PlayerID type,int ru,int En,int St);		//ï`âÊ
	bool Release(void);		//äJï˙

	void Menu(void);
	void Aitems(void);
	void ASelect(void);
	void Heal(void);
	void Important(void);
	int Opution(void);
	void Hint(void);
	void End(void);

	int OpBgm(void);

	int y;
	int x;
	int yy;
	int xx;
	int xxx;
	int yyy;
	int xxxx;
	int yyyy;
	int xxxxx;
	int yyyyy;
	int xxxxxx;
	int yyyyyy;
	int xxxxxxx;
	int yyyyyyy;
	int sy;
	int ai;
	int ah;

	int haveNum;

	int menuScr;

	int KnomiE(void);
	int AppleE(void);
	int KinominoKusiyakiE(void);
	int FruitDrinkE(void);
	int FishingRodSE(void);
	int RagBagE(void);
	int PickaxeE(void);
	int mHaoriE(void);
	int mRantanE(void);
	int RiceE(void);
	int DangoE(void);
	int TeaE(void);
	int TamE(void);
	int KeyE(void);
	int FishE(void);
	int StoneRE(void);
	int StoneBE(void);

	int NumHave(void);

	int En();

	void SetMenu(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h, int ri, int d, int t,int tam,int key,int fish, int je, int bul);

private:

	Vector2 mSize;
	int mImage[10];
	int mImageAS;
	int mImageAI[10];
	int mImageAH[10];
	int mImageH[10];
	int mImageO;
	int mEImage;

	int mImageMap[10];

	int FontSize;

	int mEnergy;
	
	Vector2 mBox[20];
	Vector2 mBoxAS[10];
	Vector2 mBoxAI[10][10];
	Vector2 mBoxAH[10][10];
	Vector2 mBoxAIs[10];
	Vector2 mBoxAHs[10];
	Vector2 mBoxO[10];


	Vector2 mPos;

	MENUS_SELECT mSelect;

	AITEMS_SELECT mAitem;

	Keyboard key_;

	bool SIflg;
	bool SHflg;

	int ssApple;
	int ssKinominoKusiyaki;
	int ssFruitDrink;
	int ssRice;
	int ssDango;
	int ssTea;
	int ssFishingRodS;
	int ssRagBag;
	int ssPickaxe;
	int ssHaoriN;
	int ssRantanN;
	int ssNumKinomi;
	int ssKey;
	int ssTama;
	int ssfish;
	int ssStoneR;
	int ssStoneB;

	int eApple;
	int eKinominoKusiyaki;
	int eFruitDrink;
	int eRice;
	int eDango;
	int eTea;
	int eFishingRodS;
	int eRagBag;
	int ePickaxe;
	int eHaoriN;
	int eRantanN;
	int eNumKinomi;
	int eKey;
	int eTama;
	int efish;
	int eStoneR;
	int eStoneB;

	bool sApple;
	bool sKinominoKusiyaki;
	bool sFruitDrink;
	bool sRice;
	bool sDango;
	bool sTea;
	bool sFishingRodS;
	bool sRagBag;
	bool sPickaxe;
	bool sHaoriN;
	bool sRantanN;
	bool sNumKinomi;
	bool sKey;
	bool sTama;
	bool sfish;

	int b;

	int have;

	//å¯â âπ
	int kHandle;
	int cHandle;
	int hHandle;

	//èÛë‘ëJà⁄
	void ChangeState(MENUS_SELECT select);

	void ChangeAitem(AITEMS_SELECT select);
};

