#include <iostream>

using namespace std;

int chess[15][15];

int num_case = 0;


bool is_possible(int x, int y, int n) {

	//y
	for (int i = 0; i < y; i++) {
		if (chess[x][i] == 1) {
			return false;
		}

	}
	//대각선1 x+y 일정
	for (int i = 0; i < y; i++) {
		if (0 <= x + y - i && x + y - i < n) {
			if (chess[x + y - i][i] == 1) {
				return false;
			}
		}
	}



	//대각선2 x - y 일정
	for (int i = 0; i < y; i++) {
		if (0 <= x - y + i && x - y + i < n) {
			if (chess[x - y + i][i] == 1) {
				return false;
			}
		}
	}

	return true;

}

void N_chess(int loc_x, int loc_y, int n) {


	chess[loc_x][loc_y] = 1;

	/*cout << "loc_x: " << loc_x << " loc_y: " << loc_y << endl;
	for (int k = 0; k < n; k++) {
	for (int j = 0; j < n; j++) {

	cout << chess[k][j] << ' ';

	}
	cout << endl;
	}
	cout << endl;*/


	if (loc_y == n - 1) {


		num_case++;
		chess[loc_x][loc_y] = 0;
		return;
	}


	int count = 0;


	for (int i = 0; i < n; i++) {


		if (is_possible(i, loc_y + 1, n)) {    //겹치는거 있음 넘기고 아니면 킵 고잉
			N_chess(i, loc_y + 1, n);
			chess[i][loc_y + 1] = 0;
		}


	}

}



int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;



	for (int i = 0; i < N; i++) {
		// clean
		for (int k = 0; k < N; k++) {
			for (int j = 0; j < N; j++) {

				chess[k][j] = 0;

			}
		}

		N_chess(i, 0, N);

	}

	cout << num_case;
}