#include <DxLib.h>
#include "SelectScene.h"
#include "GameScene.h"
#include "EventScene.h"


SelectScene::SelectScene()
{
    Init();
}

SelectScene::~SelectScene()
{
    DeleteSoundMem(SHandle);
}

bool SelectScene::SlectChar(Player player, int count, PlayerID limID, PlayerID setID)
{
    //キャラ選択が終わっていたら抜ける
    if (player_.state_ != PL_ST::NON)
    {
        return false;
    }
  
    //キャラクター選択
    if (key_.getKeyDown(KEY_INPUT_LEFT))
    {
        if (player_.plID_ != limID)
        {
            player_.plID_ = static_cast<PlayerID>(static_cast<int>(player_.plID_) + count);
        }
        else
        {
            player_.plID_ = setID;
        }
        return true;
    }
    return false;
}

bool SelectScene::DicideChar(Player player)
{
    if (key_.getKeyDown(KEY_INPUT_RETURN))
    {
        player_.state_ = PL_ST::ALIVE;
        return true;
    }

    return false;
}

uniquBaseScn SelectScene::Update(uniquBaseScn own)
{
    //キー情報のアップデート
    key_.Update();

    //キャラ選択が終わったらシーン移送
    if (DicideChar(player_))
    {
        return std::make_unique<EventScene>(std::make_unique<GameScene>(player_.plID_), player_.plID_, 5);
    }

    //playerの選択
    SlectChar(player_, 1, PlayerID::Soy, PlayerID::iti);

    DrawOwnScn();

    return std::move(own);
}

void SelectScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    if (player_.plID_ == PlayerID::iti)
    {
        DrawGraph(0, 0, titi_, true);
    }
    if (player_.plID_ == PlayerID::Calendula)
    {
        DrawGraph(0, 0, carenImage_, true);
    }
    if (player_.plID_ == PlayerID::Soy)
    {
        DrawGraph(0, 0, soyImage_, true);
    }
   
    DrawFormatString(0, 0, 0xffffff, "playerID:%d", player_.plID_);
}

bool SelectScene::Init(void)
{
    player_.plID_ = PlayerID::iti;

    soyImage_ = LoadGraph("./image/player/soy.png");
    carenImage_ = LoadGraph("./image/player/caren.png");
    titi_ = LoadGraph("./image/player/titi.png");

    SHandle = LoadSoundMem("image/music/select.ogg");

    // 音量の設定
    ChangeVolumeSoundMem(100, SHandle);



    if (CheckSoundMem(SHandle) == 0)
    {
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);
    }


    return true;
}
