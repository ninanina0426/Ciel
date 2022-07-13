#include <DxLib.h>
#include "EndScene.h"
#include "TitleScene.h"
#include "Transition/FadeInOut.h"

EndScene::EndScene(std::string end, PlayerID plID)
{
    endType_ = end;
	playerID_ = plID;
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
	case PlayerID::iti:
		if (endType_ == "end_2")
		{

			DrawFormatString(800, 590, 0xffffff, "END_2 #�ꝺ����t�]�l��");
		}
		break;
	case PlayerID::Calendula:
		if (endType_ == "end_2")
		{

			DrawFormatString(800, 590, 0xffffff, "END_2 #���|�I�Ȕ�����");
		}
		break;
	case PlayerID::Soy:
		if (endType_ == "end_2")
		{

			DrawFormatString(800, 590, 0xffffff, "END_2 #�l�ԂɃi���^�I");
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
		DrawFormatString(450, 600, 0xffffff, "END_4 #�{���̍K���Ƃ͉��Ȃ̂�");
	}

}

bool EndScene::Init(void)
{
	e1_ = LoadGraph("./image/move/�X.jpg");
	e3_ = LoadGraph("./image/ui/noizu.jpg");

    return true;
}
