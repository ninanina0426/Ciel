#include <DxLib.h>
#include "../Input/Keyboard.h"
#include "wshop.h"

wshop::wshop()
{
    /* init();*/
}

wshop::~wshop()
{
}

bool wshop::init(void)
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
    bRice = 0;
    bDango = 0;
    bTea = 0;
    bFishingRodS = 0;
    bRagBag = 0;
    bPickaxe = 0;
    bKinomi = 0;
    bRantan = 0;
    bHaori = 0;

    H = -1;

    //ÝŒÉ
    maxRice = 10;
    maxDango = 5;
    maxTea = 5;
    maxFishingRodS = 1;
    maxRagBag = 1;
    maxPickaxe = 1;
    maxKinomi = 0;
    maxRantan = 0;
    maxHaori = 1;

    //‚¨‹à
    mRi = 30;
    mD = 35;
    mT = 20;
    mFRS = 200;
    mRB = 500;
    mP = 200;
    mK = 0;
    mR = 0;
    mH = 0;

    SelectNum = 1;
    moveFlg = false;
    Canflg = false;


    mBoxSe[0] = { 80,75 };
    mBoxSe[1] = { 80,75 };
    mBoxSe[2] = { 250,75 };
    mBoxSe[3] = { 425,75 };
    mBoxSe[4] = { 650,75 };


    mBoxA[0][0] = { 70,40 };
    mBoxA[0][1] = { 70,40 };
    mBoxA[0][2] = { 70,80 };
    mBoxA[0][3] = { 70,120 };
    mBoxA[0][4] = { 70,160 };
    mBoxA[0][5] = { 70,200 };
    mBoxA[0][6] = { 70,240 };
    mBoxA[0][7] = { 70,280 };
    mBoxA[0][8] = { 70,320 };
    mBoxA[0][9] = { 70,360 };


    /*mBoxB[0][0] = { 440,426 };*/
    mBoxB[0][0] = { 440,426 };
    mBoxB[1][0] = { 440,426 };
    mBoxB[2][0] = { 534,426 };
    mBoxB[3][0] = { 648,483 };
    mBoxB[4][0] = { 648,483 };


    mImagSelect = LoadGraph("image/shop/shop1.png");
    mImagNomal = LoadGraph("image/shop/shop10.png");
    mImageHuve = LoadGraph("image/shop/shop12.png");
    mImageNHuve = LoadGraph("image/shop/shop3.png");

    mImageBsB = LoadGraph("image/shop/shop4.png");
    mImageBsS = LoadGraph("image/shop/shop5.png");
    mImageBuy = LoadGraph("image/shop/shop11.png");

    cHandle = LoadSoundMem("image/Sound/ƒLƒƒƒ“ƒZƒ‹5.ogg");
    kHandle = LoadSoundMem("image/Sound/‹àŠz•\Ž¦.ogg");


    FontSize = CreateFontToHandle(NULL, 40, 5);

    ChangeState(WSHOP_SELECT::SELECT);

    ChangeBS(WSHOP_BS::BS_MAX);

    moveSnum = 0;

    return true;
}

void wshop::Update(int num)
{
    key_.Update();

    if (num == 15)
    {
        moveFlg = true;
        ChangeState(WSHOP_SELECT::SELECT);
    }
    if (num == 30)
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
        case wshop::WSHOP_SELECT::SELECT:
            Select();
            break;
        case wshop::WSHOP_SELECT::BUY:
            Buy();
            break;
        case wshop::WSHOP_SELECT::SELL:
            Sell();
            break;
        case wshop::WSHOP_SELECT::CANSEL:
            Cansel();
            break;
        case wshop::WSHOP_SELECT::MAX:
            break;
        default:
            break;
        }
    }

   
}

