#include <iostream>
#include <cstring>

using namespace std;

inline int abs(int a) {
	if (a < 0) {
		return -a;
	}
	else {
		return a;
	}
}

int N, L;
int map[100][100];

bool r_check_route(int row) {
	
	int first_height = map[row][0];
	bool is_possible[100];
	memset(is_possible, true, sizeof(is_possible));

	for (int j = 1; j < N; j++) {
		//map[row][j];
		/*if (first_height == map[row][j]) {
			num_same++;
		}
		else*/ 
		if (abs(first_height - map[row][j]) > 1) {
			return false;
		}
		//up
		else if (first_height - map[row][j] == -1) {
			if (j - L < 0) {
				return false;
			}
			for (int b = 1; b <= L; b++) {
				if (map[row][j - b] == first_height && is_possible[j - b]) {
					is_possible[j - b] = false;
				}
				else {
					return false;
				}
			}
			first_height = map[row][j];
		}
		// down
		else if (first_height - map[row][j] == 1 ) {
			if (j + L - 1 >= N) {
				return false;
			}
			for (int b = 0; b < L; b++) {
				if (map[row][j + b] == first_height - 1 && is_possible[j + b]) {
					is_possible[j + b] = false;
				}
				else {
					return false;
				}
			}
			first_height = map[row][j];
		}

	}
	return true;

}

bool c_check_route(int colum) {

	int first_height = map[0][colum];
	bool is_possible[100];
	memset(is_possible, true, sizeof(is_possible));

	for (int i = 1; i < N; i++) {
		//map[row][j];
		/*if (first_height == map[row][j]) {
			num_same++;
		}
		else*/
		if (abs(first_height - map[i][colum]) > 1) {
			return false;
		}
		//up
		else if (first_height - map[i][colum] == -1) {
			if (i - L < 0) {
				return false;
			}
			for (int b = 1; b <= L; b++) {
				if (map[i - b][colum] == first_height && is_possible[i - b]) {
					is_possible[i - b] = false;
				}
				else {
					return false;
				}
			}
			first_height = map[i][colum];
		}
		// down
		else if (first_height - map[i][colum] == 1) {
			if (i + L - 1 >= N) {
				return false;
			}
			for (int b = 0; b < L; b++) {
				if (map[i + b][colum] == first_height - 1 && is_possible[i + b]) {
					is_possible[i + b] = false;
				}
				else {
					return false;
				}
			}
			first_height = map[i][colum];
		}

	}
	return true;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int possible_route = 0;
	for (int i = 0; i < N; i++) {
		if (r_check_route(i)) {
			possible_route++;
		}

	}
	for (int j = 0; j < N; j++) {
		if (c_check_route(j)) {
			possible_route++;
		}
	}

	cout << possible_route;


}