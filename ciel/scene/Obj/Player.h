#pragma once
#include "../../common/Vector2.h"



enum DIR		//�����Ǘ��p
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

//�L�������
enum class PL_ST
{
	NON,		//�L�������I��
	ALIVE,		//����
	MAX
};

//�L�������
enum class PlayerID
{
	iti,
	Calendula,
	Soy,
	Max
};

class Player
{
private:
	

	/*GameScene* mParent;*/
	/*GameScene* mParent;*/

	int mImage[16];		//�摜�̊i�[�̈�

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mPlayer;



	Vector2 mDamyPos;

	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;
public:
	Player();
	~Player();

	int mPosBottom;	//�L�����N�^�[�̑�����Y���W

	bool flg;

	bool init(void);		//������
	Vector2 Update(void);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
	DIR GetDIR(void);
	void SetDIR(DIR dir);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);
	
};

