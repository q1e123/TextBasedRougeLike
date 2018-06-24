#include <ctime>
#include <cstdlib>
#include "Random.h"

int Random::generate(int min,int max){
    srand(time(0));
   return rand()% (max-min+1) + min;
}
Random::Random()
{

    //ctor
}

Random::~Random()
{
    //dtor
}
