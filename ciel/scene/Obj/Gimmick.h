#pragma once
//#include "Aitem.h"
class Gimmick
{
public:
	Gimmick();
	~Gimmick();

	void Update();
	void Draw();
	bool Fishing();
	bool Pick();
	bool Ford();

	bool fisingFlg_;
private:
	void Init();
	//Aitem aitem;

	

	int count;
	int time;
};

