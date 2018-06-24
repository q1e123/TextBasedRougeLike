#include <iostream>
#include<fstream>
#include "Player.h"
#include "Window.h"
#include "Tile.h"

bool exists(){
  std::fstream FILE("save.txt");
  return FILE;
}

int main()
{
    Player player;
    Tile *start = new Tile;
    start->data  = 0;
    start->next=0;
    Tile *current=start;
    if(exists()){
        std::cout<<"A save file has been found. Do you want to load it?\n1.Yes\n2.No\n";
        int answer;
        std::cin>>answer;
        while(std::cin.fail()) {
            std::cerr << "Error: Please select an answer using 1 or 2\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin>>answer;
        }
        if(answer==1){
            std::fstream FILE("save.txt");
            int x;
            FILE>>x;
            player.setCharClass(x);
            FILE>>x;
            player.setStrength(x);
            FILE>>x;
            player.setAgility(x);
            FILE>>x;
            player.setIntelligence(x);
            FILE>>x;
            player.setHealth(x);
            FILE>>x;
            player.setAttack(x);
            FILE>>x;
            player.lvl=x;
            FILE>>x;
            player.exp=x;
            player.setSkill();
            while(!FILE.eof()){
                FILE>>x;
                Tile* tmp=new Tile;
                tmp->data  = x;
                tmp->next = 0;
                current->next=tmp;
            }
            FILE.close();
        }else{
            for(int i=0;i<100;i++) std::cout<<"\n";
            player.init();
        }
    }else{
        player.init();
    }

    while(1){
        for(int i=0;i<100;i++) std::cout<<"\n";
        Tile::go(current,player);
        if(player.getHealth()<0){
            std::remove("save.txt");
            break;
        }
        std::cout<<"Do you wish to go forward?\n1.Yes 2.No\n";
        int answer;
        checkpoint:;
        std::cin>>answer;
        while(std::cin.fail()) {
            std::cerr << "Error: Please select an answer using 1 or 2\n";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin>>answer;
        }

        if(answer==2){
            std::ofstream FILE("save.txt");
            FILE<<player.getCharClass()<<"\n";
            FILE<<player.getStrength()<<"\n";
            FILE<<player.getAgility()<<"\n";
            FILE<<player.getIntelligence()<<"\n";
            FILE<<player.getHealth()<<"\n";
            FILE<<player.getAttack()<<"\n";
            FILE<<player.lvl<<"\n";
            FILE<<player.exp<<"\n";
            while (start){
                FILE<<start->data<<"\n";
                start = start->next;
            }
            break;
        }
    }

    return 0;
}
