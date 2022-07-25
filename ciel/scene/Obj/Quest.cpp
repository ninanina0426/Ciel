#include <DxLib.h>
#include "../../stage/StageMng.h"
#include "Quest.h"

int Quest::GetHaori(void)
{
	return Hao;
}

Quest::Quest()
{
	Init();
}

Quest::~Quest()
{
}

void Quest::UpDate(bool stateFlg,int q, Vector2 plPos, Vector2 plsize, MAP_ID mapid,int fish)
{
	//クエストを受けなかったら抜ける
	if (!stateFlg)
	{
		state_= QuestState::NON;
		return;
	}
	
	
	aitem_.Update(plPos, plsize);
	key_.Update();
	//なんのクエストか
	quest_ = static_cast<QUEST>(q);
	
		switch (quest_)
		{
		case QUEST::MAX:
			break;
		case QUEST::QUEST_1:
			if (questCmpFlg[0] != QuestState::COMP)
			{
				questCmpFlg[0] = QuestState::ALIVE;
				QFlg_ = QuestState::ALIVE;
				QTxt_ = "探索してみよう!\n 　・←↑→↓：移動\n 　・左shift：走る\n 　・F：アクション";
			}
			
			break;
		case QUEST::QUEST_2:
			if (questCmpFlg[1] != QuestState::COMP)
			{
				questCmpFlg[1] = QuestState::ALIVE;
				QFlg_ = QuestState::ALIVE;
				QTxt_ = "スイーツの材料を集めよう";
			}
			break;
		case QUEST::QUEST_3:
			if (questCmpFlg[2] != QuestState::COMP)
			{
				questCmpFlg[2] = QuestState::ALIVE;
				QFlg_ = QuestState::ALIVE;
				QTxt_ = "寒い寒い地域の過ごし方";
			}
			break;
		case QUEST::QUEST_4:
			if (questCmpFlg[3] != QuestState::COMP)
			{
				questCmpFlg[3] = QuestState::ALIVE;
			}
			break;
		case QUEST::QUEST_5:
			if (questCmpFlg[4] != QuestState::COMP)
			{
				questCmpFlg[4] = QuestState::ALIVE;
			}
			break;
		default:
			break;
		}
	
	//クリア条件
	switch (mapid)
	{
	case MAP_ID::FOREST:
		if (aitem_.GetKey() == 1 && questCmpFlg[3] == QuestState::ALIVE)
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				questCmpFlg[3] = QuestState::COMP;
				CompFlg_ = true;
			}
		}
		break;
	case MAP_ID::WA:
		if (fish > 3 && questCmpFlg[2] == QuestState::ALIVE)
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				questCmpFlg[2] = QuestState::COMP;
				CompFlg_ = true;
				aitem_.mHaori = true;
				Hao = 1;
			}
		}
		break;
	case MAP_ID::WASHOP:
		break;
	case MAP_ID::CAVE:
		break;
	case MAP_ID::CAVESHOP:
		break;
	case MAP_ID::DARK:
		break;
	case MAP_ID::FORESTIN:
		break;
	case MAP_ID::TEMPLE:
		if (lpMapMng.qeopd_&& questCmpFlg[0] == QuestState::ALIVE)
		{
			questCmpFlg[0] =  QuestState::COMP;
			CompFlg_ = true;
		}
		break;
	case MAP_ID::TEMPLEIN:
		break;
	case MAP_ID::SWEETS:
		break;
	case MAP_ID::SWEETSOUT:
		if (aitem_.GetmKinomi()==0&& questCmpFlg[1]== QuestState::ALIVE)
		{
			if (key_.getKeyDown(KEY_INPUT_F))
			{
				questCmpFlg[1] = QuestState::COMP;
				CompFlg_ = true;
				aitem_.mKinomi = 0;
				getru_ = 55;
			}
		}
		break;
	case MAP_ID::SWEETSSCHOOL:
		break;
	case MAP_ID::TRANGETIONS:
		
		break;
	case MAP_ID::MAX:
		break;
	default:
		break;
	}
	
	
	if (CompFlg_)
	{
		QFlg_ = QuestState::COMP;
		quest_old = quest_;
		//quest_ = QUEST::MAX;
		state_ = QuestState::COMP;
	}

	if (QFlg_ == QuestState::ALIVE)
	{
		count_ += 5;
	}
	else if (QFlg_ == QuestState::NON)
	{
		count_ = 0;
		alq_ = 0;
	}
	if (CompFlg_)
	{
		Ccount_ += 5;
	}
	else
	{
		Ccount_ = 0;
		Calq_ = 0;
	}

	if (quest_ != quest_old)
	{
		state_ = QuestState::ALIVE;
		CompFlg_ = false;
	}

	//クエストを受けるかどうか
	//クエストの種類　メインは強制　サブは任意
	//クエストを受ける場合どこのクエストなのか
	Draw();
}

