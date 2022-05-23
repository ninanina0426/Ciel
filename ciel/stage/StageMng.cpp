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

    return true;
}

void StageMng::Draw()
{
	stage_->DrawOwnScn();		//‚»‚ê‚¼‚ê‚Ìƒ}ƒbƒv‚ð•`‰æ
}

void StageMng::Update(void)
{
	// ”wŒiiƒJƒƒ‰j‚Ì‘€ì
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
	return stage_->GetMapChip(pos);
}



StageMng::StageMng()
{
	Init();
}

StageMng::~StageMng()
{
}
