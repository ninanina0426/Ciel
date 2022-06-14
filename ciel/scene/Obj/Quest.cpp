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

void Quest::UpDate(MAP_ID mapid, QuestState qstate, QuestType qtype)
{
	mapID_ = mapid;
	type_ = qtype;
	//クエストを受けなかったら抜ける
	if (QuestType::SUB==qtype&&QuestState::NON == qstate)
	{
		return;
	}

	//場所ごとのクエスト
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
		break;
	case MAP_ID::TEMPLEIN:
		break;
	case MAP_ID::SWEETS:
		SweetQuest(qtype);
		break;
	case MAP_ID::SWEETSOUT:
		SweetQuest(qtype);
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

	//クエストを受けるかどうか
	//クエストの種類　メインは強制　サブは任意
	//クエストを受ける場合どこのクエストなのか
	Draw();
}

void Quest::Draw()
{
	if (QuestType::MAIN==type_)
	{
		if (QFlg_)
		{

			DrawFormatString(800, 0, 0xff0000, "□　メインクエスト\n  %s", QTxt_.c_str());
		}
	}
	else if (QuestType::SUB == type_)
	{
		if (QFlg_)
		{
			DrawFormatString(800, 0, 0xff0000, "□　サブクエスト \n %s", QTxt_.c_str());
		}
	}
	
	
	
}

bool Quest::Init(void)
{
	/*SetFontSize(25);*/
	state_ = QuestState::NON;
	mapID_ = MAP_ID::MAX;
	type_ = QuestType::MAX;
	QFlg_ = false;
	Item_ = 0;
	return true;
}

void Quest::SweetQuest(QuestType qtype)
{
	//メインクエスト
	if (QuestType::MAIN == qtype)
	{
		if (state_ == QuestState::NON)
		{
			Item_ = 5;
			state_ = QuestState::ALIVE;
		}
		QTxt_ = " 商売あがったり！";

		//アイテムの量を管理
		Item_;

		if (Item_ == 0)
		{
			//クエスト完了の時の処理
			state_ = QuestState::COMP;
			QFlg_ = false;
		}
		QFlg_ = true;
	}
	//サブクエスト
	else if (QuestType::SUB == qtype)
	{
		QuestState state;
		state = QuestState::NON;
	}
	else
	{
		return;
	}

}

