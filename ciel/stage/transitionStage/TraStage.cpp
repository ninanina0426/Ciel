#include "TraStage.h"

TraStage::TraStage(uniquStage beforStage, uniquStage nextStage)
{
    beforStage_ = std::move(beforStage);
    nextStage_ = std::move(nextStage);
}

TraStage::~TraStage()
{
}

//void TraStage::Update(Vector2 offset)
//{
//}

uniquStage TraStage::Update(uniquStage own)
{
    if (UpdataTrangetion())
    {
        return std::move(nextStage_);
    }
    return std::move(own);
}

//void TraStage::DrawOwnScn()
//{
//}

bool TraStage::Init(void)
{
    return true;
}

bool TraStage::CheckMapChip(Vector2 pos)
{
    return true;
}

int TraStage::GetMapChip(Vector2 pos)
{
    return 0;
}

MAP_ID TraStage::GetStageID(void)
{
    return MAP_ID::TRANGETIONS;
}
