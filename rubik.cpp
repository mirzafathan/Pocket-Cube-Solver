#include <bits/stdc++.h>
#include "rubik.h"
using namespace std;

RUBIK SolvedState;
RUBIK Problem;
vector<string> algo;
int count = 0;

void InitRubik(RUBIK *Rb) {
	InitSide(&TOP(*Rb), 2);
	InitSide(&DOWN(*Rb), 1);
	InitSide(&RIGHT(*Rb), 3);
	InitSide(&LEFT(*Rb), 6);
	InitSide(&FRONT(*Rb), 4);
	InitSide(&BACK(*Rb), 5);
}

void PrintRubik(RUBIK Rb) {
	cout << "Top Side:" << endl;
	PrintSide(TOP(Rb));
	cout << "Left Side:" << endl;
	PrintSide(LEFT(Rb));
	cout << "Right Side:" << endl;	
	PrintSide(RIGHT(Rb));
	cout << "Front Side:" << endl;
	PrintSide(FRONT(Rb));
	cout << "Back Side:" << endl;
	PrintSide(BACK(Rb));
	cout << "Down Side:" << endl;
	PrintSide(DOWN(Rb));
}

void R(RUBIK *Rb) {
	int temp[2] = {Elmt(TOP(*Rb),0,1), Elmt(TOP(*Rb),1,1)}; // top
	Elmt(TOP(*Rb),0,1) = Elmt(FRONT(*Rb),0,1);
	Elmt(TOP(*Rb),1,1) = Elmt(FRONT(*Rb),1,1);
	Elmt(FRONT(*Rb),0,1) = Elmt(DOWN(*Rb),0,1);
	Elmt(FRONT(*Rb),1,1) = Elmt(DOWN(*Rb),1,1);
 	Elmt(DOWN(*Rb),0,1) = Elmt(BACK(*Rb),0,1);
	Elmt(DOWN(*Rb),1,1) = Elmt(BACK(*Rb),1,1);
	Elmt(BACK(*Rb),0,1) = temp[0];
	Elmt(BACK(*Rb),1,1) = temp[1];
	DefineLRUD(&TOP(*Rb));
	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&DOWN(*Rb));
	DefineLRUD(&BACK(*Rb));
	
	int temp2 = Elmt(RIGHT(*Rb),0,0);
	Elmt(RIGHT(*Rb),0,0) = Elmt(RIGHT(*Rb),1,0);
	Elmt(RIGHT(*Rb),1,0) = Elmt(RIGHT(*Rb),1,1);
	Elmt(RIGHT(*Rb),1,1) = Elmt(RIGHT(*Rb),0,1);
	Elmt(RIGHT(*Rb),0,1) = temp2;
	DefineLRUD(&RIGHT(*Rb));
}

void r(RUBIK *Rb) {
	/* The R' Algorithm */
	R(Rb);
	R(Rb);
	R(Rb);
}

void R2(RUBIK *Rb) {
	R(Rb);
	R(Rb);
}

void l(RUBIK *Rb) {
	/*The L' Algorithm */
	int temp[2] = {Elmt(TOP(*Rb),0,0), Elmt(TOP(*Rb),1,0)}; // top
	Elmt(TOP(*Rb),0,0) = Elmt(FRONT(*Rb),0,0);
	Elmt(TOP(*Rb),1,0) = Elmt(FRONT(*Rb),1,0);
	Elmt(FRONT(*Rb),0,0) = Elmt(DOWN(*Rb),0,0);
	Elmt(FRONT(*Rb),1,0) = Elmt(DOWN(*Rb),1,0);
 	Elmt(DOWN(*Rb),0,0) = Elmt(BACK(*Rb),0,0);
	Elmt(DOWN(*Rb),1,0) = Elmt(BACK(*Rb),1,0);
	Elmt(BACK(*Rb),0,0) = temp[0];
	Elmt(BACK(*Rb),1,0) = temp[1];
	DefineLRUD(&TOP(*Rb));
	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&DOWN(*Rb));
	DefineLRUD(&BACK(*Rb));
	
	int temp2 = Elmt(LEFT(*Rb),0,0);
	Elmt(LEFT(*Rb),0,0) = Elmt(LEFT(*Rb),0,1);
	Elmt(LEFT(*Rb),0,1) = Elmt(LEFT(*Rb),1,1);
	Elmt(LEFT(*Rb),1,1) = Elmt(LEFT(*Rb),1,0);
	Elmt(LEFT(*Rb),1,0) = temp2;
	DefineLRUD(&LEFT(*Rb));	
}

