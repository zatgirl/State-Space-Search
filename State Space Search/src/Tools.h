#ifndef _Tools_H___
#define _Tools_H___

#include <stdio.h>
#include <stdlib.h>

#include "MagicSquare.h"

class Tools
{
public:
    int dimSquare;

    Tools(int _dimSquare);
    void InitializeSquare(MagicSquare::Square *square);
    void ShowSquare(MagicSquare::Square *square);

private:


};

#endif
