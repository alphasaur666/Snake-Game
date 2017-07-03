#ifndef __SNAKE_H__
#define __SNAKE_H__


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#define N 20
#define M 40


void SnakeInitialization();
void TailRemove();
int getch_noblock();
void Random();
void Print();
void GameOver();
void Position();
void ResetScreenPosition();


#endif
