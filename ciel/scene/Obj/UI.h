#pragma once
#include <string>
#include "../../common/Vector2.h"
#include "Aitem.h"
class UI
{
public:
	UI();
	~UI();

	void Upadate(int sta,Vector2 pos,Vector2 size);
	void Draw(void);
private:
	void Init();

	Aitem aitem_;

	int stamina;
	Vector2 plPos_;

	std::string aitemname_;

	bool telop_;
	int count_;
	int updown_;

	int boxid;
};

