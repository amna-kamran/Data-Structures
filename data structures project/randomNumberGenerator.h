#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include<time.h>
#include <cstdlib>


class randomNumberGenerator{
public:
int number;


int randNum(){
number=rand()%1000;
srand ( time(NULL) );
return number;
}


};
#endif
