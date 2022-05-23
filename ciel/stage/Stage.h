#pragma once
#include <memory>
#include <string>
#include"../common/Vector2.h"

#define CHIP_IMAGE_MAX (10000)		//マップタイル画像総サイズ

constexpr int MAP_X = 100;			//総マップタイル横
constexpr int MAP_Y = 100;			//総マップタイル縦
constexpr int ChipSize_X = 32;		//チップサイズ横
constexpr int ChipSize_Y = 32;		//チップサイズ縦
class Stage;

using uniquStage = std::unique_ptr<Stage>;			//mapのポインター

enum class MAP_ID
{
	FOREST,
	FORESTIN,
	TEMPLE,
	TEMPLEIN,
	SWEETS,
	SWEETSOUT,
	SWEETSSCHOOL,
	MAX
};

class Stage
{
public:
	Stage();
	virtual ~Stage();
	virtual void Update(Vector2 offset) = 0;
	virtual void Draw();
	virtual void DrawOwnScn() = 0;		//各シーンのDraw
	virtual bool Init(void) = 0;
	virtual bool CheckMapChip(Vector2 pos)=0;  //当たり判定
	virtual MAP_ID GetSceneID(void) = 0;
	Vector2 GetOffSet(void);
	void SetOffSet(Vector2 offset);
protected:
	Vector2 mOffset;
	int mChipImage[10000];
	int mMap[MAP_Y][MAP_X];
	
	/*MAP_ID mMapID;*/
		//座標を指定してマップチップデータをもらう。

};

