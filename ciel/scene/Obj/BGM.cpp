#include <DxLib.h>
#include"../../stage/StageMng.h"
#include "BGM.h"

BGM::BGM()
{
    Init();
}

BGM::~BGM()
{
    DeleteSoundMem(SHandle);
}

void BGM::Update(int num, bool evfl)
{
    
    x = num;

    move = 255 * x/100;

    // âπó ÇÃê›íË
    ChangeVolumeSoundMem(move, SHandle);

    MAP_ID coppymapID = lpMapMng.GetMapIdOld();
    MAP_ID mapID = lpMapMng.GetMapId();
    if (CheckSoundMem(SHandle) == 0)
    {
        Move();
    }
    if (evfl)
    {
        StopSoundMem(SHandle);
       
    }
    if (coppymapID != mapID)
    {
        DeleteSoundMem(SHandle);
        switch (mapID)
        {
        case MAP_ID::FOREST:
            SHandle = LoadSoundMem("image/music/forest.ogg");
            break;
        case MAP_ID::WA:
            SHandle = LoadSoundMem("image/music/Wa.ogg");
            break;
        case MAP_ID::WASHOP:
            SHandle = LoadSoundMem("image/music/WaShop.ogg");
            break;
        case MAP_ID::CAVE:
            SHandle = LoadSoundMem("image/music/Cave.ogg");
            break;
        case MAP_ID::CAVESHOP:
            SHandle = LoadSoundMem("image/music/Cave.ogg");
            break;
        case MAP_ID::DARK:
            SHandle = LoadSoundMem("image/music/DarkTemple.ogg");
            break;
        case MAP_ID::FORESTIN:
            SHandle = LoadSoundMem("image/music/forestIn.ogg");
            break;
        case MAP_ID::TEMPLE:
            SHandle = LoadSoundMem("image/music/titel.ogg");
            break;
        case MAP_ID::TEMPLEIN:
            SHandle = LoadSoundMem("image/music/templeIn.ogg");
            break;
        case MAP_ID::SWEETS:
            SHandle = LoadSoundMem("image/music/Sweets.ogg");
            break;
        case MAP_ID::SWEETSOUT:
            SHandle = LoadSoundMem("image/music/SweetsOut.ogg");
            break;
        case MAP_ID::SWEETSSCHOOL:
            SHandle = LoadSoundMem("image/music/SweetSchool.ogg");
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
    PlaySoundMem(SHandle, DX_PLAYTYPE_LOOP);
}


bool BGM::Init(void)
{
   /* SHandle = LoadSoundMem("bgm/retroparty.ogg");*/
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
    SHandle = LoadSoundMem("image/music/titel.ogg");

    x = 100;

    return true;
}
