#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define N 20
#define M 40

int main(){
    int Field[N][M], i, j, x, y, Speed, Gy, Tail, Head, Game, Frogs, score, a, b, Highscore;
    char pos, Var;
    system("color B");
    printf("\n\n\n\n\n                                C Console Snake Game            \n\n");
    printf("                        Copyrights: Rosu Razvan.           \n\n");
    printf("                                     HAVE FUN!            \n\n\n\n\n");
    system("Pause");
    system("Cls");

    FILE *f;

    SnakeInitialization();
    while(Game == 0)
    {
        Print();
        Random();
        Position();
        TailRemove();
        Sleep(Speed);
        ResetScreenPosition();
    }

    return 0;
    }
