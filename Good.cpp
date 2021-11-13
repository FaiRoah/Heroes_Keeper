#include "Good.h"

string Good::getType()
{
	return "GOOD";
}

void Good::getInfo(fstream* file)
{
	*file << "name:" << Good::name << endl <<
		"skills:" << Good::skills << endl << 
		"weaponType:" << Good::weaponType << endl;
}

void Good::showInfo()
{
	cout << "Name of the GOOD is " << Good::name << endl;
	cout << "Weapon type of GOOD is " << Good::weaponType << endl;
	cout << "Skills of GOOD are " << Good::skills << endl;
}

void Good::setInfo()
{
	cout << "Enter name of GOOD: ";
	name = getStringValue();	
	cout << "Enter weapon type of " << Good::name << ": ";
	weaponType = getStringValue();	
	cout << "Enter skills of " << Good::name << ": ";
	skills = getStringValue();	
}

Good::Good()
{
	cout << "Good's constructor " << this << " is called" << endl;

}

Good::Good(string name, string skills, string weaponType)
{
	this->name = name;
	this->skills = skills;
	this->weaponType = weaponType;
}
