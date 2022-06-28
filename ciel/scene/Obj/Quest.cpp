#include <DxLib.h>
#include "../../stage/StageMng.h"
#include "Quest.h"

Quest::Quest()
{
	Init();
}

Quest::~Quest()
{
}

void Quest::UpDate(bool stateFlg,int q, Vector2 plPos, Vector2 plsize, MAP_ID mapid)
{
	//クエストを受けなかったら抜ける
	if (!stateFlg)
	{
		state_= QuestState::NON;
		return;
	}
	
	
	quest_ = static_cast<QUEST>(q);

	if (quest_ != quest_old)
	{
		state_ = QuestState::ALIVE;
		CompFlg_ = false;
	}

	aitem_.Update(plPos,plsize);
	
	switch (mapid)
	{
	case MAP_ID::FOREST:
		break;
	case MAP_ID::WA:
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
		if (quest_==QUEST::QUEST_1&&plPos.y_ < 1000)
		{
			CompFlg_ = true;
		}
		break;
	case MAP_ID::TEMPLEIN:
		break;
	case MAP_ID::SWEETS:
		break;
	case MAP_ID::SWEETSOUT:
		if (quest_ == QUEST::QUEST_2&&aitem_.GetmKinomi()==0)
		{
			CompFlg_ = true;
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
		QFlg_ = false;
		quest_old = quest_;
		//quest_ = QUEST::MAX;
		state_ = QuestState::COMP;
	
	}
	

	//場所ごとのクエスト
	if (state_ == QuestState::ALIVE)
	{
		switch (quest_)
		{
		case QUEST::MAX:
			break;
		case QUEST::QUEST_1:
			QFlg_ = true;
			QTxt_ = "探索してみよう";
			break;
		case QUEST::QUEST_2:
			QFlg_ = true;
			QTxt_ = "スイーツの材料を集めよう";
			break;
		case QUEST::QUEST_3:
			QFlg_ = true;
			QTxt_ = "寒い寒い地域の過ごし方";
			break;
		case QUEST::QUEST_4:
			break;
		case QUEST::QUEST_5:
			break;
		default:
			break;
		}
	}
	if (QFlg_)
	{
		count_+=5;
	}
	else
	{
		count_ = 0;
		alq_ = 0;
	}

	//クエストを受けるかどうか
	//クエストの種類　メインは強制　サブは任意
	//クエストを受ける場合どこのクエストなのか
	Draw();
}

void Quest::Draw()
{
	if (QFlg_)
	{
		DrawFormatString(800, 0, 0xff0000, "クエスト受注しました");
		DrawFormatString(900, 50, 0xff0000, "□　%s", QTxt_.c_str());
	}
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

}

bool Quest::Init(void)
{
	/*SetFontSize(25);*/
	state_ = QuestState::NON;
	mapID_ = MAP_ID::MAX;
	type_ = QuestType::MAX;
	quest_old = QUEST::MAX;
	QFlg_ = false;
	CompFlg_ = false;
	Item_ = 0;
	count_ = 0;
	alq_ = 0;
	aitem_.init();

	qe_id_ = LoadGraph("./image/move/qe.png");

	return true;
}


