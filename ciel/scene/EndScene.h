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
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::END; };   //sceneID���^�C�g���ɐݒ�

    std::string endType_;
    PlayerID playerID_;
    Keyboard key_;

    //�O���t�B�b�N�֌W
    int e1_;
    int e3_;
    int e4_;
    int e5_;
    int el2_;
    int el3_;
};

