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

	void Upadate(Player player,Vector2 offset,int num,int kinomi,int fis);
	void Draw(bool am,bool pm,bool npm);

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

	PlayerID plID_;

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

	int kinomi_;
	int fiss_;

	int aitemBox;
	int aitem[1][15];

	int tubk_;

	int am_;
	int pm_;
	int time_;
	int stat_;
	int ene_;
	int sta_;

	int q1_;
	int q1C_;
	int q2_;
	int q2C_;
	int q3_;
	int q3C_;
	Keyboard key_;
};

