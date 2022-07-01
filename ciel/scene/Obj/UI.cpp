#include <DxLib.h>
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

void UI::Upadate(int sta)
{
	stamina = sta;
}

void UI::Draw(void)
{
	DrawBox(0, 20, stamina, 40, 0xffff00, true);
}

void UI::Init()
{
}
