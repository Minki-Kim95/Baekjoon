#include <iostream>

using namespace std;

int N, M, H;
struct Ladder {
	bool is_change = false;
	Ladder * nextLadder = NULL;
	Ladder * changeLadder = NULL;
	int R_number = 0;
};
Ladder ladders[11][31];  // N, H 

void print_cur() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= H; j++) {
			if (ladders[i][j].is_change) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << endl;
	}
}

bool check_result() {
	Ladder* curLadder;
	
	for (int i = 1; i <= N; i++) {
		curLadder = &ladders[i][1];
		for (int t = 0; t < H-1; t++) {
			if (curLadder->is_change) {
				curLadder = curLadder->changeLadder;
			}
			curLadder = curLadder->nextLadder;
		}
		if (curLadder->is_change) {
			curLadder = curLadder->changeLadder;
		}
		if (i != curLadder->R_number) {
			return false;
		}
	}
	return true;
}

bool dfs(int pre_inde, int num_line, int deep) {
	bool is_end = false;

	if (num_line == deep) {
		return check_result();
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (pre_inde < H*(i - 1) + j && ladders[i][j].is_change == false && ladders[i+1][j].is_change == false) {
				ladders[i][j].is_change = true;
				ladders[i][j].changeLadder = &ladders[i+1][j];
				ladders[i + 1][j].is_change = true;
				ladders[i + 1][j].changeLadder = &ladders[i][j];
				if (dfs(H*(i - 1) + j, num_line, deep + 1)) {
					return true;
				}
				ladders[i][j].is_change = false;
				ladders[i + 1][j].is_change = false;
				
			}
		}
	}
	return false;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < H; j++) {
			ladders[i][j].nextLadder = &ladders[i][j+1];
		}
		ladders[i][H].R_number = i;
	}
	int a, b; //1 ¡Â a ¡Â H, 1 ¡Â b ¡Â N-1
	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		ladders[b][a].is_change = true;
		ladders[b][a].changeLadder = &ladders[b + 1][a];
		ladders[b+1][a].is_change = true;
		ladders[b + 1][a].changeLadder = &ladders[b][a];
	}
	if (check_result()) {
		cout << 0;
		return 0;
	}
	for (int add_num_line = 1; add_num_line <= 3; add_num_line++) {
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= H; j++) {
				if (ladders[i][j].is_change == false && ladders[i+1][j].is_change == false) {
					ladders[i][j].is_change = true;
					ladders[i][j].changeLadder = &ladders[i + 1][j];
					ladders[i+1][j].is_change = true;
					ladders[i + 1][j].changeLadder = &ladders[i][j];
					if (dfs(H*(i - 1) + j, add_num_line, 1)) {
						cout << add_num_line;
						return 0;
					}
					ladders[i][j].is_change = false;
					ladders[i + 1][j].is_change = false;
				}
			}
		}
		

		
	}

	cout << -1;
	
}