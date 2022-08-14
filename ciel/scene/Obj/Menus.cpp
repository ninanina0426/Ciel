#include <DxLib.h>
#include "../Input/Keyboard.h"
#include"../../stage/StageMng.h"
#include "Menus.h"



Menus::Menus()
{
	init();
}

Menus::~Menus()
{
}

bool Menus::init(void)
{
	//�Ȃ̏�������
	b = 50;

	have = 0;

	//��
	mEnergy = 0;

	//�����I�����Ă��Ȃ��Ƃ�
	mImage[0]= LoadGraph("image/menyu/J.png");
	mImage[1]= LoadGraph("image/menyu/S.png");
	mImage[2]= LoadGraph("image/menyu/C.png");
	//�A�C�e���i��؂��񕜂��j
	mImageAS = LoadGraph("image/menyu/�A�C�e��.png");
	//�A�C�e���̑厖�Ȃ��̂��ǂ����邩
	mImageAI[0] = LoadGraph("image/menyu/�A�C�e��.png");
	mImageAI[1] = LoadGraph("image/menyu/���.png");
	//�A�C�e���̉񕜂��ǂ����邩
	mImageAH[0] = LoadGraph("image/menyu/�A�C�e��.png");
	mImageAH[1] = LoadGraph("image/menyu/��.png");
	//�q���g
	mImageH[0] = LoadGraph("image/menyu/�q���g�V��.png");
	mImageH[1] = LoadGraph("image/menyu/�q���g�X.png");
	mImageH[2] = LoadGraph("image/menyu/�q���g���َq.png");
	mImageH[3] = LoadGraph("image/menyu/�q���g���A.png");
	mImageH[4] = LoadGraph("image/menyu/�q���g�a.png");
	mImageH[5] = LoadGraph("image/menyu/�q���g��.png");
	mImageO= LoadGraph("image/menyu/�I�v�V����.png");
	mEImage = LoadGraph("image/menyu/�I��.png");

	mImageMap[0] = LoadGraph("image/menyu/�_�a.png");
	mImageMap[1] = LoadGraph("image/menyu/�X.png");
	mImageMap[2] = LoadGraph("image/menyu/���َq.png");
	mImageMap[3] = LoadGraph("image/menyu/���A.png");
	mImageMap[4] = LoadGraph("image/menyu/�a.png");
	mImageMap[5] = LoadGraph("image/menyu/��.png");

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
	xxxxxx = 0;
	yyyyyy = 0;
	xxxxxxx = 0;
	yyyyyyy = 0;
	sy = 0;
	ai = 0;

	haveNum = 0;

	SHflg = false;
	SIflg = false;

	sApple=false;
	sKinominoKusiyaki = false;
	sFruitDrink = false;
	sRice = false;
	sDango = false;
	sTea = false;
	sFishingRodS = false;
	sRagBag = false;
	sPickaxe = false;
	sHaoriN = false;
	sRantanN = false;
	sNumKinomi = false;
	sKey = false;
	sTama = false;
	sfish = false;

	ssApple=0;
	ssKinominoKusiyaki = 0;
	ssFruitDrink = 0;
	ssRice = 0;
	ssDango = 0;
	ssTea = 0;
	ssFishingRodS = 0;
	ssRagBag = 0;
	ssPickaxe = 0;
	ssHaoriN = 0;
	ssRantanN = 0;
	ssNumKinomi = 0;
	ssKey = 0;
	ssTama = 0;
	ssfish = 0;
	ssStoneR=0;
	ssStoneB=0;

	eApple = 0;
	eKinominoKusiyaki = 0;
	eFruitDrink = 0;
	eRice = 0;
	eDango = 0;
	eTea = 0;
	eFishingRodS = 0;
	eRagBag = 0;
	ePickaxe = 0;
	eHaoriN = 0;
	eRantanN = 0;
	eNumKinomi = 0;
	eKey = 0;
	eTama = 0;
	efish = 0;
	eStoneR = 0;
	eStoneB = 0;

	//�A�C�e���A�q���g�A�I�v�V�����A�I���I��
	mBox[0] = {80,55};
	mBox[1] = {80,55};
	mBox[2] = {315,55};
	mBox[3] = {515,55};
	mBox[4] = {792,55};
	mBox[5] = {1026,55};
	mBox[6] = {1026,55};
	//���or��
	mBoxAS[0] = { 60,160 };
	mBoxAS[1] = { 60,160 };
	mBoxAS[2] = { 555,160 };
	mBoxAS[3] = { 1025,160 };
	mBoxAS[4] = { 1025,160 };
	//���
	mBoxAI[0][0] = {57,219};
	mBoxAI[0][1] = {57,219};
	mBoxAI[0][2] = {57,267};
	mBoxAI[0][3] = {57,309};
	mBoxAI[0][4] = {57,351};
	mBoxAI[0][5] = {57,396};
	mBoxAI[0][6] = {57,428};
	mBoxAI[0][7] = {57,474};
	mBoxAI[0][8] = {57,474};
	mBoxAI[1][1] = { 294,219 };
	mBoxAI[1][2] = { 294,267 };
	mBoxAI[1][3] = { 294,309 };
	mBoxAI[1][4] = { 294,351 };
	mBoxAI[1][5] = { 294,396 };
	mBoxAI[1][6] = { 294,428 };
	mBoxAI[1][7] = { 294,474 };
	mBoxAI[1][8] = { 294,474 };
	mBoxAI[2][1] = { 555,219 };
	mBoxAI[2][2] = { 555,267 };
	mBoxAI[2][3] = { 555,309 };
	mBoxAI[2][4] = { 555,351 };
	mBoxAI[2][5] = { 555,396 };
	mBoxAI[2][6] = { 555,428 };
	mBoxAI[2][7] = { 555,474 };
	mBoxAI[2][8] = { 555,474 };
	//��
	mBoxAH[0][1] = { 560,219 };
	mBoxAH[0][2] = { 560,267 };
	mBoxAH[0][3] = { 560,309 };
	mBoxAH[0][4] = { 560,351 };
	mBoxAH[0][5] = { 560,396 };
	mBoxAH[0][6] = { 560,432 };
	mBoxAH[0][7] = { 560,474 };
	mBoxAH[0][8] = { 560,474 };
	mBoxAH[1][1] = { 816,219 };
	mBoxAH[1][2] = { 816,267 };
	mBoxAH[1][3] = { 816,309 };
	mBoxAH[1][4] = { 816,351 };
	mBoxAH[1][5] = { 816,396 };
	mBoxAH[1][6] = { 816,432 };
	mBoxAH[1][7] = { 816,474 };
	mBoxAH[1][8] = { 816,474 };
	mBoxAH[2][1] = { 1026,219 };
	mBoxAH[2][2] = { 1026,267 };
	mBoxAH[2][3] = { 1026,309 };
	mBoxAH[2][4] = { 1026,351 };
	mBoxAH[2][5] = { 1026,396 };
	mBoxAH[2][6] = { 1026,432 };
	mBoxAH[2][7] = { 1026,474 };
	mBoxAH[2][8] = { 1026,474 };

	mBoxAHs[0] = { 393,272 };
	mBoxAHs[1] = { 393,272 };
	mBoxAHs[2] = { 477,272 };
	mBoxAHs[3] = { 582,272 };
	mBoxAHs[4] = { 687,272 };
	mBoxAHs[5] = { 687,272 };

	mBoxAIs[0] = { 393,272 };
	mBoxAIs[1] = { 393,272 };
	mBoxAIs[2] = { 550,272 };
	mBoxAIs[3] = { 687,272 };
	mBoxAIs[4] = { 687,272 };

	/*mBoxO[0] = {84,192};*/
	mBoxO[0] = {84,192};
	mBoxO[1] = {84,279};
	mBoxO[2] = {84,351};
	mBoxO[3] = {84,351};
	
	FontSize = CreateFontToHandle(NULL, 48, 5);

	cHandle = LoadSoundMem("image/Sound/�L�����Z��5.ogg");
	kHandle = LoadSoundMem("image/Sound/����{�^��������42.ogg");
	hHandle = LoadSoundMem("image/Sound/�Q�[�W��1.ogg");


	ChangeState(MENUS_SELECT::MENU_ID);

	ChangeAitem(AITEMS_SELECT::AITEM_ID);

	return true;
}

