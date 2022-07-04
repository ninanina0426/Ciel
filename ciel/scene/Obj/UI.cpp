#include <DxLib.h>
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Upadate(int sta,Vector2 pos)
{
	stamina = sta;
	plPos_ = pos;


	

}

void UI::Draw(void)
{
	DrawBox(0, 20, stamina, 40, 0xffff00, true);
	
	if (plPos_.x_ > 1440 && plPos_.x_ < 1470 && plPos_.y_ < 660)
	{
		
		DrawString(476, 360, " ! ", 0xff0000,  true);
	}
	
}

void UI::Init()
{
}
