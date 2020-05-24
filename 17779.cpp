#include <iostream>

using namespace std;



int N;

int min_ans = 2147483647;
// x_start, y_start, dl, d2; // x_start, y_start // d1: 1번 선거구쪽, d2: 2번 선거구쪽

// d1, d2 ≥ 1
// 1 ≤ x < x+d1+d2 ≤ N
// 1 ≤ y-d1 < y < y+d2 ≤ N

// 1. d1 증가      1 ~ max(N - 1)
// 2. d2 증가      1 ~ max(N - 1 - d1)   
// 3. x값 큰값부터 max(N - d1 - d2)   min(1)
// 4. y값 큰값부터 max(N - d2)        min(1 + d1)

int peoples[21][21];




void check_distance(int dist1, int dist2, int x_start, int y_start) {

	int part_peoples[6];
	for (int i = 1; i < 6; i++) {
		part_peoples[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			// 1번
			if (i < x_start + dist1 && j <= y_start && i + j < x_start + y_start) {
				part_peoples[1] += peoples[i][j];
			}
			// 2번
			else if (i <= x_start + dist2 && j > y_start && i - j < x_start - y_start) {
				part_peoples[2] += peoples[i][j];
			}
			// 3번
			else if (i >= x_start + dist1 && j < y_start - dist1 +dist2 && i - j > x_start - y_start + 2 * dist1) {
				part_peoples[3] += peoples[i][j];
			}
			// 4번
			else if (i > x_start + dist2 && j >= y_start - dist1 + dist2 && i + j > x_start + y_start + 2 * dist2) {
				part_peoples[4] += peoples[i][j];
			}
			// 5번
			else {
				part_peoples[5] += peoples[i][j];
			}
		}
	}

	
	int max_value, min_value;

	max_value = part_peoples[1];
	min_value = part_peoples[1];

	for (int i = 2; i < 6; i++) {
		if (max_value < part_peoples[i]) {
			max_value = part_peoples[i];
		}
		if (min_value > part_peoples[i]) {
			min_value = part_peoples[i];
		}
	}

	int local_dist = max_value - min_value;

	if (local_dist < min_ans) {
		min_ans = local_dist;
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> peoples[i][j];
		}
	}



	// 1. d1 증가      1 ~ max(N - 1)
	for (int d1 = 1; d1 < N; d1++) {
		// 2. d2 증가      1 ~ max(N - 1 - d1)   
		for (int d2 = 1; d2 < N - d1; d2++) {
			// 3. x값 큰값부터 max(N - d1 - d2)   min(1)
			for (int x = N - d1 - d2; x > 0; x--) {
				// 4. y값 큰값부터 max(N - d2)        min(1 + d1)
				for (int y = N - d2; y > d1; y--) {
					check_distance(d1, d2, x, y);
				}
			}
		}
	}


	cout << min_ans;





}