void L(RUBIK *Rb) {
	l(Rb);
	l(Rb);
	l(Rb);
}

void L2(RUBIK *Rb) {
	l(Rb);
	l(Rb);
}

void U(RUBIK *Rb) {
	int temp[2] = {Elmt(FRONT(*Rb),0,0), Elmt(FRONT(*Rb),0,1)};
	Elmt(FRONT(*Rb),0,0) = Elmt(RIGHT(*Rb),0,0);
	Elmt(FRONT(*Rb),0,1) = Elmt(RIGHT(*Rb),0,1);
	Elmt(RIGHT(*Rb),0,0) = Elmt(BACK(*Rb),0,0);
	Elmt(RIGHT(*Rb),0,1) = Elmt(BACK(*Rb),0,1);
	Elmt(BACK(*Rb),0,0) = Elmt(LEFT(*Rb),0,0);
	Elmt(BACK(*Rb),0,1) = Elmt(LEFT(*Rb),0,1);
	Elmt(LEFT(*Rb),0,0) = temp[0];
	Elmt(LEFT(*Rb),0,1) = temp[1];
	DefineLRUD(&RIGHT(*Rb));
	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&LEFT(*Rb));
	DefineLRUD(&BACK(*Rb));

	
	
	
	int temp2 = Elmt(TOP(*Rb),0,0);
	Elmt(TOP(*Rb),0,0) = Elmt(TOP(*Rb),1,0);
	Elmt(TOP(*Rb),1,0) = Elmt(TOP(*Rb),1,1);
	Elmt(TOP(*Rb),1,1) = Elmt(TOP(*Rb),0,1);
	Elmt(TOP(*Rb),0,1) = temp2;
	DefineLRUD(&TOP(*Rb));
}

void u(RUBIK *Rb) {
	U(Rb); U(Rb); U(Rb);
}

void U2(RUBIK *Rb) {
	U(Rb); U(Rb);
}

void d(RUBIK *Rb) {
	// The D'
	int temp[2] = {Elmt(FRONT(*Rb),1,0), Elmt(FRONT(*Rb),1,1)};
	Elmt(FRONT(*Rb),1,0) = Elmt(RIGHT(*Rb),1,0);
	Elmt(FRONT(*Rb),1,1) = Elmt(RIGHT(*Rb),1,1);
	Elmt(RIGHT(*Rb),1,0) = Elmt(BACK(*Rb),1,0);
	Elmt(RIGHT(*Rb),1,1) = Elmt(BACK(*Rb),1,1);
	Elmt(BACK(*Rb),1,0) = Elmt(LEFT(*Rb),1,0);
	Elmt(BACK(*Rb),1,1) = Elmt(LEFT(*Rb),1,1);
	Elmt(LEFT(*Rb),1,0) = temp[0];
	Elmt(LEFT(*Rb),1,1) = temp[1];
	DefineLRUD(&RIGHT(*Rb));
	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&LEFT(*Rb));
	DefineLRUD(&BACK(*Rb));

	int temp2 = Elmt(DOWN(*Rb),0,0);
	Elmt(DOWN(*Rb),0,0) = Elmt(DOWN(*Rb),0,1);
	Elmt(DOWN(*Rb),0,1) = Elmt(DOWN(*Rb),1,1);
	Elmt(DOWN(*Rb),1,1) = Elmt(DOWN(*Rb),1,0);
	Elmt(DOWN(*Rb),1,0) = temp2;
	DefineLRUD(&DOWN(*Rb));

}

void D(RUBIK *Rb) {
	d(Rb); d(Rb); d(Rb);
}

void D2(RUBIK *Rb) {
	d(Rb); d(Rb);
}

void F(RUBIK *Rb) {
	int temp[2] = {Elmt(TOP(*Rb),1,0), Elmt(TOP(*Rb),1,1)};
	Elmt(TOP(*Rb),1,0) = Elmt(LEFT(*Rb),1,1);
	Elmt(TOP(*Rb),1,1) = Elmt(LEFT(*Rb),0,1);
	Elmt(LEFT(*Rb),0,1) = Elmt(DOWN(*Rb),0,0);
	Elmt(LEFT(*Rb),1,1) = Elmt(DOWN(*Rb),0,1);
	Elmt(DOWN(*Rb),0,0) = Elmt(RIGHT(*Rb),1,0);
	Elmt(DOWN(*Rb),0,1) = Elmt(RIGHT(*Rb),0,0);
	Elmt(RIGHT(*Rb),1,0) = temp[1];
	Elmt(RIGHT(*Rb),0,0) = temp[0];

	int temp2 = Elmt(FRONT(*Rb),0,0);
	Elmt(FRONT(*Rb),0,0) = Elmt(FRONT(*Rb),1,0);
	Elmt(FRONT(*Rb),1,0) = Elmt(FRONT(*Rb),1,1);
	Elmt(FRONT(*Rb),1,1) = Elmt(FRONT(*Rb),0,1);
	Elmt(FRONT(*Rb),0,1) = temp2;
	
	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&TOP(*Rb));
	DefineLRUD(&LEFT(*Rb));
	DefineLRUD(&DOWN(*Rb));
	DefineLRUD(&RIGHT(*Rb));
}

