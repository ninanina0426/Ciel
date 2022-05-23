#include "StageMng.h"
#include "ForestMap.h"
#include "SweetsMap.h"
#include"SweetsOutMap.h"
#include"SweetsSchoolMap.h"
#include "templeMap.h"
#include "TempleInMap.h"
#include "ForestInMap.h"
#include"../scene/Obj/Player.h"


bool StageMng::Init()
{
	stage_ = std::make_unique<SweetsMap>();
	//mPlayer = new Player();
	//mPlayer->init();

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();
	/*mPlayer->Draw(mOffset);*/
}

void StageMng::Update(void)
{
	// �w�i�i�J�����j�̑���
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mOffset.x_ += 4;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mOffset.x_ -= 4;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mOffset.y_ -= 4;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mOffset.y_ += 4;
	}

	stage_->Update(mOffset);

	if (CheckHitKey(KEY_INPUT_A))
	{
		stage_ = std::move(std::make_unique<ForestMap>());
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		stage_ = std::move(std::make_unique<TempleInMap>());
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		stage_ = std::move(std::make_unique<ForestInMap>());
	}
	/*mPlayer->Update();*/

}

bool StageMng::Release(void)
{
	for (int i = 0; i < CHIP_IMAGE_MAX; i++)
	{
		DeleteGraph(mChipImage[i]);
	}
	return true;
}

int StageMng::GetMapChip(Vector2 pos)
{
    //�@�}�b�v���W(pos)���}�b�v�z���index�ɕϊ���
//	//�A�}�b�v�z��ɓ����Ă���}�b�v�`�b�v�ԍ���Ԃ��B
    return mMap[pos.y_ / 32][pos.x_ / 32];
}

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
