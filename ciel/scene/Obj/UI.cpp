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
			aitemname_ = "光る玉";
		}
		if (aitem_.SetAitem()==1)
		{
			aitemname_ = "きのみ";
		}
		if (aitem_.SetAitem() == 3)
		{
			aitemname_ = "リンゴ";
		}
		if (aitem_.SetAitem() == 4)
		{
			aitemname_ = "ランタン";
		}
		if (aitem_.SetAitem() == 5)
		{
			aitemname_ = "  秘宝";
		}

	}
	if (player.aitemFlag_)
	{
		if (player.aitemNum_ == 1)
		{
			telop_ = true;
			aitemname_ = "さかな";
		}
		if (player.aitemNum_ == 2)
		{
			telop_ = true;
			aitemname_ = "赤い石";
		}
		if (player.aitemNum_ == 3)
		{
			telop_ = true;
			aitemname_ = "青い石";
		}
		if (player.aitemNum_ == 4)
		{
			telop_ = true;
			aitemname_ = "  ルー";
		}
	}
	


	//アイテム取得の表示
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
		if (plPos_.x_ > 1440 && plPos_.x_ < 1470 && plPos_.y_ < 660)
		{
			DrawString(476, 360, " ! ", 0xff0000, true);
		}
	}
	


	SetDrawBlendMode(DX_BLENDMODE_ALPHA, updown_);
	DrawGraph(0, 609 - updown_, boxid, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (telop_&& updown_>150)
	{
		DrawFormatString(5, 529, 0xffffff, "%sを拾った！", aitemname_.c_str());
	}
	if (eveflg_ == true)
	{
		DrawGraph(plPos_.x_ - off_.x_ - 63, plPos_.y_ - off_.y_ - 80, mImageChat_, true);
	}
	DrawString(0, 200, "W:菓子\nA:森\nS:神殿\nD:雪\nE:和\nR:洞窟",0x000000,true);
}



void UI::Init()
{
	boxid = LoadGraph("./image/ui/aitembox.png");
	mImageChat_=  LoadGraph("image/talk/s1.png", true);
	aitemname_ = "リンゴ";
	updown_ = 0;
	count_ = 0;
	telop_ = false;
}
