#include <iostream>

using namespace std;

int N, M;
char map[10][10];
int min_trial = 20;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int R_x, R_y;
int B_x, B_y;
int O_x, O_y;

bool move_R(int dir) {
	int next_x = R_x + dx[dir];
	int next_y = R_y + dy[dir];
	while (map[next_x][next_y] == '.') {
		next_x = next_x + dx[dir];
		next_y = next_y + dy[dir];
	}

	if (map[next_x][next_y] == 'O') {
		map[R_x][R_y] = '.';
		return true;
	}
	else {
		next_x = next_x - dx[dir];
		next_y = next_y - dy[dir];

		map[R_x][R_y] = '.';
		map[next_x][next_y] = 'R';

		R_x = next_x, R_y = next_y;
		return false;
	}


}
bool move_B(int dir) {

	int next_x = B_x + dx[dir];
	int next_y = B_y + dy[dir];
	while (map[next_x][next_y] == '.') {
		next_x = next_x + dx[dir];
		next_y = next_y + dy[dir];
	}

	if (map[next_x][next_y] == 'O') {
		map[B_x][B_y] = '.';
		return true;
	}
	else {
		next_x = next_x - dx[dir];
		next_y = next_y - dy[dir];

		map[B_x][B_y] = '.';
		map[next_x][next_y] = 'B';

		B_x = next_x, B_y = next_y;
		return false;
	}

}

pair <bool, bool> move_ball(int dir) {

	pair <bool, bool> is_holl;
	is_holl.first = false;
	is_holl.second = false;

	if (dir == 0) {		//y --
		if (R_y < B_y) {
			if (move_R(dir)) {
				is_holl.first = true;
			}
			if (move_B(dir)) {
				is_holl.second = true;
			}
			
		}
		else {
			if (move_B(dir)) {
				is_holl.second = true;
			}
			if (move_R(dir)) {
				is_holl.first = true;
			}
		}
	}
	else if (dir == 1) {		//y ++
		if (R_y > B_y) {
			if (move_R(dir)) {
				is_holl.first = true;
			}
			if (move_B(dir)) {
				is_holl.second = true;
			}

		}
		else {
			if (move_B(dir)) {
				is_holl.second = true;
			}
			if (move_R(dir)) {
				is_holl.first = true;
			}
		}
	}
	else if (dir == 2) {		//x--
		if (R_x < B_y) {
			if (move_R(dir)) {
				is_holl.first = true;
			}
			if (move_B(dir)) {
				is_holl.second = true;
			}

		}
		else {
			if (move_B(dir)) {
				is_holl.second = true;
			}
			if (move_R(dir)) {
				is_holl.first = true;
			}
		}
	}
	else if (dir == 3) {		//x++
		if (R_x > B_y) {
			if (move_R(dir)) {
				is_holl.first = true;
			}
			if (move_B(dir)) {
				is_holl.second = true;
			}

		}
		else {
			if (move_B(dir)) {
				is_holl.second = true;
			}
			if (move_R(dir)) {
				is_holl.first = true;
			}
		}
	}


	return is_holl;
}

void dfs(int deep) {

	if (deep == 10) {
		return;
	}
	
	
	for (int d = 0; d < 4; d++) {

		int Pre_R_x = R_x, Pre_R_y = R_y;
		int Pre_B_x = B_x, Pre_B_y = B_y;
		if (move_ball(d).first && move_ball(d).second == false) {
			min_trial = min_trial > deep + 1 ? deep + 1 : min_trial;
		}
		else if(move_ball(d).first == false && move_ball(d).second == false) {
			dfs(deep + 1);
		}

		map[R_x][R_y] = '.';
		map[B_x][B_y] = '.';
		map[Pre_R_x][Pre_R_y] = 'R';
		map[Pre_B_x][Pre_B_y] = 'B';

		R_x = Pre_R_x, R_y = Pre_R_y;
		B_x = Pre_B_x, B_y = Pre_B_y;

	}

}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				R_x = i, R_y = j;
			}
			else if (map[i][j] == 'B') {
				B_x = i, B_y = j;
			}
			else if (map[i][j] == 'O') {
				O_x = i, O_y = j;
			}
		}
	}

	dfs(0);

	if (min_trial == 20) {
		cout << -1;
	}
	else {
		cout << min_trial;
	}
	
	
}