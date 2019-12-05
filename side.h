#include "pcolor.h"


#define Elmt(S,i,j)	(S).TabSide[i][j]
#define Left(S)		(S).Left
#define Right(S)	(S).Right
#define Up(S)		(S).Up
#define Down(S)		(S).Down

typedef struct {
	int TabSide[2][2];
	int Left[2], Right[2], Up[2], Down[2];
} SIDE;

/*
1 : White
2 : Yellow
3 : Blue
4 : Red
5 : Magenta
6 : Green
*/

void DefineLRUD(SIDE *S);

void InitSide(SIDE *S, int C);

void PrintSide(SIDE S);

bool IsSameSide(SIDE S1, SIDE S2);

void Move(int* In, int* Out);