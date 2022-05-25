#include "StageMng.h"
#include "SweetsMap.h"
#include"../scene/Obj/Player.h"
#include"SweetsOutMap.h"
#include"SweetsSchoolMap.h"
#include "ForestMap.h"
#include "templeMap.h"
#include "TempleInMap.h"
#include "ForestInMap.h"

bool StageMng::Init()
{
	stage_ = std::make_unique<SweetsMap>();

	

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();		//���ꂼ��̃}�b�v��`��
}

Vector2 StageMng::Update(Vector2 mPlayerset)
{
	// �w�i�i�J�����j�̑���
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		mOffset.x_ += 3;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		mOffset.x_ -= 3;
	}
	if (CheckHitKey(KEY_INPUT_UP))
	{
		mOffset.y_ -= 3;
	}
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		mOffset.y_ += 6;
	}



	//�J�����Ǐ]
	if (mPlayerset.x_ - mOffset.x_ > 520)

	{
		mOffset.x_ += 2;
	}

	if (mPlayerset.x_ - mOffset.x_ < 900)
	{
		mOffset.x_ -= 2;

	}
	//�J�������ړ�����
	if (mPlayerset.y_ - mOffset.y_ < 400)
	{
		mOffset.y_ -= 2;

	}
	if (mPlayerset.y_ - mOffset.y_ > 1400)
	{
		mOffset.y_ += 2;
	}

	//�J�����[
	if (mOffset.x_ > 530)
	{
		mOffset.x_ = 530;
	}
	if (mOffset.x_ < 0)
	{
		mOffset.x_ = 0;
	}
	if (mOffset.y_ < 0)
	{
		mOffset.y_ = 0;
	}
	if (mOffset.y_ > 1000)
	{
		mOffset.y_ = 1000;
	}


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
		
	}

	stage_->Update(mOffset);

	
	
	/*if (mMapChange == true)
	{
		mMapChange = false;
	}*/
	//	/*stage_->GetSceneID(mNextMapID);*/
	//	mPlayer.SetPos(mNextPos);
	//}

	/*mPlayer.Update();*/

	if (mMapChange == true)
	{
		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//�}�b�v��؂�ւ��邱�ƂɂȂ���
			stage_ = std::move(std::make_unique<ForestInMap>());
		}
	}
	
	return mOffset;

}

bool StageMng::Release(void)
{
	for (int i = 0; i < CHIP_IMAGE_MAX; i++)
	{
		DeleteGraph(mChipImage[i]);
	}
	return true;
}


bool StageMng::cheakMapChip(Vector2 pos)
{
	return stage_->CheckMapChip(pos);
}

bool StageMng::GetEvent(Vector2 pos)
{
	int chipID = stage_->GetMapChip(pos);
	//�K�i���ŃX�e�[�W�؂�ւ�
	if (chipID == 1407)
	{
		mMapChange = true;

		if (lpMapMng.mMapID == MAP_ID::FOREST)
		{
			//�}�b�v��؂�ւ��邱�ƂɂȂ���
			
			/*mNextMapID = MAP_ID::FORESTIN;*/
			mNextPos = { 1400,400 };
			stage_ = std::move(std::make_unique<ForestInMap>());
			
		}
	}


	return mMapChange;
}

Vector2 StageMng::GetPos(void)
{

	return mNextPos;
}

StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
