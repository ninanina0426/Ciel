#include <DxLib.h>
#include "scene/SceneMng.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    lpSceneMng.Run();       //メイン呼び出し
    return 0;        // ソフトの終了
}

