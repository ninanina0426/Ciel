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
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::TITLE; };   //sceneID���^�C�g���ɐݒ�

    //Keyboard* key_;

    //�O���t�B�b�N�֌W
};

