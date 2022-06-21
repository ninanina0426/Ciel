#pragma once
#include "../../common/Vector2.h"
#include"../Input/Keyboard.h"
#include"../../stage/Stage.h"


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

//�̗͌n�萔
constexpr int STAMINA = 100;
constexpr int ENERGY = 100;

class Player
{
private:
	

	/*GameScene* mParent;*/
	/*GameScene* mParent;*/

	int mImage1[32];		//�摜�̊i�[�̈�
	int mImage2[32];		//�摜�̊i�[�̈�
	int mImage3[32];		//�摜�̊i�[�̈�
	//int mImage4[32];		//�摜�̊i�[�̈�
	//int mImage5[32];		//�摜�̊i�[�̈�
	//int mImage6[32];		//�摜�̊i�[�̈�

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mPlayer;

	Keyboard key_;
	
	int i;
	int num;

	bool moveFlg;

	int mChipId;

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

	bool init(PlayerID playerid);		//������
	Vector2 Update(int chipid);		//�X�V
	void Draw(Vector2 offset);		//�`��
	bool Release(void);		//�J��
	DIR GetDIR(void);
	void SetDIR(DIR dir);
	void SetPos(Vector2 pos);
	Vector2 GetSiz(void);
	Vector2 GetPos(void);


	int Stamina_;		//�X�^�~�i�Ǘ�
	int Energy_;		//�G�l���M�[�Ǘ�
	PL_ST state_;
	PlayerID plID_;
	
};

