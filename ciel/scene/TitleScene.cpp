#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
    Init();
    DrawOwnScn();
}

TitleScene::~TitleScene()
{
}

uniquBaseScn TitleScene::Update(uniquBaseScn own)
{
    if (CheckHitKey(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>();
    }
    DrawOwnScn();//�ʂ�Draw�����ȈוK������
    return std::move(own);
}

void TitleScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    DrawBox(0, 0, 1080, 604, 0xffffff, false);
    DrawString(500, 300, "�^�C�g���\�������", 0xffffff);
    
}

bool TitleScene::Init(void)
{
    return true;
}

