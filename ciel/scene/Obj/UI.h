#pragma once
#include "../../common/Vector2.h"
class UI
{
public:
	UI();
	~UI();

	void Upadate(int sta,Vector2 pos);
	void Draw(void);
private:
	void Init();

	int stamina;
	Vector2 plPos_;
};

