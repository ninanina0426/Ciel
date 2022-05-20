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
    DrawOwnScn();//ŒÂ•Ê‚ÌDrawˆ—‚Èˆ×•K‚¸‘‚­
    return std::move(own);
}

void TitleScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    DrawBox(0, 0, 720, 405, 0xffffff, false);
    
}

bool TitleScene::Init(void)
{
    return true;
}

