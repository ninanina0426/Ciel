#pragma once
#include <memory>
#include "../common/Vector2.h"

class BaseScene;

using uniquBaseScn = std::unique_ptr<BaseScene>;			//シーンのポインター
using shareBaseScn = std::shared_ptr<BaseScene>;

//シーンID
enum class SceneID
{
	TRANSTION,			//トランジションシーン
	TITLE,				//タイトルシーン
	SELECT,				//キャラ選択シーン
	LOAD,				//ロードシーン
	GAME,				//ゲームシーン
	EVENT,				//イベントシーン
	END,				//エンドシーン
	MAX
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual uniquBaseScn Update(uniquBaseScn own) = 0;
	virtual void Draw();
	virtual void DrawOwnScn() = 0;		//各シーンのDraw
	virtual bool Init(void) = 0;
	virtual SceneID GetSceneID(void) = 0;
protected:
	int sceneScrID_;					//スクリーンID
	Vector2 screenSize_;				//スクリーンsize


};


