#include "side.h"
using namespace std;

typedef struct {
	SIDE TOP;
	SIDE DOWN;
	SIDE RIGHT;
	SIDE LEFT;
	SIDE FRONT;
	SIDE BACK;
} RUBIK;

#define TOP(R) 		(R).TOP
#define DOWN(R) 	(R).DOWN
#define RIGHT(R) 	(R).RIGHT
#define LEFT(R) 	(R).LEFT
#define FRONT(R) 	(R).FRONT
#define BACK(R) 	(R).BACK

void InitRubik(RUBIK *R);
void PrintRubik(RUBIK R);
void R(RUBIK *R);
void r(RUBIK *Rb);
void R2(RUBIK *Rb);
void l(RUBIK *Rb);
void L(RUBIK *Rb);
void L2(RUBIK *Rb);
void U(RUBIK *Rb);
void u(RUBIK *Rb);
void U2(RUBIK *Rb);
void d(RUBIK *Rb);
void D(RUBIK *Rb);
void D2(RUBIK *Rb);
void F(RUBIK *Rb);
void f(RUBIK *Rb);
void F2(RUBIK *Rb);
void b(RUBIK *Rb);
void B(RUBIK *Rb);
void B2(RUBIK *Rb);
bool IsSameState(RUBIK Rb1, RUBIK Rb2);