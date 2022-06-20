#include <DxLib.h>
#include"../GameScene.h"
#include "../Input/Keyboard.h"
#include"../Obj/Aitem.h"
#include "shop.h"

shop::shop()
{
   /* init();*/
}

shop::~shop()
{
}

bool shop::init(GameScene* parent)
{
    mParent = parent;

    num = 0;
    mPos = { 0,0 };
    y = 0;
    x = 0;
    xx = 0;
    yy = 0;

    moveFlg = false;

    Canflg = false;

    mBoxSe[0] = { 80,75 };
    mBoxSe[1] = { 80,75 };
    mBoxSe[2] = { 250,75 };
    mBoxSe[3] = { 425,75 };
    mBoxSe[4] = { 650,75 };

    mBoxA[0][0] = { 70,40};
    mBoxA[0][1] = { 70,40};
    mBoxA[0][2] = { 70,80};
    mBoxA[0][3] = { 70,120};
    mBoxA[0][4] = { 70,160};
    mBoxA[0][5] = { 70,200};
    mBoxA[0][6] = { 70,240};
    mBoxA[0][7] = { 70,280};
    mBoxA[0][8] = { 70,320};
    mBoxA[0][9] = { 70,360};
   

    mImagSelect = LoadGraph("image/shop/shop1.png");
    mImageHuve= LoadGraph("image/shop/shop2.png");
    mImageNHuve= LoadGraph("image/shop/shop3.png");


    FontSize = CreateFontToHandle(NULL, 40, 5);

    ChangeState(SHOP_SELECT::SELECT);

    mAitems = new Aitem();

    moveSnum = 0;

    return true;
}

void shop::Update(int num)
{
    key_.Update();

    if (num==4)
    {
        moveFlg = true;
        ChangeState(SHOP_SELECT::SELECT);
    }
    if (num == 20)
    {
        moveFlg = true;
    }

    //if (num == 3)
    //{
    //    moveFlg = false;
    //}
    //
    if (moveFlg == true)
    {
        switch (mSelect)
        {
        case shop::SHOP_SELECT::SELECT:
            Select();
            break;
        case shop::SHOP_SELECT::BUY:
            Buy();
            break;
        case shop::SHOP_SELECT::SELL:
            Sell();
            break;
        case shop::SHOP_SELECT::CANSEL:
            Cansel();
            break;
        case shop::SHOP_SELECT::MAX:
            break;
        default:
            break;
        }
    }
    
}

void shop::Draw(int k,int a)
{
    int mKnum = k;
    int mAnum = a;


    if (moveFlg == true)
    {
        //˜g
        DrawGraph(0, 0, mImagSelect, true);
        //Box
        switch (mSelect)
        {
        case shop::SHOP_SELECT::SELECT:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(mBoxSe[x].x_, 155, mBoxSe[x + 1].x_, 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case shop::SHOP_SELECT::BUY:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(70, mBoxA[0][yy].y_ + 210, 545, mBoxA[0][yy + 1].y_ + 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case shop::SHOP_SELECT::SELL:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(70, mBoxA[0][yy].y_ + 210, 545, mBoxA[0][yy + 1].y_ + 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case shop::SHOP_SELECT::CANSEL:

            break;
        case shop::SHOP_SELECT::MAX:
            break;
        default:
            break;
        }

        //•¶Žš
        DrawGraph(0, 0, mImageNHuve, true);

        //box‚Ì•\Ž¦
        switch (mSelect)
        {
        case shop::SHOP_SELECT::SELECT:

            break;
        case shop::SHOP_SELECT::BUY:
        {
             if (mParent->IsKinomi1()==true)
             {
                 DrawRectGraph(70, mBoxA[0][1].y_+210, 70, mBoxA[0][1].y_+210,520,40, mImageHuve, true, false);
             }
             DrawFormatStringToHandle(950, 260, 0xff0000, FontSize,"%d", mKnum);
             DrawFormatStringToHandle(950, 320, 0xff0000, FontSize,"%d", mAnum);
        }
        break;
        case shop::SHOP_SELECT::SELL:
            /* if (flg == true)
             {
                 DrawRectGraph(mPos.x_, mPos.y_, mPos.x_, mPos.y_, 0, 0, mImageHuve, true, false);
             }*/

            DrawFormatStringToHandle(900, 250, 0xff0000, FontSize, "%d", mKnum);
            DrawFormatStringToHandle(900, 400, 0xff0000, FontSize, "%d", mAnum);
            break;
        case shop::SHOP_SELECT::CANSEL:

            break;
        case shop::SHOP_SELECT::MAX:
            break;
        default:
            break;
        }
    }
}

bool shop::Release(void)
{
    DeleteGraph(mImagSelect);
    DeleteGraph(mImageHuve);
    DeleteGraph(mImageNHuve);

    return true;
}

bool shop::SPose(void)
{
    return moveFlg;
}

bool shop::CanselFlg(void)
{
    return Canflg;
}


void shop::Select(void)
{
    Canflg = false;
    if (x >= 0)
    {
        if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            x += 1;
            if (x > 3)
            {
                x = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT) && x >= 0)
        {
            x -= 1;
            if (x <= 0)
            {
                x = 3;
            }

        }
    }
    if (key_.getKeyDown(KEY_INPUT_F))
    {
        if (x == 1)
        {
            ChangeState(SHOP_SELECT::BUY);
            yy = 1;
        }
        if (x == 2)
        {
            ChangeState(SHOP_SELECT::SELL);
            yy = 1;
        }
        if (x == 3)
        {
            ChangeState(SHOP_SELECT::CANSEL); 
            yy = 1;
        }

    }

    
}

void shop::Buy(void)
{
    Canflg = false;
    if (yy >= 0)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            yy += 1;
            if (yy > 6)
            {
                yy = 1;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_UP) && yy >= 0)
        {
            yy -= 1;
            if (yy <= 0)
            {
                yy = 6;
            }
        }
        if (key_.getKeyDown(KEY_INPUT_F)/* || key_.getKeyDown(KEY_INPUT_RETURN)*/)
        {
          
        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(SHOP_SELECT::SELECT);
          
        }
    }

   
}

void shop::Sell(void)
{
    Canflg = false;
    if (yy >= 0)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            yy += 1;
            if (yy > 6)
            {
                yy = 1;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_UP) && yy >= 0)
        {
            yy -= 1;
            if (yy <= 0)
            {
                yy = 6;
            }
        }
        if (key_.getKeyDown(KEY_INPUT_F)/* || key_.getKeyDown(KEY_INPUT_RETURN)*/)
        {

        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(SHOP_SELECT::SELECT);

        }
    }
   
}

void shop::Cansel(void)
{
    moveFlg = false;
    Canflg = true;
    x = 0;
}

void shop::ChangeState(SHOP_SELECT select)
{
    mSelect = select;

    switch (mSelect)
    {
    case shop::SHOP_SELECT::SELECT:
        break;
    case shop::SHOP_SELECT::BUY:
        break;
    case shop::SHOP_SELECT::SELL:
        break;
    case shop::SHOP_SELECT::CANSEL:
        break;
    case shop::SHOP_SELECT::MAX:
        break;
    default:
        break;
    }

}
