#ifndef _MAGICSQUARE_H___
#define _MAGICSQUARE_H___

#include <stdio.h>
#include <stdlib.h>
#include <cmath>

#define DEF_DIM_SQUARE 3

class MagicSquare
{
public:
    struct Square
    {
        int grade[DEF_DIM_SQUARE][DEF_DIM_SQUARE] = {{0}};
        int permutations;
        int dimension;
        int magicConst;
        int amountCells;
    };
    Square *square;

    MagicSquare();

private:

};

#endif

