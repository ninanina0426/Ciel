#pragma once
#include "../../common/Vector2.h"
#include "../Input/Keyboard.h"
#include"Aitem.h"
class GameScene;


class Menu
{
public:

	enum class MENU_SELECT
	{
		MENU_ID,
		MENU_AITEM,
		MENU_HINT,
		MENU_OPTION,
		MENU_END,
		MENU_MAX
	};

	enum class AITEM_SELECT
	{
		AITEM_ID,
		AITEM_NOMAL,
		AITEM_HEAL,
		AITEM_IMPORTANT,
		AITEM_MAX
	};

	Menu();
	~Menu();

	bool init(GameScene* parent);		//èâä˙âª
	void Update(void);		//çXêV
	void Draw(void);		//ï`âÊ
	bool Release(void);		//äJï˙

	void Menus(void);
	void Aitems(void);
	void Select(void);
	void Nomal(void);
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
	int sy;
	
	int menuScr;

	
	void SetMenu(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h);

private:

	Vector2 mSize;
	GameScene* mParent;
	int mImage[20][20];
	int mImagSelect[20][20];
	int mImageGet[20][20];
	int mAImage[20];
	int mEImage;
	Vector2 mBox[20];
	Vector2 mBoxS[10][10];
	Vector2 mBoxA[10][10];
	Vector2 mBoxAs[10][10];
	Vector2 mBoxH[10];
	Vector2 mBoxO[10];


	Vector2 mPos;
	
	Aitem mAitems;

	MENU_SELECT mSelect;

	AITEM_SELECT mAitem;

	Keyboard key_;

	int ssApple;
	int ssKinominoKusiyaki;
	int ssFruitDrink;
	int ssFishingRodS;
	int ssRagBag;
	int ssPickaxe;
	int ssHaoriN;
	int ssRantanN;
	int ssNumKinomi;

	int b;

	//èÛë‘ëJà⁄
	void ChangeState(MENU_SELECT select);

	void ChangeAitem(AITEM_SELECT select);
};


