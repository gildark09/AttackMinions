#include <stdio.h>
#include <windows.h>
#ifndef MinionsAttack_h
#define MinionsAttack_h

typedef struct {
    int soldiers;
    int x;
    int y;
    int col;
    int row;
} ARMY;  

typedef struct {
    int gold;
    int farm;
    ARMY army;  
} PLAYER;

typedef struct{
	int soldiers;
	int row;
	int col;
	int x;
	int y;
}ENEMY;

void gotoxy(int column, int row);
void StartGame();
void SoloGameplay(PLAYER player);
void printReturn();
PLAYER attack(PLAYER player);
void printPlayerCastle();
void printEnemyCastle();
void printEnemySoldiers(ENEMY enemy);

#endif









