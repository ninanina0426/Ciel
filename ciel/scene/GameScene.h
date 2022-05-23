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

    //チップ座標を受け取りマップチップ番号を返す
    void GetEvent(Vector2 pos);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::GAME; };   //sceneIDをタイトルに設定

    //player
    Player*mPlayer;

    //マップの変更処理
    bool mMapChange;
    MAP_ID mNextMapID;
    Vector2 mNextPos;

    Vector2 mMapOffset;

};

