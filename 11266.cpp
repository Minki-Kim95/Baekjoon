#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> vertex;
int order[10001];
int cur_order = 0;
bool is_visited[10001];
bool is_cut[10001];
int num_cut = 0;


int miin(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int dfs(int start, bool head) {

	order[start] = ++cur_order;
	int min_order = order[start];
	is_visited[start] = true;
	int child = 0;
	bool not_pushed = true;

	for (int present : vertex[start]) {

		if (is_visited[present]) {
			min_order = miin(min_order, order[present]);

		}
		else {
			child++;
			int low = dfs(present, 0);
			if (not_pushed && !head && order[start] <= low) {


				is_cut[start] = true;
				num_cut++;
				not_pushed = false;
			}
			min_order = miin(min_order, low);


		}

	}
	if (head) {
		if (child > 1) {
			is_cut[start] = true;
			num_cut++;
		}
	}



	return min_order;

}



int main(void) {
	int V, E, sv, ev;

	cin.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++) {
		is_visited[i] = false;
	}
	vertex.resize(V + 1);
	for (int i = 0; i < E; i++) {
		cin >> sv >> ev;
		vertex[sv].push_back(ev);
		vertex[ev].push_back(sv);
	}

	for (int i = 1; i <= V; i++) {
		if (!is_visited[i]) {
			dfs(i, 1);
		}
	}



	cout << num_cut << '\n';

	if (num_cut) {
		for (int i = 1; i <= V; i++) {
			if (is_cut[i]) {
				cout << i << ' ';
			}

		}
	}

}