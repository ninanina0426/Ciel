#include <DxLib.h>
#include "EventScene.h"

EventScene::EventScene(uniquBaseScn gameScene)
{
    gameScene_ = std::move(gameScene);
    Init();
}

EventScene::~EventScene()
{
}

uniquBaseScn EventScene::Update(uniquBaseScn own)
{
    if (CheckHitKey(KEY_INPUT_F))
    {
        flg_ = true;
    }
    //フラグがtrueになったらゲームシーンに返す
    if (flg_)
    {
        return std::move(gameScene_);
    }
    DrawOwnScn();
    return std::move(own);
}

void EventScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    DrawBox(0, 0, 1080, 609, 0xffabcf, true);

}

bool EventScene::Init(void)
{
    flg_ = false;

    return true;
}

SceneID EventScene::GetSceneID(void)
{
    return SceneID::EVENT;
}
