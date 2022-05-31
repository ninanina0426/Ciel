#include <DxLib.h>
#include "scene/SceneMng.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}

	

	lpSceneMng.Run();       //メイン呼び出し
	return 0;        // ソフトの終了
}

