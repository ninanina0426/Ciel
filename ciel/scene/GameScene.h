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
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneID���^�C�g���ɐݒ�

  
};

