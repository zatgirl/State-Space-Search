#include "Tools.h"

Tools::Tools(int _dimSquare)
{
    this->dimSquare = _dimSquare;
}

void Tools::InitializeSquare(MagicSquare::Square *square)
{
    for(int line = 0; line < this->dimSquare; line ++)
    {
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            square->grade[line][coll] = 0;
        }
    }
    square->grade[1][1] = 3;
}

void Tools::ShowSquare(MagicSquare::Square *square)
{
    printf("Square: \n");
    for(int line = 0; line < this->dimSquare; line ++)
    {
        printf("%d ",   square->grade[line][0]);
        printf("%d ",   square->grade[line][1]);
        printf("%d \n", square->grade[line][2]);
    }
}
