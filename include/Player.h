#include<string>

#ifndef PLAYER_H
#define PLAYER_H



class Player
{
    public:
        Player();
        virtual ~Player();
        ///Getters
        int getStrength();
        int getAgility();
        int getIntelligence();
        int getCharClass();
        int getHealth();
        int getAttack();
        ///Setters
        void setStrength(int str);
        void setAgility(int agl);
        void setIntelligence(int intl);
        void setCharClass(int cl);
        void setHealth(int hp);
        void setAttack(int atk);

        void refreshAtk();
        void init();
        void lvlUp();
        void setSkill();

        int lvl,exp;
        std::string skill;
    protected:

    private:
        int strength,agility,intelligence,charClass,health,attack;

};

#endif // PLAYER_H
