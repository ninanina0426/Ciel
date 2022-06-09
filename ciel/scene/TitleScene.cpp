#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "GameScene.h"
#include "SelectScene.h"

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
    key_.Update();
    if (key_.getKeyDown(KEY_INPUT_SPACE))
    {
        return std::make_unique<SelectScene>();
    }
    
    DrawOwnScn();//ŒÂ•Ê‚ÌDrawˆ—‚Èˆ×•K‚¸‘‚­
    return std::move(own);
}

void TitleScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();


    DrawGraph(100, 100, title_, true);
    
}

bool TitleScene::Init(void)
{
    title_ = LoadGraph("./image/title.png");
    return true;
}

