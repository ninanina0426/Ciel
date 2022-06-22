#include <DxLib.h>
#include"../GameScene.h"
#include "../Input/Keyboard.h"
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

    //‚¨‹à
    numRu = 0;
    MoneyFlg = false;

    //”„”ƒ
    bApple=0;
    bKinominoKusiyaki = 0;
    bFruitDrink = 0;
    bFishingRodS = 0;
    bRagBag = 0;
    bPickaxe =0;
    bKinomi = 0;
    bRantan = 0;
    bHaori = 0;

    H = -1;

    //ÝŒÉ
    maxApple=10;
    maxKinominoKusiyaki=5;
    maxFruitDrink=5;
    maxFishingRodS=1;
    maxRagBag=1;
    maxPickaxe=1;
    maxKinomi=0;
    maxRantan=0;
    maxHaori=1;

    //‚¨‹à
    mA=25;
    mKK=30;
    mFD=50;
    mFRS=200;
    mRB=500;
    mP=200;
    mK=0;
    mR=0;
    mH=0;

    SelectNum = 1;
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


    /*mBoxB[0][0] = { 440,426 };*/
    mBoxB[0][0] = { 440,426 };
    mBoxB[1][0] = { 440,426 };
    mBoxB[2][0] = { 534,426 };
    mBoxB[3][0] = { 648,483 };
    mBoxB[4][0] = { 648,483 };
   

    mImagSelect = LoadGraph("image/shop/shop1.png");
    mImagNomal = LoadGraph("image/shop/shop10.png");
    mImageHuve= LoadGraph("image/shop/shop2.png");
    mImageNHuve= LoadGraph("image/shop/shop3.png");

    mImageBsB = LoadGraph("image/shop/shop4.png");
    mImageBsS = LoadGraph("image/shop/shop5.png");
    mImageBuy = LoadGraph("image/shop/shop6.png");


    FontSize = CreateFontToHandle(NULL, 40, 5);

    ChangeState(SHOP_SELECT::SELECT);

    ChangeBS(SHOP_BS::BS_MAX);

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

void shop::Draw(void)
{
   
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

        

        //box‚Ì•\Ž¦
        switch (mSelect)
        {
        case shop::SHOP_SELECT::SELECT:
            //•¶Žš  
            DrawGraph(0, 0, mImagNomal, true);
            break;
        case shop::SHOP_SELECT::BUY:
        {
            DrawGraph(0, 0, mImageNHuve, true);
             if (mParent->IsKinomi1()==true)
             {
                 DrawRectGraph(70, mBoxA[0][1].y_+210, 70, mBoxA[0][1].y_+210,520,40, mImageHuve, true, false);
             }
             if (yy == 1)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sApple);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxApple);
             }
             if (yy == 2)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sKinominoKusiyaki);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxKinominoKusiyaki);
             }
             if (yy == 3)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sFruitDrink);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFruitDrink);
             }
             if (yy == 4)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sFishingRodS);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFishingRodS);
             }
             if (yy == 5)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sRagBag);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxRagBag);
             }
             if (yy == 6)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sPickaxe);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxPickaxe);
             }
        }
        break;
        case shop::SHOP_SELECT::SELL:
            DrawGraph(0, 0, mImageBuy, true);
            if (yy == 1)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sApple);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxApple);*/
            }
            if (yy == 2)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sKinominoKusiyaki);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxKinominoKusiyaki);*/
            }
            if (yy == 3)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sFruitDrink);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFruitDrink);*/
            }
            if (yy == 4)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sFishingRodS);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFishingRodS);*/
            }
            if (yy == 5)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sRagBag);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxRagBag);*/
            }
            if (yy == 6)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sPickaxe);
               /* DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxPickaxe);*/
            }
            break;
        case shop::SHOP_SELECT::CANSEL:
            break;
        case shop::SHOP_SELECT::MAX:
            break;
        default:
            break;
        }
    }

    switch (mBS)
    {
    case shop::SHOP_BS::BS_BUY:
        DrawGraph(0, 0, mImageBsB, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawBox(mBoxB[SelectNum][0].x_, 418, mBoxB[SelectNum + 1][0].x_, 475, GetColor(255, 255, 255), true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (yy == 1)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bApple);
        }
        if (yy == 2)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bKinominoKusiyaki);
        }
        if (yy == 3)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bFruitDrink);
        }
        if (yy == 4)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bFishingRodS);
        }
        if (yy == 5)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bRagBag);
        }
        if (yy == 6)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bPickaxe);
        }
        break;
    case shop::SHOP_BS::BS_SELL:
        DrawGraph(0, 0, mImageBsS, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawBox(mBoxB[SelectNum][0].x_, 418, mBoxB[SelectNum + 1][0].x_, 475, GetColor(255, 255, 255), true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (yy == 1)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bApple);
        }
        if (yy == 2)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bKinominoKusiyaki);
        }
        if (yy == 3)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bFruitDrink);
        }
        if (yy == 4)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bFishingRodS);
        }
        if (yy == 5)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bRagBag);
        }
        if (yy == 6)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bPickaxe);
        }
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }

    DrawFormatString(0, 200, GetColor(255,255,255), "%d", SelectNum);
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