void Menus::Update(int num, bool flg)
{
	key_.Update();

	if (num == 100)
	{
		haveNum = 0;
	}
	
	if (flg == true)
	{
		switch (mSelect)
		{
		case Menus::MENUS_SELECT::MENU_ID:
			Menu();
			break;
		case Menus::MENUS_SELECT::MENU_AITEM:
			Aitems();
			break;
		case Menus::MENUS_SELECT::MENU_HINT:
			Hint();
			break;
		case Menus::MENUS_SELECT::MENU_OPTION:
			Opution();
			break;
		case Menus::MENUS_SELECT::MENU_END:
			End();
			break;
		case Menus::MENUS_SELECT::MENU_MAX:
			break;
		default:
			break;
		}
	}
	

}

void Menus::Draw(PlayerID type, int ru, int En, int St)
{
	PlayerID mType = type;

	MAP_ID mapID = lpMapMng.GetMapId();

	int Ru = ru;

	int E = En;

	int S = St;

	switch (mSelect)
	{
	case Menus::MENUS_SELECT::MENU_ID:
		switch (mType)
		{
		case PlayerID::Jack:
			DrawGraph(0, 0, mImage[0], true);
			DrawFormatStringToHandle(850, 370, GetColor(255, 255, 255), FontSize, "%d", E);
			DrawFormatStringToHandle(850, 410, GetColor(255, 255, 255), FontSize, "%d", S);
			break;
		case PlayerID::Calendula:
			DrawGraph(0, 0, mImage[2], true);
			DrawFormatStringToHandle(850, 370, GetColor(255, 255, 255), FontSize, "%d", E);
			DrawFormatStringToHandle(850, 410, GetColor(255, 255, 255), FontSize, "%d", S);
			break;
		case PlayerID::Soy:
			DrawGraph(0, 0, mImage[1], true);
			DrawFormatStringToHandle(850, 370, GetColor(255, 255, 255), FontSize, "%d", E);
			DrawFormatStringToHandle(850, 410, GetColor(255, 255, 255), FontSize, "%d", S);
			break;
		case PlayerID::Max:
			break;
		default:
			break;
		}
		
		break;
	case Menus::MENUS_SELECT::MENU_AITEM:
		DrawGraph(0, 0, mImageAS, true);
		break;
	case Menus::MENUS_SELECT::MENU_HINT:
		switch (mapID)
		{
		case MAP_ID::FOREST:
			DrawGraph(0, 0, mImageH[1], true);
			break;
		case MAP_ID::WA:
			DrawGraph(0, 0, mImageH[4], true);
			break;
		case MAP_ID::WASHOP:
			DrawGraph(0, 0, mImageH[4], true);
			break;
		case MAP_ID::CAVE:
			DrawGraph(0, 0, mImageH[3], true);
			break;
		case MAP_ID::CAVESHOP:
			DrawGraph(0, 0, mImageH[3], true);
			break;
		case MAP_ID::DARK:
			DrawGraph(0, 0, mImageH[3], true);
			break;
		case MAP_ID::FORESTIN:
			DrawGraph(0, 0, mImageH[1], true);
			break;
		case MAP_ID::TEMPLE:
			DrawGraph(0, 0, mImageH[0], true);
			break;
		case MAP_ID::TEMPLEIN:
			DrawGraph(0, 0, mImageH[0], true);
			break;
		case MAP_ID::SWEETS:
			DrawGraph(0, 0, mImageH[2], true);
			break;
		case MAP_ID::SWEETSOUT:
			DrawGraph(0, 0, mImageH[2], true);
			break;
		case MAP_ID::SWEETSSCHOOL:
			DrawGraph(0, 0, mImageH[2], true);
			break;
		case MAP_ID::SNOW:
			DrawGraph(0, 0, mImageH[5], true);
			break;
		case MAP_ID::SNOWCAVE:
			DrawGraph(0, 0, mImageH[5], true);
			break;
		case MAP_ID::TRANGETIONS:
			break;
		case MAP_ID::MAX:
			break;
		default:
			break;
		}
		break;
	case Menus::MENUS_SELECT::MENU_OPTION:
		DrawGraph(0, 0, mImageO, true);
		break;
	case Menus::MENUS_SELECT::MENU_END:
		DrawGraph(0, 0, mEImage, true);
		break;
	case Menus::MENUS_SELECT::MENU_MAX:

		break;
	default:
		break;
	}

	switch (mAitem)
	{
	case Menus::AITEMS_SELECT::AITEM_ID:

		break;
	case Menus::AITEMS_SELECT::AITEM_HEAL:
		if (SHflg == true)
		{
			DrawGraph(0, 0, mImageAH[1], true);
			if (xxxx == 0)
			{
				if (yyyy == 1)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssApple);
				}
				if (yyyy == 2)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssRice);
				}
				if (yyyy == 3)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssKinominoKusiyaki);
				}
				if (yyyy == 4)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssDango);
				}
				if (yyyy == 5)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssFruitDrink);
				}
				if (yyyy == 6)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssTea);
				}
			}
			else if (xxxx == 1)
			{
				if (yyyy == 1)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssfish);
				}
			}
			
		}
		else
		{
			DrawGraph(0, 0, mImageAH[0], true);
		}
		break;
	case Menus::AITEMS_SELECT::AITEM_IMPORTANT:
		if (SIflg == true)
		{
			DrawGraph(0, 0, mImageAI[1], true);
			if (xxx == 0)
			{
				if (yyy == 1)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssRagBag);
				}
				if (yyy == 2)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssFishingRodS);
				}
				if (yyy == 3)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssPickaxe);
				}
				if (yyy == 4)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssRantanN);
				}
				if (yyy == 5)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssHaoriN);
				}
			}
			if (xxx == 1)
			{
				if (yyy == 1)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssTama);
				}
				if (yyy == 2)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssKey);
				}
				if (yyy == 3)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssNumKinomi);
				}
				if (yyy == 4)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssStoneR);
				}
				if (yyy == 5)
				{
					DrawFormatStringToHandle(470, 190, GetColor(255, 255, 255), FontSize, "����:%d", ssStoneB);
				}
			}
			
		}
		else
		{
			DrawGraph(0, 0, mImageAI[0], true);
		}
		
		break;
	case Menus::AITEMS_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}

	switch (mapID)
	{
	case MAP_ID::FOREST:
		DrawGraph(0, 0, mImageMap[1], true);
		break;
	case MAP_ID::WA:
		DrawGraph(0, 0, mImageMap[4], true);
		break;
	case MAP_ID::WASHOP:
		DrawGraph(0, 0, mImageMap[4], true);
		break;
	case MAP_ID::CAVE:
		DrawGraph(0, 0, mImageMap[3], true);
		break;
	case MAP_ID::CAVESHOP:
		DrawGraph(0, 0, mImageMap[3], true);
		break;
	case MAP_ID::DARK:
		DrawGraph(0, 0, mImageMap[3], true);
		break;
	case MAP_ID::FORESTIN:
		DrawGraph(0, 0, mImageMap[1], true);
		break;
	case MAP_ID::TEMPLE:
		DrawGraph(0, 0, mImageMap[0], true);
		break;
	case MAP_ID::TEMPLEIN:
		DrawGraph(0, 0, mImageMap[0], true);
		break;
	case MAP_ID::SWEETS:
		DrawGraph(0, 0, mImageMap[2], true);
		break;
	case MAP_ID::SWEETSOUT:
		DrawGraph(0, 0, mImageMap[2], true);
		break;
	case MAP_ID::SWEETSSCHOOL:
		DrawGraph(0, 0, mImageMap[2], true);
		break;
	case MAP_ID::SNOW:
		DrawGraph(0, 0, mImageMap[5], true);
		break;
	case MAP_ID::SNOWCAVE:
		DrawGraph(0, 0, mImageMap[5], true);
		break;
	case MAP_ID::TRANGETIONS:
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}

	DrawFormatStringToHandle(850, 515, GetColor(150,255,255), FontSize, "%d", Ru);
	DrawString(0, 590, "F:����@Q:�L�����Z��", 0xffffff, true);
	DrawString(1000, 590, "ESC:�߂�", 0xffffff, true);
	//box�̕\��
	switch (mSelect)
	{
	case Menus::MENUS_SELECT::MENU_ID:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(mBox[x].x_, mBox[x].y_, mBox[x + 1].x_, 125, GetColor(255,255,255), true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		break;
	case Menus::MENUS_SELECT::MENU_AITEM:

		break;
	case Menus::MENUS_SELECT::MENU_HINT:

		break;
	case Menus::MENUS_SELECT::MENU_OPTION:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(mBoxO[yyyyy].x_, mBoxO[yyyyy].y_, 243, mBoxO[yyyyy+1].y_,GetColor(255, 255, 255), true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		break;
	case Menus::MENUS_SELECT::MENU_END:

		break;
	case Menus::MENUS_SELECT::MENU_MAX:

		break;
	default:
		break;
	}

	switch (mAitem)
	{
	case Menus::AITEMS_SELECT::AITEM_ID:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
		DrawBox(mBoxAS[xx].x_, mBoxAS[xx].y_, mBoxAS[xx + 1].x_, 210, GetColor(255,255,255), true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		break;
	case Menus::AITEMS_SELECT::AITEM_HEAL:
		if (SHflg == false)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawBox(mBoxAH[xxxx][yyyy].x_, mBoxAH[xxxx][yyyy].y_, mBoxAH[xxxx + 1][yyyy].x_, mBoxAH[xxxx][yyyy + 1].y_, GetColor(255, 255, 255), true);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		}
		else if (SHflg == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawBox(mBoxAHs[ai].x_, mBoxAHs[ai].y_, mBoxAHs[ai + 1].x_,319, GetColor(255, 255, 255), true);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		}
		break;
	case Menus::AITEMS_SELECT::AITEM_IMPORTANT:
		if (SIflg == false)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawBox(mBoxAI[xxx][yyy].x_, mBoxAI[xxx][yyy].y_, mBoxAI[xxx + 1][yyy].x_, mBoxAI[xxx][yyy + 1].y_, GetColor(255, 255, 255), true);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		}
		if (SIflg == true)
		{
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
			DrawBox(mBoxAIs[ah].x_, mBoxAIs[ah].y_, mBoxAIs[ah + 1].x_, 319, GetColor(255, 255, 255), true);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0);
		}
		
		break;
	case Menus::AITEMS_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}


	
}

	

