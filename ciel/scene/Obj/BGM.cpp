#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "BGM.h"

BGM::BGM()
{
    Init();
}

BGM::~BGM()
{
}

void BGM::Update(int num)
{
    
    x = num;

    move = 255 * x;

    // ���ʂ̐ݒ�
    ChangeVolumeSoundMem(move / 100, SHandle);

    MAP_ID coppymapID = lpMapMng.GetMapIdOld();
    MAP_ID mapID = lpMapMng.GetMapId();
    if (CheckSoundMem(SHandle) == 0)
    {
        Move();
    }
    if (coppymapID != mapID)
    {
        DeleteSoundMem(SHandle);
        switch (mapID)
        {
        case MAP_ID::FOREST:
            SHandle = LoadSoundMem("bgm/yume.mp3");
            break;
        case MAP_ID::WA:
            break;
        case MAP_ID::WASHOP:
            break;
        case MAP_ID::CAVE:
            break;
        case MAP_ID::CAVESHOP:
            break;
        case MAP_ID::DARK:
            break;
        case MAP_ID::FORESTIN:
            break;
        case MAP_ID::TEMPLE:
            break;
        case MAP_ID::TEMPLEIN:
            break;
        case MAP_ID::SWEETS:
            SHandle = LoadSoundMem("bgm/retroparty.mp3");
            break;
        case MAP_ID::SWEETSOUT:
            break;
        case MAP_ID::SWEETSSCHOOL:
            break;
        case MAP_ID::TRANGETIONS:
            break;
        case MAP_ID::MAX:
            break;
        default:
            break;
        }
  
    }
}

void BGM::Move(void)
{
    PlaySoundMem(SHandle, DX_PLAYTYPE_BACK);
}


bool BGM::Init(void)
{
    SHandle = LoadSoundMem("bgm/retroparty.mp3");
   // /*MAP_ID mapID = lpMapMng.GetMapId();

   // if (mapID == MAP_ID::FOREST)
   // {
   //     SHandle = LoadSoundMem("bgm/retroparty.mp3");
   // }*/

   //// PlaySoundMem(SHandle, DX_PLAYTYPE_BACK);

   ///* SHandle[0] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[1] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[2] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[3] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[4] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[5] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[6] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[7] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[8] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[9] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[10] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[11] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[12] = LoadSoundMem("bgm/retroparty.mp3");
   // SHandle[13] = LoadSoundMem("bgm/retroparty.mp3");*/

    return true;
}