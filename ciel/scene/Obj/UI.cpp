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
			aitemname_ = "Œõ‚é‹Ê";
		}
		if (aitem_.SetAitem()==1)
		{
			aitemname_ = "‚«‚Ì‚İ";
		}
		if (aitem_.SetAitem() == 3)
		{
			aitemname_ = "ƒŠƒ“ƒS";
		}
		if (aitem_.SetAitem() == 4)
		{
			aitemname_ = "ƒ‰ƒ“ƒ^ƒ“";
		}
		if (aitem_.SetAitem() == 5)
		{
			aitemname_ = "  ”é•ó";
		}

	}
	if (player.aitemFlag_)
	{
		if (player.aitemNum_ == 1)
		{
			telop_ = true;
			aitemname_ = "‚³‚©‚È";
		}
		if (player.aitemNum_ == 2)
		{
			telop_ = true;
			aitemname_ = "Ô‚¢Î";
		}
		if (player.aitemNum_ == 3)
		{
			telop_ = true;
			aitemname_ = "Â‚¢Î";
		}
		if (player.aitemNum_ == 4)
		{
			telop_ = true;
			aitemname_ = "  ƒ‹[";
		}
	}
	


	//ƒAƒCƒeƒ€æ“¾‚Ì•\¦
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
		DrawFormatString(5, 529, 0xffffff, "%s‚ğE‚Á‚½I", aitemname_.c_str());
	}
	if (eveflg_ == true)
	{
		DrawGraph(plPos_.x_ - off_.x_ - 63, plPos_.y_ - off_.y_ - 80, mImageChat_, true);
	}
	DrawString(0, 200, "W:‰Ùq\nA:X\nS:_“a\nD:á\nE:˜a\nR:“´ŒA",0x000000,true);
}



void UI::Init()
{
	boxid = LoadGraph("./image/ui/aitembox.png");
	mImageChat_=  LoadGraph("image/talk/s1.png", true);
	action_ = LoadGraph("image/ui/action.png", true);
	aitemname_ = "ƒŠƒ“ƒS";
	updown_ = 0;
	count_ = 0;
	telop_ = false;
}
