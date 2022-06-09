#include <DxLib.h>
#include "SelectScene.h"
#include "GameScene.h"


SelectScene::SelectScene()
{
    Init();
}

SelectScene::~SelectScene()
{
}

bool SelectScene::SlectChar(Player player, int count, PlayerID limID, PlayerID setID)
{
    //�L�����I�����I����Ă����甲����
    if (player_.state_ != PL_ST::NON)
    {
        return false;
    }
  
    //�L�����N�^�[�I��
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
    //�L�[���̃A�b�v�f�[�g
    key_.Update();

    //�L�����I�����I�������V�[���ڑ�
    if (DicideChar(player_))
    {
        return std::make_unique<GameScene>(player_.plID_);
    }

    //player�̑I��
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

    return true;
}
