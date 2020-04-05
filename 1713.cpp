#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, input_num;

vector<pair<int, int>> pictures;
int recommand[101];

bool cmp(const pair<int, int>&a, const pair<int, int>&b) {

	return a.first < b.first;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> N >> M;

	pictures.resize(N);
	
	for (int i = 0; i < M; i++) {
		cin >> input_num;
		recommand[input_num]++;

		bool is_replace = true;

		for (int j = 0; j < N; j++) {

			if (pictures[j].first == 0) {
				pictures[j].first = input_num;
				pictures[j].second = i;
				is_replace = false;
				break;

			}
			else if (pictures[j].first == input_num) {
				is_replace = false;
				break;
			}

		}

		if (is_replace) {

			int loc_replace = 0;
			for (int j = 1; j < N; j++) {
				if (recommand[pictures[j].first] == recommand[pictures[loc_replace].first]) {
					if (pictures[j].second < pictures[loc_replace].second) {
						loc_replace = j;
					}
				}
				else if (recommand[pictures[j].first] < recommand[pictures[loc_replace].first]) {
					loc_replace = j;
				}
			}

			recommand[pictures[loc_replace].first] = 0;
			pictures[loc_replace].first = input_num;
			pictures[loc_replace].second = i;
		}


	}

	sort(pictures.begin(), pictures.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << pictures[i].first << ' ';
	}
		

}