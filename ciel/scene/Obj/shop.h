#pragma once
#include "../../common/Vector2.h"
#include "../Input/Keyboard.h"
class Aitem;
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
		MAX
	};

	shop();
	~shop();

	bool init(GameScene* parent);		//初期化
	void Update(int num);		//更新
	void Draw(int k,int a);		//描画
	bool Release(void);		//開放

private:
	
	int FontSize;

	int mImagSelect;
	int mImageHuve;
	int mImageNHuve;
	
	Vector2 mBoxSe[10];
	Vector2 mBoxA[10][10];

	Vector2 mPos;
	Vector2 mSize;
	Aitem*mAitems;
	
	SHOP_SELECT mSelect;

	Keyboard key_;

	GameScene* mParent;

	int num;

	int x;
	int y;

	int xx;
	int yy;

	bool moveFlg;

	void Select(void);
	void Buy(void);
	void Sell(void);
	void Cansel(void);

	//状態遷移
	void ChangeState(SHOP_SELECT select);
};

