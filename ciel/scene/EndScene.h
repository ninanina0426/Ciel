#pragma once
#include "BaseScene.h"
class EndScene :
    public BaseScene
{
public:
    EndScene();
    ~EndScene();
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::END; };   //sceneID���^�C�g���ɐݒ�

};

