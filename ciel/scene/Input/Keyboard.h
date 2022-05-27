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
	
	bool getKeyDown(unsigned char KeyCode);		//キーが押された瞬間だけ
	int  getKeyDownHold(unsigned char KeyCode);	//キーが押されている間

private:
	char keyBuf_[256];
	char keyBufOld_[256];
	Trg keyTrg_;
};

