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
    DeleteSoundMem(SHandle);
}

uniquBaseScn TitleScene::Update(uniquBaseScn own)
{
    key_.Update();
    if (key_.getKeyDown(KEY_INPUT_SPACE))
    {
        return std::make_unique<SelectScene>();
    }
    
    DrawOwnScn();//個別のDraw処理な為必ず書く
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
   
    SHandle = LoadSoundMem("image/music/titel.ogg");

    // 音量の設定
    ChangeVolumeSoundMem(100, SHandle);

   

    if (CheckSoundMem(SHandle) == 0)
    {
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);
    }


    return true;
}

