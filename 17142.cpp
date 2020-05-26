#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, num_virus;

int industry[50][50];

int min_ans = 2147483647;

int num_zero = 0;

vector<int> init_viruses;

vector < pair<int, int > > virus;

queue <pair<int, int>> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs() {
	//bool is_changed = false;
	int local_indus[50][50];
	bool is_visited[50][50];

	int zombi_zero = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			local_indus[i][j] = industry[i][j];
			is_visited[i][j] = false;

		}
	}
	for (int there : init_viruses) {
		is_visited[virus[there].first][virus[there].second] = true;
	}


	int timer = 0;
	while (!q.empty() && zombi_zero != num_zero) {
		int q_size = q.size();
		timer++;

		for (int i = 0; i < q_size; i++) {
			//pair<int, int> cur_loc = q.front();
			int x_loc = q.front().first;
			int y_loc = q.front().second;
			int next_x, next_y;

			//bool is_visit = false;
			for (int i = 0; i < 4; i++) {
				next_x = x_loc + dx[i];
				next_y = y_loc + dy[i];
				if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N && is_visited[next_x][next_y] == false) {
					if (local_indus[next_x][next_y] == 0) {
						q.push(make_pair(next_x, next_y));
						zombi_zero++;
						is_visited[next_x][next_y] = true;
					}
					else if (local_indus[next_x][next_y] == 2) {
						q.push(make_pair(next_x, next_y));
						is_visited[next_x][next_y] = true;
					}
				}
			}

			q.pop();
		}

		
	}


	//timer--;

	if (zombi_zero == num_zero && timer < min_ans) {
		min_ans = timer;
	}

	/*cout << "timer: " << timer << " num_zero: " << num_zero << " zombi_zero: " << zombi_zero <<endl;

	for (int there : init_viruses) {
		cout << there << ' ';
	}
	cout << endl;
	for (int there : init_viruses) {
		cout << virus[there].first << ' ' << virus[there].second << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << is_visited[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/
}

void dfs(int preval, int deep) {

	if (deep == M) {
		while (!q.empty()) {
			q.pop();
		}
		for (int there : init_viruses) {
			//cout << virus[there].first << ' ' << virus[there].first << endl;
			q.push(make_pair(virus[there].first, virus[there].second));
		}
		bfs();
		return;
	}
	for (int i = preval + 1; i < num_virus; i++) {
		init_viruses.push_back(i);
		dfs(i, deep + 1);
		init_viruses.pop_back();

	}



}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> industry[i][j];
			if (industry[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				//industry[i][j] = -2;
			}
			/*else if (industry[i][j] == 1) {
				industry[i][j] = -1;
			}*/
			else if(industry[i][j] == 0) {
				num_zero++;
			}

		}
	}
	num_virus = virus.size();

	dfs(-1, 0);

	if (min_ans != 2147483647) {
		cout << min_ans;
	}
	else {
		cout << -1;
	}


}