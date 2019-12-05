#include <bits/stdc++.h>
#include "pcolor.h"
#include "side.h"
using namespace std;

void DefineLRUD(SIDE *S) {
	Left(*S)[0] = Elmt(*S,0,0);
	Left(*S)[1] = Elmt(*S,1,0);
	Right(*S)[0] = Elmt(*S,0,1);
	Right(*S)[1] = Elmt(*S,1,1);
	Up(*S)[0] = Elmt(*S,0,0);
	Up(*S)[1] = Elmt(*S,0,1);
	Down(*S)[0] = Elmt(*S,1,0);
	Down(*S)[1] = Elmt(*S,1,1);
}

void InitSide(SIDE *S, int C) {
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) Elmt(*S,i,j) = C;
	}
	DefineLRUD(S);
}

void PrintSide(SIDE S) {
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			switch(Elmt(S,i,j)) {
				case 1:
					print_white('o');
					break;
				case 2:
					print_yellow('o');
					break;
				case 3:
					print_cyan('o');
					break;
				case 4:
					print_red('o');
					break;
				case 5:
					print_magenta('o');
					break;
				case 6:
					print_green('o');
					break;
				default:
					cout << "ERROR";
			}
			if (j == 1) cout << endl;
			else cout << " ";
		} 
	}
}

void Move(int* In, int* Out) {
	Out[0] = In[0];
	Out[1] = In[1];
}

bool IsSameSide(SIDE S1, SIDE S2) {
	return (Elmt(S1,0,0) == Elmt(S2,0,0)) &&
		   (Elmt(S1,0,1) == Elmt(S2,0,1)) &&
		   (Elmt(S1,1,0) == Elmt(S2,1,0)) &&
		   (Elmt(S1,1,1) == Elmt(S2,1,1));
}