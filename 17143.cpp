#include <iostream>
#include <vector>

using namespace std;

typedef struct {
	bool isAbsent = true;
	int speed;
	int direct;
	int size;
}Shark;


Shark shark[105][105];

vector<pair <int, int> > shark_loc;
int R, C, M;

int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int sum_size = 0;

int change_direct(int pre_dir) {
	if (pre_dir == 1) {
		return 2;
	}
	else if (pre_dir == 2) {
		return 1;
	}
	else if (pre_dir == 3) {
		return 4;
	}
	else {
		return 3;
	}
}

void shark_move(void) {
	Shark temp_shark[105][105];
	vector<pair<int, int>> changelist;
	int temp_shark_index = 0;

	for (pair<int, int> there : shark_loc) {
		int i = there.first;
		int j = there.second;
		if (shark[i][j].isAbsent == false) {
			shark[i][j].isAbsent = true;
			int next_x = i;
			int next_y = j;
			int loc_size = shark[i][j].size;
			int loc_speed = shark[i][j].speed;
			int loc_direct = shark[i][j].direct;

			

			if (dx[loc_direct] == 0) {

				if (loc_speed > 2 * (C - 1)) {
					loc_speed = loc_speed % (2 * (C - 1));
				}

				int loc_next_y = j;
				if (loc_next_y == C && loc_direct == 3) {
					loc_direct = change_direct(loc_direct);
				}
				else if(loc_next_y == 1 && loc_direct == 4) {
					loc_direct = change_direct(loc_direct);
				}
				for (int i = 0; i < loc_speed; i++) {
					loc_next_y += dy[loc_direct];
					if (loc_next_y == C || loc_next_y == 1) {
						loc_direct = change_direct(loc_direct);
					}
				}
				next_y = loc_next_y;

			}
			else {

				if (loc_speed > 2 * (R - 1)) {
					loc_speed = loc_speed % (2 * (R - 1));
				}


				int loc_next_x = i;
				if (loc_next_x == R && loc_direct == 2) {
					loc_direct = change_direct(loc_direct);
				}
				else if (loc_next_x == 1 && loc_direct == 1) {
					loc_direct = change_direct(loc_direct);
				}
				for (int i = 0; i < loc_speed; i++) {
					loc_next_x += dx[loc_direct];
					if (loc_next_x == R || loc_next_x == 1) {
						loc_direct = change_direct(loc_direct);
					}
				}
				next_x = loc_next_x;


			}
			if (temp_shark[next_x][next_y].isAbsent == false) {
				if (loc_size > temp_shark[next_x][next_y].size) {
					temp_shark[next_x][next_y].direct = loc_direct;
					temp_shark[next_x][next_y].size = shark[i][j].size;
					temp_shark[next_x][next_y].speed = shark[i][j].speed;
				}
			}
			else {
				temp_shark[next_x][next_y].isAbsent = false;
				temp_shark[next_x][next_y].direct = loc_direct;
				temp_shark[next_x][next_y].size = shark[i][j].size;
				temp_shark[next_x][next_y].speed = shark[i][j].speed;
				changelist.push_back(make_pair(next_x, next_y));
			}



		}
	}
	shark_loc.clear();

	for (pair<int, int> there : changelist) {
		shark_loc.push_back(there);
		shark[there.first][there.second].isAbsent = false;
		shark[there.first][there.second].direct = temp_shark[there.first][there.second].direct;
		shark[there.first][there.second].size = temp_shark[there.first][there.second].size;
		shark[there.first][there.second].speed = temp_shark[there.first][there.second].speed;

	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, c, s, d, z;

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		cin >> r>> c>> s>> d>> z;
		shark_loc.push_back(make_pair(r, c));
		shark[r][c].isAbsent = false;
		shark[r][c].speed = s;
		shark[r][c].direct = d;
		shark[r][c].size = z;

	}

	for (int j= 1; j <= C; j++) {
		
		// catch
		for (int i = 1; i <= R; i++) {
			if (shark[i][j].isAbsent == false) {
				sum_size += shark[i][j].size;
				shark[i][j].isAbsent = true;
				break;

			}
		}
		// shark move
		shark_move();
	}

	cout << sum_size;




}