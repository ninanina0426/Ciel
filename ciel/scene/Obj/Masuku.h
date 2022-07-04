#pragma once
#include "../../common/Vector2.h"


class Masuku
{
private:
	int mImage;
	int mImage2;

	Vector2 mPos;
	Vector2 mSize;

public:
	Masuku();
	~Masuku();

	bool init(void);		//初期化
	void Update(Vector2 playerPos);		//更新
	void Draw(Vector2 offset,int r);		//描画
	bool Release(void);		//開放

};

