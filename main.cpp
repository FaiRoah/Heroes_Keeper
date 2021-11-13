#define LOWLIMIT 0  //limits for the main menu
#define UPLIMIT 6

#define MONSTER 1
#define GOOD 2
#define EVIL 3

#define SHOW 1
#define ADD 2
#define REMOVE 3
#define SAVE 4
#define UPLOAD 5
#define GAMEMODE 6
#define EXIT 0

#define PATH "savingFile.txt"

#include <iostream>
#include <typeinfo>	
#include <conio.h>
#include "Keeper.h"
#include "Monster.h"
#include "Good.h"
#include "Evil.h"
#include "InputCheck.h"
#include "Player.h"

using namespace std;

void printMenu();
void gamemode();

int main() { //dynamic array base** ptr;
	Keeper keeper;
    

	cout << endl << "Hey :)" << endl << endl;
	while (true) {
		printMenu();
        switch (getIntValue(LOWLIMIT, UPLIMIT)) {
            cout << endl;
        case SHOW :
            keeper.showAllInfo();
            break;
        case ADD :
            cout << "What entity do you want to add?:" << endl <<
                "1. MONSTER" << endl <<
                "2. GOOD" << endl <<
                "3. EVIL" << endl;
            switch (getIntValue(1, 3)) {    //3 types of entities
            case MONSTER:
                keeper.add(new Monster);    //adding a new entity
                keeper.dataPtr[keeper.getSize()-1]->setInfo();
                break;
            case GOOD:
                keeper.add(new Good);    //adding a new entity
                keeper.dataPtr[keeper.getSize() - 1]->setInfo();
                break;
            case EVIL:
                keeper.add(new Evil);    //adding a new entity
                keeper.dataPtr[keeper.getSize() - 1]->setInfo();
                break;
            default:
                cout << "Wrong number entered." << endl;
                break;
            }
            break;
        case REMOVE :
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to remove..." << endl << endl;
                break;
            }
            else {
                cout << "Here are all entities:" << endl;
                keeper.showAllInfo();
                cout << "What entity you want to remove? Enter a number:";
                keeper.remove(keeper.dataPtr[getIntValue(1, keeper.getSize()) - 1]);
                break;
            }
        case SAVE :
            if (keeper.isEmpty()) {
                cout << endl << "The array is empty. Nothing to save..." << endl << endl;
                break;
            }
            else {
                keeper.saveData(PATH);
                cout <<  endl << "Successful saving data" << endl << endl;
                break;
            }
        case UPLOAD :
            keeper.uploadData(PATH);
            cout << endl << "Successful uploading data" << endl << endl;
            break;
        case GAMEMODE :
            cout << endl << "Entering the game mode" << endl << endl;
            gamemode();
            break;
        case EXIT :
            /*while (true) {
                cout << endl << "Confirm exiting. y/n:";
                _getch()
            }*/
            cout << endl << "Exiting the program. Bye-bye." << endl << endl;
            return 0;
        default:
            cout << endl << "Wrong number entered." << endl;
            break;
        }
	}
	return 0;
}

void printMenu() {
	cout << "What do you want to do:" << endl;
    cout << "1. Show every entity" << endl <<
        "2. Add an entity" << endl <<
        "3. Remove an entity" << endl <<
        "4. Save data to file" << endl <<
        "5. Upload data from file" << endl <<
        "6. Enter GAMEMODE" << endl <<
        "0. Exit the program" << endl << endl <<
		"Enter a number:";
}

void gamemode() {
    srand(time(0));
    int hpToSubtract;
    Player me;
    Player enemy(evil);
    
    ////////////The enemy//////////////
    
    cout << endl << "*******************LET THE FIGHT BEGIN*******************" << endl;
    while (me.getHP() > 0 && enemy.getHP() > 0) {
        int randNumber = rand() % 25 + 1;
        cout << endl << "~~~~~~~~Your turn~~~~~~~~" << endl << endl;
        cout << "How you want to attack:" << endl
            << "1.With brute force!" << endl
            //<< "2.Intelligent..." << endl
            << "Enter a number:";
        switch (getIntValue(1, 1)) {
        case 1:
            hpToSubtract = (randNumber * (me.getStrength()) * (1 + me.getLuck()));
            enemy - hpToSubtract;
            cout << endl << "You hit " << enemy.getName() << " for " << hpToSubtract << " hp." << endl;
            cout << "Enemy has " << enemy.getHP() << " hp." << endl;
            break;
        case 2:
            //Being developed
            break;
        default:
            cout << "Something went wrong with switch-case..." << endl;
            break;
        }

        cout << endl << "~~~~~~~~Enemy turn~~~~~~~~" << endl << endl;
        hpToSubtract = (rand() % 25 * (enemy.getStrength()) * (1 + enemy.getLuck()));
        me - hpToSubtract;
        cout << endl << "Enemy hit you for " << hpToSubtract << " hp." << endl;
        cout << "You have " << me.getHP() << " hp." << endl;
    }
    if (me.getHP() <= 0)
        cout << endl << "YOU ARE DEAD. YOU LOOSE" << endl;
    else if (enemy.getHP() <= 0)
        cout << endl << "ENEMY IS DEAD. YOU WIN" << endl << endl;
}
