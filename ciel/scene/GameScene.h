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


    //アイテム
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
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneIDをタイトルに設定

    Vector2 PlayerPos;
    Vector2 PlayerSize;
    //player
    Player mPlayer;

    Menu mMenu;

    Aitem *mAitem;

    shop mShop;
    wshop mWshop;


    Npc* mNpc;

    //マップの変更処理
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    FadeInStage fadein_;
    

    Vector2 mMapOffset;

    //時間関係
    void TimeManeger(void);
    bool AMflg_;            //朝
    bool PMflg_;            //夕方
    bool Nightflg_;         //夜
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

