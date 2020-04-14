#include <iostream>

using namespace std;

long long chess[91];


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;


	chess[0] = 0;
	chess[1] = 1;

	for (int i = 2; i <= n; i++) {

		chess[i] = chess[i - 1] + chess[i - 2];

	}

	cout << chess[n];

}