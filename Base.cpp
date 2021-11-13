#include "Base.h"

Base::Base()
{
	cout << "Base's constructor " << this << " is called" << endl;

}

Base::Base(const Base& other) {
	cout << "Base's copy constructor " << this << " is called" << endl;
}

Base::~Base()
{
	
	cout << "Base's destructor "<< this << " is called" << endl;
}
