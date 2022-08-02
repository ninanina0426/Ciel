#pragma once
#include <string>
#include "../../common/Vector2.h"
#include "Aitem.h"
#include "../Input/Keyboard.h"


class UI
{
public:
	UI();
	~UI();

	void Upadate(Player player,Vector2 offset,int num);
	void Draw(void);

	bool eveflg_;

private:
	void Init();

	Aitem aitem_;
	int aitemNum;

	int stamina;
	int energy;
	Vector2 plPos_;
	Vector2 off_;

	std::string aitemname_;



	bool telop_;
	int count_;
	int updown_;

	int action_;
	int que_;
	int boxid;
	int mImageChat_;
	int questid_;
	bool queTabF_;
	bool kuesution_;

	int aitemBox;
	int aitem[1][15];

	Keyboard key_;
};

