#pragma once
#include "InputCheck.h"
#include <iostream>
#include <string>

enum evilOrGood {
    evil = 1,
    good = 2
};
enum strength {
    weakest = 0,
    strongest = 100
};
enum smart {
    mostDumb = 0,
    mostIntelligent = 100
};
enum luck {
    notLucky = -100,
    luckiest = 100
};
class Player {
private:
    string entityType;
    string name;
    int character;
    double strength;
    double intelligence;
    double luck;
    int hp;
public:
    int getHP();
    string getName();
    double getLuck();
    double getStrength();
    Player();
    Player(int);    //a constructor for enemy
    ~Player();
    void operator-(int hpToSubtract);
};