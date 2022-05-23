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
	
}

Vector2 Stage::GetOffSet(void)
{
	return mOffset;
}

void Stage::SetOffSet(Vector2 offset)
{
	mOffset = offset;
}


