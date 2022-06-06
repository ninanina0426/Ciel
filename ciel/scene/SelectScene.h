#pragma once
#include "BaseScene.h"
#include "Obj/Player.h"

class Player;
class SelectScene :
    public BaseScene
{
public:
    SelectScene();
    ~SelectScene();


    //�L�����I��  �i�v���C���[�@�L�[�����@ID�ύX�ʁ@�Ō�̃L�����@�Ōォ��ŏ��֖߂��Ă���L�����j*�Ń|�C���^�[�ɂȂ�
    bool SlectChar(Player* player, DIR dir, int count, PlayerID limID, PlayerID setID);
    //�L������ԁ@�i�v���C���[�@�L�[�����@���ID�j
    bool DicideChar(Player* player, DIR dir, PL_ST plID);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::SELECT; };   //sceneID���^�C�g���ɐݒ�


   
   Player player[3];

};

