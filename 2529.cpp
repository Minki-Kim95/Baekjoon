#include <iostream>

using namespace std;

int k;
char compare[9];
int numlist[10];
bool visited[10];

int resultlist[10];
bool flag = false;

void dfs(int dept) {

	if (dept == k + 1) {
		for (int i = 0; i < k + 1; i++) {
			cout << resultlist[i];
		}
		cout << '\n';
		flag = true;
	}

	for (int i = 0; i < k + 1; i++) {

		if (compare[dept - 1] == '<') {
			if (resultlist[dept - 1] < numlist[i] && visited[numlist[i]] == false) {
				resultlist[dept] = numlist[i];
				visited[numlist[i]] = true;
				dfs(dept + 1);
				visited[numlist[i]] = false;
			}
		}
		else if (compare[dept - 1] == '>') {
			if (resultlist[dept - 1] > numlist[i] && visited[numlist[i]] == false) {
				resultlist[dept] = numlist[i];
				visited[numlist[i]] = true;
				dfs(dept + 1);
				visited[numlist[i]] = false;
			}
		}
		if (flag) {
			return;
		}
	}

}

void max_value() {
	int loc = 0;
	for (int i = 9; i >= 9 - k; i--) {
		numlist[loc++] = i;
	}

	for (int i = 0; i < k + 1; i++) {
		resultlist[0] = numlist[i];
		visited[numlist[i]] = true;
		dfs(1);
		visited[numlist[i]] = false;
	}
	

}

void min_value() {
	int loc = 0;
	for (int i = 0; i <= k; i++) {
		numlist[loc++] = i;
	}

	for (int i = 0; i < k + 1; i++) {
		resultlist[0] = numlist[i];
		visited[numlist[i]] = true;
		dfs(1);
		visited[numlist[i]] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> compare[i];
	}

	max_value();
	flag = false;
	min_value();


}