#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, T;

vector<vector <int>> circles;
queue<pair<int, int>> q;

int circle_location[51];

int trance[50][3];

int num_ele = 0;
int sum_ele = 0;

void rotate_circle(int x, int d, int k) {
	if (d != 1) {
		k = -k;
	}
	for (int i = x; i <= N; i += x) {
		circle_location[i] += k;

		// 음수인경우
		if (circle_location[i] < 0) {
			circle_location[i] += M;
		}
		// M보다 커진 경우
		else if (circle_location[i] >= M) {
			circle_location[i] -= M;
		}
	}

}
bool check_injub(int board, int element) {

	bool is_injub = false;

	int cur_value = circles[board][element];

	if(cur_value == -100){
		return false;
	}
	q.push(make_pair(board, element));
	bool first_ele = true;


	while (!q.empty()) {
		int left_element, right_element, out_element, in_element;

		int new_board = q.front().first;
		int new_element = q.front().second;

		if (circles[new_board][new_element] == -100) {
			q.pop();
			continue;
		}

		// left
		if (new_element == 0) {
			left_element = M - 1;
		}
		else {
			left_element = new_element - 1;
		}
		if (cur_value == circles[new_board][left_element]) {
			q.push(make_pair(new_board, left_element));
		}

		// right
		if (new_element == M - 1) {
			right_element = 0;
		}
		else {
			right_element = new_element + 1;
		}
		if (cur_value == circles[new_board][right_element]) {
			q.push(make_pair(new_board, right_element));
		}

		// out
		if (new_board != N) {
			 out_element = new_element + circle_location[new_board + 1] - circle_location[new_board];

			 if (out_element < 0) {
				 out_element += M;
			 }
			 else if (out_element >= M) {
				 out_element -= M;
			 }

			 if (cur_value == circles[new_board + 1][out_element]) {
				 q.push(make_pair(new_board + 1, out_element));
			 }
		} 

		// in
		if (new_board != 1) {
			in_element = new_element + circle_location[new_board - 1] - circle_location[new_board];

			if (in_element < 0) {
				in_element += M;
			}
			else if (in_element >= M) {
				in_element -= M;
			}

			if (cur_value == circles[new_board - 1][in_element]) {
				q.push(make_pair(new_board - 1, in_element));
			}
		}
		q.pop();
		// result
		if (first_ele == false || (first_ele && !q.empty())) {
			sum_ele -= cur_value;
			num_ele--;
			circles[new_board][new_element] = -100;
			first_ele = false;
			is_injub = true;
		}
	}
	
	return is_injub;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;

	circles.resize(N + 1);

	num_ele = N * M;

	for (int i = 1; i < N + 1; i++) {
		circle_location[i] = 0;
		circles[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> circles[i][j];
			sum_ele += circles[i][j];
		}
	}


	// 첫시도 -> 모든거 돌면서 같은거 제거
	bool is_injub = false;
	//float avg;

	for (int i = 0; i < T; i++) {
		cin >> trance[i][0] >> trance[i][1] >> trance[i][2];
		rotate_circle(trance[i][0], trance[i][1], trance[i][2]);
		is_injub = false;

		for (int j = 1; j < N + 1; j ++) {
			for (int k = 0; k < M; k++) {
				if (circles[j][k] != -100) {
					if (check_injub(j, k)) {
						is_injub = true;
					}
				}
				
			}
			
		}
		if (is_injub == false) {

			if (num_ele != 0) {
				//avg = (float)sum_ele / (float)num_ele;
				int cur_sum = sum_ele;
				for (int j = 1; j < N + 1; j++) {
					for (int k = 0; k < M; k++) {
						if (circles[j][k] != -100) {
							if (circles[j][k] * num_ele > cur_sum) {
								circles[j][k]--;
								sum_ele--;
							}
							else if (circles[j][k] * num_ele < cur_sum) {
								circles[j][k]++;
								sum_ele++;
							}
						}
						
					}
				}
			}

		}
	}



	cout << sum_ele;




}