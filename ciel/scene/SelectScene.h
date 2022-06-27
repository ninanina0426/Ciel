#pragma once
#include "BaseScene.h"
#include "Obj/Player.h"
#include "Input/Keyboard.h"

enum class KeyDir
{
    RIGHT,
    LEFT
};

class SelectScene :
    public BaseScene
{
public:
    SelectScene();
    ~SelectScene();


    //�L�����I��  �i�v���C���[�@ID�ύX�ʁ@�Ō�̃L�����@�Ōォ��ŏ��֖߂��Ă���L�����j
    bool SlectChar(Player player, KeyDir dir,int count, PlayerID limID, PlayerID setID);
    //�L������ԁ@�i�v���C���[�@���ID�j
    bool DicideChar(Player player);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�Z���N�g�V�[��Updata
    void DrawOwnScn() override;                         //�Z���N�g�V�[��Draw
    bool Init(void) override;                           // �Z���N�g�V�[��������
    SceneID GetSceneID(void) override { return SceneID::SELECT; };   //sceneID���Z���N�g�ɐݒ�

    

    Keyboard key_;      //�L�[���i�[
    int keydir_;
    Player player_;     //�v���C���[���i�[

    int soyImage_;      //Soy�̃O���t�B�b�NID
    int carenImage_;    //�J�����f�����̃O���t�B�b�NID
    int titi_;          //

    int eff_[16];
    int eff_f[10];
    int eff_b[10];
    int bg_;
    int animcnt_;

    int SHandle;

};

