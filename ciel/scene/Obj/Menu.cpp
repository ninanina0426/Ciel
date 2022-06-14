#include <DxLib.h>
#include"../GameScene.h"
#include "../Input/Keyboard.h"
#include "Menu.h"

Menu::Menu()
{
}

Menu::~Menu()
{
}

bool Menu::init(GameScene* parent)
{
	mParent = parent;

	b = 0;
	
	
	mImage[0][0] = LoadGraph("image/menyu/menu10.png");
	//アイテム
	mImage[1][0] = LoadGraph("image/menyu/aitem.png");
	mImage[1][1] = LoadGraph("image/menyu/aitem.png");
	mImage[1][2] = LoadGraph("image/menyu/aitem.png");
	mImagSelect[1][1] = LoadGraph("image/menyu/shot.png");
	mImageGet[1][1]= LoadGraph("image/menyu/kuro2.png");
	mImagSelect[1][2] = LoadGraph("image/menyu/kaifuku.png");
	mImageGet[1][2] = LoadGraph("image/menyu/kuro1.png");
	mImagSelect[1][3] = LoadGraph("image/menyu/tai.png");
	mImageGet[1][3] = LoadGraph("image/menyu/kuro.png");
	//ヒント
	mImage[2][0] = LoadGraph("image/menyu/Hint.png");
	//オプション
	mImage[3][0] = LoadGraph("image/menyu/Option.png");
	//エンド
	mImage[4][0] = LoadGraph("image/menyu/menu10.png");

	//アイテム欄
	mAImage[1]= LoadGraph("image/menyu/kizi1.png");
	mAImage[2] = LoadGraph("image/menyu/houtai1.png");
	mAImage[3] = LoadGraph("image/menyu/bann1.png");
	mAImage[4] = LoadGraph("image/menyu/key1.png");
	mAImage[5] = LoadGraph("image/menyu/kami1.png");

	mEImage = LoadGraph("image/menyu/end1.png");

	y = 0;
	x = 0;
	yy = 0;
	xx = 0;
	xxx = 0;
	yyy = 0;
	xxxx = 0;
	yyyy = 0;
	xxxxx = 0;
	yyyyy = 0;
	sy = 0;

	mBox[0] = { 45,25 };
	mBox[1] = { 45,25 };
	mBox[2]	= { 45,60 };
	mBox[3] = { 45,95 };
	mBox[4] = { 45,130 };
	mBox[5] = { 45,160 };
	mBox[6] = { 45,195 };
	mBox[7] = { 45,225 };
	mBox[8] = { 45,260 };

	mBoxS[0][0] = { 217,10};
	mBoxS[0][1] = { 217,10 };
	mBoxS[0][2] = { 217,125 };
	mBoxS[0][3] = { 217,245 };
	mBoxS[0][4] = { 217,355 };
	mBoxS[0][5] = { 217,480 };

	mBoxS[1][0] = { 217,10 };
	mBoxS[1][1] = { 217,10 };
	mBoxS[1][2] = { 217,125 };
	mBoxS[1][3] = { 217,245 };
	mBoxS[1][4] = { 217,355 };
	mBoxS[1][5] = { 217,480 };

	mBoxS[2][0] = { 217,10 };
	mBoxS[2][1] = { 217,10 };
	mBoxS[2][2] = { 217,125 };
	mBoxS[2][3] = { 217,245 };
	mBoxS[2][4] = { 217,355 };
	mBoxS[2][5] = { 217,480 };

	mBoxA[0][0] = { 220,120 };
	mBoxA[1][0] = { 220,120 };
	mBoxA[2][0] = { 350,120 };
	mBoxA[3][0] = { 455,120 };
	mBoxA[4][0] = { 625,120 };

	mBoxAs[0][0] = { 220,200 };
	mBoxAs[0][1] = { 220,200 };
	mBoxAs[0][2] = { 220,245 };
	mBoxAs[0][3] = { 220,295 };
	mBoxAs[0][4] = { 220,345 };
	mBoxAs[0][5] = { 220,395 };
	mBoxAs[0][6] = { 220,445 };
	mBoxAs[0][7] = { 220,470 };
	mBoxAs[0][8] = { 220,515 };
	mBoxAs[1][0] = { 390,200 };
	mBoxAs[1][1] = { 390,200 };
	mBoxAs[1][2] = { 390,245 };
	mBoxAs[1][3] = { 390,295 };
	mBoxAs[1][4] = { 390,345 };
	mBoxAs[1][5] = { 390,395 };
	mBoxAs[1][6] = { 390,445 };
	mBoxAs[1][7] = { 390,470 };
	mBoxAs[1][8] = { 390,515 };
	mBoxAs[2][0] = { 610,200 };
	mBoxAs[2][1] = { 610,200 };
	mBoxAs[2][2] = { 610,245 };
	mBoxAs[2][3] = { 610,295 };
	mBoxAs[2][4] = { 610,345 };
	mBoxAs[2][5] = { 610,395 };
	mBoxAs[2][6] = { 610,445 };
	mBoxAs[2][7] = { 610,470 };
	mBoxAs[2][8] = { 610,515 };


	mBoxH[0] = { 380,135 };
	mBoxH[1] = { 380,135 };
	//mBoxSo[2] = { 440,135 };
	//mBoxSo[3] = { 540,135 };
	//mBoxSo[4] = { 630,135 };
	//mBoxSo[5] = { 700,135 };

	mBoxO[0] = { 225,133 };
	mBoxO[1] = { 225,133 };
	/*mBoxSk[2] = { 225,167 };
	mBoxSk[3] = { 225,200 };*/

	mPos = { 0,-10 };

	ChangeState(MENU_SELECT::MENU_ID);

	ChangeAitem(AITEM_SELECT::AITEM_ID);

	return true;
}

