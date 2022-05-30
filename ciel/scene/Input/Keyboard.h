#pragma once

enum class Trg
{
	NOW,
	OLD,
	MAX
};


class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	void Update(void);
	bool Init();

	Trg GetTrg(void);
	
	bool getKeyDown(unsigned char KeyCode);		//�L�[�������ꂽ�u�Ԃ���
	int  getKeyDownHold(unsigned char KeyCode);	//�L�[��������Ă����

private:
	char keyBuf_[256];
	char keyBufOld_[256];
	Trg keyTrg_;
};

