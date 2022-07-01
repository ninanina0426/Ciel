#pragma once
#include <string>
#include "../../stage/Stage.h"
#include "Player.h"
#include "Aitem.h"

#define QuestIns Quest::GetInstance()

//
enum class QuestType
{
	MAIN,
	SUB,
	MAX
};
//
enum class QuestState
{
	NON,		//クエスト未完了
	ALIVE,		//クエスト受注
	COMP,		//クエスト完了
	MAX
};
//
enum class QUEST
{
	MAX,
	QUEST_1,
	QUEST_2,
	QUEST_3,
	QUEST_4,
	QUEST_5
};


class Quest
{
public:
	static Quest& GetInstance()
	{
		static Quest s_Instance;
		return s_Instance;
	}
	

	void UpDate(bool stateFlg, int q,Vector2 plPos, Vector2 plsize,MAP_ID mapid);
	void Draw(void);

private:
	Quest();
	~Quest();
	bool Init(void);

	Aitem aitem_;
	//Player *player_;


	bool QFlg_;
	bool CompFlg_;
	std::string QTxt_;
	QUEST quest_;
	QUEST quest_old;
	QuestState state_;
	QuestType type_;
	MAP_ID mapID_;
	int Item_;

	
	bool keyf_[3];

	int qe_id_;
	int qe_cm_;
	int count_;
	int alq_;
	int Ccount_;
	int Calq_;
};

