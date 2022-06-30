#include <DxLib.h>
#include "../Input/Keyboard.h"
#include "shop.h"

shop::shop()
{
   /* init();*/
}

shop::~shop()
{
}

bool shop::init(void)
{
   
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
    bRice=0;
    bDango=0;
    bTea=0;

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
    maxRice=0;
    maxDango=0;
    maxTea=0;

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
    mRi = 30;
    mD = 35;
    mT = 20;

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
    mImageBuy = LoadGraph("image/shop/shop20.png");

    cHandle = LoadSoundMem("image/Sound/ƒLƒƒƒ“ƒZƒ‹5.ogg");
    kHandle = LoadSoundMem("image/Sound/‹àŠz•\Ž¦.ogg");


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
            DrawGraph(0, 0, mImageHuve, true);
             /*if (mParent->IsKinomi1()==true)
             {
                 DrawRectGraph(70, mBoxA[0][1].y_+210, 70, mBoxA[0][1].y_+210,520,40, mImageHuve, true, false);
             }*/
             if (yy == 1)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gApple);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxApple);
             }
             if (yy == 2)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gKinominoKusiyaki);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxKinominoKusiyaki);
             }
             if (yy == 3)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gFruitDrink);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFruitDrink);
             }
             if (yy == 4)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gFishingRodS);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFishingRodS);
             }
             if (yy == 5)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gRagBag);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxRagBag);
             }
             if (yy == 6)
             {
                 DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gPickaxe);
                 DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxPickaxe);
             }
        }
        break;
        case shop::SHOP_SELECT::SELL:
            DrawGraph(0, 0, mImageBuy, true);
            if (yy == 1)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gApple);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxApple);*/
            }
            if (yy == 2)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gKinominoKusiyaki);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxKinominoKusiyaki);*/
            }
            if (yy == 3)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gFruitDrink);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFruitDrink);*/
            }
            if (yy == 4)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gRice);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxFishingRodS);*/
            }
            if (yy == 5)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gDango);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxRagBag);*/
            }
            if (yy == 6)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", gTea);
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

        DrawFormatStringToHandle(900, 170, 0xff0000, FontSize, "%d", haveRu);
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
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bRice);
        }
        if (yy == 5)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bDango);
        }
        if (yy == 6)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bTea);
        }
        break;
    case shop::SHOP_BS::BS_MAX:
        break;
    default:
        break;
    }

    /*DrawFormatString(0, 200, GetColor(255,255,255), "%d", SelectNum);*/

   
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

int shop::SetAitem(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h, int ri, int d, int t)
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
    gRice = ri;
    gDango = d;
    gTea = t;

    if (gFishingRodS == 1)
    {
        maxFishingRodS = 0;
        sFishingRodS = gFishingRodS;
    }
    /*if (sFishingRodS == 1)
    {
        maxFishingRodS = 0;
        sFishingRodS = gFishingRodS;
    }*/
    if (gRagBag == 1)
    {
        maxRagBag = 0;
        sRagBag = gRagBag;
    }
   /* if (sRagBag == 1)
    {
        maxRagBag = 0;
        sRagBag = gRagBag;
    }*/
    if (gPickaxe == 1)
    {
        maxPickaxe = 0;
        sPickaxe = gPickaxe;
    }
    /*if (sRagBag == 1)
    {
        maxPickaxe = 0;
        sPickaxe = gPickaxe;
    }*/

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

void  shop::sHaveMoney(int ru)
{
    haveRu = ru;

}

void shop::AMoney(int money)
{
    sMoney = money;
}