int shop::SetAitem(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h)
{
    gApple=a;
    gKinominoKusiyaki=kk;
    gFruitDrink=fd;
    gFishingRodS=frs;
    gRagBag=rb;
    gPickaxe=p;
    gKinomi=k;
    gRantan=r;
    gHaori=h;

    return true;
}

int shop::SetMoney()
{
    return numRu;
}

bool shop::GetMoney()
{
    return MoneyFlg;
}

void shop::AMoney(int money)
{
    sMoney = money;
}

void shop::SSetNum(void)
{
    H += 1;

    kApple = sApple-H;
    kKinominoKusiyaki = sKinominoKusiyaki/* - H*/;
    kFruitDrink = sFruitDrink/* - H*/;
    kFishingRodS = sFishingRodS/* - H*/;
    kRagBag = sRagBag/* - H*/;
    kPickaxe = sPickaxe/* - H*/;
    kKinomi = sKinomi/* - H*/;
    kRantan = sRantan/* - H*/;
    kHaori = sHaori/* - H*/;

    sApple = gApple+ kApple;
    sKinominoKusiyaki = gKinominoKusiyaki+ kKinominoKusiyaki;
    sFruitDrink = gFruitDrink+ kFruitDrink;
    sFishingRodS = gFishingRodS + kFishingRodS;
    sRagBag = gRagBag+kRagBag;
    sPickaxe = gPickaxe+ kPickaxe;
    sKinomi = gKinomi+kKinomi;
    sRantan = gRantan+ kRantan;
    sHaori = gHaori+kHaori;

}

void shop::SsetAitem(bool flg)
{
    if ((flg==true))
    {
        SSetNum();
    }
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
    if ((yy >= 0)&&(xx==0))
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
            ChangeBS(SHOP_BS::BS_BUY);
            xx = 1;
           /* BSBuy();*/
        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(SHOP_SELECT::SELECT);
          
        }
    }

    if (key_.getKeyDown(KEY_INPUT_F))
    {
    }
    else
    {
        MoneyFlg = false;
    }

    switch (mBS)
    {
    case shop::SHOP_BS::BS_BUY:
        BSBuy();
        break;
    case shop::SHOP_BS::BS_SELL:
     /*   BSSell();*/
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
}

void shop::Sell(void)
{
    Canflg = false;
    if ((yy >= 0) && (xx == 0))
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
            ChangeBS(SHOP_BS::BS_SELL);
            xx = 1;
        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(SHOP_SELECT::SELECT);

        }
    }
    if (key_.getKeyDown(KEY_INPUT_F))
    {
    }
    else
    {
        MoneyFlg = false;
    }

    switch (mBS)
    {
    case shop::SHOP_BS::BS_BUY:
        /*BSBuy();*/
        break;
    case shop::SHOP_BS::BS_SELL:
        BSSell();
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
}

void shop::Cansel(void)
{
    moveFlg = false;
    Canflg = true;
    x = 1;
}

