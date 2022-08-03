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
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::TITLE; };   //sceneID���^�C�g���ɐݒ�

    Keyboard key_;

    //�O���t�B�b�N�֌W

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

