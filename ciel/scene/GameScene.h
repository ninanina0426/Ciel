#pragma once
#include <chrono>
#include "BaseScene.h"
#include"../scene/Obj/Player.h"
#include"../scene/Obj/Menu.h"
#include "../stage/stage.h"
class SceneMng;
class Aitem;


class GameScene : public BaseScene
{
public:
    GameScene(/*SceneMng* manager*/);
    ~GameScene();

    //�A�C�e��
    bool IsKami1(void);
    bool IsKami2(void);
    bool mKami3(void);
    bool mKami4(void);
    bool mKami5(void);

    bool mTma(void);
    bool mMasinngan(void);
    bool mHoutai(void);
    bool mHeal(void);
    bool mKey(void);
    bool mbook(void);
    bool mMagazinn(void);

    bool mEnd();

    bool mPose;
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneID���^�C�g���ɐݒ�

    Vector2 PlayerPos;
    //player
    Player mPlayer;

    Menu mMenu;
    Aitem*mAitem;

    //�}�b�v�̕ύX����
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    Vector2 mMapOffset;


    //���Ԋ֌W
    void TimeManeger(void);
    bool AMflg_;            //��
    bool PMflg_;            //�[��
    bool Nightflg_;         //��
    int count_;
    int night_;
    int evening_;
    std::chrono::system_clock::time_point nowTime_;
    std::chrono::system_clock::time_point oldTime_;

};

