#pragma once
#include "BaseScene.h"
#include "Input/Keyboard.h"

#define  BGSIZE (1200)

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

    Keyboard key_;

    //グラフィック関係

    int title_;
    int bgid_;
    int bg1_;
    int bg2_;
    int push_;
    int blink_;
    Vector2 pos1_;
    int alpha_;

    int SHandle;

    bool tabF_;
    int tb_;

};

