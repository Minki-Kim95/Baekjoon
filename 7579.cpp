#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 10001;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef struct {
	int mem;
	int cost;
}App;


App Applist[100];

//int cost[INF];
//vector<int> cost_list;

int cost[101][INF];


int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> Applist[i].mem;
	}

	for (int i = 0; i < N; i++) {
		cin >> Applist[i].cost;
	}

	

	int min_cost = INF;
	cost[0][Applist[0].cost] = Applist[0].mem;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < INF; j++) {
			if (j >= Applist[i].cost) {
				cost[i][j] = max(cost[i][j], cost[i - 1][j - Applist[i].cost] + Applist[i].mem);
			}
			cost[i][j] = max(cost[i][j], cost[i - 1][j]);

			if (cost[i][j] >= M) {
				min_cost = min(min_cost, j);
			}
		}
	}




	//int len_cost_list;
	
	/*for (int i = 0; i < INF; i++) {
		cost[i] = -1;
	}*/


	//if (Applist[0].cost != 0) {
	//	cost[0] = 0;
	//	cost_list.push_back(0);

	//	cost[Applist[0].cost] = Applist[0].mem;
	//	cost_list.push_back(Applist[0].cost);

	//}
	//else {
	//	cost[0] = Applist[0].mem;
	//	cost_list.push_back(0);

	//}


	//for (int i = 1; i < N; i++) {	//Applist

	//	len_cost_list = cost_list.size();

	//	for (int j = 0; j < len_cost_list; j++) {

	//		if (cost[cost_list[j] + Applist[i].cost] < cost[cost_list[j]] + Applist[i].mem) {	//해당 cost의 값보다 큰값이 들어온 경우

	//			if (cost[cost_list[j] + Applist[i].cost] == -1) {	//해당 cost에 처음 방문한 경우
	//				cost_list.push_back(cost_list[j] + Applist[i].cost);
	//			}

	//			cost[cost_list[j] + Applist[i].cost] = cost[cost_list[j]] + Applist[i].mem;	// 해당 cost 값 변경
	//		}
	//	}

	//	
	//}

	//int min_cost = INF;

	//sort(cost_list.begin(), cost_list.end());

	//for (int there : cost_list) {
	//	if (cost[there] >= M) {
	//		min_cost = there;
	//		break;
	//	}
	//}


	/*for (int there : cost_list) {
		if (min_cost > there && cost[there] >= M) {
			min_cost = there;
		}
	}*/


	cout << min_cost;
}