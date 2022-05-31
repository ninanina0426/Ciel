#include "TraStage.h"

//TraStage::TraStage(uniquStage beforStage, uniquStage nextStage)
//{
//   /* beforStage_ = std::move(beforStage);
//    nextStage_ = std::move(nextStage);*/
//}

TraStage::~TraStage()
{
}


void TraStage::Update(uniquStage own)
{
    if (UpdataTrangetion())
    {
        ChangeFlg_ = true;
        //std::move(nextStage_);
    }
    ChangeFlg_ = false;
}
    


bool TraStage::Init(void)
{
    ChangeFlg_ = false;
    return true;
}


