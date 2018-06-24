#include<iostream>
#include "Player.h"

//Getters
int Player::getAgility(){
    return agility;
}
int Player::getStrength(){
    return strength;
}
int Player::getIntelligence(){
    return intelligence;
}

int Player::getCharClass(){
    return charClass;
}

int Player::getHealth(){
    return health;
}
int Player::getAttack(){
    return attack;
}

//Setters

void Player::setAgility(int agl){
    agility=agl;
}
void Player::setIntelligence(int intl){
    intelligence=intl;
}
void Player::setStrength(int str){
    strength=str;
}
void Player::setCharClass(int cl){
    charClass=cl;
}
void Player::setHealth(int hp){
    health=hp;
}
void Player::setAttack(int atk){
    attack=atk;
}

void Player::refreshAtk(){
    switch(charClass){
        case 1:{ //Warrior
            attack=strength+intelligence/2+agility/2;
            break;
        }
        case 2:{ //Rouge
            attack=strength/2+intelligence+agility*2;
            break;
        }
        case 3:{ //Mage
            attack=strength/2+intelligence*3+agility;
        }
    }
}

void Player::lvlUp(){
    if(exp/10>lvl){
        lvl++;
        switch(charClass){
            case 1:{
                strength+=5;
                agility+=2;
                intelligence++;
                health+=40;
                break;
            }
            case 2:{
                strength++;
                agility+=5;
                intelligence+=2;
                health+=30;
                break;
            }
            case 3:{
                strength++;
                agility+=2;
                intelligence+=5;
                health+=20;
            }
        }
        std::cout<<"Level up!\n";
    }
}

void Player::setSkill(){
    switch(charClass){
        case 1:{
            skill="2.Rage\n3.Stone armor\n";
            break;
        }
        case 2:{
            skill="2.Sneak\n3.Assassinate\n";
            break;
        }
        case 3:{
            skill="2.Focus\n3.Blood Magic\n";
        }
    }
}

void Player::init(){
    std::cout<<"Choose a class\n1.Warrior\n2.Rouge\n3.Mage\n";
    checkpoint:;
    std::cin>>charClass;
    while(std::cin.fail()) {
        std::cerr << "Error: Please put valid input\n";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin>>charClass;
    }
    switch(charClass){
        case 1:{ //Warrior
            strength=5;
            agility=2;
            intelligence=1;
            break;
        }
        case 2:{ //Rouge
            strength=1;
            agility=5;
            intelligence=2;
            break;
        }
        case 3:{ //Mage
            strength=1;
            agility=2;
            intelligence=5;
            break;
        }
        default:{
            std::cerr<<"Error: Choose your class by using 1, 2 or 3\n";
            goto checkpoint;
        }
    }
    health=strength*5;
    lvl=0;
    exp=0;
    setSkill();
    refreshAtk();

}


Player::Player()
{
    //ctor

}

Player::~Player()
{
    //dtor
}