void Menu::Update(void)
{
	key_.Update();
	key_.getKeyDown(KEY_INPUT_DOWN);

	switch (mSelect)
	{
	case Menu::MENU_SELECT::MENU_ID:
		Menus();
		break;
	case Menu::MENU_SELECT::MENU_AITEM:
		Aitems();
		break;
	case Menu::MENU_SELECT::MENU_HINT:
		Hint();
		break;
	case Menu::MENU_SELECT::MENU_OPTION:
		Opution();
		break;
	case Menu::MENU_SELECT::MENU_END:
		End();
		break;
	case Menu::MENU_SELECT::MENU_MAX:
		break;
	default:
		break;
	}

	//メニューの自動的な移動
	if (mPos.y_ < 0)
	{
		mPos.y_ += 1;
	}
}

void Menu::Draw(void)
{
	switch (mSelect)
	{
	case Menu::MENU_SELECT::MENU_ID:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBox[y].x_, mBox[y].y_, 190, mBox[y + 1].y_, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::MENU_SELECT::MENU_AITEM:
		
		break;
	case Menu::MENU_SELECT::MENU_HINT:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxH[xxxxx].x_, mBoxH[yyyyy].y_,325, mBoxH[yyyyy+1].y_, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::MENU_SELECT::MENU_OPTION:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		/*DrawBox(mBoxO[xxxx].x_, 135, mBoxO[xxxx + 1].x_,180,GetColor(0, 0, 200), true);*/
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	/*case Menu::MENU_SELECT::MENU_NO:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxS[0][sy].X, mBoxS[0][sy].Y, 630, mBoxS[0][sy + 1].Y - 10, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::MENU_SELECT::MENU_SAVE:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxS[x][yy].X, mBoxS[x][yy].Y, 630, mBoxS[x][yy + 1].Y - 10, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;*/
	case Menu::MENU_SELECT::MENU_END:

		break;
	case Menu::MENU_SELECT::MENU_MAX:

		break;
	default:
		break;
	}
	
	switch (mAitem)
	{
	case Menu::AITEM_SELECT::AITEM_ID:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxA[xx][0].x_, mBoxA[xx][0].y_, mBoxA[xx + 1][0].x_, 180, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::AITEM_SELECT::AITEM_NOMAL:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxAs[xxx][yyy].x_, mBoxAs[xxx][yyy].y_, mBoxAs[xxx + 1][yyy].x_, mBoxAs[xxx][yyy+1].y_, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::AITEM_SELECT::AITEM_HEAL:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxAs[xxx][yyy].x_, mBoxAs[xxx][yyy].y_, mBoxAs[xxx + 1][yyy].x_, mBoxAs[xxx][yyy + 1].y_, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::AITEM_SELECT::AITEM_IMPORTANT:
		SetDrawBlendMode(DX_BLENDMODE_MULA, 150);
		DrawBox(mBoxAs[xxx][yyy].x_, mBoxAs[xxx][yyy].y_, mBoxAs[xxx + 1][yyy].x_, mBoxAs[xxx][yyy + 1].y_, GetColor(0, 0, 200), true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	case Menu::AITEM_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}

	DrawRectGraph(215, mPos.y_, 215, 0, 640 - 215, 480, mImage[y][x], true, false);
	DrawRectGraph(mPos.x_, mPos.y_, mPos.x_,mPos.y_, 215, 480, mImage[4][0], true, false);

	switch (mSelect)
	{
	case Menu::MENU_SELECT::MENU_ID:
		
		break;
	case Menu::MENU_SELECT::MENU_AITEM:
		DrawGraph(0, 0, mImageGet[y][xx], true);
		if (xx == 1)
		{
			/*if (mParent->mTma() == false)
			{
				DrawRectGraph(0, 0, 0, 0, 400, 250, mImagSelect[1][1], true, false);
			}
			if (mParent->mMasinngan() == false)
			{
				DrawRectGraph(0, 250, 0, 250, 400, 250, mImagSelect[1][1], true, false);
			}*/
		}
		if (xx == 2)
		{
			/*if (mParent->mHoutai() == false)
			{
				DrawRectGraph(0, 0, 0, 0, 400, 250, mImagSelect[1][2], true, false);
			}
			if (mParent->mHeal() == false)
			{
				DrawRectGraph(0, 250, 0, 250, 400, 250, mImagSelect[1][2], true, false);
			}*/
		}
		if (xx == 3)
		{
		
			/*if (mParent->IsKami1() == false)
			{
				DrawRectGraph(0, 200,0, 200, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->IsKami2() == false)
			{
				DrawRectGraph(0, 250,0, 250, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->mKami3() == false)
			{
				DrawRectGraph(0, 300, 0, 300, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->mKami4() == false)
			{
				DrawRectGraph(0, 350,0, 350, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->mKami5() == false)
			{
				DrawRectGraph(0, 400,0, 400, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->mKey() == false)
			{
				DrawRectGraph(390, 0, 390, 0, 400, 250, mImagSelect[1][3], true, false);
			}
			if (mParent->mbook() == false)
			{
				DrawRectGraph(390, 250, 390, 250, 400, 50, mImagSelect[1][3], true, false);
			}
			if (mParent->mMagazinn() == false)
			{
				DrawRectGraph(390, 300, 390, 300, 400, 50, mImagSelect[1][3], true, false);
			}*/
		}
		
		break;
	case Menu::MENU_SELECT::MENU_HINT :

		break;
	case Menu::MENU_SELECT::MENU_OPTION:

		break;
	case Menu::MENU_SELECT::MENU_END:
		DrawGraph(mPos.x_, 0, mEImage, true);
		break;
	case Menu::MENU_SELECT::MENU_MAX:

		break;
	default:
		break;
	}

	switch (mAitem)
	{
	case Menu::AITEM_SELECT::AITEM_ID:
		
		break;
	case Menu::AITEM_SELECT::AITEM_NOMAL:
		
		break;
	case Menu::AITEM_SELECT::AITEM_HEAL:
		if (xx == 2)
		{
			/*if (mParent->mHoutai() == false)
			{
				
				if (yyy == 1)
				{
					DrawGraph(mPos.x_, 0, mAImage[2], true);
				}

			}
			if (mParent->mHeal() == false)
			{
				if (yyy == 2)
				{
					DrawGraph(mPos.x_, 0, mAImage[3], true);
				}
			}*/
		}
		break;
	case Menu::AITEM_SELECT::AITEM_IMPORTANT:
		if (xx == 3)
		{
			if (xxx == 0)
			{
				if (mParent->IsTama1() == false)
				{
					if (yyy == 1)
					{
						DrawGraph(mPos.x_, 0, mAImage[5], true);
					}
				}
				if (mParent->IsTama2() == false)
				{
					if (yyy == 2)
					{
						DrawGraph(mPos.x_, 0, mAImage[5], true);
					}
				}
				if (mParent->IsTama3() == false)
				{
					if (yyy == 3)
					{
						DrawGraph(mPos.x_, 0, mAImage[5], true);
					}
				}
				if (mParent->IsTama4() == false)
				{
					if (yyy == 4)
					{
						DrawGraph(mPos.x_, 0, mAImage[5], true);
					}
				}
				if (mParent->IsTama5() == false)
				{
					if (yyy == 5)
					{
						DrawGraph(mPos.x_, 0, mAImage[5], true);
					}
				}
			}
		
			if (xxx == 1)
			{
				/*if (mParent->mKey() == false)
				{
					if (yyy == 1)
					{
						DrawGraph(mPos.x_, 0, mAImage[4], true);
					}

				}
				if (mParent->mMagazinn() == false)
				{
					if (yyy == 2)
					{
						DrawGraph(mPos.x_, 0, mAImage[1], true);
					}

				}*/

			}
			
		}
		break;
	case Menu::AITEM_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}
}

bool Menu::Release(void)
{
	for (int i = 0; i < 20; i++)
	{
		for (int ii = 0; ii < 20; ii++)
		{
			DeleteGraph(mImage[ii][i]);
			DeleteGraph(mImagSelect[ii][i]);
			DeleteGraph(mImageGet[ii][i]);
		}
	}

	DeleteGraph(mEImage);
	return true;
}

void Menu::Menus(void)
{
	if (y >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_DOWN))
		{
			y += 1;
			if (y > 4)
			{
				y = 1;
			}
			mPos.y_ = -10;
		}
		else if (key_.getKeyDown(KEY_INPUT_UP) && y >= 0)
		{
			y -= 1;
			if (y <= 0)
			{
				y = 4;
			}
			mPos.y_ = -10;
		}
		if (key_.getKeyDown(KEY_INPUT_F)/* || key_.getKeyDown(KEY_INPUT_RETURN)*/)
		{
			if (y == 1)
			{
				ChangeState(MENU_SELECT::MENU_AITEM);
				xx = 1;
			}
			if (y == 2)
			{
				ChangeState(MENU_SELECT::MENU_HINT);
				yyyyy = 1;
			}
			if (y == 3)
			{
				ChangeState(MENU_SELECT::MENU_OPTION);
				xxxx = 1;
			}
			/*if (y == 4)
			{
				ChangeState(MENU_SELECT::MENU_NO);
				sy = 1;
			}
			if (y == 5)
			{
				ChangeState(MENU_SELECT::MENU_SAVE);
				yy = 1;
			}*/
			if (y == 4)
			{
				ChangeState(MENU_SELECT::MENU_END);
			}
		
			
		}
	}

	
}


