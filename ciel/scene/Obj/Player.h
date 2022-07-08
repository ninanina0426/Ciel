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
constexpr int STAMINA = 500;
constexpr int ENERGY = 100;

class Player
{
private:
	

	/*GameScene* mParent;*/
	/*GameScene* mParent;*/

	int mImage1[48];		//�摜�̊i�[�̈�
	int mImage2[48];		//�摜�̊i�[�̈�
	int mImage3[48];		//�摜�̊i�[�̈�

	int mImageTI[24];		//�摜�̊i�[�̈�
	int mImageTS[24];		//�摜�̊i�[�̈�

	int mImageC[27];		//
	int mImageI[27];		//
	int mImageS[27];		//
	int mImageChat[100];	//

	int mImageF;
	//int mImage4[32];		//�摜�̊i�[�̈�
	//int mImage5[32];		//�摜�̊i�[�̈�
	//int mImage6[32];		//�摜�̊i�[�̈�

	DIR mMoveDir;		//�L�����N�^�[�̌���
	Vector2 mPos;		//�L�����N�^�[�̒n�}��̍��W
	Vector2 mPlayer;

	Keyboard key_;
	
	int i;
	int num;
	int move;

	int tCnt;
	int ttCnt;

	bool moveAnmCnt;

	//�ނ�
	bool moveFlg;
	//��
	bool mFlg;
	//��͂�
	bool tFlg;

	int mChipId;
	int mChiID;

	Vector2 mDamyPos;

	Vector2 mSizeOffset;//�L�����N�^�[�̃I�t�Z�b�g�T�C�Y�@�@�����̒l
	Vector2 mSize;		//�L�����N�^�[�摜�̃T�C�Y
	int mMoveSpeed;		//�L�����N�^�[�ړ��X�s�[�h
	int mAnmCnt;

	//���ʉ�
	int sHandle;
	int tHandle;
	int fHandle;
	int oHandle;
	int ttHandle;

	//�M�~�b�N
	Vector2 mgPos;
	Vector2 mgSize;
	bool gFlg;
	MAP_ID mapID;

	void message_box();

	DIR keyDir;

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

	int GetStamina(void);

	int Stamina_;		//�X�^�~�i�Ǘ�
	int Energy_;		//�G�l���M�[�Ǘ�
	bool staminaFlg_;	//�X�^�~�i�̃t���O
	int staminacnt_;

	bool qflg_;
	

	PL_ST state_;
	PlayerID plID_;
	
};


