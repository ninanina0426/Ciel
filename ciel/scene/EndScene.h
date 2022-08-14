#pragma once
#include "BaseScene.h"
#include <string>
#include "Obj/Player.h"
#include "Input/Keyboard.h"

class EndScene :
    public BaseScene
{
public:
    EndScene(std::string end, PlayerID plID);
    ~EndScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::END; };   //sceneIDをタイトルに設定

    std::string endType_;
    PlayerID playerID_;
    Keyboard key_;

    //グラフィック関係
    int e1_;
    int e3_;
    int e4_;
    int e5_;
    int el2_;
    int el3_;
};