void Menu::Aitems(void)
{
	switch (mAitem)
	{
	case Menu::AITEM_SELECT::AITEM_ID:
		Select();
		break;
	case Menu::AITEM_SELECT::AITEM_NOMAL:
		Nomal();
		break;
	case Menu::AITEM_SELECT::AITEM_HEAL:
		Heal();
		break;
	case Menu::AITEM_SELECT::AITEM_IMPORTANT:
		Important();
		break;
	case Menu::AITEM_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}
}

void Menu::Select(void)
{
	if (xx >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_RIGHT))
		{
			xx += 1;
			if (xx > 3)
			{
				xx = 1;
			}

		}
		else if (key_.getKeyDown(KEY_INPUT_LEFT) && xx >= 0)
		{
			xx -= 1;
			if (xx <= 0)
			{
				xx = 3;
			}

		}
	}
	if (key_.getKeyDown(KEY_INPUT_F)/*|| key_.getKeyDown(KEY_INPUT_RETURN)*/)
	{
		if (xx == 1)
		{
			ChangeAitem(AITEM_SELECT::AITEM_NOMAL);
			yyy = 1;

		}
		if (xx == 2)
		{
			ChangeAitem(AITEM_SELECT::AITEM_HEAL);
			yyy = 1;
		}
		if (xx == 3)
		{
			ChangeAitem(AITEM_SELECT::AITEM_IMPORTANT);
			yyy = 1;
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENU_SELECT::MENU_ID);
		xx = 0;
		yy = 0;
	}

}

