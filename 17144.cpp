#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C, T;

int map[52][52];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

//queue <pair<int, pair<int, int>>> dust;
vector <pair<int, pair<int, int>>> dust_list;
//vector <pair<int, int>> dust_list_upgroup;
//vector <pair<int, int>> dust_list_downgroup;


int u_clear_x;
int d_clear_x;

void spread() {
	int dl_size = dust_list.size();
	/*int dlu_size = dust_list_upgroup.size();
	int dld_size = dust_list_downgroup.size();*/

	int loc_x;
	int loc_y;
	int num_dir;
	int amount, spread_amount;

	for (int i = 0; i < dl_size; i++) {
		loc_x = dust_list[i].second.first;
		loc_y = dust_list[i].second.second;
		//map[loc_x][loc_y]
		num_dir = 0;
		amount = dust_list[i].first;
		spread_amount = amount / 5;
		for (int d = 0; d < 4; d++) {
			if (0 < loc_x + dx[d] && loc_x + dx[d] <= R && 0 < loc_y + dy[d] && loc_y + dy[d] <= C) {
				if (map[loc_x + dx[d]][loc_y + dy[d]] >= 0) {
					map[loc_x + dx[d]][loc_y + dy[d]] += spread_amount;
					num_dir++;
				}
			}
		}
		map[loc_x][loc_y] -= num_dir * spread_amount;
	}

	// upper circle

	u_clear_x;
	// 1
	map[u_clear_x - 1][1] = 0;
	for (int i = u_clear_x - 2; i >= 1; i--) {
		map[i + 1][1] = map[i][1];
		//map[i][1] = 0;
	}
	// 2
	for (int j = 1; j < C; j++) {
		map[1][j] = map[1][j + 1];
	}
	// 3
	for (int i = 0; i <= u_clear_x; i++) {
		map[i][C] = map[i + 1][C];
		//map[i][1] = 0;
	}
	// 4
	for (int j = C; j > 1; j--) {
		map[u_clear_x][j] = map[u_clear_x][j - 1];
	}
	map[u_clear_x][2] = 0;


	//down circle
	d_clear_x;
	// 1
	map[d_clear_x + 1][1] = 0;
	for (int i = d_clear_x + 2; i <= R; i++) {
		map[i - 1][1] = map[i][1];
		//map[i][1] = 0;
	}
	// 2
	for (int j = 1; j < C; j++) {
		map[R][j] = map[R][j + 1];
	}
	// 3
	for (int i = R; i > d_clear_x; i--) {
		map[i][C] = map[i - 1][C];
		//map[i][1] = 0;
	}
	// 4
	for (int j = C; j > 1; j--) {
		map[d_clear_x][j] = map[d_clear_x][j - 1];
	}
	map[d_clear_x][2] = 0;

	dust_list.clear();

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] > 0) {
				dust_list.push_back(make_pair(map[i][j], make_pair(i, j)));
			}
		}
	}



}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	bool is_first_clear = true;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> map[i][j];

			if (map[i][j] == -1 && is_first_clear) {
				if (is_first_clear) {
					u_clear_x = i;
					d_clear_x = i + 1;
					is_first_clear = false;
				}
			}
			else if (map[i][j] > 0) {
				dust_list.push_back(make_pair(map[i][j], make_pair(i, j)));
				/*if (i == u_clear_x) {
					dust_list_upgroup.push_back(make_pair(i, j));
				}
				else if (i == d_clear_x) {
					dust_list_downgroup.push_back(make_pair(i, j));
				}
				else {
					dust_list.push_back(make_pair(i, j));
				}*/
				
			}

		}
	}

	for (int t = 0; t < T; t++) {
		// È®»ê
		spread();
	}

	int total_dust = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] > 0) {
				total_dust += map[i][j];
			}
		}
	}

	cout << total_dust;



}