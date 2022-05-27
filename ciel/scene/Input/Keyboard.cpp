#include <DxLib.h>
#include "Keyboard.h"

Keyboard::Keyboard()
{
    Init();
}

Keyboard::~Keyboard()
{
}

void Keyboard::Update(void)
{
    char tmpKey[256];   // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey);  // 全てのキーの入力状態を得る

    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) {   // i番のキーコードに対応するキーが押されていたら
            keyBuf_[i]++;   // 加算
        }
        else {
            // 押されていなければ
            keyBuf_[i] = 0;   // 0にする
        }
    }
}

bool Keyboard::Init()
{
    //キー状態配列を初期化
    for (int i = 0; i < 256; i++)
    {
        keyBuf_[i] = 0;
    }
    GetHitKeyStateAll(keyBuf_);
    
    return true;
}

Trg Keyboard::GetTrg(void)
{
    return keyTrg_;
}

//押した瞬間の状態取得
bool Keyboard::getKeyDown(unsigned char KeyCode)
{
    if (keyBuf_[KeyCode] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//押し続けた状態取得
int Keyboard::getKeyDownHold(unsigned char KeyCode)
{
    return keyBuf_[KeyCode];
}



