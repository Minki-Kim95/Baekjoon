#include <iostream>
#include <cstring>

using namespace std;

char F[3][3];
char L[3][3];
char R[3][3];
char B[3][3];
char U[3][3];
char D[3][3];

int n;

void initQube() {
	
	memset(F, 'r', sizeof(F));
	memset(L, 'g', sizeof(L));
	memset(R, 'b', sizeof(R));
	memset(B, 'o', sizeof(B));
	memset(U, 'w', sizeof(U));
	memset(D, 'y', sizeof(D));
}
void trans_pose(char face, char dir) {
	int temp[3][3];
	// F
	if (face == 'F') {

		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = F[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = F[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				F[i][j] = temp[i][j];
			}
		}

	}
	else if (face == 'L') {
		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = L[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = L[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				L[i][j] = temp[i][j];
			}
		}

	}
	else if (face == 'R') {

		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = R[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = R[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				R[i][j] = temp[i][j];
			}
		}


	}
	else if (face == 'B') {
		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = B[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = B[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				B[i][j] = temp[i][j];
			}
		}
	}
	else if (face == 'U') {
		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = U[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = U[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				U[i][j] = temp[i][j];
			}
		}
	}
	else if (face == 'D') {
		if (dir == '+') {
			// 
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[j][2 - i] = D[i][j];
				}
			}

		}
		else {
			//
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					temp[2 - j][i] = D[i][j];
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				D[i][j] = temp[i][j];
			}
		}
	}

}

