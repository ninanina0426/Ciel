#pragma once
#include "BaseScene.h"
#define lpSceneMng SceneMng::GetInstance()  //���I�Ȋ֐�

constexpr int ScreenSizeX = 1080;			//�X�N���[���T�C�Y��
constexpr int ScreenSizeY = 609;			//�X�N���[���T�C�Y�c

class SceneMng
{
public:
	static SceneMng& GetInstance()
	{
		static SceneMng s_Instance;
		return s_Instance;
	}
	void Run(void);
	void Update(void);
	void Draw(void);
	bool Release(void);

private:
	bool SysInit(void);
	bool InitFlag_;//�V�X�e���̏��������킩

	//static SceneMng s_Instance;
	SceneMng();
	~SceneMng();
	uniquBaseScn  scene_;//�V�[���Ǘ�
};

