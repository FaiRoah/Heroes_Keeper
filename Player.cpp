#include "Player.h"

int Player::getHP()
{
    return this->hp;
}

string Player::getName()
{
    return this->name;
}

double Player::getLuck()
{
    return this->luck;
}

double Player::getStrength()
{
    return this->strength;
}

Player::Player() {
    cout << endl << endl << "Player's constructor is called" << endl << endl;
    cout << endl << "Tell me your entity type:";
    entityType = getStringValue();
    cout << endl << "Are you evil or good?:" << endl;
    cout << "1.Evil" << endl
        << "2.Good" << endl;
    character = getIntValue(evil, good);  //1 - Evil, 2 - Good
    cout << endl << "What is your strength on a 0 to 100 scale?:";
    strength = getDoubleValue(weakest, strongest)/100;
    cout << endl << "How intelligent are you on a 0 to 100 scale?:";
    intelligence = getDoubleValue(mostDumb, mostIntelligent)/100;
    cout << endl << "How lucky are you on a -100 to 100 scale?:";
    luck = getDoubleValue(notLucky, luckiest)/100;
    hp = 100;
}

Player::Player(int)
{
    cout << endl << endl << "Player's (enemy) constructor is called" << endl << endl;
    name = "Darth Vader";
    hp = 100;
    entityType = "Human";
    character = evil;
    strength = 0.75;
    intelligence = 0.7;
    luck = 0.6;
}

Player::~Player()
{
    cout << endl << "Player's destructor " << this << " is called" << endl;
}

void Player::operator-(int hpToSubtract)
{
    this->hp-= hpToSubtract;
}
