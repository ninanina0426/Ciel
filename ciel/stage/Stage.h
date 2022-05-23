#pragma once
#include <memory>
#include <string>
#include"../common/Vector2.h"

#define CHIP_IMAGE_MAX (10000)		//�}�b�v�^�C���摜���T�C�Y

constexpr int MAP_X = 100;			//���}�b�v�^�C����
constexpr int MAP_Y = 100;			//���}�b�v�^�C���c
constexpr int ChipSize_X = 32;		//�`�b�v�T�C�Y��
constexpr int ChipSize_Y = 32;		//�`�b�v�T�C�Y�c
class Stage;

using uniquStage = std::unique_ptr<Stage>;			//map�̃|�C���^�[

enum class MAP_ID
{
	FOREST,
	FORESTIN,
	TEMPLE,
	TEMPLEIN,
	SWEETS,
	SWEETSOUT,
	SWEETSSCHOOL,
	MAX
};

class Stage
{
public:
	Stage();
	virtual ~Stage();
	virtual void Update(Vector2 offset) = 0;
	virtual void Draw();
	virtual void DrawOwnScn() = 0;		//�e�V�[����Draw
	virtual bool Init(void) = 0;
	virtual bool CheckMapChip(Vector2 pos)=0;  //�����蔻��
	virtual MAP_ID GetSceneID(void) = 0;
	Vector2 GetOffSet(void);
	void SetOffSet(Vector2 offset);
protected:
	Vector2 mOffset;
	int mChipImage[10000];
	int mMap[MAP_Y][MAP_X];
	
	/*MAP_ID mMapID;*/
		//���W���w�肵�ă}�b�v�`�b�v�f�[�^�����炤�B

};

