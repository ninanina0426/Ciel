#pragma once
#include "../../common/Vector2.h"
#include "../Input/Keyboard.h"
class GameScene;

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

	bool init(GameScene* parent);		//������
	void Update(int num);		//�X�V
	void Draw(void);		//�`��
	bool Release(void);		//�J��

	bool SPose(void);
	bool CanselFlg(void);

	int SetAitem(int a, int kk, int fd, int frs, int rb, int p,int k,int r,int h);

	bool Canflg;

	void SSetNum(void);

	void SsetAitem(bool flg);

private:
	
	int FontSize;

	int mImagSelect;
	int mImagNomal;
	int mImageHuve;
	int mImageNHuve;
	int mImageBsB;
	int mImageBsS;
	int mImageBuy;
	
	Vector2 mBoxSe[10];
	Vector2 mBoxA[10][10];
	Vector2 mBoxB[10][10];

	Vector2 mPos;
	Vector2 mSize;
	
	SHOP_SELECT mSelect;

	SHOP_BS mBS;

	Keyboard key_;

	GameScene* mParent;

	int num;

	int moveSnum;

	int x;
	int y;

	int xx;
	int yy;

	int SelectNum;

	//�����Ă���
	int gApple;
	int gKinominoKusiyaki;
	int gFruitDrink;
	int gFishingRodS;
	int gRagBag;
	int gPickaxe;
	int gKinomi;
	int gRantan;
	int gHaori;

	//����
	int bApple;
	int bKinominoKusiyaki;
	int bFruitDrink;
	int bFishingRodS;
	int bRagBag;
	int bPickaxe;
	int bKinomi;
	int bRantan;
	int bHaori;

	//�݌�
	int maxApple;
	int maxKinominoKusiyaki;
	int maxFruitDrink;
	int maxFishingRodS;
	int maxRagBag;
	int maxPickaxe;
	int maxKinomi;
	int maxRantan;
	int maxHaori;

	//����
	int sApple;
	int sKinominoKusiyaki;
	int sFruitDrink;
	int sFishingRodS;
	int sRagBag;
	int sPickaxe;
	int sKinomi;
	int sRantan;
	int sHaori;

	//�����Z
	int kApple;
	int kKinominoKusiyaki;
	int kFruitDrink;
	int kFishingRodS;
	int kRagBag;
	int kPickaxe;
	int kKinomi;
	int kRantan;
	int kHaori;

	bool moveFlg;

	int H;

	void Select(void);
	void Buy(void);
	void Sell(void);
	void Cansel(void);

	void BSBuy(void);
	void BSSell(void);

	void BS(void);

	//��ԑJ��
	void ChangeState(SHOP_SELECT select);
	void ChangeBS(SHOP_BS bs);
};