void shop::BSBuy(void)
{
    if (yy == 1)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bApple -= 1;
            if (bApple <= 0)
            {
                bApple = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bApple += 1;
            if (bApple >= maxApple)
            {
                bApple = maxApple;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {
           
            if (SelectNum == 2)
            {
                numRu = -(mA * (bApple));
                if (sMoney >= -(numRu))
                {
                    maxApple -= bApple;
                    sApple += (bApple);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    MoneyFlg = true;
                    bApple = 0;
                }
                else
                {
                    sApple = sApple;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bApple = 0;
                    numRu = 0;
                }
                
            }
            else if (SelectNum == 1)
            {
                sApple = sApple;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bApple = 0;
                numRu = 0;
            }
        }
    }
    if (yy == 2)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bKinominoKusiyaki -= 1;
            if (bKinominoKusiyaki <= 0)
            {
                bKinominoKusiyaki = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bKinominoKusiyaki += 1;
            if (bKinominoKusiyaki >= maxKinominoKusiyaki)
            {
                bKinominoKusiyaki = maxKinominoKusiyaki;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                numRu = -(mKK * (bKinominoKusiyaki));
                if (sMoney >= -(numRu))
                {
                    maxKinominoKusiyaki -= bKinominoKusiyaki;
                    sKinominoKusiyaki += (bKinominoKusiyaki);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bKinominoKusiyaki = 0;
                }
                else
                {
                    sKinominoKusiyaki = sKinominoKusiyaki;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bKinominoKusiyaki = 0;
                }
            }
            else if (SelectNum == 1)
            {
                sKinominoKusiyaki = sKinominoKusiyaki;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bKinominoKusiyaki = 0;
            }
        }
    }
    if (yy == 3)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bFruitDrink -= 1;
            if (bFruitDrink <= 0)
            {
                bFruitDrink = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bFruitDrink += 1;
            if (bFruitDrink >= maxFruitDrink)
            {
                bFruitDrink = maxFruitDrink;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                numRu = -(mFD * (bFruitDrink));
                if (sMoney >= -(numRu))
                {
                    maxFruitDrink -= bFruitDrink;
                    sFruitDrink += (bFruitDrink);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bFruitDrink = 0;
                }
                else
                {
                    sFruitDrink = sFruitDrink;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bFruitDrink = 0;
                }
            }
            else if (SelectNum == 1)
            {
                sFruitDrink = sFruitDrink;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFruitDrink = 0;
            }
        }
    }
    if (yy == 4)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bFishingRodS -= 1;
            if (bFishingRodS <= 0)
            {
                bFishingRodS = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bFishingRodS += 1;
            if (bFishingRodS >= maxFishingRodS)
            {
                bFishingRodS = maxFishingRodS;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                numRu = -(mFRS * (bFishingRodS));
                if (sMoney >= -(numRu))
                {
                    maxFishingRodS -= bFishingRodS;
                    sFishingRodS += (bFishingRodS);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bFishingRodS = 0;
                }
            }
            else if (SelectNum == 1)
            {
                sFishingRodS = sFishingRodS;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFishingRodS = 0;
            }
        }
    }
    if (yy == 5)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bRagBag -= 1;
            if (bRagBag <= 0)
            {
                bRagBag = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bRagBag += 1;
            if (bRagBag >= maxRagBag)
            {
                bRagBag = maxRagBag;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                numRu = -(mRB * (bRagBag));
                if (sMoney >= -(numRu))
                {
                    maxRagBag -= bRagBag;
                    sRagBag += (bRagBag);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bRagBag = 0;
                }
                else
                {
                    sRagBag = sRagBag;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bRagBag = 0;
                }
            }
            else if (SelectNum == 1)
            {
                sRagBag = sRagBag;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bRagBag = 0;
            }
        }
    }
    if (yy == 6)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bPickaxe -= 1;
            if (bPickaxe <= 0)
            {
                bPickaxe = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bPickaxe += 1;
            if (bPickaxe >= maxPickaxe)
            {
                bPickaxe = maxPickaxe;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                numRu = -(mP * (bPickaxe));
                if (sMoney >= -(numRu))
                {
                    maxPickaxe -= bPickaxe;
                    sPickaxe += (bPickaxe);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bPickaxe = 0;
                }
                else
                {
                    sPickaxe = sPickaxe;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bPickaxe = 0;
                }

            }
            else if (SelectNum == 1)
            {
                sPickaxe = sPickaxe;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bPickaxe = 0;
            }
        }
    }
 
}

