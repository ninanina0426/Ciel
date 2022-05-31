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

    //アイテム
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
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneIDをタイトルに設定

    Vector2 PlayerPos;
    //player
    Player mPlayer;

    Menu mMenu;
    Aitem*mAitem;

    //マップの変更処理
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    Vector2 mMapOffset;


    //時間関係
    void TimeManeger(void);
    bool AMflg_;            //朝
    bool PMflg_;            //夕方
    bool Nightflg_;         //夜
    int count_;
    int night_;
    int evening_;
    std::chrono::system_clock::time_point nowTime_;
    std::chrono::system_clock::time_point oldTime_;

};

