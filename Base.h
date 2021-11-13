#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "InputCheck.h"

using namespace std;

class Base
{
public:
	//common methods
	virtual void showInfo() = 0;
	virtual void getInfo(fstream* file) = 0;
	virtual void setInfo() = 0;
	virtual string getType() = 0;
	

	//individual methods
	

	Base();
	Base(const Base& other);
	virtual ~Base();
};