void qube_spin(char face, char dir) {
	char temp[3];
	// F
	trans_pose(face, dir);

	if (face == 'F') {
		
		if (dir == '+') {
			// U r2 + /  R c0 + /D r0 - / L c2 -
			// R temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[i][0];
			}
			// U -> R
			for (int i = 0; i < 3; i++) {
				R[i][0] = U[2][i];
			}
			// L -> U
			for (int i = 0; i < 3; i++) {
				U[2][i] = L[2 - i][2];
			}
			// D -> L
			for (int i = 0; i < 3; i++) {
				L[2 - i][2] = D[0][2 - i];
			}
			// R(temp)-> D
			for (int i = 0; i < 3; i++) {
				D[0][2 - i] = temp[i];
			}

		}
		else {
			// U r2 + /  R c0 + /D r0 - / L c2 -

			// R temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[i][0];
			}
			// D -> R
			for (int i = 0; i < 3; i++) {
				R[i][0] = D[0][2 - i];
			}
			// L -> D
			for (int i = 0; i < 3; i++) {
				D[0][2 - i] = L[2 - i][2];
			}
			// U -> L
			for (int i = 0; i < 3; i++) {
				L[2 - i][2] = U[2][i];
			}
			// R(temp)-> U
			for (int i = 0; i < 3; i++) {
				U[2][i] = temp[i];
			}
		}

	}
	else if (face == 'L') {
		// U c0 +/ F c0 +/ D c0 +/ B c2 -
		if (dir == '+') {
			// F -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = F[i][0];
			}
			// U -> F
			for (int i = 0; i < 3; i++) {
				F[i][0] = U[i][0];
			}
			// B -> U
			for (int i = 0; i < 3; i++) {
				U[i][0] = B[2 - i][2];
			}
			// D -> B
			for (int i = 0; i < 3; i++) {
				B[2 - i][2] = D[i][0];
			}
			// F(temp) -> D
			for (int i = 0; i < 3; i++) {
				D[i][0] = temp[i];
			}
		}
		else {
			// U c0 +/ F c0 +/ D c0 +/ B c2 -

			// F -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = F[i][0];
			}
			// D -> F
			for (int i = 0; i < 3; i++) {
				F[i][0] = D[i][0];
			}
			// B -> D
			for (int i = 0; i < 3; i++) {
				D[i][0] = B[2 - i][2];
			}
			// U -> B
			for (int i = 0; i < 3; i++) {
				B[2 - i][2] = U[i][0];
			}
			// F(temp) -> U
			for (int i = 0; i < 3; i++) {
				U[i][0] = temp[i];
			}
		}

	}
	else if (face == 'R') {
		
		if (dir == '+') {
			// U c2 -/ B c0 +/ D c2 -/ F c2 -

			// B -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = B[i][0];
			}
			// U -> B
			for (int i = 0; i < 3; i++) {
				B[i][0] = U[2 - i][2];
			}
			// F -> U
			for (int i = 0; i < 3; i++) {
				U[2 - i][2] = F[2 - i][2];
			}
			// D -> F
			for (int i = 0; i < 3; i++) {
				F[2 - i][2] = D[2 -i][2];
			}
			// B(temp) -> D
			for (int i = 0; i < 3; i++) {
				D[2 - i][2] = temp[i];
			}

		}
		else {
			// U c2 -/ B c0 +/ D c2 -/ F c2 -

			// B -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = B[i][0];
			}
			// D -> B
			for (int i = 0; i < 3; i++) {
				B[i][0] = D[2 - i][2];
			}
			// F -> D
			for (int i = 0; i < 3; i++) {
				D[2 - i][2] = F[2 - i][2];
			}
			// U -> F
			for (int i = 0; i < 3; i++) {
				F[2 - i][2] = U[2 - i][2];
			}
			// B(temp) -> U
			for (int i = 0; i < 3; i++) {
				U[2 - i][2] = temp[i];
			}

		}

		




	}
	else if (face == 'B') {
		
		if (dir == '+') {
			// U r0 -/ L c0 + / D r2 + / R c2 -

			// L -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = L[i][0];
			}
			// U -> L
			for (int i = 0; i < 3; i++) {
				L[i][0] = U[0][2 - i];
			}
			// R -> U
			for (int i = 0; i < 3; i++) {
				U[0][2 - i] = R[2 - i][2];
			}
			// D -> R
			for (int i = 0; i < 3; i++) {
				R[2 - i][2] = D[2][i];
			}
			// L(temp) -> D
			for (int i = 0; i < 3; i++) {
				D[2][i] = temp[i];
			}

		}
		else {
			// U r0 -/ L c0 + / D r2 + / R c2 -

			// L -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = L[i][0];
			}
			// D -> L
			for (int i = 0; i < 3; i++) {
				L[i][0] = D[2][i];
			}
			// R -> D
			for (int i = 0; i < 3; i++) {
				D[2][i] = R[2 - i][2];
			}
			// U -> R
			for (int i = 0; i < 3; i++) {
				R[2 - i][2] = U[0][2 - i];
			}
			// L(temp) -> U
			for (int i = 0; i < 3; i++) {
				U[0][2 - i] = temp[i];
			}
		}


	}
	else if (face == 'U') {
		
		if (dir == '+') {
			// B r0 - / R r0 - / F r0 - / L r0 - 

			// R -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[0][i];
			}
			// B -> R
			for (int i = 0; i < 3; i++) {
				R[0][2-i] = B[0][2 - i];
			}
			// L -> B
			for (int i = 0; i < 3; i++) {
				B[0][2 - i] = L[0][2 - i];
			}
			// F -> L
			for (int i = 0; i < 3; i++) {
				L[0][2 - i] = F[0][2-i];
			}
			// R(temp) -> F
			for (int i = 0; i < 3; i++) {
				F[0][2 - i] = temp[2 - i];
			}

		}
		else {
			// B r0 - / R r0 - / F r0 - / L r0 - 

			// R -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[0][i];
			}
			// F -> R
			for (int i = 0; i < 3; i++) {
				R[0][2 - i] = F[0][2 - i];
			}
			// L -> F
			for (int i = 0; i < 3; i++) {
				F[0][2 - i] = L[0][2 - i];
			}
			// B -> L
			for (int i = 0; i < 3; i++) {
				L[0][2 - i] = B[0][2 - i];
			}
			// R(temp) -> B
			for (int i = 0; i < 3; i++) {
				B[0][2 - i] = temp[2 - i];
			}

		}


	}
	else if (face == 'D') {
		

		if (dir == '+') {
			// F r2 + / R  r2 + / B r2 + / L r2 +

			// R -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[2][i];
			}
			// F -> R
			for (int i = 0; i < 3; i++) {
				R[2][i] = F[2][i];
			}
			// L -> F
			for (int i = 0; i < 3; i++) {
				F[2][i] = L[2][i];
			}
			// B -> L
			for (int i = 0; i < 3; i++) {
				L[2][i] = B[2][i];
			}
			// R(temp) -> B
			for (int i = 0; i < 3; i++) {
				B[2][i] = temp[i];
			}

		}
		else {
			// F r2 + / R  r2 + / B r2 + / L r2 +

			// R -> temp
			for (int i = 0; i < 3; i++) {
				temp[i] = R[2][i];
			}
			// B -> R
			for (int i = 0; i < 3; i++) {
				R[2][i] = B[2][i];
			}
			// L -> B
			for (int i = 0; i < 3; i++) {
				B[2][i] = L[2][i];
			}
			// F -> L
			for (int i = 0; i < 3; i++) {
				L[2][i] = F[2][i];
			}
			// R(temp) -> F
			for (int i = 0; i < 3; i++) {
				F[2][i] = temp[i];
			}

		}


	}
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num_spin;
	char face, dir;
	cin >> n;

	for (int tri = 0; tri < n; tri++) {
		initQube();
		cin >> num_spin;
		for (int s = 0; s < num_spin; s++) {
			cin >> face >> dir;
			qube_spin(face, dir);
			
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << U[i][j];
			}
			cout << '\n';
		}
		
	}
}