void Quest::Draw()
{
	if (QFlg_== QuestState::ALIVE)
	{
		/*DrawFormatString(800, 0, 0xff0000, "クエスト受注しました");
		DrawFormatString(900, 50, 0xff0000, "□　%s", QTxt_.c_str());*/
		if (count_ < 570)
		{
			if (count_ < 255)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, count_);
				DrawExtendGraph(150, 100, 930, 500, qe_id_, true);
			}
			else if (count_ < 315)
			{
				DrawExtendGraph(150, 100, 930, 500, qe_id_, true);
			}
			else
			{
				alq_ += 3;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - alq_);
				DrawExtendGraph(150, 100, 930, 500, qe_id_, true);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else if(count_ > 570)
		{
			QFlg_ = QuestState::NON;
		}
	}
	else if(QFlg_ == QuestState::COMP)
	{
		if (Ccount_ < 570)
		{
			if (Ccount_ < 255)
			{
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, Ccount_);
				DrawExtendGraph(150, 100, 930, 500, qe_cm_, true);
			}
			else if (Ccount_ < 315)
			{
				DrawExtendGraph(150, 100, 930, 500, qe_cm_, true);
			}
			else
			{
				Calq_ += 5;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - Calq_);
				DrawExtendGraph(150, 100, 930, 500, qe_cm_, true);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
		else
		{
			QFlg_ = QuestState::NON;
		}
	}
	

	if (questCmpFlg[0] == QuestState::ALIVE)
	{
		DrawString(1000, 0, "クエスト１", 0xffffff, true);
	}

	if (questCmpFlg[1] == QuestState::ALIVE)
	{
		DrawString(1000, 10, "クエスト2", 0xffffff, true);
	}
	if (questCmpFlg[2] == QuestState::ALIVE)
	{
		DrawString(1000, 20, "クエスト3", 0xffffff, true);
	}



}

bool Quest::CompFlg(void)
{
	return CompFlg_;
}

int Quest::GetCont(void)
{
	return Ccount_;
}

int Quest::GetRu(void)
{
	return getru_;
}

bool Quest::Init(void)
{
	/*SetFontSize(25);*/
	state_ = QuestState::NON;
	mapID_ = MAP_ID::MAX;
	type_ = QuestType::MAX;
	quest_old = QUEST::MAX;
	QFlg_ = QuestState::NON;
	CompFlg_ = false;
	Item_ = 0;
	count_ = 0;
	alq_ = 0;
	Ccount_=0;
	Calq_=0;
	aitem_.init();
	Hao = 0;

	keyf_[0] = false;
	keyf_[1] = false;
	keyf_[2] = false;


	for (int a = 0; a < 5; a++)
	{
		questCmpFlg[a] = QuestState::NON;
	}

	qe_id_ = LoadGraph("./image/move/qe.png");
	qe_cm_ = LoadGraph("./image/move/qeCm.png");


	return true;
}