void wshop::Draw(void)
{

    if (moveFlg == true)
    {
        //˜g
        DrawGraph(0, 0, mImagSelect, true);


        //Box
        switch (mSelect)
        {
        case wshop::WSHOP_SELECT::SELECT:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(mBoxSe[x].x_, 155, mBoxSe[x + 1].x_, 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case wshop::WSHOP_SELECT::BUY:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(70, mBoxA[0][yy].y_ + 210, 545, mBoxA[0][yy + 1].y_ + 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case wshop::WSHOP_SELECT::SELL:
            SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
            DrawBox(70, mBoxA[0][yy].y_ + 210, 545, mBoxA[0][yy + 1].y_ + 210, GetColor(255, 255, 255), true);
            SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
            break;
        case wshop::WSHOP_SELECT::CANSEL:

            break;
        case wshop::WSHOP_SELECT::MAX:
            break;
        default:
            break;
        }



        //box‚Ì•\Ž¦
        switch (mSelect)
        {
        case wshop::WSHOP_SELECT::SELECT:
            //•¶Žš  
            DrawGraph(0, 0, mImagNomal, true);
            break;
        case wshop::WSHOP_SELECT::BUY:
        {
            DrawGraph(0, 0, mImageHuve, true);
            /*if (mParent->IsKinomi1()==true)
            {
                DrawRectGraph(70, mBoxA[0][1].y_+210, 70, mBoxA[0][1].y_+210,520,40, mImageHuve, true, false);
            }*/
            if (yy == 1)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sRice);
                DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxRice);
            }
            if (yy == 2)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sDango);
                DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxDango);
            }
            if (yy == 3)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sTea);
                DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxTea);
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
        case wshop::WSHOP_SELECT::SELL:
            DrawGraph(0, 0, mImageBuy, true);
            if (yy == 1)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sRice);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxApple);*/
            }
            if (yy == 2)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sDango);
                /*DrawFormatStringToHandle(950, 320, 0xff0000, FontSize, "%d", maxKinominoKusiyaki);*/
            }
            if (yy == 3)
            {
                DrawFormatStringToHandle(950, 260, 0xff0000, FontSize, "%d", sTea);
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
        case wshop::WSHOP_SELECT::CANSEL:
            break;
        case wshop::WSHOP_SELECT::MAX:
            break;
        default:
            break;
        }

        DrawFormatStringToHandle(900, 170, 0xff0000, FontSize, "%d", haveRu);
    }

    switch (mBS)
    {
    case wshop::WSHOP_BS::BS_BUY:
        DrawGraph(0, 0, mImageBsB, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawBox(mBoxB[SelectNum][0].x_, 418, mBoxB[SelectNum + 1][0].x_, 475, GetColor(255, 255, 255), true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (yy == 1)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bRice);
        }
        if (yy == 2)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bDango);
        }
        if (yy == 3)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bTea);
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
    case wshop::WSHOP_BS::BS_SELL:
        DrawGraph(0, 0, mImageBsS, true);
        SetDrawBlendMode(DX_BLENDMODE_ALPHA, 150);
        DrawBox(mBoxB[SelectNum][0].x_, 418, mBoxB[SelectNum + 1][0].x_, 475, GetColor(255, 255, 255), true);
        SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
        if (yy == 1)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bRice);
        }
        if (yy == 2)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bDango);
        }
        if (yy == 3)
        {
            DrawFormatStringToHandle(530, 300, 0xff0000, FontSize, "%d", bTea);
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
    case wshop::WSHOP_BS::BS_MAX:
        break;
    default:
        break;
    }

    /*DrawFormatString(0, 200, GetColor(255,255,255), "%d", SelectNum);*/


}

bool wshop::Release(void)
{
    DeleteGraph(mImagSelect);
    DeleteGraph(mImageHuve);
    DeleteGraph(mImageNHuve);

    return true;
}

bool wshop::SPose(void)
{
    return moveFlg;
}

bool wshop::CanselFlg(void)
{
    return Canflg;
}

int wshop::SetAitem(int a, int kk, int fd, int frs, int rb, int p, int k, int r, int h)
{
    gRice = a;
    gDango = kk;
    gTea = fd;
    gFishingRodS = frs;
    gRagBag = rb;
    gPickaxe = p;
    gKinomi = k;
    gRantan = r;
    gHaori = h;

    if (gFishingRodS == 1)
    {
        maxFishingRodS = 0;
        sFishingRodS = gFishingRodS;
    }
    if (sFishingRodS == 1)
    {
        maxFishingRodS = 0;
        sFishingRodS = gFishingRodS;
    }
    if (gRagBag == 1)
    {
        maxRagBag = 0;
        sRagBag = gRagBag;
    }
    if (sRagBag == 1)
    {
        maxRagBag = 0;
        sRagBag = gRagBag;
    }
    if (gPickaxe == 1)
    {
        maxPickaxe = 0;
        sPickaxe = gPickaxe;
    }
    if (sRagBag == 1)
    {
        maxPickaxe = 0;
        sPickaxe = gPickaxe;
    }

    return true;
}

int wshop::SetMoney()
{
    return numRu;
}

