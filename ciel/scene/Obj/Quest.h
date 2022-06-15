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
	NON,		//�N�G�X�g������
	ALIVE,		//�N�G�X�g��
	COMP,		//�N�G�X�g����
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
	

	void UpDate(bool stateFlg, int q,Vector2 plPos,MAP_ID mapid);
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
};

