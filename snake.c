#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define N 20
#define M 40


void SnakeInitialization(){
    f=fopen("high.txt", "r");
    fscanf(f, "%d   ", &Highscore);
    fclose(f);
        for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < M ; j++)
        {
            Field[i][j] = 0;
        }
    }
    x=N/2; y=M/2; Speed=99; Head=5; Tail=1; score=0; Frogs=0; Gy=y; pos = 'd'; Game=0;
    for(i = 0 ; i < Head ; i++)
    {
        Gy++;
        Field[x][Gy-Head] = i+1;
    }
}

void TailRemove(){
    for(i = 0 ; i < N ; i++)
    {
        for(j = 0 ; j < M ; j++)
        {
            if(Field[i][j] == Tail)
            {
                Field[i][j]=0;
            }
        }
    }
    Tail++;
}

int getch_noblock(){
    if (_kbhit())
        return _getch();
    else
        return -1;
}

void Random(){
    a = 1 + rand()%17;
    b = 1 + rand()%37;
    if(Frogs == 0 && Field[a][b] == 0)
    {
        Field[a][b] = -1;
        Frogs = 1;
        if(Speed > 10 && score != 0) Speed--;
    }

}

void Print(){
    for(i = 0 ; i <= M + 1; i++)
    {
        if(i==0) printf("%c", 201);
        else if(i == M + 1) printf("%c", 187);
        else printf("%c", 205);
    }
    printf(" CURRENT SCORE: %d   HIGHSCORE: %d", score, Highscore);
    printf("\n");
    for(i = 0 ; i < N ; i++)
    {
        printf("%c", 186);
        for(j = 0 ; j < M ; j++)
        {
            if(Field[i][j] == 0)  printf(" ");
            if(Field[i][j] > 0 && Field[i][j] != Head)  printf("%c", 176);
            if(Field[i][j] == Head)  printf("%c", 178);
            if(Field[i][j] == -1)  printf("%c", 15);
            if(j == M - 1) printf("%c\n", 186);
        }
    }

    for(i = 0 ; i <= M + 1; i++)
    {
        if(i == 0) printf("%c", 200);
        else if(i == M + 1) printf("%c", 188);
        else printf("%c", 205);
    }
}

void GameOver(){
    printf("\a");
    Sleep(1500);
    system("Cls");
    if(score>Highscore)
    {
    printf("NEW HIGHSCORE %d!!!\n\n", score);
    system("pause");
    f=fopen("high.txt", "w");
    fprintf(f,"%d   ", score);
    fclose(f);
    }
    system("Cls");
    printf("                                 GAME OVER!!! \n\n");
    printf("                                   SCORE: %d \n\n", score);
    printf("                   PRESS ENTER TO PLAY AGAIN OR ESC TO EXIT... \n");

    while(1)
    {
        Var = getch_noblock();
        if(Var == 13)
        {
            Game = 0;
            SnakeInitialization();
            break;
        }
        else if(Var == 27)
        {
            Game = 1;
            break;
        }
    }
    system("Cls");
}

void Position(){
    Var = getch_noblock();
    Var = tolower(Var);
    if(((Var == 'd' || Var=='a') || (Var == 'w' || Var == 's')) && (abs(pos - Var) > 5)) pos = Var;
    if(pos == 'd')
    {
        y++;
        if(Field[x][y] != 0 && Field[x][y] != -1) GameOver();
        if(y == M) y = 0;
        if(Field[x][y]==-1)
        {
            score = score + 5;
            Tail--;
            Tail--;
            Frogs=0;
        }
        Head++;
        Field[x][y] = Head;
    }

    if(pos == 'a')
    {
        y--;
        if(y == -1) y = M - 1;
        if(Field[x][y] != 0 && Field[x][y] != -1) GameOver();
        if(Field[x][y]==-1)
        {
            score = score + 5;
            Tail--;
            Tail--;
            Frogs=0;
        }
        Head++;
        Field[x][y] = Head;
    }

    if(pos == 'w')
    {
        x--;
        if(x == -1) x = N - 1;
        if(Field[x][y] != 0 && Field[x][y] != -1) GameOver();
        if(Field[x][y]==-1)
        {
            score = score + 5;
            Tail--;
            Tail--;
            Frogs = 0;
        }
        Head++;
        Field[x][y] = Head;
    }

    if(pos == 's')
    {
        x++;
        if(x == N) x = 0;
        if(Field[x][y] != 0 && Field[x][y] != -1) GameOver();
        if(Field[x][y]==-1)
        {
            score = score + 5;
            Tail--;
            Tail--;
            Frogs=0;
        }
        Head++;
        Field[x][y] = Head;
    }
}

void ResetScreenPosition(){
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
