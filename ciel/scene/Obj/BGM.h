#pragma once
#include"../Input/Keyboard.h"
#include "../../common/Vector2.h"



//enum class MAP_B_ID
//{
//	FOREST,
//	WA,
//	WASHOP,
//	CAVE,
//	CAVESHOP,
//	DARK,
//	FORESTIN,
//	TEMPLE,
//	TEMPLEIN,
//	SWEETS,
//	SWEETSOUT,
//	SWEETSSCHOOL,
//	TRANGETIONS,
//	MAX
//};

class BGM
{
public:
	BGM();
	~BGM();

	/*MAP_B_ID mMapBID;*/

	int SHandle;
	/*int SHandle[15];*/
	void Update(int num);
	void Move(void);
	bool Init(void);
private:

	Keyboard key_;

	int x;
	int move;

	int nume;

};

