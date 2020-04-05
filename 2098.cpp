#include <iostream>
#include <cmath>

using namespace std;

const int INF = 16000001;

int W[17][17];

int Dp[65536][17];

int N;

int miin(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int tsp(int curent, int visited) {

	if (visited == ((1 << N) - 1)) {

		if (W[curent][0] != 0)
			return W[curent][0];

	}

	int& result = Dp[visited][curent];

	if (result != 0) {
		return result;
	}

	result = INF;

	for (int nexti = 1; nexti < N; nexti++) {
		if (visited & (1 << nexti)) {
			continue;
		}
		if (W[curent][nexti] == 0) {
			continue;
		}
		result = miin(result, W[curent][nexti] + tsp(nexti, visited | (1 << nexti)));

	}

	return result;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> W[i][j];

		}
	}

	cout << tsp(0, 1);



}