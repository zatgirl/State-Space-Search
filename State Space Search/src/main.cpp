/*********************************************************************
// Canvas para desenho, criada sobre a API OpenGL. Nao eh necessario conhecimentos de OpenGL para usar.
//  Autor: Cesar Tadeu Pozzer
//         05/2020
//
//  Versao 2.0
// *********************************************************************/

#include <GL/glut.h>
#include <GL/freeglut_ext.h> //callback da wheel do mouse.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "gl_canvas2d.h"

#include "Vector2.h"
#include "Vector3.h"
#include "Frames.h"
#include "MagicSquare.h"
#include "Tools.h"

MagicSquare *magicSquare;
Tools *tools;

int screenWidth = 900, screenHeight = 900;
bool click = false;
float fps;

int grade = 3;

void render()
{

}

void keyboard(int key)
{

}

void keyboardUp(int key)
{

}

//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{

}

int main(void)
{
    magicSquare = new MagicSquare();
    tools = new Tools(3);

    tools->InitializeSquare(magicSquare->square);
    //tools->ShowSquare(magicSquare->square);
    tools->GenerateSquare(magicSquare->square);

    //CV::init(&screenWidth, &screenHeight, "T3 - State Space Search");
    //CV::run();

    return 0;
}