void shop::BSSell(void)
{
    
    if (yy == 1)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bApple -= 1;
            if (bApple <= 0)
            {
                bApple = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bApple += 1;
            if (bApple >= sApple)
            {
                bApple = sApple;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {
            if (SelectNum == 2)
            {
                sApple -= bApple;
                /*sApple += (bApple);*/
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mA * (bApple));
                MoneyFlg = true;
                SelectNum = 0;
                bApple = 0;
            }
            else if (SelectNum == 1)
            {
                sApple = sApple;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bApple = 0;
            }
            

        }

    }
    if (yy == 2)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bKinominoKusiyaki -= 1;
            if (bKinominoKusiyaki <= 0)
            {
                bKinominoKusiyaki = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bKinominoKusiyaki += 1;
            if (bKinominoKusiyaki >= maxKinominoKusiyaki)
            {
                bKinominoKusiyaki = maxKinominoKusiyaki;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                maxKinominoKusiyaki -= bKinominoKusiyaki;
                sKinominoKusiyaki += (bKinominoKusiyaki);
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mKK * (bKinominoKusiyaki));
                MoneyFlg = true;
                SelectNum = 0;
                bKinominoKusiyaki = 0;
            }
            else if (SelectNum == 1)
            {
                sKinominoKusiyaki = sKinominoKusiyaki;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bKinominoKusiyaki = 0;
            }
        }
    }
    if (yy == 3)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bFruitDrink -= 1;
            if (bFruitDrink <= 0)
            {
                bFruitDrink = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bFruitDrink += 1;
            if (bFruitDrink >= maxFruitDrink)
            {
                bFruitDrink = maxFruitDrink;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                maxFruitDrink -= bFruitDrink;
                sFruitDrink += (bFruitDrink);
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mFD * (bFruitDrink));
                MoneyFlg = true;
                SelectNum = 0;
                bFruitDrink = 0;
            }
            else if (SelectNum == 1)
            {
                sFruitDrink = sFruitDrink;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFruitDrink = 0;
            }
        }
    }
    if (yy == 4)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bFishingRodS -= 1;
            if (bFishingRodS <= 0)
            {
                bFishingRodS = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bFishingRodS += 1;
            if (bFishingRodS >= maxFishingRodS)
            {
                bFishingRodS = maxFishingRodS;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                maxFishingRodS -= bFishingRodS;
                sFishingRodS += (bFishingRodS);
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mFRS * (bFishingRodS));
                MoneyFlg = true;
                SelectNum = 0;
                bFishingRodS = 0;
            }
            else if (SelectNum == 1)
            {
                sFishingRodS = sFishingRodS;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFishingRodS = 0;
            }
        }
    }
    if (yy == 5)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bRagBag -= 1;
            if (bRagBag <= 0)
            {
                bRagBag = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bRagBag += 1;
            if (bRagBag >= maxRagBag)
            {
                bRagBag = maxRagBag;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                maxRagBag -= bRagBag;
                sRagBag += (bRagBag);
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mRB * (bRagBag));
                MoneyFlg = true;
                SelectNum = 0;
                bRagBag = 0;
            }
            else if (SelectNum == 1)
            {
                sRagBag = sRagBag;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bRagBag = 0;
            }
        }
    }
    if (yy == 6)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bPickaxe -= 1;
            if (bPickaxe <= 0)
            {
                bPickaxe = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bPickaxe += 1;
            if (bPickaxe >= maxPickaxe)
            {
                bPickaxe = maxPickaxe;
            }
        }
        else if (key_.getKeyDown(KEY_INPUT_RIGHT))
        {
            SelectNum += 1;
            if (SelectNum >= 3)
            {
                SelectNum = 1;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_LEFT))
        {
            SelectNum -= 1;
            if (SelectNum <= 0)
            {
                SelectNum = 2;
            }
        }

        if (key_.getKeyDown(KEY_INPUT_F))
        {

            if (SelectNum == 2)
            {
                maxPickaxe -= bPickaxe;
                sPickaxe += (bPickaxe);
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mP * (bPickaxe));
                MoneyFlg = true;
                SelectNum = 0;
                bPickaxe = 0;
            }
            else if (SelectNum == 1)
            {
                sPickaxe = sPickaxe;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bPickaxe = 0;
            }
        }
    }
}

void shop::BS(void)
{
    switch (mBS)
    {
    case shop::SHOP_BS::BS_BUY:
        BSBuy();
        break;
    case shop::SHOP_BS::BS_SELL:
        BSSell();
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
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

void shop::ChangeBS(SHOP_BS bs)
{
    mBS = bs;
    switch (mBS)
    {
    case shop::SHOP_BS::BS_BUY:
        break;
    case shop::SHOP_BS::BS_SELL:
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }

}

int shop::SsApple(void)
{
    return sApple;
}

int shop::SsKinominoKusiyaki(void)
{
    return sKinominoKusiyaki;
}

int shop::SsFruitDrink(void)
{
    return sFruitDrink;
}

int shop::SsFishingRodS(void)
{
    return sFishingRodS;
}

int shop::SsRagBag(void)
{
    return sRagBag;
}

int shop::SsPickaxe(void)
{
    return sPickaxe;
}

int shop::SsKinomi(void)
{
    return sKinomi;
}

int shop::SsRantan(void)
{
    return sRantan;
}

int shop::SsHaori(void)
{
    return sHaori;
}