bool Menus::Release(void)
{
	return false;
}

void Menus::Menu(void)
{
	if (x >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_RIGHT))
		{
			x+= 1;
			if (x > 4)
			{
				x = 1;
			}
			
		}
		else if (key_.getKeyDown(KEY_INPUT_LEFT) && x >= 0)
		{
			x -= 1;
			if (x <= 0)
			{
				x = 4;
			}
			
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
			if (x == 1)
			{
				ChangeState(MENUS_SELECT::MENU_AITEM);
				xx = 1;
			}
			if (x == 2)
			{
				ChangeState(MENUS_SELECT::MENU_HINT);
			}
			if (x == 3)
			{
				ChangeState(MENUS_SELECT::MENU_OPTION);
				/*yyyyy = 1;*/
			}
			if (x == 4)
			{
				ChangeState(MENUS_SELECT::MENU_END);
			}


		}
	}
}

void Menus::Aitems(void)
{
	switch (mAitem)
	{
	case Menus::AITEMS_SELECT::AITEM_ID:
		ASelect();
		break;
	case Menus::AITEMS_SELECT::AITEM_HEAL:
		Heal();
		break;
	case Menus::AITEMS_SELECT::AITEM_IMPORTANT:
		Important();
		break;
	case Menus::AITEMS_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}
}