void Menu::Nomal(void)
{
	if (xxx >= 0)
	{
		if (yyy >= 0)
		{
			if (key_.getKeyDown(KEY_INPUT_DOWN))
			{
				yyy += 1;
				if (yyy > 2)
				{
					yyy = 1;
				}
			}
			else if (key_.getKeyDown(KEY_INPUT_UP) && yyy >= 0)
			{
				yyy -= 1;
				if (yyy <= 0)
				{
					yyy = 2;
				}
			}
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeAitem(AITEM_SELECT::AITEM_ID);
		xxx = 0;
		yyy = 0;
	}
}

void Menu::Heal(void)
{
	if (xxx >= 0)
	{
		if (yyy >= 0)
		{
			if (key_.getKeyDown(KEY_INPUT_DOWN))
			{
				yyy += 1;
				if (yyy > 2)
				{
					yyy = 1;
				}
			}
			else if (key_.getKeyDown(KEY_INPUT_UP) && yyy >= 0)
			{
				yyy -= 1;
				if (yyy <= 0)
				{
					yyy = 2;
				}
			}
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeAitem(AITEM_SELECT::AITEM_ID);
		xxx = 0;
		yyy = 0;
	}

}

void Menu::Important(void)
{
	if (xxx >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_RIGHT))
		{
			xxx += 1;
			if (xxx >= 2)
			{
				xxx = 0;
			}
		}
		else if (key_.getKeyDown(KEY_INPUT_LEFT) && xxx >= 0)
		{
			xxx -= 1;
			if (xxx < 0)
			{
				xxx = 1;
			}
		}
		if (yyy >= 0)
		{
			if (xxx == 0)
			{
				if (key_.getKeyDown(KEY_INPUT_DOWN))
				{
					yyy += 1;
					if (yyy > 5)
					{
						yyy = 1;
					}
				}
				else if (key_.getKeyDown(KEY_INPUT_UP) && yyy >= 0)
				{
					yyy -= 1;
					if (yyy <= 0)
					{
						yyy = 5;
					}
				}
			}
			else if (xxx == 1)
			{
				if (key_.getKeyDown(KEY_INPUT_DOWN))
				{
					yyy += 1;
					if (yyy > 3)
					{
						yyy = 1;
					}
				}
				else if (key_.getKeyDown(KEY_INPUT_UP) && yyy >= 0)
				{
					yyy -= 1;
					if (yyy <= 0)
					{
						yyy = 3;
					}
				}
			}
			
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeAitem(AITEM_SELECT::AITEM_ID);
		xxx = 0;
		yyy = 0;
	}
}

void Menu::Hint(void)
{
	if (yyyyy >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_DOWN))
		{
			yyyyy += 1;
			if (yyyyy > 2)
			{
				yyyyy = 1;
			}
		}
		else if (key_.getKeyDown(KEY_INPUT_UP) && yyy >= 0)
		{
			yyyyy -= 1;
			if (yyyyy <= 0)
			{
				yyyyy = 2;
			}
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENU_SELECT::MENU_ID);
		xxxxx = 0;
		yyyyy = 0;
	}

}

