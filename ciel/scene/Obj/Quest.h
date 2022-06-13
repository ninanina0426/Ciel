#pragma once
#include <string>
#include "../../stage/Stage.h"

#define QuestIns Quest::GetInstance()

enum class QuestType
{
	MAIN,
	SUB,
	MAX
};

enum class QuestState
{
	NON,		//クエスト未完了
	ALIVE,		//クエスト受注
	COMP,		//クエスト完了
	MAX
};

class Quest
{
public:
	static Quest& GetInstance()
	{
		static Quest s_Instance;
		return s_Instance;
	}
	

	void UpDate(MAP_ID mapid, QuestState qstate, QuestType qtype);
	void Draw(void);

private:
	Quest();
	~Quest();
	bool Init(void);

	void SweetQuest(QuestType qtype);


	bool QFlg_;
	std::string QTxt_;
	QuestState state_;
	QuestType type_;
	MAP_ID mapID_;
	int Item_;
};

