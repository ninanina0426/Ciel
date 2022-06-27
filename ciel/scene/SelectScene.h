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


    //キャラ選択  （プレイヤー　ID変更量　最後のキャラ　最後から最初へ戻ってくるキャラ）
    bool SlectChar(Player player, KeyDir dir,int count, PlayerID limID, PlayerID setID);
    //キャラ状態　（プレイヤー　状態ID）
    bool DicideChar(Player player);
private:
    uniquBaseScn Update(uniquBaseScn own) override;     //セレクトシーンUpdata
    void DrawOwnScn() override;                         //セレクトシーンDraw
    bool Init(void) override;                           // セレクトシーン初期化
    SceneID GetSceneID(void) override { return SceneID::SELECT; };   //sceneIDをセレクトに設定

    

    Keyboard key_;      //キー情報格納
    int keydir_;
    Player player_;     //プレイヤー情報格納

    int soyImage_;      //SoyのグラフィックID
    int carenImage_;    //カレンデュラのグラフィックID
    int titi_;          //

    int eff_[16];
    int eff_f[10];
    int eff_b[10];
    int bg_;
    int animcnt_;

    int SHandle;

};

