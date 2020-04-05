#include <iostream>

typedef long long ll;

using namespace std;


int parent[100010];
ll compare[100010];
int num[100010];


void init_parent(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		compare[i] = 0;
		num[i] = 1;
	}


}

int find_f(int a) {

	if (parent[a] == a) {
		return a;
	}

	int daddy = parent[a];
	int prev = find_f(daddy);
	compare[a] += compare[daddy];
	return parent[a] = prev;



}
void union_fuc(int a, int b, ll w) {
	int aRoot = find_f(a);
	int bRoot = find_f(b);

	//cout << " aRoot: " << aRoot << " bRoot: " << bRoot;


	if (aRoot == bRoot) {
		return;
	}

	parent[aRoot] = bRoot;

	compare[aRoot] += compare[b] - compare[a] - w;

	/*else {
		if (num[bRoot] >= num[aRoot]) {
			parent[aRoot] = bRoot;
			ll diff = compare[b] - compare[a] - w;
			compare[aRoot] += diff;

			num[bRoot] += num[aRoot];
			num[aRoot] = 1;

		}
		else {
			parent[bRoot] = aRoot;

			ll diff = compare[b] - compare[a] - w;
			compare[bRoot] -= diff;

			num[aRoot] += num[bRoot];
			num[bRoot] = 1;

		}
	}*/
	

}

int main(void) {
	int N, M, sv, ev;
	ll weight;
	char act;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while ((cin >> N >> M), (N != 0 || M != 0)) {


		init_parent(N);
		for (int i = 0; i < M; i++) {
			cin >> act;
			if (act == '!') {
				cin >> sv >> ev >> weight;
				union_fuc(sv, ev, weight);
			}
			else {
				cin >> sv >> ev;
				if (find_f(sv) == find_f(ev)) {
					cout << compare[ev] - compare[sv] << '\n';
				}
				else {
					cout << "UNKNOWN\n";
				}

			}
		}

	}




}