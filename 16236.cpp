#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;

int baby_size = 2;

int time_cul = 0;
int num_eat_fist = 0;
int map[21][21];

int dx[4] = { 0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int x_baby, y_baby;
int min_dist;
vector < pair<int, pair<int, int>>> fishes_eatable; // size
//vector <pair<int, pair<int, int>>> min_fish_list; // index
int min_index;
int min_x;
int min_y;

int cal_distance(int dest_x, int dest_y) {
	// max 2 * (N - 1)
	queue <pair <int, int>> q;
	// todo: is_visited Æ÷ÇÔ
	bool is_visited[21][21];
	memset(is_visited, false, sizeof(is_visited));
	q.push(make_pair(x_baby, y_baby));
	is_visited[x_baby][y_baby] = true;
	int t = 0;
	int q_size, cur_x, cur_y, next_x, next_y;
	bool bfs_done = false;
	while (!q.empty()) {
		t++;
		q_size = q.size();
		for (int i = 0; i < q_size; i++) {

			cur_x = q.front().first;
			cur_y = q.front().second;

			for (int d = 0; d < 4; d++) {
				next_x = cur_x + dx[d];
				next_y = cur_y + dy[d];
				if (next_x == dest_x && next_y == dest_y) {
					bfs_done = true;
					break;
				}
				if (0 < next_x && next_x <= N && 0 < next_y && next_y <= N) {
					if (map[next_x][next_y] <= baby_size && is_visited[next_x][next_y] == false) {
						q.push(make_pair(next_x, next_y));
						is_visited[next_x][next_y] = true;
					}
				}
			}
			if (bfs_done) {
				break;
			}
			q.pop();
		}
		
		if (bfs_done) {
			break;
		}

	}

	if (bfs_done) {
		return t;
	}
	else {
		return 0;
	}

	

}

//bool cmp(const pair<int, pair<int, int>> a, const pair<int, pair<int, int>> b) {
//
//	if (a.second.first == b.second.first) {
//		return a.second.second < b.second.second;
//	}
//	else {
//		return a.second.first < b.second.first;
//	}
//}

bool check_isfish() {

	int loc_dist;
	int i = 0;
	min_dist = 400;

	
	bool is_noempty = false;

	for (pair<int, pair<int, int>> there : fishes_eatable) {
		if (loc_dist = cal_distance(there.second.first, there.second.second)) {
			if (loc_dist < min_dist) {
				min_dist = loc_dist;
				min_index = i;
				min_x = there.second.first;
				min_y = there.second.second;
				//min_fish_list.push_back(make_pair(i, make_pair(there.second.first, there.second.second)));
				is_noempty = true;
			}
			else if (loc_dist == min_dist) {

				if (there.second.first < min_x || (there.second.first == min_x && there.second.second < min_y)) {
					min_index = i;
					min_x = there.second.first;
					min_y = there.second.second;
				}

				//min_fish_list.push_back(make_pair(i, make_pair(there.second.first, there.second.second)));
			}
		}
		i++;
	}

	if (is_noempty) {
		return true;
	}
	else {
		return false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 2) {
				fishes_eatable.push_back(make_pair(map[i][j], make_pair(i, j)));
			}
			else if (map[i][j] == 9) {
				x_baby = i;
				y_baby = j;
			}
		}
	}

	

	while (check_isfish()) {
		
		
		/*if (min_fish_list.size() > 1) {
			sort(min_fish_list.begin(), min_fish_list.end(), cmp);


		}*/
		//int min_index;
		//int min_x;
		//int min_y;
		time_cul += min_dist;
		fishes_eatable.erase(fishes_eatable.begin() + min_index);
		map[x_baby][y_baby] = 0;
		x_baby = min_x;
		y_baby = min_y;
		num_eat_fist++;
		map[x_baby][y_baby] = 9;
		//////////////////
		/*cout << endl;
		cout << "num_eat_fist: " << num_eat_fist << " min_dist: " << min_dist << " time_cul: " << time_cul << " baby_size: " << baby_size <<endl;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (map[i][j] == 9) {
					cout << "* ";
				}
				else {
					cout << map[i][j] << ' ';
				}
				
			}
			cout << endl;
		}*/
		//////////////////////////
		if (baby_size == num_eat_fist && baby_size < 7) {
			baby_size++;
			num_eat_fist = 0;

			fishes_eatable.clear();

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (map[i][j] > 0 && map[i][j] < baby_size) {
						fishes_eatable.push_back(make_pair(map[i][j], make_pair(i, j)));
					}
				}
			}


		}

	}

	cout << time_cul;



}