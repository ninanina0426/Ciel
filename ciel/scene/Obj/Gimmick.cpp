#include <DxLib.h>
#include "Gimmick.h"

Gimmick::Gimmick()
{
	Init();
}

Gimmick::~Gimmick()
{
}

void Gimmick::Update()
{
	time=GetRand(100);
	rock = GetRand(8);
	if (fisingFlg_)
	{
		count--;
	}
	Draw();
}

void Gimmick::Draw()
{
	if (fisingFlg_)
	{
		DrawBox(0, 0, 200, 200, 0xff0000, true);
	}
}

bool Gimmick::Fishing()
{
	if (time == 8)
	{

		fisingFlg_ = true;
		return true;
	}

	if (count > 60)
	{
		return true;
	}
	else if (count < 0 || fisingFlg_ == false)
	{
		fisingFlg_ = false;
		count = 60;
		return false;
	}

}

bool Gimmick::Pick()
{
	if (rock==7 )
	{
		return true;
	}
	return false;
}

bool Gimmick::Ford()
{
	//ƒ‰ƒ“ƒ_ƒ€‚ÈŠÔ
	if (time == 3)
	{
		
		fisingFlg_ = true;
		return true;
	}

	if (count > 30)
	{
		return true;
	}
	else if(count<0|| fisingFlg_==false)
	{
		fisingFlg_ = false;
		count = 30;
		return false;
	}
	
}

void Gimmick::Init()
{
	fisingFlg_ = false;
	count = 30;
}
