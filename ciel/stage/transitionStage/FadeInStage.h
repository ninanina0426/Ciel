#pragma once

class FadeInStage 
{
public:
	FadeInStage();
	~FadeInStage();
	bool UpdataTrangetion(void);
	void DrawOwnScn(void);
	int GetCnt(void);
	void Setcnt(int num);
private:
	void Init();
	

	int id_;
	bool flg_;
	bool ChangeFlg_;
	int count_;
	int cnt_;
};

