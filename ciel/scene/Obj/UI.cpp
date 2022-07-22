#include <DxLib.h>
#include "UI.h"
#include "../../stage/StageMng.h"

UI::UI()
{
	Init();
}

UI::~UI()
{
}

void UI::Upadate(Player player, Vector2 offset)
{
	stamina = player.Stamina_;
	plPos_ = player.GetPos();
	off_ = offset;
	energy = player.Energy_;

	aitem_.Update(plPos_, player.GetSiz());
	
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
		if (aitem_.SetAitem() == 5)
		{
			aitemname_ = "  ���";
		}

	}
	if (player.aitemFlag_)
	{
		if (player.aitemNum_ == 1)
		{
			telop_ = true;
			aitemname_ = "������";
		}
		if (player.aitemNum_ == 2)
		{
			telop_ = true;
			aitemname_ = "�Ԃ���";
		}
		if (player.aitemNum_ == 3)
		{
			telop_ = true;
			aitemname_ = "����";
		}
		if (player.aitemNum_ == 4)
		{
			telop_ = true;
			aitemname_ = "  ���[";
		}
	}
	


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
	DrawBox(0, 0, energy*4, 20, 0x00ff00, true);
	
	auto mapid = lpMapMng.GetMapId();
	if (mapid == MAP_ID::TEMPLE)
	{
		if (!aitem_.mTama6)
		{
			if (plPos_.x_ > 1440 && plPos_.x_ < 1470 && plPos_.y_ < 660)
			{
				DrawGraph(480, 320, action_, true);
				//DrawString(476, 360, " ! ", 0xff0000, true);
			}
		}
		
	}
	


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, updown_);
	DrawGraph(0, 609 - updown_, boxid, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (telop_&& updown_>150)
	{
		DrawFormatString(5, 529, 0xffffff, "%s���E�����I", aitemname_.c_str());
	}
	if (eveflg_ == true)
	{
		DrawGraph(plPos_.x_ - off_.x_ - 63, plPos_.y_ - off_.y_ - 80, mImageChat_, true);
	}
	DrawString(0, 200, "W:�َq\nA:�X\nS:�_�a\nD:��\nE:�a\nR:���A",0x000000,true);
}



void UI::Init()
{
	boxid = LoadGraph("./image/ui/aitembox.png");
	mImageChat_=  LoadGraph("image/talk/s1.png", true);
	action_ = LoadGraph("image/ui/action.png", true);
	aitemname_ = "�����S";
	updown_ = 0;
	count_ = 0;
	telop_ = false;
}
