#pragma once
#include "../../common/Vector2.h"


class Player;

class Gimmick
{
public:
	Gimmick();
	~Gimmick();

	void Update(Player player);
	void Draw();
	bool Fishing();
	bool Pick();
	bool Ford();

	bool fisingFlg_;
	
private:
	void Init();
	//Aitem aitem;

	Vector2 Offset;
	Vector2 plPos;

	int rock;

	int id;
	int count;
	int time;
};