void Menus::ASelect(void)
{
	if (xx >= 0)
	{
		if (key_.getKeyDown(KEY_INPUT_RIGHT))
		{
			xx += 1;
			if (xx > 2)
			{
				xx = 1;
			}

		}
		else if (key_.getKeyDown(KEY_INPUT_LEFT) && xx >= 0)
		{
			xx -= 1;
			if (xx <= 0)
			{
				xx = 2;
			}

		}
	}
	if (key_.getKeyDown(KEY_INPUT_F))
	{
		PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
		if (xx == 1)
		{
			ChangeAitem(AITEMS_SELECT::AITEM_IMPORTANT);
			yyy = 1;
		}
		if (xx == 2)
		{
			ChangeAitem(AITEMS_SELECT::AITEM_HEAL);
			yyyy = 1;
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
		ChangeState(MENUS_SELECT::MENU_ID);
		xx = 0;
		yy = 0;
	}
}

void Menus::Heal(void)
{
	if (SHflg == false)
	{
		if (xxxx >= 0)
		{
			if (key_.getKeyDown(KEY_INPUT_RIGHT))
			{
				xxxx += 1;
				if (xxxx >= 2)
				{
					xxxx = 0;
				}
			}
			else if (key_.getKeyDown(KEY_INPUT_LEFT) && xxxx >= 0)
			{
				xxxx -= 1;
				if (xxxx < 0)
				{
					xxxx = 1;
				}
			}
			if (yyyy >= 0)
			{
				if (xxxx == 0)
				{
					if (key_.getKeyDown(KEY_INPUT_DOWN))
					{
						yyyy += 1;
						if (yyyy > 6)
						{
							yyyy = 1;
						}
					}
					else if (key_.getKeyDown(KEY_INPUT_UP) && yyyy >= 0)
					{
						yyyy -= 1;
						if (yyyy <= 0)
						{
							yyyy = 6;
						}
					}
				}
				else if (xxxx == 1)
				{
					if (key_.getKeyDown(KEY_INPUT_DOWN))
					{
						yyyy += 1;
						if (yyyy > 1)
						{
							yyyy = 1;
						}
					}
					else if (key_.getKeyDown(KEY_INPUT_UP) && yyyy >= 0)
					{
						yyyy -= 1;
						if (yyyy <= 0)
						{
							yyyy = 1;
						}
					}
				}

			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			SHflg = true;
			ai = 1;
			PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
		}
		
		mEnergy = 0;
		
	}
	else if (SHflg == true)
	{
		if (ai >= 0)
		{
			if (key_.getKeyDown(KEY_INPUT_RIGHT))
			{
				ai += 1;
				if (ai > 3)
				{
					ai = 1;
				}

			}
			else if (key_.getKeyDown(KEY_INPUT_LEFT) && ai >= 0)
			{
				ai -= 1;
				if (ai <= 0)
				{
					ai = 3;
				}

			}
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				if (xxxx == 0)
				{
					if (yyyy == 1)
					{
						if (ai == 1)
						{
							if (ssApple > 0)
							{
								haveNum = 1;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssApple > 0)
							{
								eApple += 1;
								mEnergy += 20;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
								SHflg = false;
							}
							else
							{
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ai == 3)
						{
							ai = 0;
							haveNum = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyyy == 2)
					{

						if (ai == 1)
						{
							if (ssRice > 0)
							{
								haveNum = 2;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssRice > 0)
							{
								eRice += 1;
								mEnergy += 15;
								SHflg = false;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}


						}
						else if (ai == 3)
						{
							ai = 0;
							haveNum = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyyy == 3)
					{

						if (ai == 1)
						{
							if (ssKinominoKusiyaki > 0)
							{
								haveNum = 3;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssKinominoKusiyaki > 0)
							{
								eKinominoKusiyaki += 1;
								mEnergy += 25;
								SHflg = false;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}


						}
						else if (ai == 3)
						{
							ai = 0;
							haveNum = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyyy == 4)
					{

						if (ai == 1)
						{
							if (ssDango > 0)
							{
								haveNum = 4;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssDango > 0)
							{
								mEnergy += 20;
								eDango += 1;
								SHflg = false;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
								SHflg = false;
							}

						}
						else if (ai == 3)
						{
							ai = 0;
							haveNum = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyyy == 5)
					{

						if (ai == 1)
						{
							if (ssFruitDrink > 0)
							{
								haveNum = 5;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
								SHflg = false;
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssFruitDrink > 0)
							{
								mEnergy += 30;
								eFruitDrink += 1;
								SHflg = false;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
								SHflg = false;
							}

						}
						else if (ai == 3)
						{
							haveNum = 0;
							ai = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyyy == 6)
					{

						if (ai == 1)
						{
							if (ssTea > 0)
							{
								haveNum = 6;
								SHflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
								SHflg = false;
							}
						}
						else if (ai == 2)
						{
							//��
							if (ssTea > 0)
							{
								mEnergy = 15;
								eTea += 1;
								SHflg = false;
								PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								SHflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ai == 3)
						{
							haveNum = 0;
							ai = 0;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}

				}
				else if (xxxx == 1)
				{
					if (ai == 1)
					{
						if (ssfish > 0)
						{
							haveNum = 15;
							SHflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
						else
						{
							haveNum = 0;
							SHflg = false;
							PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (ai == 2)
					{
						//��
						if (ssfish > 0)
						{
							efish += 1;
							mEnergy += 10;
							PlaySoundMem(hHandle, DX_PLAYTYPE_BACK);
							SHflg = false;
						}
						else
						{
							SHflg = false;
							PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
						}

					}
					else if (ai == 3)
					{
						ai = 0;
						haveNum = 0;
						SHflg = false;
						PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
					}
				}
			}

		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeAitem(AITEMS_SELECT::AITEM_ID);
		xxxx = 0;
		yyyy = 0;
		SHflg = false;
		PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
	}
}

void Menus::Important(void)
{
	if (SIflg == false)
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

			}
		}
		if (key_.getKeyDown(KEY_INPUT_F))
		{
			SIflg = true;
			ah = 1;
			PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
		}
	}
	else if (SIflg == true)
	{
		if (ah >= 0)
		{
			if (key_.getKeyDown(KEY_INPUT_RIGHT))
			{
				ah += 1;
				if (ah > 2)
				{
					ah = 1;
				}

			}
			else if (key_.getKeyDown(KEY_INPUT_LEFT) && ah >= 0)
			{
				ah -= 1;
				if (ah <= 0)
				{
					ah = 2;
				}

			}
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				if (xxx == 0)
				{
					if (yyy == 1)
					{
						
						if (ah == 1)
						{
							if (ssRagBag > 0)
							{
								haveNum = 7;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								sRagBag = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}
							
						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 2)
					{
						
						if (ah == 1)
						{
							if (ssFishingRodS > 0)
							{
								haveNum = 8;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								sFishingRodS = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							ah = 0;
							haveNum = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 3)
					{
						
						if (ah == 1)
						{
							if (ssPickaxe > 0)
							{
								haveNum = 9;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 4)
					{
						
						if (ah == 1)
						{
							if (ssRantanN > 0)
							{
								haveNum = 10;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 5)
					{
					
						if (ah == 1)
						{
							if (ssHaoriN > 0)
							{
								haveNum = 11;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								sHaoriN = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
				}
				else if (xxx == 1)
				{
					if (yyy == 1)
					{
						
						if (ah == 1)
						{
							if (ssTama > 0)
							{
								haveNum = 12;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								sTama = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 2)
					{
						
						if (ah == 1)
						{
							if (ssKey > 0)
							{
								haveNum = 13;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 3)
					{
						
						if (ah == 1)
						{
							if (ssNumKinomi > 0)
							{
								haveNum = 14;
								
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 4)
					{

						if (ah == 1)
						{
							if (ssStoneR > 0)
							{
								haveNum = 16;
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
					else if (yyy == 5)
					{

						if (ah == 1)
						{
							if (ssStoneB > 0)
							{
								haveNum = 17;
								SIflg = false;
								PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
							}
							else
							{
								haveNum = 0;
								SIflg = false;
								sHaoriN = false;
								PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
							}

						}
						else if (ah == 2)
						{
							haveNum = 0;
							ah = 0;
							SIflg = false;
							PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
						}
					}
				}				
			}
				
		}
	}
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeAitem(AITEMS_SELECT::AITEM_ID);
		xxx = 0;
		yyy = 0;
		PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
	}
}

int Menus::Opution(void)
{
	if (key_.getKeyDown(KEY_INPUT_DOWN))
	{
		yyyyy += 1;
		if (yyyyy >= 2)
		{
			yyyyy = 0;
		}
	}
	if (key_.getKeyDown(KEY_INPUT_UP))
	{
		yyyyy -= 1;
		if (yyyyy < 0)
		{
			yyyyy = 1;
		}
	}

	if (yyyyy == 0)
	{
		if (key_.getKeyDownHold(KEY_INPUT_RIGHT))
		{
			b += 1;
			if (b > 100)
			{
				x = 100;
			}
		}
		if (key_.getKeyDownHold(KEY_INPUT_LEFT))
		{
			b -= 1;
			if (b < 0)
			{
				b = 0;
			}
		}
	}
	else if (yyyyy == 1)
	{

	}
	

	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENUS_SELECT::MENU_ID);
	}

	return b;
}

void Menus::Hint(void)
{
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENUS_SELECT::MENU_ID);
	}
}

void Menus::End(void)
{
	if (key_.getKeyDown(KEY_INPUT_Q))
	{
		ChangeState(MENUS_SELECT::MENU_ID);
	}
	if (key_.getKeyDown(KEY_INPUT_SPACE))
	{
		exit(0);
	}
}

int Menus::OpBgm(void)
{
	return b;
}

void Menus::SetMenu(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h, int ri, int d, int t, int tam, int key, int fish,int je,int bul)
{
	ssApple=a;
	ssKinominoKusiyaki=kk;
	ssFruitDrink=fd;
	ssRice=ri;
	ssDango = d;
	ssTea=t;
	ssFishingRodS=frs;
	ssRagBag=rb;
	ssPickaxe=p;
	ssHaoriN=h;
	ssRantanN=r;
	ssNumKinomi=k;
	ssKey=key;
	ssTama=tam;
	ssfish=fish;
	ssStoneR=je;
	ssStoneB=bul;

}



void Menus::ChangeState(MENUS_SELECT select)
{
	mSelect = select;

	switch (mSelect)
	{
	case Menus::MENUS_SELECT::MENU_ID:

		break;
	case Menus::MENUS_SELECT::MENU_AITEM:

		break;
	case Menus::MENUS_SELECT::MENU_HINT:

		break;
	case Menus::MENUS_SELECT::MENU_OPTION:

		break;
	case Menus::MENUS_SELECT::MENU_END:

		break;
	case Menus::MENUS_SELECT::MENU_MAX:

		break;
	default:
		break;
	}
}

void Menus::ChangeAitem(AITEMS_SELECT select)
{
	mAitem = select;

	switch (mAitem)
	{
	case Menus::AITEMS_SELECT::AITEM_ID:
		break;
	case Menus::AITEMS_SELECT::AITEM_HEAL:
		break;
	case Menus::AITEMS_SELECT::AITEM_IMPORTANT:
		break;
	case Menus::AITEMS_SELECT::AITEM_MAX:
		break;
	default:
		break;
	}
}

int Menus::KnomiE(void)
{
	return eNumKinomi;
}

int Menus::AppleE(void)
{
	return eApple;
}

int Menus::KinominoKusiyakiE(void)
{
	return eKinominoKusiyaki;
}

int Menus::FruitDrinkE(void)
{
	return eFruitDrink;
}

int Menus::FishingRodSE(void)
{
	return eFishingRodS;
}

int Menus::RagBagE(void)
{
	return eRagBag;
}

int Menus::PickaxeE(void)
{
	return ePickaxe;
}

int Menus::mHaoriE(void)
{
	return eHaoriN;
}

int Menus::mRantanE(void)
{
	return eRantanN;
}

int Menus::RiceE(void)
{
	return eRice;
}

int Menus::DangoE(void)
{
	return eDango;
}

int Menus::TeaE(void)
{
	return eTea;
}

int Menus::TamE(void)
{
	return eTama;
}

int Menus::KeyE(void)
{
	return eKey;
}

int Menus::FishE(void)
{
	return efish;
}

int Menus::StoneRE(void)
{
	return eStoneR;
}

int Menus::StoneBE(void)
{
	return eStoneB;
}

int Menus::NumHave(void)
{
	return haveNum;
}

int Menus::En()
{
	return mEnergy;
}
