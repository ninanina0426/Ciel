#include <DxLib.h>
#include "SelectScene.h"
#include "GameScene.h"
#include "EventScene.h"
#include "EndScene.h"
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
        if (player_.plID_ == PlayerID::Max)
        {
           auto s= MessageBox(NULL, TEXT("本当にやめるのですか？"),TEXT(""), MB_YESNO| MB_ICONQUESTION);
           if (s == IDYES)
           {
               auto d = MessageBox(NULL, TEXT("ホントニ？　イイノ？"), TEXT(""), MB_YESNO| MB_ICONEXCLAMATION);
               if (d == IDYES)
               {
                   auto f = MessageBox(NULL, TEXT("ホ　ホン　ト　二二　い　い？　イ　ノ？　？"), TEXT(""), MB_YESNO | MB_ICONWARNING);
                   if (f == IDYES)
                   {
                       return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EndScene>("end_3", player_.plID_));
                   }
                   else if (f == IDNO)
                   {
                       player_.state_ = PL_ST::NON;
                       return std::move(own);
                   }
               }
               else if (d == IDNO)
               {
                   player_.state_ = PL_ST::NON;
                   return std::move(own);
               }
           }
           else if (s == IDNO)
           {
               player_.state_ = PL_ST::NON;
               return std::move(own);
           }
        }
        return std::make_unique<FadeInOut>(std::move(own), std::make_unique<EventScene>(std::make_unique<GameScene>(player_.plID_), player_.plID_, 5));
    }

    //playerの選択
    SlectChar(player_,KeyDir::LEFT, 1, PlayerID::Max, PlayerID::Jack);
    SlectChar(player_,KeyDir::RIGHT, -1, PlayerID::Jack, PlayerID::Soy);

    DrawOwnScn();
    animcnt_++;
    return std::move(own);
}

void SelectScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();

    DrawExtendGraph(0, 0, 1080, 609, bg_, true);
    if (player_.plID_ != PlayerID::Max)
    {
        DrawExtendGraph(0, 100, 800, 700, eff_b[(animcnt_ / 10) % 10], true);
        DrawGraph(0, 100, eff_[(animcnt_ / 10) % 15], true);
        DrawGraph(0, 0, Ui_, true);
    }
    
    

    if (player_.plID_ == PlayerID::Jack)
    {
        DrawGraph(0, 0, a, true);
        DrawGraph(280, 20, titi_, true);
    }
    if (player_.plID_ == PlayerID::Calendula)
    {
        DrawGraph(0, 0, b, true);
        DrawGraph(280, 30, carenImage_, true);
    }
    if (player_.plID_ == PlayerID::Soy)
    {
        DrawGraph(0, 0, c, true);
        DrawGraph(300, 30, soyImage_, true);
    }

    if (player_.plID_ != PlayerID::Max)
    {
        DrawExtendGraph(0, 100, 800, 670, eff_f[(animcnt_ / 10) % 10], true);
    }
    else
    {
        DrawString(350, 300, "冒険しない", 0xffffff);
    }
   
    DrawString(200, 300, "<", 0xffffff, true);
    DrawString(600, 300, ">", 0xffffff, true);
    DrawString(950, 580, "Enterで決定", 0xffffff, true);

}

bool SelectScene::Init(void)
{
    player_.plID_ = PlayerID::Jack;

    keydir_ = 0;
    animcnt_ = 0;
    soyImage_ = LoadGraph("./image/player/soy.png");
    carenImage_ = LoadGraph("./image/player/caren.png");
    titi_ = LoadGraph("./image/player/titi.png");
    bg_ = LoadGraph("./image/player/hi.png");
    Ui_ = LoadGraph("./image/player/selectUI.png");

    a = LoadGraph("./image/player/jackN.png");
    b = LoadGraph("./image/player/calN.png");
    c = LoadGraph("./image/player/soyN.png");

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
