#include <iostream>
#include <vector>

using namespace std;

int N, M;
int map[8][8];

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };
// up, down, left, right

int total_num_zero = 0;
int min_zero_num;

int numcam;
vector <pair<int, pair<int, int> >> camera;

void print_map() {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int check_zero() {
	int total_zero = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				total_zero++;
			}
		}
	}

	return total_zero;
}
vector<pair<int, int>> make_route(int dir, int x, int y) {
//void make_route(int dir, int x, int y) {
	// dir // up, down, left, right
	vector<pair<int, int>> change_list;
	int next_x, next_y;
	next_x = x + dx[dir];
	next_y = y + dy[dir];
	while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
		if (map[next_x][next_y] == 0) {
			map[next_x][next_y] = 9;
			change_list.push_back(make_pair(next_x, next_y));
		}
		else if (map[next_x][next_y] == 6) {
			break;
		}
		next_x += dx[dir];
		next_y += dy[dir];
	}
	return change_list;
}

void simul_cam(int cam_index) {
	int copy_map[8][8];

	if (cam_index == numcam) {
		int loc_min = check_zero();
		if (loc_min < min_zero_num) {
			min_zero_num = loc_min;
		}
		//print_map();
		return;
	}
	int cam_x, cam_y;
	cam_x = camera[cam_index].second.first;
	cam_y = camera[cam_index].second.second;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
	vector <pair<int, int>> change_list[4];
	if (camera[cam_index].first == 1) {	//4
		for (int d = 0; d < 4; d++) {
			change_list[0] = make_route(d, cam_x, cam_y);

			simul_cam(cam_index + 1);

			for(pair<int, int> there: change_list[0]) {
				map[there.first][there.second] = copy_map[there.first][there.second];
			}
			/*next_x = cam_x + dx[d];
			next_y = cam_x + dy[d];
			while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				map[next_x][next_y] = copy_map[next_x][next_y];
				next_x += dx[d];
				next_y += dy[d];
			}*/
			/*for (int i = 0; i < N; i++) {
				map[i][cam_y] = copy_map[i][cam_y];
			}
			for (int j = 0; j < M; j++) {
				map[cam_x][j] = copy_map[cam_x][j];
			}*/

		}
	}
	else if (camera[cam_index].first == 2) { //2
		for (int d = 0; d < 4; d += 2) {
			change_list[0] = make_route(d, cam_x, cam_y);
			change_list[1] = make_route(d+1, cam_x, cam_y);
			
			/*cout << cam_index <<"befor" << endl;
			print_map();*/

			simul_cam(cam_index + 1);

			/*cout << cam_index << "after" << endl;
			print_map();*/

			for (pair<int, int> there : change_list[0]) {
				map[there.first][there.second] = copy_map[there.first][there.second];
			}
			for (pair<int, int> there : change_list[1]) {
				map[there.first][there.second] = copy_map[there.first][there.second];
			}


			/*next_x = cam_x + dx[d];
			next_y = cam_x + dy[d];
			while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				map[next_x][next_y] = copy_map[next_x][next_y];
				next_x += dx[d];
				next_y += dy[d];
			}
			next_x = cam_x + dx[d+1];
			next_y = cam_x + dy[d+1];
			while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				map[next_x][next_y] = copy_map[next_x][next_y];
				next_x += dx[d+1];
				next_y += dy[d+1];
			}*/
		}
	}
	else if (camera[cam_index].first == 3) {
		for (int d = 0; d < 2; d++) {
			for (int n = 2; n < 4; n++) {
				change_list[0] = make_route(d, cam_x, cam_y);
				change_list[1] = make_route(n, cam_x, cam_y);

				simul_cam(cam_index + 1);

				for (pair<int, int> there : change_list[0]) {
					map[there.first][there.second] = copy_map[there.first][there.second];
				}
				for (pair<int, int> there : change_list[1]) {
					map[there.first][there.second] = copy_map[there.first][there.second];
				}
				/*next_x = cam_x + dx[d];
				next_y = cam_x + dy[d];
				while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
					map[next_x][next_y] = copy_map[next_x][next_y];
					next_x += dx[d];
					next_y += dy[d];
				}
				next_x = cam_x + dx[n];
				next_y = cam_x + dy[n];
				while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
					map[next_x][next_y] = copy_map[next_x][next_y];
					next_x += dx[n];
					next_y += dy[n];
				}*/
			}
			
		}
	}
	else if (camera[cam_index].first == 4) { // 4
		for (int d = 0; d < 4; d++) {
			for (int n = 0; n < 4; n++) {
				if (d != n) {
					change_list[n] = make_route(n, cam_x, cam_y);
				}
			}
			simul_cam(cam_index + 1);
			for (int n = 0; n < 4; n++) {
				if (d != n) {
					for (pair<int, int> there : change_list[n]) {
						map[there.first][there.second] = copy_map[there.first][there.second];
					}
					/*next_x = cam_x + dx[n];
					next_y = cam_x + dy[n];
					while (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
						map[next_x][next_y] = copy_map[next_x][next_y];
						next_x += dx[n];
						next_y += dy[n];
					}*/
				}
			}
		}
	}
	else if (camera[cam_index].first == 5) {
		for (int n = 0; n < 4; n++) {
			make_route(n, cam_x, cam_y);
		}
		simul_cam(cam_index + 1);
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
			if (map[i][j] == 0) {
				total_num_zero++;
			}
			else if (map[i][j] == 1) {
				camera.push_back(make_pair(1, make_pair(i, j)));	//4
			}
			else if (map[i][j] == 2) {
				camera.push_back(make_pair(2, make_pair(i, j)));	//2
			}
			else if (map[i][j] == 3) {
				camera.push_back(make_pair(3, make_pair(i, j)));	//4
			}
			else if (map[i][j] == 4) {
				camera.push_back(make_pair(4, make_pair(i, j)));	//4
			}
			else if (map[i][j] == 5) {
				camera.push_back(make_pair(5, make_pair(i, j)));	//1
			}
		}
	}
	min_zero_num = total_num_zero;

	numcam = camera.size();

	simul_cam(0);

	cout << min_zero_num;


}