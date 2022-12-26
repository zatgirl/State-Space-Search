#include "Tools.h"

Tools::Tools(int _dimSquare)
{
    this->dimSquare = _dimSquare;
}

void Tools::InitializeSquare(MagicSquare::Square *square)
{
    bool teste;
    for(int line = 0; line < this->dimSquare; line ++)
    {
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            square->grade[line][coll] = 0;
        }
    }
    square->magicConst = ((this->dimSquare * (pow(this->dimSquare, 2) + 1)) / 2);
    square->amountCells = pow(this->dimSquare, 2);

    teste = Tools::GenerateSquareRec(square, square->amountCells);
}

void Tools::CleanMatrix(MagicSquare::Square *square)
{
    for(int line = 0; line < this->dimSquare; line ++)
    {
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            square->grade[line][coll] = 0;
        }
    }
}

void Tools::GenerateSquare(MagicSquare::Square *square)
{
    int i = 0;

    for(int index_cell_1 = 1; index_cell_1 <= square->amountCells; index_cell_1 ++)
    {
        square->grade[0][0] = index_cell_1;
        for(int index_cell_2 = 1; index_cell_2 <= square->amountCells; index_cell_2 ++)
        {
            if(index_cell_1 == index_cell_2){
                continue;
            }
            square->grade[0][1] = index_cell_2;
            for(int index_cell_3 = 1; index_cell_3 <= square->amountCells; index_cell_3 ++)
            {
                if((index_cell_3 == index_cell_2) || (index_cell_3 == index_cell_1)){
                    continue;
                }
                square->grade[0][2] = index_cell_3;
                for(int index_cell_4 = 1; index_cell_4 <= square->amountCells; index_cell_4 ++)
                {
                    if((index_cell_4 == index_cell_2) || (index_cell_4 == index_cell_3) ||
                       (index_cell_4 == index_cell_1)){
                        continue;
                    }
                    square->grade[1][0] = index_cell_4;
                    for(int index_cell_5 = 1; index_cell_5 <= square->amountCells; index_cell_5 ++)
                    {
                        if((index_cell_5 == index_cell_2) || (index_cell_5 == index_cell_3) ||
                           (index_cell_5 == index_cell_1) || (index_cell_5 == index_cell_4)){
                            continue;
                        }
                        square->grade[1][1] = index_cell_5;
                        for(int index_cell_6 = 1; index_cell_6 <= square->amountCells; index_cell_6 ++)
                        {
                            if((index_cell_6 == index_cell_2) || (index_cell_6 == index_cell_3) ||
                               (index_cell_6 == index_cell_1) || (index_cell_6 == index_cell_4) ||
                               (index_cell_6 == index_cell_5)){
                                continue;
                            }
                            square->grade[1][2] = index_cell_6;
                            for(int index_cell_7 = 1; index_cell_7 <= square->amountCells; index_cell_7 ++)
                            {
                                if((index_cell_7 == index_cell_2) || (index_cell_7 == index_cell_3) ||
                                   (index_cell_7 == index_cell_1) || (index_cell_7 == index_cell_4) ||
                                   (index_cell_7 == index_cell_5) || (index_cell_7 == index_cell_6)){
                                    continue;
                                }
                                square->grade[2][0] = index_cell_7;
                                for(int index_cell_8 = 1; index_cell_8 <= square->amountCells; index_cell_8 ++)
                                {
                                    if((index_cell_8 == index_cell_1) || (index_cell_8 == index_cell_3) ||
                                       (index_cell_8 == index_cell_2) || (index_cell_8 == index_cell_4) ||
                                       (index_cell_8 == index_cell_5) || (index_cell_8 == index_cell_6) ||
                                       (index_cell_8 == index_cell_7)){
                                        continue;
                                    }
                                    square->grade[2][1] = index_cell_8;
                                    for(int index_cell_9 = 1; index_cell_9 <= square->amountCells; index_cell_9 ++)
                                    {
                                        if((index_cell_9 == index_cell_1) || (index_cell_9 == index_cell_3) ||
                                           (index_cell_9 == index_cell_2) || (index_cell_9 == index_cell_4) ||
                                           (index_cell_9 == index_cell_5) || (index_cell_9 == index_cell_6) ||
                                           (index_cell_9 == index_cell_7) || (index_cell_9 == index_cell_8)){
                                            continue;
                                        }
                                        square->grade[2][2] = index_cell_9;
                                        if(Tools::IsMagicSquare(square))
                                        {
                                            square->permutations ++;
                                        }
                                        i++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Combinacoes encontradas: %d\n", i);
    printf("Combinacoes validas: %d\n", square->permutations);
}

bool Tools::IsMagicSquare(MagicSquare::Square *square)
{
    //Tools::ShowSquare(square);
    int index = 0;
    int saveSums[(int)pow(this->dimSquare, 2)];
    ///Verificar Linhas
    for(int line = 0; line < this->dimSquare; line ++)
    {
        int sum = 0;
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            sum += square->grade[line][coll];
        }
        saveSums[index] = sum;
        index ++;
    }
    ///Verificar Colunas
    for(int coll = 0; coll < this->dimSquare; coll ++)
    {
        int sum = 0;
        for(int line = 0; line < this->dimSquare; line ++)
        {
            sum += square->grade[line][coll];
        }
        saveSums[index] = sum;
        index ++;
    }

    ///Verificar Diagonal Primaria
    int sum = 0;
    for(int line = 0; line < this->dimSquare; line ++)
    {
        sum += square->grade[line][line];
    }
    saveSums[index] = sum;
    index ++;

    ///Verificar Diagonal Secundaria
    sum = 0;
    for(int line = 0, coll = this->dimSquare - 1 ; line < this->dimSquare; line ++, coll --)
    {
        sum += square->grade[line][coll];
    }
    saveSums[index] = sum;


    ///Verificação final
    for(int i = 0; i <= index; i ++)
    {
        if(saveSums[i] != square->magicConst)
        {
            return false;
        }
    }
    return true;
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

bool Tools::GenerateSquareRec(MagicSquare::Square *square, int stop)
{
    bool condStop = false;
    int cont;
    for(int line = 0; line < this->dimSquare; line ++)
    {
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            square->grade[line][coll] = Tools::FillsCell(square->grade[line][coll], this->dimSquare, square);
        }
    }
    if(Tools::IsMagicSquare(square))
    {
        square->permutations ++;
    }
    else
    {
        for(int line = 0; line < this->dimSquare; line ++)
        {
            for(int coll = 0; coll < this->dimSquare; coll ++)
            {
                if(square->grade[line][coll] == stop)
                {
                    cont ++;
                }
            }
        }
        if(cont == stop)
        {
            return true;
        }
        if(cont != stop)
        {
            condStop = Tools::GenerateSquareRec(square, stop);
        }
    }
}

int Tools::FillsCell(int num, int cond, MagicSquare::Square *square)
{
    int n;

    for(int line = 0; line < this->dimSquare; line ++)
    {
        for(int coll = 0; coll < this->dimSquare; coll ++)
        {
            if (num == square->grade[line][coll])
            {
                n = Tools::FillsCell(num + 1, cond, square);
            }
        }
    }
    return n;
}

int Tools::MagicSquareCombinations (int N)
{
    printf("N: %d\n", N);
    if (N == 1)
    {
        return 1;
    }
    if (N == 2 || N == 0)
    {
        return 0;
    }
    if ((N % 2) == 0)
    {
        ///se o quadrado for par, divido em 4 quadrados
        return 4 * Tools::MagicSquareCombinations(N / 2);
    }
    else
    {
        ///se o quadrado for impar, divido em 9 quadrados
        return 9 * Tools::MagicSquareCombinations((N - 2) / 2) + 1;
    }

}
