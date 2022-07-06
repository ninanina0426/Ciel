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

		if (aitem_.mTama1 || aitem_.mTama2 || aitem_.mTama3 || aitem_.mTama4 || aitem_.mTama5)
		{
			aitemname_ = "不思議な玉";
		}
		if (aitem_.mKinomi1 || aitem_.mKinomi2 || aitem_.mKinomi3 || aitem_.mKinomi4 || aitem_.mKinomi2)
		{
			aitemname_ = "きのみ";
		}
	}
	
	/*if (CheckHitKey(KEY_INPUT_F))
	{
		telop_ = true;
	}*/

	//アイテム取得の表示
	if (telop_)
	{
		count_++;
		if (updown_ < 151)
		{
			updown_ += 2;
		}
		
	}
	if (count_ > 120)
	{
		telop_ = false;
		updown_ -= 2;
		if (updown_ == 0)
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
		DrawFormatString(10, 529, 0xffffff, "%sを拾った！", aitemname_.c_str());
	}
	

}

void UI::Init()
{
	boxid = LoadGraph("./image/ui/aitembox.png");

	aitemname_ = "リンゴ";
	updown_ = 0;
	count_ = 0;
	telop_ = false;
}
