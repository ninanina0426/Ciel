#include <DxLib.h>
#include "EndScene.h"
#include "TitleScene.h"
#include "../stage/StageMng.h"
#include "Transition/FadeInOut.h"

EndScene::EndScene(std::string end, PlayerID plID)
{
    endType_ = end;
	playerID_ = plID;
	lpMapMng.Init();
    Init();
}

EndScene::~EndScene()
{
}

uniquBaseScn EndScene::Update(uniquBaseScn own)
{
	key_.Update();
	if (key_.getKeyDown(KEY_INPUT_SPACE))
	{
		return std::make_unique<FadeInOut>(std::move(own), std::make_unique<TitleScene>());
	}
	DrawOwnScn();
    return std::move(own);
}

void EndScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
	if (endType_ == "end_1")
	{
		DrawGraph(0, 0, e1_, false);
		DrawFormatString(750, 590, 0xffffff, "END_1 #����Ȃ��y�n�ɂ͓G��Ȃ�");
	}
	switch (playerID_)
	{
	case PlayerID::Jack:
		if (endType_ == "end_2")
		{
			DrawExtendGraph(0, 0, 1080, 609, el2_, false);
			DrawFormatString(850, 590, 0x000000, "END_2 #�ꝺ����t�]�l��");
		}
		break;
	case PlayerID::Calendula:
		if (endType_ == "end_2")
		{

			DrawFormatString(850, 590, 0xffffff, "END_2 #���|�I�Ȕ�����");
		}
		break;
	case PlayerID::Soy:
		if (endType_ == "end_2")
		{
			DrawExtendGraph(0, 0, 1080, 609, el3_, false);
			DrawFormatString(850, 590, GetColor(255,0,0), "END_2 #�l�ԂɃi���^�I");
		}
		break;
	case PlayerID::Max:
		if (endType_ == "end_3")
		{
			DrawGraph(0, 0, e3_, false);
			DrawFormatString(680, 590, 0x000000, "END_3 #�D��S���Ȃ��Ȃ�Ă܂�Ȃ��l�Ԃ���");
		}
		break;
	default:
		break;
	}
	
	if (endType_ == "end_4")
	{
		DrawExtendGraph(0, 0, 1080, 610, e4_, false);
		DrawFormatString(700, 590, 0xffffff, "END_4 #�{���̍K���Ƃ͉��Ȃ̂�");
	}
	if (endType_ == "end_5")
	{
		DrawExtendGraph(0, 0, 1080, 610, e5_, false);
		DrawFormatString(850, 590, 0xffffff, "END_5 #�J���_���Z�c��");
	}
	if (endType_ == "end_6")
	{
		DrawExtendGraph(0, 0, 1080, 610, e5_, false);
		DrawFormatString(850, 590, 0xffffff, "END_6 #�Â����炢�Â��N���C�B");
	}
}

bool EndScene::Init(void)
{
	e1_ = LoadGraph("./image/move/�X.jpg");
	el2_ = LoadGraph("./image/kane.jpg");
	el3_ = LoadGraph("./image/negai.png");
	e3_ = LoadGraph("./image/ui/noizu.jpg");
	e4_ = LoadGraph("./image/love.jpg");
	e5_ = LoadGraph("./image/move/yourdead.png");
    return true;
}
