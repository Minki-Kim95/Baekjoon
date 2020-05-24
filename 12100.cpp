#include <iostream>

using namespace std;

int N;

int chess[22][22];

int max_ans = 0;

// right, left, up, down
// 0, 1, 2, 3

void print_chess() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << chess[i][j] << ' ';
		}
		cout << endl;
	}
}

void move_mals(int direction) {

	int cur_x, cur_y, loc_value;

	bool is_sum[22][22];
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			is_sum[i][j] = false;
		}
	}

	
	if (direction == 0) {
		for (int j = N - 1; j > 0; j--) {
			for (int i = 1; i <= N; i++) {
				//j+
				if (chess[i][j]) {
					cur_x = i;
					cur_y = j;
					loc_value = chess[cur_x][cur_y];
					while (chess[cur_x][cur_y + 1] == 0 && cur_y < N) {
						chess[cur_x][cur_y] = 0;
						chess[cur_x][++cur_y] = loc_value;
					}
					if (chess[cur_x][cur_y + 1] == loc_value && !is_sum[cur_x][cur_y + 1]) {
						chess[cur_x][cur_y] = 0;
						chess[cur_x][++cur_y] = 2 * loc_value;
						is_sum[cur_x][cur_y] = true;
						if (2 * loc_value > max_ans) {
							max_ans = 2 * loc_value;
						}
					}
				}
			}
		}

	}
	else if (direction == 1) {
		for (int j = 2; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				//j-
				if (chess[i][j]) {
					cur_x = i;
					cur_y = j;
					loc_value = chess[cur_x][cur_y];
					while (chess[cur_x][cur_y - 1] == 0 && cur_y > 1) {
						chess[cur_x][cur_y] = 0;
						chess[cur_x][--cur_y] = loc_value;
					}
					if (chess[cur_x][cur_y - 1] == loc_value && !is_sum[cur_x][cur_y - 1]) {
						chess[cur_x][cur_y] = 0;
						chess[cur_x][--cur_y] = 2 * loc_value;
						is_sum[cur_x][cur_y] = true;
						if (2 * loc_value > max_ans) {
							max_ans = 2 * loc_value;
						}
					}
				}
			}
		}
	}
	else if (direction == 2) {
		// up
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				//i-
				if (chess[i][j]) {
					cur_x = i;
					cur_y = j;
					loc_value = chess[cur_x][cur_y];
					while (chess[cur_x - 1][cur_y] == 0 && cur_x > 1) {
						chess[cur_x][cur_y] = 0;
						chess[--cur_x][cur_y] = loc_value;
					}
					if (chess[cur_x - 1][cur_y] == loc_value && !is_sum[cur_x - 1][cur_y]) {
						chess[cur_x][cur_y] = 0;
						chess[--cur_x][cur_y] = 2 * loc_value;
						is_sum[cur_x][cur_y] = true;
						if (2 * loc_value > max_ans) {
							max_ans = 2 * loc_value;
						}
					}
				}
			}
		}
	}
	else {
		for (int i = N - 1; i > 0; i--) {
			for (int j = 1; j <= N; j++) {
				//i+
				if (chess[i][j]) {
					cur_x = i;
					cur_y = j;
					loc_value = chess[cur_x][cur_y];
					while (chess[cur_x + 1][cur_y] == 0 && cur_x < N) {
						chess[cur_x][cur_y] = 0;
						chess[++cur_x][cur_y] = loc_value;
					}
					if (chess[cur_x + 1][cur_y] == loc_value && !is_sum[cur_x + 1][cur_y]) {
						chess[cur_x][cur_y] = 0;
						chess[++cur_x][cur_y] = 2 * loc_value;
						is_sum[cur_x][cur_y] = true;
						if (2 * loc_value > max_ans) {
							max_ans = 2 * loc_value;
						}
					}
				}
			}
		}
	}

}

void dfs(int deep) {

	/*cout << "deep: "<<deep << endl;
	print_chess();*/

	if (deep == 5) {
		return;
	}

	int temp_chess[22][22];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			temp_chess[i][j] = chess[i][j];
		}
	}



	for (int i = 0; i < 4; i++) {


		move_mals(i);
		dfs(deep + 1);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				chess[i][j] = temp_chess[i][j];
			}
		}
	}




}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> chess[i][j];
			if (max_ans < chess[i][j])
				max_ans = chess[i][j];
		}
	}
	//cout << endl;
	dfs(0);
	//move_mals(3);
	//print_chess();


	cout << max_ans;
	



}