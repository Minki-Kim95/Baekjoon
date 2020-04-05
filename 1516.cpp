#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N;
queue<int> q;
vector<int> edge[501];

int build_time[501];
int indegree[501];
bool visited[501];

int min_time[501];



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int temp, count = 0;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> build_time[i];

		while ((cin >> temp), (temp != -1)) {
			edge[temp].push_back(i);
			indegree[i]++;
		}

	}
	
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			visited[i] = true;
			min_time[i] = build_time[i];
		}
	}

	int start_v;
	while (!q.empty()) {
		start_v = q.front();
		q.pop();

		for (int there : edge[start_v]) {
			indegree[there]--;
			min_time[there] = max(min_time[start_v] + build_time[there], min_time[there]);

			if (indegree[there] == 0) {
				q.push(there);
				
			}
		}

	}

	for (int i = 1; i <= N; i++) {
		cout << min_time[i] << '\n';
	}

}