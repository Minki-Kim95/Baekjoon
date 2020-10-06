#include<iostream>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

int n;
int schedule[16][2];
int max_value[16];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	max_value[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> schedule[i][0] >> schedule[i][1];
		max_value[i] = 0;
	}
	if (schedule[1][0] != 1) {
		max_value[1] = 0;
	}
	else {
		max_value[1] = schedule[1][1];
	}
	
	
	for (int day = 2; day <= n; day++) {

		for (int i = 0; i < day; i++) {
			// max_value[i] + i+1번째의 그거
			max_value[day] = max(max_value[day], max_value[i]);

			if (i + schedule[i+1][0] <= day) {
				max_value[day] = max(max_value[day], max_value[i] + schedule[i+1][1]);
			}

		}

		
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << max_value[i] << '\n';
	//}

	cout << max_value[n];

}