#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "GameScene.h"
#include "Input/Keyboard.h"
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

    
    if (key_.getKeyDown(KEY_INPUT_SPACE))
    {
        return std::make_unique<GameScene>();
    }
    DrawOwnScn();//個別のDraw処理な為必ず書く
    return std::move(own);
}

void TitleScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    //if (//key_->getKeyDown(KEY_INPUT_A))
    //{
    //    DrawString(100, 100, "aaaaaaaa", 0xffffff);
    //}
    //DrawBox(0, 0, 1080, 604, 0xffffff, false);
    //DrawString(500, 300, "タイトル表示するよ", 0xffffff);
>>>>>>> f24996e4e0ad12600b7d95cd93c919c1cb3e8240
    
}

bool TitleScene::Init(void)
{

    return true;
}

