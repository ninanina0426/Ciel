#pragma once
#include <chrono>
#include "BaseScene.h"
#include"../scene/Input/Keyboard.h"
#include"../scene/Obj/Player.h"
#include"../scene/Obj/Menu.h"
#include"Obj/shop.h"
#include"Obj/wshop.h"
#include "../stage/stage.h"
#include "../stage/transitionStage/FadeInStage.h"
#include "Obj/UI.h"
class SceneMng;
class Aitem;
class BGM;
class Npc;
class Chat;
class Layer;
class Masuku;

class GameScene : public BaseScene
{
public:
    GameScene() {};
    GameScene(PlayerID playerID);
    ~GameScene();


    //�A�C�e��
    bool IsTama1(void);
    bool IsTama2(void);
    bool IsTama3(void);
    bool IsTama4(void);
    bool IsTama5(void);

    bool IsKinomi1(void);
    bool IsKinomi2(void);
    bool IsKinomi3(void);
    bool IsKinomi4(void);
    bool IsKinomi5(void);

    bool IsHaori(void);

    bool IsRantan(void);


    bool mEnd();

    int SHandle;

    bool mPose;
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //�^�C�g���V�[��Updata
    void DrawOwnScn() override;                         //�^�C�g���V�[��Draw
    bool Init(void) override;                           // �^�C�g���V�[��������
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneID���^�C�g���ɐݒ�

    Vector2 PlayerPos;
    Vector2 PlayerSize;
    //player
    Player mPlayer;

    Menu mMenu;

    Aitem *mAitem;

    shop mShop;
    wshop mWshop;


    Npc* mNpc;

    //�}�b�v�̕ύX����
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    FadeInStage fadein_;
    

    Vector2 mMapOffset;

    //���Ԋ֌W
    void TimeManeger(void);
    bool AMflg_;            //��
    bool PMflg_;            //�[��
    bool Nightflg_;         //��
    bool skyflg_;
    int skycnt_;
    int count_;
    int night_;
    int evening_;
    int asa_;
    int yuu_;
    int you_;
    std::chrono::system_clock::time_point nowTime_;
    std::chrono::system_clock::time_point oldTime_;

    Chat* mChat;

    Keyboard key_;

    BGM*mBgm;

    Layer* mLayer;

    int x;
    

    UI ui_;

    Masuku* mMasuku;
};

