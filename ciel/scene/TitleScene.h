#pragma once
#include "BaseScene.h"
//#include "Input/Keyboard.h"

class TitleScene :
    public BaseScene
{
public:
    TitleScene();
    ~TitleScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::TITLE; };   //sceneIDをタイトルに設定

    //Keyboard* key_;

    //グラフィック関係
};

