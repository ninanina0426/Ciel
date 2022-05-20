#include <DxLib.h>
#include "Stage.h"
#include "../_debug/_DebugConOut.h"
#include "../_debug/_DebugDispOut.h"



Stage::Stage()
{
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	//for (int x = 0; x < MAP_X; x++)
	//{
	//	for (int y = 0; y < MAP_Y; y++)
	//	{
	//		mMap[y][x];
	//		

	//		DrawGraph(32 * x - mOffset.x_, 32 * y - mOffset.y_, mChipImage[mMap[y][x]], true);
	//		/*DrawFormatString(32 * x - mOffset.X, 32 * y - mOffset.Y, GetColor(255, 255, 255), "%d", mMap[y][x]);*/

	//	}
	//}
}

Vector2 Stage::GetOffSet(void)
{
	return mOffset;
}

void Stage::SetOffSet(Vector2 offset)
{
	mOffset = offset;
}


