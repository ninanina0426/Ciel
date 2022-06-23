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
    //�t���O��true�ɂȂ�����Q�[���V�[���ɕԂ�
    if (flg_)
    {
        return std::move(gameScene_);
    }
    DrawOwnScn();
    if (GetMovieStateToGraph(move1_) == 0)
    {
        flg_ = true;
    }
    return std::move(own);
}

void EventScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    DrawBox(0, 0, 1080, 609, 0xffabcf, true);
   // DrawExtendGraph(0, 0, 1080,609,move1_, false);
}

bool EventScene::Init(void)
{
    flg_ = false;
    //move1_ = LoadGraph("./image/move/video.avi");
    PlayMovieToGraph(move1_);
    return true;
}

SceneID EventScene::GetSceneID(void)
{
    return SceneID::EVENT;
}