void shop::SSetNum(void)
{
    //H += 1;

    //kApple = sApple-H;
    //kKinominoKusiyaki = sKinominoKusiyaki/* - H*/;
    //kFruitDrink = sFruitDrink/* - H*/;
    //kFishingRodS = sFishingRodS/* - H*/;
    //kRagBag = sRagBag/* - H*/;
    //kPickaxe = sPickaxe/* - H*/;
    //kKinomi = sKinomi/* - H*/;
    //kRantan = sRantan/* - H*/;
    //kHaori = sHaori/* - H*/;
    //kRice = sRice;
    //kDango = sDango/* - H*/;
    //kTea = sTea/* - H*/;

    //sApple = gApple+ kApple;
    //sKinominoKusiyaki = gKinominoKusiyaki+ kKinominoKusiyaki;
    //sFruitDrink = gFruitDrink+ kFruitDrink;
    //sFishingRodS = gFishingRodS + kFishingRodS;
    //sRagBag = gRagBag+kRagBag;
    //sPickaxe = gPickaxe+ kPickaxe;
    //sKinomi = gKinomi+kKinomi;
    //sRantan = gRantan+ kRantan;
    //sHaori = gHaori+kHaori;
    //sRice = gRice + kRice;
    //sDango = gDango + kDango;
    //sTea = gTea + kTea;

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
                    kApple = bApple+sApple;
                    sApple += (bApple);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    MoneyFlg = true;
                    bApple = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sApple = sApple;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bApple = 0;
                    numRu = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                    kKinominoKusiyaki = bKinominoKusiyaki + sKinominoKusiyaki;
                    sKinominoKusiyaki += (bKinominoKusiyaki);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bKinominoKusiyaki = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sKinominoKusiyaki = sKinominoKusiyaki;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bKinominoKusiyaki = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sKinominoKusiyaki = sKinominoKusiyaki;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bKinominoKusiyaki = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                    kFruitDrink = bFruitDrink + sFruitDrink;
                    sFruitDrink += (bFruitDrink);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bFruitDrink = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sFruitDrink = sFruitDrink;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bFruitDrink = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sFruitDrink = sFruitDrink;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFruitDrink = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                    kFishingRodS = bFishingRodS + sFishingRodS;
                    sFishingRodS += (bFishingRodS);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bFishingRodS = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);

                }
                else
                {
                    sFishingRodS = sFishingRodS;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bFishingRodS = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sFishingRodS = sFishingRodS;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFishingRodS = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                    kRagBag = bRagBag + sRagBag;
                    sRagBag += (bRagBag);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bRagBag = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sRagBag = sRagBag;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bRagBag = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sRagBag = sRagBag;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bRagBag = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
                    kPickaxe = bPickaxe + sPickaxe;
                    sPickaxe += (bPickaxe);
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bPickaxe = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sPickaxe = sPickaxe;
                    xx = 0;
                    ChangeBS(SHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bPickaxe = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }

            }
            else if (SelectNum == 1)
            {
                sPickaxe = sPickaxe;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bPickaxe = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
            if (bApple >= gApple)
            {
                bApple = gApple;
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
                gApple -= bApple;
                kApple = -bApple + sApple;
                sApple = kApple;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mA * (bApple));
                MoneyFlg = true;
                SelectNum = 0;
                bApple = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sApple = sApple;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bApple = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
            if (bKinominoKusiyaki >= gKinominoKusiyaki)
            {
                bKinominoKusiyaki = gKinominoKusiyaki;
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
                gKinominoKusiyaki -= bKinominoKusiyaki;
                kKinominoKusiyaki = -bKinominoKusiyaki + sKinominoKusiyaki;
                sKinominoKusiyaki = kKinominoKusiyaki;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mKK * (bKinominoKusiyaki));
                MoneyFlg = true;
                SelectNum = 0;
                bKinominoKusiyaki = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sKinominoKusiyaki = sKinominoKusiyaki;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bKinominoKusiyaki = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
            if (bFruitDrink >= gFruitDrink)
            {
                bFruitDrink = gFruitDrink;
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
                gFruitDrink -= bFruitDrink;
                kFruitDrink = -bFruitDrink + sFruitDrink;
                sFruitDrink = kFruitDrink;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mFD * (bFruitDrink));
                MoneyFlg = true;
                SelectNum = 0;
                bFruitDrink = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sFruitDrink = sFruitDrink;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bFruitDrink = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
    if (yy == 4)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bRice -= 1;
            if (bRice <= 0)
            {
                bRice = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bRice += 1;
            if (bRice >= gRice)
            {
                bRice = gRice;
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
                gRice -= bRice;
                kRice = -bRice + sRice;
                sRice = kRice;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mRi * (bRice));
                MoneyFlg = true;
                SelectNum = 0;
                bRice = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sRice = sRice;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bRice = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }


        }

    }
    if (yy == 5)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bDango -= 1;
            if (bDango <= 0)
            {
                bDango = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bDango += 1;
            if (bDango >= gDango)
            {
                bDango = gDango;
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
                gDango -= bDango;
                kDango = -bDango + sDango;
                sDango = kDango;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mD * (bDango));
                MoneyFlg = true;
                SelectNum = 0;
                bDango = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sDango = sDango;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bDango = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
    if (yy == 6)
    {
        if (key_.getKeyDown(KEY_INPUT_DOWN))
        {
            bTea -= 1;
            if (bTea <= 0)
            {
                bTea = 0;
            }

        }
        else if (key_.getKeyDown(KEY_INPUT_UP))
        {
            bTea += 1;
            if (bTea >= gTea)
            {
                bTea = gTea;
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
                gTea -= bTea;
                kTea = -bTea + sTea;
                sTea = kTea;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                numRu = (mT * (bTea));
                MoneyFlg = true;
                SelectNum = 0;
                bTea = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sTea = sTea;
                xx = 0;
                ChangeBS(SHOP_BS::BS_MAX);
                SelectNum = 0;
                bTea = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
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
    return kApple;
}

int shop::SsKinominoKusiyaki(void)
{
    return kKinominoKusiyaki;
}

int shop::SsFruitDrink(void)
{
    return kFruitDrink;
}

int shop::SsFishingRodS(void)
{
    return kFishingRodS;
}

int shop::SsRagBag(void)
{
    return kRagBag;
}

int shop::SsPickaxe(void)
{
    return kPickaxe;
}

int shop::SsKinomi(void)
{
    return kKinomi;
}

int shop::SsRantan(void)
{
    return kRantan;
}

int shop::SsHaori(void)
{
    return kHaori;
}

int shop::SsRice(void)
{
    return kRice;
}

int shop::SsDango(void)
{
    return kDango;
}

int shop::SsTea(void)
{
    return kTea;
}
