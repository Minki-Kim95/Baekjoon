#include <iostream>

using namespace std;

int N, B, C;
long long ans = 0;
int num_person[1000001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num_person[i];
	}
	cin >> B >> C;

	for (int i = 0; i < N; i++) {
		num_person[i] -= B;
		ans++;

		if (num_person[i] > 0) {
			if (num_person[i] % C == 0) {
				ans += (num_person[i] / C);
			}
			else {
				ans += (num_person[i] / C) + 1;
			}
			
		}

		/*while (num_person[i] > 0) {
			num_person[i] -= C;
			ans++;
		}*/
	}

	cout << ans;

}