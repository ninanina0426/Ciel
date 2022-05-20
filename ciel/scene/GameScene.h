#pragma once
#include "BaseScene.h"

#include "../stage/stage.h"
class GameScene :
    public BaseScene
{
public:
    GameScene();
    ~GameScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneIDをタイトルに設定

  
};

