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

	bool init(void);		//������
	void Update(Vector2 playerPos);		//�X�V
	void Draw(Vector2 offset,int r);		//�`��
	bool Release(void);		//�J��

};

