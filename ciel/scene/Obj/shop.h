#pragma once
#include "../../common/Vector2.h"
#include "../Input/Keyboard.h"

class shop
{
public:

	enum class SHOP_SELECT
	{
		SELECT,
		BUY,
		SELL,
		CANSEL,
		NUM,
		MAX
	};

	enum class SHOP_BS
	{
		BS_BUY,
		BS_SELL,
		BS_MAX
	};

	shop();
	~shop();

	bool init(void);		//èâä˙âª
	void Update(int num);		//çXêV
	void Draw(void);		//ï`âÊ
	bool Release(void);		//äJï˙

	bool SPose(void);
	bool CanselFlg(void);

	int SetAitem(int a, int kk, int fd, int frs, int rb, int p,int k,int r,int h, int ri, int d, int t,int f,int sr,int sb);

	int SetMoney();
	bool GetMoney();
	void sHaveMoney(int ru);

	void AMoney(int money);

	bool Canflg;

	void SSetNum(void);

	void SsetAitem(bool flg);

	int SsApple(void);
	int SsKinominoKusiyaki(void);
	int SsFruitDrink(void);
	int SsFishingRodS(void);
	int SsRagBag(void);
	int SsPickaxe(void);
	int SsKinomi(void);
	int SsRantan(void);
	int SsHaori(void);
	int SsRice(void);
	int SsDango(void);
	int SsTea(void);
	int SsFish(void);
	int SsStoneR(void);
	int SsStoneB(void);

private:
	
	bool MoneyFlg;
	int sMoney;

	int FontSize;

	int numRu;
	int haveRu;

	int mImagSelect;
	int mImagNomal;
	int mImageHuve;
	int mImageNHuve;
	int mImageBsB;
	int mImageBsS;
	int mImageBuy;
	int mImageBuy2;

	int mNumS;
	
	Vector2 mBoxSe[10];
	Vector2 mBoxA[10][10];
	Vector2 mBoxB[10][10];

	Vector2 mPos;
	Vector2 mSize;
	
	SHOP_SELECT mSelect;

	SHOP_BS mBS;

	Keyboard key_;

	int num;

	int moveSnum;

	int x;
	int y;

	int xx;
	int yy;

	int SelectNum;

	//éùÇ¡ÇƒÇ¢ÇÈ
	int gApple;
	int gKinominoKusiyaki;
	int gFruitDrink;
	int gFishingRodS;
	int gRagBag;
	int gPickaxe;
	int gKinomi;
	int gRantan;
	int gHaori;
	int gRice;
	int gDango;
	int gTea;
	int gFish;
	int gStoneR;
	int gStoneB;

	//îÑîÉ
	int bApple;
	int bKinominoKusiyaki;
	int bFruitDrink;
	int bFishingRodS;
	int bRagBag;
	int bPickaxe;
	int bKinomi;
	int bRantan;
	int bHaori;
	int bRice;
	int bDango;
	int bTea;
	int bFish;
	int bStoneR;
	int bStoneB;

	//ç›å…
	int maxApple;
	int maxKinominoKusiyaki;
	int maxFruitDrink;
	int maxFishingRodS;
	int maxRagBag;
	int maxPickaxe;
	int maxKinomi;
	int maxRantan;
	int maxHaori;
	int maxRice;
	int maxDango;
	int maxTea;

	//ëççá
	int sApple;
	int sKinominoKusiyaki;
	int sFruitDrink;
	int sFishingRodS;
	int sRagBag;
	int sPickaxe;
	int sKinomi;
	int sRantan;
	int sHaori;
	int sRice;
	int sDango;
	int sTea;
	int sFish;
	int sStoneR;
	int sStoneB;

	//â¡å∏éZ
	int kApple;
	int kKinominoKusiyaki;
	int kFruitDrink;
	int kFishingRodS;
	int kRagBag;
	int kPickaxe;
	int kKinomi;
	int kRantan;
	int kHaori;
	int kRice;
	int kDango;
	int kTea;
	int kFish;
	int kStoneR;
	int kStoneB;

	//Ç®ã‡
	int mA;
	int mKK;
	int mFD;
	int mFRS;
	int mRB;
	int mP;
	int mK;
	int mR;
	int mH;
	int mRi;
	int mD;
	int mT;
	int mF;
	int mSR;
	int mSB;

	bool moveFlg;

	//å¯â âπ
	int kHandle;
	int cHandle;

	int H;

	void Select(void);
	void Buy(void);
	void Sell(void);
	void Cansel(void);

	void BSBuy(void);
	void BSSell(void);

	void BS(void);

	//èÛë‘ëJà⁄
	void ChangeState(SHOP_SELECT select);
	void ChangeBS(SHOP_BS bs);
};

