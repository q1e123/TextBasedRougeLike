#include <iostream>
#include "Tile.h"
#include "Random.h"

void Tile::go(Tile *&last,Player &player){
    Tile *newTile =new Tile;
    newTile->data  = Random::generate(1,5);
    newTile->next = 0;
    last->next=newTile;
    last=newTile;
    Tile::event(last->data,player);
}

void Tile::event(int eventNumber,Player &player){
    switch(eventNumber){
        case 1:{
            //Buff
            std::cout<<"A mage appears and gives you a potion. ";
            switch( Random::generate(0,3) ){
                case 0:{
                    std::cout<<"It gives you more strength.\n";
                    player.setStrength(player.getStrength()+2);
                    player.setHealth(player.getHealth()+10); //Health = str*5
                    break;
                }
                case 1:{
                    std::cout<<"It gives you more agility.\n";
                    player.setAgility(player.getAgility()+5);
                    break;
                }
                case 2:{
                    std::cout<<"It gives you more intelligence.\n";
                    player.setIntelligence(player.getIntelligence()+5);
                    break;
                }
                case 3:{
                    std::cout<<"It heals you.\n";
                    player.setHealth(player.getHealth()+20);
                    break;
                }
            }
            player.refreshAtk();
            break;
        }
        case 2:{
            //Debuff
            std::cout<<"A mage appears and it curses you. ";
            switch( Random::generate(0,3) ){
                case 0:{
                    std::cout<<"You lose strength.\n";
                    player.setStrength(player.getStrength()-2);
                    break;
                }
                case 1:{
                    std::cout<<"You lose agility.\n";
                    player.setAgility(player.getAgility()-5);
                    break;
                }
                case 2:{
                    std::cout<<"You lose intelligence.\n";
                    player.setIntelligence(player.getIntelligence()-5);
                    break;
                }
                case 3:{
                    std::cout<<"You lose health.\n";
                    player.setHealth(player.getHealth()-5);
                    break;
                }
            }
            player.refreshAtk();
            break;
        }
        case 3:{
            //Found an item
            std::cout<<"You found an item. ";
            switch(player.getCharClass()){
                case 1:{
                    std::cout<<"It's a mighty sword.\n";
                    player.setStrength(player.getStrength()+5);
                    break;
                }
                case 2:{
                    std::cout<<"It's a mighty dagger.\n";
                    player.setAgility(player.getAgility()+8);
                    break;
                }
                case 3:{
                    std::cout<<"It's a mighty staff.\n";
                    player.setIntelligence(player.getIntelligence()+8);
                    break;
                }
            }
            player.refreshAtk();
            break;
        }
        case 4:{
            //Normal Mob
            int mobHp,mobAtk;
            mobHp=10;
            mobAtk=5;
            do{
                std::cout<<"HP: "<<player.getHealth()<<"         "<<"Enemy HP: "<<mobHp<<"\n1.Attack\n"<<player.skill<<"4.Flee\n";
                int answer;
                std::cin>>answer;
                while(std::cin.fail()) {
                    std::cerr << "Error: Please select an answer using 1-4\n";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    std::cin>>answer;
                }
                if(answer==4) break;
                switch(answer){
                    case 1:{
                        mobHp-=player.getAttack();
                        break;
                    }
                    case 2:{
                        switch(player.getCharClass()){
                            case 1:{
                                player.setStrength(player.getStrength()+3);
                                break;
                            }
                            case 2:{
                                player.setAgility(player.getAgility()+3);
                                break;
                            }
                            case 3:{
                                 player.setIntelligence(player.getIntelligence()+3);
                            }
                        }
                        break;
                    }
                    case 3:{
                        switch(player.getCharClass()){
                            case 1:{
                                if(mobAtk) mobAtk--;
                                break;
                            }
                            case 2:{
                                if(mobHp<=player.getAgility()/2) mobHp=0;
                                break;
                            }
                            case 3:{
                                 mobHp-=player.getIntelligence()*5;
                                 player.setHealth(player.getHealth()/2);
                            }
                        }
                        break;
                    }
                }
                player.setHealth(player.getHealth()-mobAtk);

                for(int i=0;i<0;i++)std::cout<<"\n";
            }while(mobHp>0 && player.getHealth()>0);
            if(player.getHealth()>0 && mobHp<=0){
                player.exp+=5;
                player.lvlUp();
            }
            break;
        }
        case 5:{
            //Boss Fight
            int mobHp,mobAtk;
            mobHp=15;
            mobAtk=10;
           do{
                std::cout<<"HP: "<<player.getHealth()<<"         "<<"Enemy HP: "<<mobHp<<"\n1.Attack\n"<<player.skill<<"4.Flee\n";
                int answer;
                std::cin>>answer;
                while(std::cin.fail()) {
                    std::cerr << "Error: Please select an answer using 1-4\n";
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                    std::cin>>answer;
                }
                if(answer==4) break;
                switch(answer){
                    case 1:{
                        mobHp-=player.getAttack();
                        break;
                    }
                    case 2:{
                        switch(player.getCharClass()){
                            case 1:{
                                player.setStrength(player.getStrength()+3);
                                break;
                            }
                            case 2:{
                                player.setAgility(player.getAgility()+3);
                                break;
                            }
                            case 3:{
                                 player.setIntelligence(player.getIntelligence()+3);
                            }
                        }
                        break;
                    }
                    case 3:{
                        switch(player.getCharClass()){
                            case 1:{
                                if(mobAtk) mobAtk--;
                                break;
                            }
                            case 2:{
                                if(mobHp<=player.getAgility()/2) mobHp=0;
                                break;
                            }
                            case 3:{
                                 mobHp-=player.getIntelligence()*5;
                                 player.setHealth(player.getHealth()/2);
                            }
                        }
                        break;
                    }
                }
                player.setHealth(player.getHealth()-mobAtk);

                for(int i=0;i<0;i++)std::cout<<"\n";
            }while(mobHp>0 && player.getHealth()>0);
            if(player.getHealth()>0 && mobHp<=0){
                player.exp+=10;
                player.lvlUp();
            }
            break;
        }
    }
}

Tile::Tile()
{

}


Tile::~Tile()
{
    //dtor
}
