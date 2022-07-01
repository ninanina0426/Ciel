#pragma once
class UI
{
public:
	UI();
	~UI();

	void Upadate(int sta);
	void Draw(void);
private:
	void Init();

	int stamina;
};