void f(RUBIK *Rb) {
	F(Rb); F(Rb); F(Rb);
}

void F2(RUBIK *Rb) {
	F(Rb); F(Rb);
}

void b(RUBIK *Rb) {
	int temp[2] = {Elmt(TOP(*Rb),0,0), Elmt(TOP(*Rb),0,1)};
	Elmt(TOP(*Rb),0,0) = Elmt(LEFT(*Rb),1,0);
	Elmt(TOP(*Rb),0,1) = Elmt(LEFT(*Rb),0,0);
	Elmt(LEFT(*Rb),0,0) = Elmt(DOWN(*Rb),1,0);
	Elmt(LEFT(*Rb),1,0) = Elmt(DOWN(*Rb),1,1);
	Elmt(DOWN(*Rb),1,0) = Elmt(RIGHT(*Rb),1,1);
	Elmt(DOWN(*Rb),1,1) = Elmt(RIGHT(*Rb),0,1);
	Elmt(RIGHT(*Rb),1,1) = temp[1];
	Elmt(RIGHT(*Rb),0,1) = temp[0];	

	int temp2 = Elmt(BACK(*Rb),0,0);
	Elmt(BACK(*Rb),0,0) = Elmt(BACK(*Rb),0,1);
	Elmt(BACK(*Rb),0,1) = Elmt(BACK(*Rb),1,1);
	Elmt(BACK(*Rb),1,1) = Elmt(BACK(*Rb),1,0);
	Elmt(BACK(*Rb),1,0) = temp2;
	
	DefineLRUD(&BACK(*Rb));
	DefineLRUD(&TOP(*Rb));
	DefineLRUD(&LEFT(*Rb));
	DefineLRUD(&DOWN(*Rb));
	DefineLRUD(&RIGHT(*Rb));
}

void B(RUBIK *Rb) {
	b(Rb); b(Rb); b(Rb);
}

void B2(RUBIK *Rb) {
	b(Rb); b(Rb);
}

bool IsSameState(RUBIK Rb1, RUBIK Rb2) {
	return 	IsSameSide(TOP(Rb1),TOP(Rb2)) &&
			IsSameSide(DOWN(Rb1),DOWN(Rb2)) &&
			IsSameSide(RIGHT(Rb1),RIGHT(Rb2)) &&
			IsSameSide(LEFT(Rb1),LEFT(Rb2)) &&
			IsSameSide(BACK(Rb1),BACK(Rb2)) &&
			IsSameSide(FRONT(Rb1),FRONT(Rb2));
}

void Input(RUBIK *Rb) {
	cout << "Insert Top Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(TOP(*Rb),i,j);
		}
	}

	cout << "Insert Down Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(DOWN(*Rb),i,j);
		}
	}

	cout << "Insert Right Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(RIGHT(*Rb),i,j);
		}
	}

	cout << "Insert Left Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(LEFT(*Rb),i,j);
		}
	}

	cout << "Insert Front Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(FRONT(*Rb),i,j);
		}
	}

	cout << "Insert Back Side:" << endl;
	for(int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			cout << "[" << i+1 << "]" << "[" << j+1 << "] : ";
			cin >> Elmt(BACK(*Rb),i,j);
		}
	}

	DefineLRUD(&FRONT(*Rb));
	DefineLRUD(&BACK(*Rb));
	DefineLRUD(&TOP(*Rb));
	DefineLRUD(&LEFT(*Rb));
	DefineLRUD(&DOWN(*Rb));
	DefineLRUD(&RIGHT(*Rb));
}

vector<string> Solve(vector<string> algo, RUBIK *Finder) {
	
	if !(IsSameState(algo, Finder)) {
		R(Finder);
		Solves
	}
}

int main() {
	RUBIK Rb1, Rb2;
	InitRubik(&Rb1);
	InitRubik(&Rb2);

	Input(&Rb1);

	PrintRubik(Rb1);
	return 0;
}