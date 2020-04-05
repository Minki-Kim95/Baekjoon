#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N, M, chicken_size, house_size;

int map[50][50];

vector<pair<int, int>> house;
vector<pair<int, int >> chicken;

vector<pair<int, int>> selected_chic;

bool is_chic[13];

int result = 10000;

void dfs(int start, int deep) {

	if (deep == M) {
		int min_distance = 0;
		int min_dis_house;
		for (int i = 0; i < house_size; i++) {
			min_dis_house = 100;
			for (int j = 0; j < M; j++) {
				int dist = abs(house[i].first - selected_chic[j].first) + abs(house[i].second - selected_chic[j].second);
				if (dist < min_dis_house) {
					min_dis_house = dist;
				}
			}
			min_distance += min_dis_house;
		}

		if (min_distance < result) {
			result = min_distance;
		}

	}
	

	for (int i = start + 1; i < chicken_size; i++) {
		is_chic[i] = true;
		selected_chic.push_back(chicken[i]);
		dfs(i, deep + 1);
		is_chic[i] = false;
		selected_chic.pop_back();
	}



}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> map[i][j];

			if (map[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}*/

	/*cout << house.size();
	cout << chicken.size();
*/

	chicken_size = chicken.size();
	house_size = house.size();

	for (int i = 0; i < chicken_size - M + 1; i++) {
		is_chic[i] = true;
		selected_chic.push_back(chicken[i]);
		dfs(i, 1);
		is_chic[i] = false;
		selected_chic.pop_back();
	}
	
	cout << result;

}