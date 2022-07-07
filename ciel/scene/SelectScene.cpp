#include <DxLib.h>
#include "SelectScene.h"
#include "GameScene.h"
#include "EventScene.h"
#include "Transition/FadeInOut.h"

SelectScene::SelectScene()
{
    Init();
}

SelectScene::~SelectScene()
{
    DeleteSoundMem(SHandle);
}

bool SelectScene::SlectChar(Player player, KeyDir dir, int count, PlayerID limID, PlayerID setID)
{
    //キャラ選択が終わっていたら抜ける
    if (player_.state_ != PL_ST::NON)
    {
        return false;
    }
  
    if (dir == KeyDir::RIGHT)
    {
        keydir_ = KEY_INPUT_RIGHT;
    }
    else
    {
        keydir_ = KEY_INPUT_LEFT;
    }

    
    //キャラクター選択
    if (key_.getKeyDown(keydir_))
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
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EventScene>(std::make_unique<GameScene>(player_.plID_), player_.plID_, 5));
    }

    //playerの選択
    SlectChar(player_,KeyDir::LEFT, 1, PlayerID::Soy, PlayerID::iti);
    SlectChar(player_,KeyDir::RIGHT, -1, PlayerID::iti, PlayerID::Soy);

    DrawOwnScn();
    animcnt_++;
    return std::move(own);
}

void SelectScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    DrawExtendGraph(0, 0, 1080, 609, bg_, true);
    DrawExtendGraph(0, 100, 800, 700, eff_b[(animcnt_ / 10) % 10], true);
    DrawGraph(0, 100, eff_[(animcnt_/10)%15], true);
    
    DrawBox(650, 50, 1030, 350, 0xffffff, false);
    DrawBox(0, 30, 200, 80, 0xffffff, false);

    if (player_.plID_ == PlayerID::iti)
    {
        DrawString(20, 50, "ジャック", 0xffffff, true);
        DrawGraph(280, 20, titi_, true);
    }
    if (player_.plID_ == PlayerID::Calendula)
    {
        DrawString(20, 50, "カレンデュラ", 0xffffff, true);
        DrawGraph(280, 30, carenImage_, true);
    }
    if (player_.plID_ == PlayerID::Soy)
    {
        DrawString(20, 50, "SOY", 0xffffff, true);
        DrawGraph(300, 30, soyImage_, true);
    }

    DrawExtendGraph(0, 100, 800, 670, eff_f[(animcnt_ / 10) % 10], true);
    DrawString(200, 300, "<", 0xffffff, true);
    DrawString(600, 300, ">", 0xffffff, true);
    DrawString(950, 580, "Enterで決定", 0xffffff, true);

}

bool SelectScene::Init(void)
{
    player_.plID_ = PlayerID::iti;

    keydir_ = 0;
    animcnt_ = 0;
    soyImage_ = LoadGraph("./image/player/soy.png");
    carenImage_ = LoadGraph("./image/player/caren.png");
    titi_ = LoadGraph("./image/player/titi.png");
    bg_ = LoadGraph("./image/player/hi.png");
    LoadDivGraph("./image/player/eff.png", 16, 2, 8, 800, 600, eff_, true);
    LoadDivGraph("./image/player/eff_f.png", 10, 5, 2, 400, 400, eff_f, true);
    LoadDivGraph("./image/player/eff_b.png", 10, 5, 2, 400, 400, eff_b, true);


    SHandle = LoadSoundMem("image/music/select.ogg");

    // 音量の設定
    ChangeVolumeSoundMem(100, SHandle);



    if (CheckSoundMem(SHandle) == 0)
    {
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);
    }


    return true;
}
