#include <iostream>
#include <vector>

inline int min(int a, int b) { return a < b ? a : b; }
inline int max(int a, int b) { return a > b ? a : b; }

using namespace std;

const int INF = 1000000;

int N, M;

int dept[100001];
int parent[100001][18];
int visited[100001];
int W_min[100001][18];
int W_max[100001][18];

int min_weight;
int max_weight;

vector <vector <pair<int, int>>> edge;

void dfs(int start, int depth) {
	visited[start] = true;
	dept[start] = depth;

	int edge_size = edge[start].size();
	for (int i = 0; i < edge_size; i++) {
		if (visited[edge[start][i].first])
			continue;
		parent[edge[start][i].first][0] = start;
		dfs(edge[start][i].first, depth + 1);
		W_min[edge[start][i].first][0] = edge[start][i].second;
		W_max[edge[start][i].first][0] = edge[start][i].second;
		
	}

}

void dp() {

	for (int i = 1; i < 18; i++) {
		for (int j = 1; j <= N; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
			W_min[j][i] = min(W_min[j][i - 1], W_min[parent[j][i - 1]][i - 1]);
			W_max[j][i] = max(W_max[j][i - 1], W_max[parent[j][i - 1]][i - 1]);
		}

	}

}


int diff_to_zero(int deep, int shallow) {

	for (int i = 17; i >= 0; i--) {
		if (dept[deep] - dept[shallow] >= (1 << i)) {
			min_weight = min(min_weight, W_min[deep][i]);
			max_weight = max(max_weight, W_max[deep][i]);
			deep = parent[deep][i];
		}
	}
	return deep;
}


void LCA(int a, int b) {

	min_weight = INF;
	max_weight = -INF;

	//int lca;
	
	if (dept[a] < dept[b]) {
		b = diff_to_zero(b, a);
	}
	else if (dept[b] < dept[a]) {
		a = diff_to_zero(a, b);
	}

	//if (a == b) {
	//	// lca = a;
	//}

	if (a != b) {

		for (int i = 17; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				min_weight = min(min_weight, min(W_min[a][i], W_min[b][i]));
				max_weight = max(max_weight, max(W_max[a][i], W_max[b][i]));
				a = parent[a][i];
				b = parent[b][i];
			}
		}

		// lca = parent[a][0];
		min_weight = min(min_weight, min(W_min[a][0], W_min[b][0]));
		max_weight = max(max_weight, max(W_max[a][0], W_max[b][0]));
		
	}
	cout << min_weight << ' ' << max_weight << '\n';

	

	
	

	


}


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sv, ev, weight;
	
	cin >> N;

	edge.resize(N + 1);


	for (int i = 0; i < N - 1; i++) {
		cin >> sv >> ev >> weight;//2°³
		edge[sv].push_back(make_pair(ev, weight));
		edge[ev].push_back(make_pair(sv, weight));


	}

	dfs(1, 0);
	dp();

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> sv >> ev;
		LCA(sv, ev);

	}


}