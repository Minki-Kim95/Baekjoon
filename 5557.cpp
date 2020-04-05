#include<iostream>

using namespace std;

int input_int[101];

long long dp[101][21];

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> input_int[i];
	}

	dp[1][input_int[1]]++;

	for (int i = 2; i < N; i++) {
		for (int j = 0; j <= 20; j++) {

			if (dp[i - 1][j]) {

				if (j + input_int[i] < 21) {
					dp[i][j + input_int[i]] += dp[i - 1][j];
				}
				if (j - input_int[i] >= 0) {
					dp[i][j - input_int[i]] += dp[i - 1][j];
				}
			}

		}
		

	}

	cout << dp[N - 1][input_int[N]];




}