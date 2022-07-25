#pragma once
#include <string>
#include "../../common/Vector2.h"
#include "Aitem.h"


class UI
{
public:
	UI();
	~UI();

	void Upadate(Player player,Vector2 offset);
	void Draw(void);

	bool eveflg_;

private:
	void Init();

	Aitem aitem_;
	

	int stamina;
	int energy;
	Vector2 plPos_;
	Vector2 off_;

	std::string aitemname_;

	bool telop_;
	int count_;
	int updown_;

	int action_;
	int boxid;
	int mImageChat_;
	int questid_;
	bool queTabF_;

	Keyboard key_;
};

