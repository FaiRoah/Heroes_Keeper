#include "Evil.h"

string Evil::getType()
{
	return "EVIL";
}

void Evil::getInfo(fstream* file)
{
	*file << "crime:" << Evil::crime << endl <<
		"location:" << Evil::location << endl <<
		"name:" << Evil::name << endl <<
		"skills:" << Evil::skills << endl <<
		"weaponType:" << Evil::weaponType << endl;
}

void Evil::showInfo()
{
	cout << "Name of the EVIL is " << Evil::name << endl;
	cout << "Weapon type of EVIL is " << Evil::weaponType << endl;
	cout << "Skills of EVIL are " << Evil::skills << endl;
	cout << "Crime of EVIL is " << Evil::crime << endl;
	cout << "Location of EVIL is " << Evil::location<< endl;
}

void Evil::setInfo()
{
	cout << "Enter name of EVIL: ";
	name = getStringValue();	
	cout << "Enter weapon type of " << Evil::name << ": ";
	weaponType = getStringValue();
	cout << "Enter skills of " << Evil::name << ": ";
	skills = getStringValue();
	cout << "Enter crime of " << Evil::name << ": ";
	crime = getStringValue();
	cout << "Enter location of " << Evil::name << ": ";
	location = getStringValue();	
}

Evil::Evil()
{
	cout << "Evil's constructor " << this << " is called" << endl;
}

Evil::Evil(string crime, string location, string name, string skills, string weaponType)
{
	this->crime= crime;			
	this->location= location;	
	this->name= name;			
	this->skills = skills;		
	this->weaponType= weaponType;
}
