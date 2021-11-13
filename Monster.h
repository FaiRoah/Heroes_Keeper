#pragma once
#include "Base.h"


class Monster : public Base
{
private:
	string appearance;
	string name;
public:
	string getType() override;
	void getInfo(fstream* file) override;
	void showInfo() override;
	void setInfo() override;
	Monster();
	Monster(string appearance, string name);
};

