#pragma once
#include "Stage.h"


class Layer
{
public:
	Layer();
	~Layer();

	void Draw(Vector2 offset);

	MAP_ID mMapID;
	void SetMap(MAP_ID mapID);
private:
	void Update(Vector2 offset);
	bool Init(void);
	
	Vector2 mOffset;
	int mChipImage1[10000];
	int mChipImage2[10000];
	int mChipImage3[10000];
	int mChipImage4[10000];
};

