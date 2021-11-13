#pragma once

#define MONSTER_FIELDS 2
#define GOOD_FIELDS 3
#define EVIL_FIELDS 5
#include <iostream>
#include <fstream>
#include <string>
#include "Base.h"
#include "Monster.h"
#include "Good.h"
#include "Evil.h"
#include "InputCheck.h"

using namespace std;

class Keeper
{
private:
	int size;	//size of the dynamic array of pointers
public:
	Base** dataPtr;
	void add(Base* basePtr);
	void remove(Base* basePtr);
	int getSize();	//remember that size starts from 1, all other functions start from 0
	void showAllInfo();
	void saveData(const char* path);
	void uploadData(const char* path);
	bool isEmpty();

	Keeper();
	Keeper(const Keeper &other);
	~Keeper();
};

