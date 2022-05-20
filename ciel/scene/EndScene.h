#pragma once
#include "BaseScene.h"
class EndScene :
    public BaseScene
{
public:
    EndScene();
    ~EndScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::END; };   //sceneIDをタイトルに設定

};

