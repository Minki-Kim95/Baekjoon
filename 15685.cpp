#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool map[101][101];
int end_x, end_y;

vector<pair<int, int>> local_dot_list;

void transpose(int center_x, int center_y) {

	int local_dot_list_size = local_dot_list.size();
	
	end_x = center_x + center_y - local_dot_list[0].second;
	end_y = center_y - (center_x - local_dot_list[0].first);

	for (int i = 1; i < local_dot_list_size; i++) {
		local_dot_list.push_back(make_pair(center_x + center_y - local_dot_list[i].second, center_y - (center_x - local_dot_list[i].first)));
	}
	local_dot_list.push_back(make_pair(center_x, center_y));
	
}

void create_dragon(int x, int y, int dir, int generation) {
	
	local_dot_list.push_back(make_pair(x, y));

	end_x = x + dx[dir];
	end_y = y + dy[dir];

	for (int g = 0; g < generation; g++) {
		transpose(end_x, end_y);
	}
	local_dot_list.push_back(make_pair(end_x, end_y));



	for (pair<int, int> there : local_dot_list) {
		map[there.second][there.first] = true;
	}
	local_dot_list.clear();
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, y, d, g;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y >> d >> g;
		create_dragon(x, y, d, g);
	}
	int squar_num = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i + 1][j + 1] && map[i][j + 1]) {
				squar_num++;
			}
		}
	}
	cout << squar_num;


}