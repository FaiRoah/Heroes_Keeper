#include "Monster.h"

string Monster::getType()
{
	return "MONSTER";
}

void Monster::getInfo(fstream* file)
{
	*file << "appearance:" << Monster::appearance << endl <<
		"name:" << Monster::name << endl;
}

void Monster::showInfo()
{
	cout << "MONSTER name is " << Monster::name << endl;
	cout << "MONSTER appearance is " << Monster::appearance << endl;
}

void Monster::setInfo()
{
	cout << "Enter name of MONSTER: ";
	name = getStringValue();
	cout << "Enter appearance of " << Monster::name << ": ";
	appearance = getStringValue();
}

Monster::Monster()
{
	cout << "Monster's constructor " << this << " is called" << endl;
}

Monster::Monster(string appearance, string name)
{
	this->appearance = appearance;
	this->name = name;
}
