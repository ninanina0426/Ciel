#pragma once
#include <memory>
#include "../common/Vector2.h"

class BaseScene;

using uniquBaseScn = std::unique_ptr<BaseScene>;			//�V�[���̃|�C���^�[
using shareBaseScn = std::shared_ptr<BaseScene>;

//�V�[��ID
enum class SceneID
{
	TRANSTION,			//�g�����W�V�����V�[��
	TITLE,				//�^�C�g���V�[��
	SELECT,				//�L�����I���V�[��
	LOAD,				//���[�h�V�[��
	GAME,				//�Q�[���V�[��
	EVENT,				//�C�x���g�V�[��
	END,				//�G���h�V�[��
	MAX
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();
	virtual uniquBaseScn Update(uniquBaseScn own) = 0;
	virtual void Draw();
	virtual void DrawOwnScn() = 0;		//�e�V�[����Draw
	virtual bool Init(void) = 0;
	virtual SceneID GetSceneID(void) = 0;
protected:
	int sceneScrID_;					//�X�N���[��ID
	Vector2 screenSize_;				//�X�N���[��size


};


