#include <DxLib.h>
#include "UI.h"
#include "../../stage/StageMng.h"
#include "Quest.h"

UI::UI()
{
	Init();
}

UI::~UI()
{
}

void UI::Upadate(Player player, Vector2 offset,int num)
{
	key_.Update();
	stamina = player.Stamina_;
	plPos_ = player.GetPos();
	off_ = offset;
	energy = player.Energy_;



	if (num == 0){aitemNum = 14;}
	if (num == 1){aitemNum = 0;}
	if (num == 2){aitemNum = 1;}
	if (num == 3){aitemNum = 2;}
	if (num == 4){aitemNum = 3;}
	if (num == 5){aitemNum = 4;}
	if (num == 6){aitemNum = 5;}
	if (num == 10){aitemNum = 6;}
	if (num == 12){aitemNum = 7;}
	if (num == 13){aitemNum = 8;}
	if (num == 14){aitemNum = 9;}
	if (num == 16){aitemNum = 10;}
	if (num == 17){aitemNum = 11;}
	if (num == 15){aitemNum = 12;}
	

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
		if (aitem_.SetAitem() == 6)
		{
			aitemname_ = "  　鍵";
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
	if (queTabF_ == false)
	{
		if (key_.getKeyDown(KEY_INPUT_TAB))
		{
			queTabF_ = true;
			
			//QuestIns.questCmpFlg[1]
		}
	}
	else
	{
		if (key_.getKeyDown(KEY_INPUT_TAB))
		{
			queTabF_ = false;
		}
	}
	
}



void UI::Draw(void)
{
	DrawBox(0, 20, stamina, 40, 0xffff00, true);
	DrawBox(0, 0, energy*4, 20, 0x00ff00, true);

	DrawBox(1050, 0, 1080, 30, 0x000000, true);
	DrawGraph(1050, 0, tubk_, true);

	if (queTabF_)
	{
		DrawGraph(780, 0, questid_, true);
		if (QuestIns.questCmpFlg[0] == QuestState::ALIVE) {DrawGraph(10, 0, q1_, true);}
		if (QuestIns.questCmpFlg[0] == QuestState::COMP) {DrawGraph(10, 0, q1C_, true);}
		if (QuestIns.questCmpFlg[2] == QuestState::NON)
		{
			if (QuestIns.questCmpFlg[1] == QuestState::ALIVE)
			{
				DrawGraph(10, 50, q2_, true);
			}	
			
			if (QuestIns.questCmpFlg[1] == QuestState::COMP) { DrawGraph(10, 50, q2C_, true); }
		}
		else if(QuestIns.questCmpFlg[2] == QuestState::ALIVE)
		{
			if (QuestIns.questCmpFlg[1] == QuestState::ALIVE)
			{
				DrawGraph(10, 100, q2_, true);
			}
			if (QuestIns.questCmpFlg[1] == QuestState::COMP) { DrawGraph(10, 100, q2C_, true); }
		}
		if (QuestIns.questCmpFlg[2] == QuestState::COMP)
		{
			if (QuestIns.questCmpFlg[1] == QuestState::ALIVE)
			{
				DrawGraph(10, 100, q2_, true);
			}
			if (QuestIns.questCmpFlg[1] == QuestState::COMP) { DrawGraph(10, 100, q2C_, true); }
		}
		if (QuestIns.questCmpFlg[2] == QuestState::ALIVE) { DrawGraph(10,50, q3_, true); }
		if (QuestIns.questCmpFlg[2] == QuestState::COMP) { DrawGraph(10, 50, q3C_, true); }
	}

	

	DrawGraph(990, 520, aitemBox, true);
	DrawGraph(1000, 520, aitem[0][aitemNum], true);

	auto mapid = lpMapMng.GetMapId();
	auto mChipId = lpMapMng.GetChipId();
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
		if (plPos_.y_ < 580)
		{
			DrawGraph(plPos_.x_ - off_.x_ - 20, plPos_.y_ - off_.y_ - 55, action_, true);
		}

	}
	if (mapid == MAP_ID::CAVE)
	{
		if ((mChipId == 315) || (mChipId == 316) || (mChipId == 317) || (mChipId == 306) || (mChipId == 308) || (mChipId == 297))
		{
			if (!kuesution_)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					kuesution_ = true;
				}
			}
			else
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					kuesution_ = false;
				}
			}
			if (!kuesution_)
			{
				DrawGraph(plPos_.x_ - off_.x_ - 20, plPos_.y_ - off_.y_ - 55, que_, true);
			}	
		}
	}
	if (mapid == MAP_ID::FORESTIN)
	{
		if ((mChipId == 896))
		{
			if (!kuesution_)
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					kuesution_ = true;
				}
			}
			else
			{
				if (key_.getKeyDown(KEY_INPUT_F))
				{
					kuesution_ = false;
				}
			}
			if (!kuesution_)
			{
				DrawGraph(plPos_.x_ - off_.x_ - 20, plPos_.y_ - off_.y_ - 55, que_, true);
			}
		}
	}


	
	

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, updown_);
	DrawGraph(0, 609 - updown_, boxid, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (telop_ && updown_ > 150)
	{
		DrawFormatString(5, 529, 0xffffff, "%sを拾った！", aitemname_.c_str());
	}
	if (eveflg_ == true)
	{
		DrawGraph(plPos_.x_ - off_.x_ - 63, plPos_.y_ - off_.y_ - 80, mImageChat_, true);
	}

	



	
	DrawString(0, 200, "W:菓子\nA:森\nS:神殿\nD:雪\nE:和\nR:洞窟",0x000000,true);

	
	
	/*auto a = QuestIns.QuestList;
	auto b = QuestIns.quelmap.find(1);
	auto c = QuestIns.quelmap;
	if (b != c.end())
	{

		auto C = c.at(1).c_str();
		DrawFormatString(0, 500, 0x000000, "%s", C);
	}
	
	DrawFormatString(500, 100, 0x000000, "%s", a.begin());*/

}



void UI::Init()
{
	questid_= LoadGraph("./image/ui/questbox.jpg");
	boxid = LoadGraph("./image/ui/aitembox.png");
	mImageChat_=  LoadGraph("image/talk/s1.png");
	action_ = LoadGraph("image/ui/action.png");
	aitemBox = LoadGraph("./image/ui/aitemB.png");
	que_ = LoadGraph("./image/ui/question.png");

	tubk_ = LoadGraph("./image/ui/tub.jpg");

	q1_= LoadGraph("./image/ui/Q1.png");
	q1C_ = LoadGraph("./image/ui/Q1C.png");
	q2_ = LoadGraph("./image/ui/Q2.png");
	q2C_ = LoadGraph("./image/ui/Q2C.png");
	q3_ = LoadGraph("./image/ui/Q3.png");
	q3C_ = LoadGraph("./image/ui/Q3C.png");

	LoadDivGraph("./image/ui/aitem.png", 15, 1, 15, 70, 70, *aitem, true);
	aitemname_ = "リンゴ";
	updown_ = 0;
	count_ = 0;
	aitemNum = 14;
	telop_ = false;
	queTabF_ = false;
	kuesution_ = false;
}
