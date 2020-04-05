#include <iostream>
#include <algorithm>

using namespace std;

int parent[10001];

int sum;

typedef struct {

	int start;
	int end;

}Vertex;

Vertex vertex[100000];

int find_p(int a) {
	if (parent[a] == a)
		return a;
	else return parent[a] = find_p(parent[a]);

}

void union_fuc(int a, int b) {
	int aRoot = find_p(a);
	int bRoot = find_p(b);
	parent[aRoot] = bRoot;
	sum ++;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, T;

	cin >> T;

	for (int t = 0; t < T; t++) {
		sum = 0;
		cin >> N >> M;

		int sv, ev;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			cin >> sv >> ev;

			vertex[i].start = sv;
			vertex[i].end = ev;

		}


		for (int i = 0; i < M; i++) {
			if (find_p(vertex[i].start) != find_p(vertex[i].end)) {
				union_fuc(vertex[i].start, vertex[i].end);
			}
		}

		printf("%d\n", sum);

	}

	

}