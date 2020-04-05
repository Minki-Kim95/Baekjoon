#include <iostream>

using namespace std;
typedef long long ll;

int N;
int alter[10001];
int num_alter = 0;

ll alter_counter[2][10002];

ll remain(ll a) {
	return a % 1000000007;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> alter[i];
	}


	if ((alter[0] != -1 && alter[0] != 0) || (alter[N - 1] != -1 && alter[N - 1] != 0)) {
		cout << 0;
		return 0;
	}

	alter_counter[1][0] = 1;

	for (int i = 1; i < N - 1; i++) {
		for (int i = 0; i < 10001; i++) {
			alter_counter[0][i] = alter_counter[1][i];
			alter_counter[1][i] = 0;
		}


		if (alter[i] == -1) {
			alter_counter[1][0] = remain(alter_counter[0][0] + alter_counter[0][1]);
			for (int j = 1; j < 10001; j++) {
				alter_counter[1][j] = remain(alter_counter[0][j - 1] + alter_counter[0][j] + alter_counter[0][j + 1]);
			}
		}
		else if (alter[i] == 0) {
			alter_counter[1][0] = remain(alter_counter[0][0] + alter_counter[0][1]);
		}
		else {
			alter_counter[1][alter[i]] = remain(alter_counter[0][alter[i] - 1] + alter_counter[0][alter[i]] + alter_counter[0][alter[i] + 1]);
		}

	}

	cout << remain(alter_counter[1][0] + alter_counter[1][1]);

}