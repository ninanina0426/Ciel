#pragma once
#include "BaseScene.h"
//#include"../scene/Obj/Player.h"
#include "../stage/stage.h"
class SceneMng;
class Player;

class GameScene : public BaseScene
{
public:
    GameScene(/*SceneMng* manager*/);
    ~GameScene();

    //�`�b�v���W���󂯎��}�b�v�`�b�v�ԍ���Ԃ�
    void GetEvent(Vector2 pos);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneID���^�C�g���ɐݒ�

    //player
    Player*mPlayer;

    //�}�b�v�̕ύX����
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    Vector2 mMapOffset;

};

