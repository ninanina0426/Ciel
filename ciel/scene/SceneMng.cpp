#include <DxLib.h>
#include "SceneMng.h"
#include "TitleScene.h"
#include "Obj/Player.h"
#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"


//SceneMng* SceneMng::s_Instance = nullptr;



void SceneMng::Run(void)
{

	if (!InitFlag_)
	{
		if (!SysInit())//再度失敗なら抜ける
		{
			return;
		}
	}

	//初期シーンのインスタンス
	scene_ = std::make_unique<TitleScene>();
	


	while (ProcessMessage() == 0 ) //ProcessMessage()はウィンドウにメッセージを送る
	{
		_dbgStartDraw();		//デバッグDraw

		scene_ = scene_->Update(std::move(scene_));			//シーンのUpdata呼び出し



		SetDrawScreen(DX_SCREEN_BACK);//転写するだけのバックバッファ
		ClsDrawScreen();

		scene_->Draw();				//シーンのDraw

		_dbgDraw();
		ScreenFlip();

		
	}
}

void SceneMng::Update(void)
{
}

void SceneMng::Draw(void)
{
}

//シーンの解放
bool SceneMng::Release(void)
{
	scene_.release();

	return true;
}

//システム初期化関数
bool SceneMng::SysInit(void)
{
	SetWindowText("Ciel");
	//システム処理
	SetGraphMode(ScreenSizeX, ScreenSizeY, 16);			//720×405ドット65536色モードに設定
	ChangeWindowMode(true);				//true:window false:フルスクリーン

	//DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;
	}
	_dbgSetup(ScreenSizeX, ScreenSizeY, 255);


	return true;
}

SceneMng::SceneMng()
{
	InitFlag_ = SysInit();		//初期化の状態取得
}

SceneMng::~SceneMng()
{
}

