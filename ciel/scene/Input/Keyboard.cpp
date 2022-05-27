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
    char tmpKey[256];   // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey);  // �S�ẴL�[�̓��͏�Ԃ𓾂�

    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) {   // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            keyBuf_[i]++;   // ���Z
        }
        else {
            // ������Ă��Ȃ����
            keyBuf_[i] = 0;   // 0�ɂ���
        }
    }
}

bool Keyboard::Init()
{
    //�L�[��Ԕz���������
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

//�������u�Ԃ̏�Ԏ擾
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

//������������Ԏ擾
int Keyboard::getKeyDownHold(unsigned char KeyCode)
{
    return keyBuf_[KeyCode];
}



