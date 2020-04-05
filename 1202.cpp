#include<iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

pair <int , int> jewel[300000];
int bag[300000];
priority_queue<int> pq;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}

	for (int i = 0; i < k; i++) {
		cin >> bag[i];
	}

	sort(jewel, jewel + n);
	sort(bag, bag + k);

	/*for (int i = 0; i < n; i++) {
		cout<< jewel[i].first << jewel[i].second << endl;
	}*/

	int loc_jewel = 0;
	long long result = 0;

	for (int i = 0; i < k; i++) {

		while (loc_jewel < n && jewel[loc_jewel].first <= bag[i]) {
			pq.push(jewel[loc_jewel++].second);
		}

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}


	}
	cout << result;

}