int Menu::Opution(void)
{
	/*if (xxxx >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_RIGHT))
		{
			xxxx += 1;
			if (xxxx > 3)
			{
				xxxx = 1;
			}
		}
		else if (key_.getKeyDown(KEY_INPUT_LEFT) && xxxx >= 0)
		{
			xxxx -= 1;
			if (xxxx <= 0)
			{
				xxxx = 3;
			}
		}

	}*/

	

	if (key_.getKeyDownHold(KEY_INPUT_DOWN))
	{
		b += 1;
		if (b > 100)
		{
			x = 100;
		}
	}
	if (key_.getKeyDownHold(KEY_INPUT_UP))
	{
		b -= 1;
		if (b < 0)
		{
			b = 0;
		}
	}

	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENU_SELECT::MENU_ID);
		xxxx = 0;
		yyyy = 0;
	}

	return b;
	
}

//void Menu::Opution(void)
//{
//	if (sy >= 0)
//	{
//		if (CheckHitKey(KEY_INPUT_DOWN))
//		{
//			sy += 1;
//			if (sy > 4)
//			{
//				sy = 1;
//			}
//		}
//		else if (CheckHitKey(KEY_INPUT_UP) && y >= 0)
//		{
//			sy -= 1;
//			if (sy <= 0)
//			{
//				sy = 4;
//			}
//		}
//	}
//	if (CheckHitKey(KEY_INPUT_B))
//	{
//		ChangeState(MENU_SELECT::MENU_ID);
//		sy = 0;
//	}
//}

