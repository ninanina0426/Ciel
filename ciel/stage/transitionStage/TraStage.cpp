#include "TraStage.h"

TraStage::TraStage(uniquStage beforStage, uniquStage nextStage)
{
    beforStage_ = std::move(beforStage);
    nextStage_ = std::move(nextStage);
}

TraStage::~TraStage()
{
}


void TraStage::Update(uniquStage own)
{
    if (UpdataTrangetion())
    {
        std::move(nextStage_);
    }
}
    


bool TraStage::Init(void)
{
    return true;
}


