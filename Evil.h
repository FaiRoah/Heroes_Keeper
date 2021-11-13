#pragma once
#include "Base.h"
class Evil : public Base
{	
private:
	string name;
	string weaponType;
	string crime;	//haha
	string location;
	string skills;

public:
	string getType() override;
	void getInfo(fstream* file) override;
	void showInfo() override;
	void setInfo() override;

	Evil();
	Evil(string name, string weaponType, string crime, string location, string skills);
};