//void Menu::Save(void)
//{
//	
//	if (x >= 0)
//	{
//		if (keyTrgDown[KEY_P1_RIGHT])
//		{
//			x += 1;
//			if (x > 2)
//			{
//				x = 0;
//			}
//			mPos.Y = -10;
//		}
//		else if (keyTrgDown[KEY_P1_LEFT] && x >= 0)
//		{
//			x -= 1;
//			if (x < 0)
//			{
//				x = 2;
//			}
//			mPos.Y = -10;
//		}
//		if (yy >= 0)
//		{
//			if (keyTrgDown[KEY_P1_DOWN])
//			{
//				yy += 1;
//				if (yy > 4)
//				{
//					yy = 1;
//				}
//			}
//			else if (keyTrgDown[KEY_P1_UP] && y >= 0)
//			{
//				yy -= 1;
//				if (yy <= 0)
//				{
//					yy = 4;
//				}
//			}
//		}
//
//	}
//	
//	if (keyTrgDown[KEY_P1_B])
//	{
//		ChangeState(MENU_SELECT::MENU_ID);
//		x = 0;
//		yy = 0;
//	}
//}

void Menu::End(void)
{
	if (CheckHitKey(KEY_INPUT_Q))
	{
		ChangeState(MENU_SELECT::MENU_ID);
		x = 0;
		yy = 0;
	}
}

int Menu::OpBgm(void)
{
	return b;
}

void Menu::ChangeState(MENU_SELECT select)
{
	mSelect = select;

	switch (mSelect)
	{
	case Menu::MENU_SELECT::MENU_ID:

		break;
	case Menu::MENU_SELECT::MENU_AITEM:

		break;
	case Menu::MENU_SELECT::MENU_HINT:

		break;
	case Menu::MENU_SELECT::MENU_OPTION:

		break;
	case Menu::MENU_SELECT::MENU_END:

		break;
	case Menu::MENU_SELECT::MENU_MAX:

		break;
	default:
		break;
	}
}

void Menu::ChangeAitem(AITEM_SELECT select)
{
	mAitem = select;

	switch (mAitem)
	{
	case Menu::AITEM_SELECT::AITEM_ID:
		break;
	case Menu::AITEM_SELECT::AITEM_HEAL:
		break;
	case Menu::AITEM_SELECT::AITEM_IMPORTANT:
		break;
	case Menu::AITEM_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}

}
