#include "Keeper.h"

void Keeper::add(Base* basePtr)
{
	Base** tmp = Keeper::dataPtr;
	Keeper::size++;
	dataPtr = new Base * [Keeper::size];
	for (int i = 0; i < size - 1; i++)
		dataPtr[i] = tmp[i];
	dataPtr[Keeper::size - 1] = basePtr;	//adding new entity to the end of the array
}

void Keeper::remove(Base* basePtr) {
	Base** tmp = Keeper::dataPtr;
	Keeper::size--;
	dataPtr = new Base * [Keeper::size];
	for (int i = 0; i <= size; i++) {	//"i <= size" because i have to check all elements of the initial array
		if (tmp[i] != basePtr) {
			dataPtr[i] = tmp[i];
		}
		else {
			i++;
			for (int j=i-1; i <= size; j++,i++)
				dataPtr[j] = tmp[i];
			break;
		}
	}
	delete basePtr;
	cout << endl << "The element has been removed" << endl << endl;
}

void Keeper::showAllInfo() {
	if (size == 0)		//array is empty
		cout << endl << "The array is empty. Nothing to show for now..." << endl << endl;
	else
		for (int i = 0; i < size; i++) {
			cout << endl << "~~~~~~~~~~~~~~~~~~" << endl;
			cout << i + 1 << "." << endl;
			dataPtr[i]->showInfo();
			cout << "~~~~~~~~~~~~~~~~~~" << endl << endl;
		}
}
////////////////////////////////////////////////////////////////////
//How data is stored in the saving file:
//*Entity type*
//field#1:
//field#2:
//field#3:
//field#4:
//field#5:
//
//Amount of fields is optional (MONSTER - 2, GOOD - 3, EVIL - 5)
//Example:
//MONSTER
//appearance:green big stinky
//name : Shrek
////////////////////////////////////////////////////////////////////

void Keeper::saveData(const char* path)
{
	fstream file;
	file.exceptions(ofstream::badbit | ofstream::failbit);
	try {
		file.open(path, std::fstream::out | std::fstream::trunc);
	}
	catch(const ofstream::failure & ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}
	file << Keeper::size << endl << endl;			//save size of the array to file
	for (int i = 0; i < size; i++) {
		file << dataPtr[i]->getType() << endl;		//save type of an entity to file
		dataPtr[i]->getInfo(&file);				  //save fields of an entity to file
		file << endl;
	}
	file.close();
}

