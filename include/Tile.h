#include "Player.h"

#ifndef TILE_H
#define TILE_H


class Tile
{
    public:
        int data;
        Tile *next;
        static void go(Tile *&tile,Player &player);
        Tile();
        virtual ~Tile();

    protected:
    private:
        static void event(int eventNumber,Player &player);
};

#endif // TILE_H
