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


    //キャラ選択  （プレイヤー　キー方向　ID変更量　最後のキャラ　最後から最初へ戻ってくるキャラ）*でポインターになる
    bool SlectChar(Player* player, DIR dir, int count, PlayerID limID, PlayerID setID);
    //キャラ状態　（プレイヤー　キー方向　状態ID）
    bool DicideChar(Player* player, DIR dir, PL_ST plID);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //タイトルシーンUpdata
    void DrawOwnScn() override;                         //タイトルシーンDraw
    bool Init(void) override;                           // タイトルシーン初期化
    SceneID GetSceneID(void) override { return SceneID::SELECT; };   //sceneIDをタイトルに設定


   
   Player player[3];

};

