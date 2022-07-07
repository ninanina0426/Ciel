#include <DxLib.h>
#include "UI.h"

UI::UI()
{
	Init();
}

UI::~UI()
{
}

void UI::Upadate(int sta,Vector2 pos,Vector2 size)
{
	stamina = sta;
	plPos_ = pos;

	aitem_.Update(plPos_, size);

	if (aitem_.GetAitem())
	{
		telop_ = true;

		if (aitem_.SetAitem()==2)
		{
			aitemname_ = "�����";
		}
		if (aitem_.SetAitem()==1)
		{
			aitemname_ = "���̂�";
		}
		if (aitem_.SetAitem() == 3)
		{
			aitemname_ = "�����S";
		}
		if (aitem_.SetAitem() == 4)
		{
			aitemname_ = "�����^��";
		}
	}
	
	/*if (CheckHitKey(KEY_INPUT_F))
	{
		telop_ = true;
	}*/

	//�A�C�e���擾�̕\��
	if (telop_)
	{
		count_++;
		if (updown_ < 151)
		{
			updown_ += 5;
		}
		
	}
	if (count_ > 120)
	{
		telop_ = false;
		updown_ -= 3;
		if (updown_ < 0)
		{
			updown_ = 0;
			count_ = 0;
			
		}
	}

}

void UI::Draw(void)
{
	DrawBox(0, 20, stamina, 40, 0xffff00, true);
	
	if (plPos_.x_ > 1440 && plPos_.x_ < 1470 && plPos_.y_ < 660)
	{
		
		DrawString(476, 360, " ! ", 0xff0000,  true);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, updown_);
	DrawGraph(0, 609 - updown_, boxid, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (telop_&& updown_>150)
	{
		DrawFormatString(5, 529, 0xffffff, "%s���E�����I", aitemname_.c_str());
	}
	
	DrawString(0, 200, "W:�َq\nA:�X\nS:�_�a\nD:��\nE:�a\nR:���A",0x000000,true);
}

void UI::Init()
{
	boxid = LoadGraph("./image/ui/aitembox.png");

	aitemname_ = "�����S";
	updown_ = 0;
	count_ = 0;
	telop_ = false;
}
