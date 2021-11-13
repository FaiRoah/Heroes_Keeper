#pragma once
#include "Base.h"
class Good : public Base
{
private:
	string name;
	string skills;
	string weaponType;
public:
	string getType() override;
	void getInfo(fstream* file) override;
	void showInfo() override;
	void setInfo() override;

	Good();
	Good(string name, string skills, string weaponType);
};

