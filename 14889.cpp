#include<iostream>
#include<vector>

using namespace std;
int n;
int S[21][21];
int answer = 2147483647;

vector<int> start;
vector<int> link;
int start_s = 0;
int link_s = 0;

inline int min(int a, int b) {
	return a > b ? b : a;
}

int abss(int a) {
	if (a < 0) return -a;
	return a;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> S[i][j];
		}
	}
	
	for (int i = (1 << (n >> 1)) - 1; i < (1 << n); i++) {
		start.clear();
		link.clear();
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				start.push_back(j);
			}
			else {
				link.push_back(j);
			}
		}
		if (start.size() == (n >> 1)) {
			start_s = 0;
			link_s = 0;
			for (int f = 0; f < (n >> 1); f++) {
				for (int s = f + 1; s < (n >> 1); s++) {
					// start[f] start[s]
					// link[f] link[s]
					start_s += S[start[f]][start[s]] + S[start[s]][start[f]];
					link_s += S[link[f]][link[s]] + S[link[s]][link[f]];
				}
			}
			answer = min(answer, abss(start_s - link_s));
		}

	}
	cout << answer;




}