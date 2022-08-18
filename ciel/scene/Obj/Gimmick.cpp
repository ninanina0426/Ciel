#include <DxLib.h>
#include "Gimmick.h"
#include "Player.h"

Gimmick::Gimmick()
{
	Init();
}

Gimmick::~Gimmick()
{
}

void Gimmick::Update(Player player)
{
	plPos = player.GetPos();
	Offset = player.GetOffset();

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
		DrawGraph (plPos.x_ - Offset.x_-20, plPos.y_ - Offset.y_-55, id, true);
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
		return fisingFlg_;
	}

	if (count > 30)
	{
		return true;
	}
	else if(count<0|| fisingFlg_==false)
	{
		fisingFlg_ = false;
		count = 30;
		return fisingFlg_;
	}
	
}

void Gimmick::Init()
{
	id = LoadGraph("image/ui/action.png", true);
	fisingFlg_ = false;
	count = 30;
}
