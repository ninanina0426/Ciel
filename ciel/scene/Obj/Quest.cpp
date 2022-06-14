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
	//�N�G�X�g���󂯂Ȃ������甲����
	if (QuestType::SUB==qtype&&QuestState::NON == qstate)
	{
		return;
	}

	//�ꏊ���Ƃ̃N�G�X�g
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

	//�N�G�X�g���󂯂邩�ǂ���
	//�N�G�X�g�̎�ށ@���C���͋����@�T�u�͔C��
	//�N�G�X�g���󂯂�ꍇ�ǂ��̃N�G�X�g�Ȃ̂�
	Draw();
}

void Quest::Draw()
{
	if (QuestType::MAIN==type_)
	{
		if (QFlg_)
		{

			DrawFormatString(800, 0, 0xff0000, "���@���C���N�G�X�g\n  %s", QTxt_.c_str());
		}
	}
	else if (QuestType::SUB == type_)
	{
		if (QFlg_)
		{
			DrawFormatString(800, 0, 0xff0000, "���@�T�u�N�G�X�g \n %s", QTxt_.c_str());
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
	//���C���N�G�X�g
	if (QuestType::MAIN == qtype)
	{
		if (state_ == QuestState::NON)
		{
			Item_ = 5;
			state_ = QuestState::ALIVE;
		}
		QTxt_ = " ��������������I";

		//�A�C�e���̗ʂ��Ǘ�
		Item_;

		if (Item_ == 0)
		{
			//�N�G�X�g�����̎��̏���
			state_ = QuestState::COMP;
			QFlg_ = false;
		}
		QFlg_ = true;
	}
	//�T�u�N�G�X�g
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

