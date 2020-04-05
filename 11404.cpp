#include <iostream>

using namespace std;

inline int min(int a, int b) { return a < b ? a : b; }

const int INF = 10000000;

int n, m;

int D[101][101];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;

	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			D[i][j] = INF;
		}
	}

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (D[a][b] > c) {
			D[a][b] = c;
		}
		

	}

	for (int k = 1; k <= n; k++) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if(i != j)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}



	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (D[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << D[i][j] << ' ';
			}

		}
		cout << '\n';
;
	}
}