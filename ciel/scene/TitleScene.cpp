#include <DxLib.h>
#include <memory>
#include "TitleScene.h"
#include "SelectScene.h"
#include "Transition/FadeInOut.h"

TitleScene::TitleScene()
{
    Init();
    DrawOwnScn();
}

TitleScene::~TitleScene()
{
    DeleteSoundMem(SHandle);
}

uniquBaseScn TitleScene::Update(uniquBaseScn own)
{
    key_.Update();
    if (key_.getKeyDown(KEY_INPUT_SPACE))
    {
        return std::make_unique<FadeInOut>(std::move(own),std::make_unique<SelectScene>());
    }
    
    DrawOwnScn();//å¬ï ÇÃDrawèàóùÇ»à◊ïKÇ∏èëÇ≠
    pos1_.y_--;
    pos1_.x_--;
    blink_++;
    alpha_++;
    

    if (tabF_ == false)
    {
        if (key_.getKeyDown(KEY_INPUT_TAB))
        {
            tabF_ = true;

            //QuestIns.questCmpFlg[1]
        }
    }
    else
    {
        if (key_.getKeyDown(KEY_INPUT_TAB))
        {
            tabF_ = false;
        }
    }

    return std::move(own);
}

void TitleScene::DrawOwnScn()
{
    SetDrawScreen(sceneScrID_);
    ClsDrawScreen();
    DrawGraph(0, 0, bgid_, true);
    DrawGraph(1050, 0, tb_, true);
    if (pos1_.y_ < -BGSIZE)
    {
        pos1_.y_ = pos1_.y_ +BGSIZE*2;
    }
    if (pos1_.x_ < -BGSIZE)
    {
        pos1_.x_ = pos1_.x_ + BGSIZE*2;
    }
    SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
    DrawGraph(0, pos1_.y_, bg1_, true);
    DrawGraph(0, pos1_.x_, bg2_, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    if (alpha_ > 255)
    {
        if ((blink_ / 60) % 2 == 0)
        {
            DrawGraph(0, 0, push_, true);
        }
    }
    
    if (tabF_)
    {
        DrawGraph(780, 0, tb_, true);
    }
  
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
    //800,550
    DrawExtendGraph(0, 0, 480, 330, title_, true);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
    
}

bool TitleScene::Init(void)
{
    title_ = LoadGraph("./image/title.png");
    bgid_ = LoadGraph("./image/sky.jpg");
    bg1_ = LoadGraph("./image/kirakira.png");
    bg2_ = LoadGraph("./image/kirakira.png");
    push_ = LoadGraph("./image/push_spce.png");
    alpha_ = 0;
    pos1_ = { -BGSIZE,0 };
    SHandle = LoadSoundMem("image/music/titel.ogg");
    tb_ = LoadGraph("./image/ui/tub.jpg");
    blink_ = 0;
    // âπó ÇÃê›íË
    ChangeVolumeSoundMem(100, SHandle);
    
    tabF_ = false;
   

    if (CheckSoundMem(SHandle) == 0)
    {
        PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);
    }


    return true;
}

