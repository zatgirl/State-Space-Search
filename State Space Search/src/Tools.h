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
    void CleanMatrix(MagicSquare::Square *square);
    void InitializeSquare(MagicSquare::Square *square);
    void GenerateSquare(MagicSquare::Square *square);
    void ShowSquare(MagicSquare::Square *square);
    int MagicSquareCombinations(int N);
    bool IsMagicSquare(MagicSquare::Square *square);

private:


};

#endif