bool wshop::GetMoney()
{
    return MoneyFlg;
}

void  wshop::sHaveMoney(int ru)
{
    haveRu = ru;

}

void wshop::AMoney(int money)
{
    wMoney = money;
}

void wshop::SSetNum(void)
{
   
    kRice = sRice;
    kDango = sDango/* - H*/;
    kTea = sTea/* - H*/;
    kFishingRodS = sFishingRodS/* - H*/;
    kRagBag = sRagBag/* - H*/;
    kPickaxe = sPickaxe/* - H*/;
    kKinomi = sKinomi/* - H*/;
    kRantan = sRantan/* - H*/;
    kHaori = sHaori/* - H*/;

    sRice = gRice + kRice;
    sDango = gDango + kDango;
    sTea = gTea + kTea;
    sFishingRodS = gFishingRodS + kFishingRodS;
    sRagBag = gRagBag + kRagBag;
    sPickaxe = gPickaxe + kPickaxe;
    sKinomi = gKinomi + kKinomi;
    sRantan = gRantan + kRantan;
    sHaori = gHaori + kHaori;

}

void wshop::SsetAitem(bool flg)
{
    if ((flg == true))
    {
        SSetNum();
    }
}



void wshop::Select(void)
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
            ChangeState(WSHOP_SELECT::BUY);
            yy = 1;
        }
        if (x == 2)
        {
            ChangeState(WSHOP_SELECT::SELL);
            yy = 1;
        }
        if (x == 3)
        {
            ChangeState(WSHOP_SELECT::CANSEL);
            yy = 1;
        }
    }
}

void wshop::Buy(void)
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
            ChangeBS(WSHOP_BS::BS_BUY);
            xx = 1;
            /* BSBuy();*/
        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(WSHOP_SELECT::SELECT);

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
    case wshop::WSHOP_BS::BS_BUY:
        BSBuy();
        break;
    case wshop::WSHOP_BS::BS_SELL:
        /*   BSSell();*/
        break;
    case wshop::WSHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
}

void wshop::Sell(void)
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
            ChangeBS(WSHOP_BS::BS_SELL);
            xx = 1;
        }
        if (key_.getKeyDown(KEY_INPUT_Q))
        {
            ChangeState(WSHOP_SELECT::SELECT);

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
    case wshop::WSHOP_BS::BS_BUY:
        /*BSBuy();*/
        break;
    case wshop::WSHOP_BS::BS_SELL:
        BSSell();
        break;
    case wshop::WSHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
}

void wshop::Cansel(void)
{
    moveFlg = false;
    Canflg = true;
    x = 1;
}