void Keeper::uploadData(const char* path){
	fstream file;			//file to upload to
	string entityBuffer;	//buffer to define which entity to create: MONSTER, GOOD or EVIL
	string fieldBuffer[5];	//buffer to define fields of each entity. 5 is the biggest amount of fields of an entity
	string buf;				//buffer to skip empty line breaker
	file.exceptions(ifstream::badbit);
	try {
		file.open(path);
	}
	catch (const ifstream::failure& ex) {
		cout << "Error occured while opening the file." << endl;
		cout << ex.what() << endl << ex.code() << endl;
	}
	if (!Keeper::isEmpty()) {
		int prevArrSize = Keeper::getSize();	//size of the array that needs to be removed
		for (int i = 0; i < prevArrSize; i++)
			Keeper::remove(dataPtr[0]);		//removing 0th element every time because Keeper::remove() moves elements to the left by 1
	}

	while (!file.eof()) {
		getline(file, buf);
		if (buf == "MONSTER") {
			getline(file, buf);
			if (
				(buf[0] == 'a') &&
				(buf[1] == 'p') &&
				(buf[2] == 'p') &&
				(buf[3] == 'e') &&
				(buf[4] == 'a') &&
				(buf[5] == 'r') &&
				(buf[6] == 'a') &&
				(buf[7] == 'n') &&
				(buf[8] == 'c') &&
				(buf[9] == 'e') &&
				(buf[10] == ':')
				) {
				fieldBuffer[0].assign(buf.begin() + 11, buf.end());
			}
			else {
				cout << "Appearance of the MONSTER not found. Input an appearance of the MONSTER:";
				fieldBuffer[0] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'n') &&
				(buf[1] == 'a') &&
				(buf[2] == 'm') &&
				(buf[3] == 'e') &&
				(buf[4] == ':')
				) {
				fieldBuffer[1].assign(buf.begin() + 5, buf.end());
			}
			else {
				cout << "Name of the MONSTER not found. Input a name of the MONSTER:";
				fieldBuffer[1] = getStringValue();
			}
			Keeper::add(new Monster(fieldBuffer[0], fieldBuffer[1]));    //adding a new entity
		}

		else if (buf == "GOOD") {
			getline(file, buf);
			if (
				(buf[0] == 'n') &&
				(buf[1] == 'a') &&
				(buf[2] == 'm') &&
				(buf[3] == 'e') &&
				(buf[4] == ':')
				) {
				fieldBuffer[0].assign(buf.begin() + 5, buf.end());
			}
			else {
				cout << "Name of the GOOD not found. Input a name of the GOOD:";
				fieldBuffer[0] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 's') &&
				(buf[1] == 'k') &&
				(buf[2] == 'i') &&
				(buf[3] == 'l') &&
				(buf[4] == 'l') &&
				(buf[5] == 's') &&
				(buf[6] == ':')
				) {
				fieldBuffer[1].assign(buf.begin() + 7, buf.end());
			}
			else {
				cout << "Skills of the GOOD not found. Input skills of the GOOD:";
				fieldBuffer[1] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'w') &&
				(buf[1] == 'e') &&
				(buf[2] == 'a') &&
				(buf[3] == 'p') &&
				(buf[4] == 'o') &&
				(buf[5] == 'n') &&
				(buf[6] == 'T') &&
				(buf[7] == 'y') &&
				(buf[8] == 'p') &&
				(buf[9] == 'e') &&
				(buf[10] == ':')
				) {
				fieldBuffer[2].assign(buf.begin() + 11, buf.end());
			}
			else {
				cout << "Weapon type of the GOOD not found. Input a weapon type of the GOOD:";
				fieldBuffer[2] = getStringValue();
			}
			Keeper::add(new Good(fieldBuffer[0], fieldBuffer[1], fieldBuffer[2]));    //adding a new entity
		
		}

		else if (buf == "EVIL") {
			getline(file, buf);
			if (
				(buf[0] == 'c') &&
				(buf[1] == 'r') &&
				(buf[2] == 'i') &&
				(buf[3] == 'm') &&
				(buf[4] == 'e') &&
				(buf[5] == ':')
				) {
				fieldBuffer[0].assign(buf.begin() + 6, buf.end());
			}
			else {
				cout << "Crime of the EVIL not found. Input a name of the EVIL:";
				fieldBuffer[0] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'l') &&
				(buf[1] == 'o') &&
				(buf[2] == 'c') &&
				(buf[3] == 'a') &&
				(buf[4] == 't') &&
				(buf[5] == 'i') &&
				(buf[6] == 'o') &&
				(buf[7] == 'n') &&
				(buf[8] == ':')
				) {
				fieldBuffer[1].assign(buf.begin() + 9, buf.end());
			}
			else {
				cout << "Location of the EVIL not found. Input an appearance of the EVIL:";
				fieldBuffer[1] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'n') &&
				(buf[1] == 'a') &&
				(buf[2] == 'm') &&
				(buf[3] == 'e') &&
				(buf[4] == ':')
				) {
				fieldBuffer[2].assign(buf.begin() + 5, buf.end());
			}
			else {
				cout << "Name of the EVIL not found. Input an appearance of the EVIL:";
				fieldBuffer[2] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 's') &&
				(buf[1] == 'k') &&
				(buf[2] == 'i') &&
				(buf[3] == 'l') &&
				(buf[4] == 'l') &&
				(buf[5] == 's') &&
				(buf[6] == ':')
				) {
				fieldBuffer[3].assign(buf.begin() + 7, buf.end());
			}
			else {
				cout << "Skills of the EVIL not found. Input skills of the EVIL:";
				fieldBuffer[3] = getStringValue();
			}
			getline(file, buf);
			if (
				(buf[0] == 'w') &&
				(buf[1] == 'e') &&
				(buf[2] == 'a') &&
				(buf[3] == 'p') &&
				(buf[4] == 'o') &&
				(buf[5] == 'n') &&
				(buf[6] == 'T') &&
				(buf[7] == 'y') &&
				(buf[8] == 'p') &&
				(buf[9] == 'e') &&
				(buf[10] == ':')
				) {
				fieldBuffer[4].assign(buf.begin() + 11, buf.end());
			}
			else {
				cout << "Weapon type of the EVIL not found. Input a weapon type of the EVIL:";
				fieldBuffer[4] = getStringValue();
			}
			Keeper::add(new Evil(fieldBuffer[0], fieldBuffer[1], fieldBuffer[2], fieldBuffer[3], fieldBuffer[4]));    //adding a new entity
		}
		
	}



	//for (int i = 0; i < tempSize; i++) {
	//	getline(file, entityBuffer);		//skip the \n
	//	getline(file, entityBuffer);		//type of entity: MONSTER, GOOD or EVIL
	//	if (entityBuffer == "MONSTER") {
	//		for (int j = 0; j < MONSTER_FIELDS; j++) {
	//			getline(file, fieldBuffer[j]);
	//
	//		}
	//		Keeper::add(new Monster(fieldBuffer[0], fieldBuffer[1]));    //adding a new entity
	//	}
	//	else if (entityBuffer == "GOOD") {
	//		for (int j = 0; j < GOOD_FIELDS; j++) {
	//			getline(file, fieldBuffer[j]);
	//		}
	//		Keeper::add(new Good(fieldBuffer[0], fieldBuffer[1], fieldBuffer[2]));	//adding a new entity
	//	}
	//	else if (entityBuffer == "EVIL"){
	//		for (int j = 0; j < EVIL_FIELDS; j++) {
	//			getline(file, fieldBuffer[j]);
	//		}
	//		Keeper::add(new Evil(fieldBuffer[0], fieldBuffer[1], fieldBuffer[2], fieldBuffer[3], fieldBuffer[4]));	//adding a new entity
	//	}
	//	else
	//		cout << "Something went wrong with defining type of Entity" << endl;	
	//}
	file.close();
}

bool Keeper::isEmpty()
{
	if (Keeper::size > 0)
		return false;
	else
		return true;
}


Keeper::Keeper()
{
	cout << "Keeper's constructor " << this << " is called" << endl;
	size = 0;
	dataPtr = new Base*[size];
}

Keeper::Keeper(const Keeper& other) {
	cout << "Keeper's copy constructor " << this << " is called" << endl;
}


Keeper::~Keeper() {
	cout << "Keeper's destructor " << this << " is called" << endl;
	for (int i = 0; i < size; i++) {
		
		delete dataPtr[i];
	}
	dataPtr = nullptr;
	size = 0;
}

int Keeper::getSize()
{
	return Keeper::size;
}