void wshop::BSBuy(void)
{
    if (yy == 1)
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
            if (bRice >= maxRice)
            {
                bRice = maxRice;
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
                numRu = -(mRi * (bRice));
                if (wMoney >= -(numRu))
                {
                    maxRice -= bRice;
                    sRice += (bRice);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    MoneyFlg = true;
                    bRice = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sRice = sRice;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bRice = 0;
                    numRu = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }

            }
            else if (SelectNum == 1)
            {
                sRice = sRice;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bRice = 0;
                numRu = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
    if (yy == 2)
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
            if (bDango >= maxDango)
            {
                bDango = maxDango;
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
                numRu = -(mD * (bDango));
                if (wMoney >= -(numRu))
                {
                    maxDango -= bDango;
                    sDango += (bDango);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bDango = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sDango = sDango;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bDango = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sDango = sDango;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bDango = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
    if (yy == 3)
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
            if (bTea >= maxTea)
            {
                bTea = maxTea;
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
                numRu = -(mT * (bTea));
                if (wMoney >= -(numRu))
                {
                    maxTea -= bTea;
                    sTea += (bTea);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bTea = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sTea = sTea;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bTea = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sTea = sTea;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bTea = 0;
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
                if (wMoney >= -(numRu))
                {
                    maxFishingRodS -= bFishingRodS;
                    sFishingRodS += (bFishingRodS);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bFishingRodS = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);

                }
                else
                {
                    sFishingRodS = sFishingRodS;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bFishingRodS = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sFishingRodS = sFishingRodS;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
                if (wMoney >= -(numRu))
                {
                    maxRagBag -= bRagBag;
                    sRagBag += (bRagBag);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bRagBag = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sRagBag = sRagBag;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bRagBag = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }
            }
            else if (SelectNum == 1)
            {
                sRagBag = sRagBag;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
                if (wMoney >= -(numRu))
                {
                    maxPickaxe -= bPickaxe;
                    sPickaxe += (bPickaxe);
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    MoneyFlg = true;
                    SelectNum = 0;
                    bPickaxe = 0;
                    PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
                }
                else
                {
                    sPickaxe = sPickaxe;
                    xx = 0;
                    ChangeBS(WSHOP_BS::BS_MAX);
                    SelectNum = 0;
                    bPickaxe = 0;
                    PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
                }

            }
            else if (SelectNum == 1)
            {
                sPickaxe = sPickaxe;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bPickaxe = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }

}

void wshop::BSSell(void)
{

    if (yy == 1)
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
            if (bRice >= sRice)
            {
                bRice = sRice;
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
                sRice -= bRice;
                /*sApple += (bApple);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bRice = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }


        }

    }
    if (yy == 2)
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
            if (bDango >= sDango)
            {
                bDango = sDango;
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
                sDango -= bDango;
                /*sDango += (bDango);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bDango = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
    if (yy == 3)
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
            if (bTea >= sTea)
            {
                bTea = sTea;
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
                sTea -= bTea;
               /* sTea += (bTea);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bTea = 0;
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
            if (bFishingRodS >= sFishingRodS)
            {
                bFishingRodS = sFishingRodS;
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
                sFishingRodS -= bFishingRodS;
                /*sFishingRodS += (bFishingRodS);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                numRu = (mFRS * (bFishingRodS));
                MoneyFlg = true;
                SelectNum = 0;
                bFishingRodS = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sFishingRodS = sFishingRodS;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
            if (bRagBag >= sRagBag)
            {
                bRagBag = sRagBag;
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
                sRagBag -= bRagBag;
               /* sRagBag += (bRagBag);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                numRu = (mRB * (bRagBag));
                MoneyFlg = true;
                SelectNum = 0;
                bRagBag = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sRagBag = sRagBag;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
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
            if (bPickaxe >= sPickaxe)
            {
                bPickaxe = sPickaxe;
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
                sPickaxe -= bPickaxe;
                /*sPickaxe += (bPickaxe);*/
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                numRu = (mP * (bPickaxe));
                MoneyFlg = true;
                SelectNum = 0;
                bPickaxe = 0;
                PlaySoundMem(kHandle, DX_PLAYTYPE_BACK);
            }
            else if (SelectNum == 1)
            {
                sPickaxe = sPickaxe;
                xx = 0;
                ChangeBS(WSHOP_BS::BS_MAX);
                SelectNum = 0;
                bPickaxe = 0;
                PlaySoundMem(cHandle, DX_PLAYTYPE_BACK);
            }
        }
    }
}

void wshop::BS(void)
{
    switch (mBS)
    {
    case wshop::WSHOP_BS::BS_BUY:
        BSBuy();
        break;
    case wshop::WSHOP_BS::BS_SELL:
        BSSell();
        break;
    case wshop::WSHOP_BS::BS_MAX:
        break;
    default:
        break;
    }
}

void wshop::ChangeState(WSHOP_SELECT select)
{
    mSelect = select;

    switch (mSelect)
    {
    case wshop::WSHOP_SELECT::SELECT:
        break;
    case wshop::WSHOP_SELECT::BUY:
        break;
    case wshop::WSHOP_SELECT::SELL:
        break;
    case wshop::WSHOP_SELECT::CANSEL:
        break;
    case wshop::WSHOP_SELECT::MAX:
        break;
    default:
        break;
    }

}

void wshop::ChangeBS(WSHOP_BS bs)
{
    mBS = bs;
    switch (mBS)
    {
    case wshop::WSHOP_BS::BS_BUY:
        break;
    case wshop::WSHOP_BS::BS_SELL:
        break;
    case wshop::WSHOP_BS::BS_MAX:
        break;
    default:
        break;
    }

}

int wshop::SsRice(void)
{
    return sRice;
}

int wshop::SsDango(void)
{
    return sDango;
}

int wshop::SsTea(void)
{
    return sTea;
}

int wshop::SsFishingRodS(void)
{
    return sFishingRodS;
}

int wshop::SsRagBag(void)
{
    return sRagBag;
}

int wshop::SsPickaxe(void)
{
    return sPickaxe;
}

int wshop::SsKinomi(void)
{
    return sKinomi;
}

int wshop::SsRantan(void)
{
    return sRantan;
}

int wshop::SsHaori(void)
{
    return sHaori;
}