#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
int r, c, k;

int max_r = 3;
int max_c = 3;

int tarray[101][101];

void print_arr() {
	for (int i = 1; i <= max_r; i++) {
		for (int j = 1; j <= max_c; j++) {
			cout << tarray[i][j] << ' ';
		}
		cout << endl;
	}
}

bool cmp(const pair<int, int>& a, const pair<int, int> &b) {
	if(a.second == b.second){
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}

int sortRow(int colum) {
	int len_array = 0;
	map <int, int> local_map;
	vector<pair<int, int>> local_row;

	for (int i = 1; i <= max_r; i++) {
		if (tarray[i][colum] != 0) {
			if (local_map.count(tarray[i][colum])) {
				local_map.find(tarray[i][colum])->second++;
			}
			else {
				local_map.insert(make_pair(tarray[i][colum], 1));
			}
			tarray[i][colum] = 0;
		}
		
	}


	map <int, int> ::iterator it;

	for (it = local_map.begin(); it != local_map.end();it ++) {
		//cout << "it->first: " << it->first << ' ' << " it->second: " << it->second << endl;
		local_row.push_back(make_pair(it->first, it->second));
	}
	len_array = local_row.size();


	sort(local_row.begin(), local_row.end(), cmp);

	int row_index = 0;
	for (int i = 0; i < len_array; i++) {
		//cout << "local_row[i].first: " << local_row[i].first << ' ' << " local_row[i].second: " << local_row[i].second << endl;
		//cout << local_row[i].first << ' ' << local_row[i].second << ' ';
		tarray[++row_index][colum] = local_row[i].first;
		tarray[++row_index][colum] = local_row[i].second;
		if (row_index == 100) {
			break;
		}
	}
	//cout << endl;

	return row_index;
}

int sortColum(int row) {
	int len_array = 0;
	map <int, int> local_map;
	vector<pair<int, int>> local_colum;

	for (int i = 1; i <= max_c; i++) {

		if (tarray[row][i] != 0) {
			if (local_map.count(tarray[row][i])) {
				local_map.find(tarray[row][i])->second++;
			}
			else {
				local_map.insert(make_pair(tarray[row][i], 1));
			}
			tarray[row][i] = 0;
		}
		
		

	}
	map <int, int> ::iterator it;

	for (it = local_map.begin(); it != local_map.end();it++) {
		//cout << "it->first: " << it->first << ' ' << " it->second: " << it->second << endl;
		local_colum.push_back(make_pair(it->first, it->second));
	}
	len_array = local_colum.size();


	sort(local_colum.begin(), local_colum.end(), cmp);

	int colum_index = 0;
	for (int i = 0; i < len_array; i++) {
		//cout << local_colum[i].first << ' ' <<  local_colum[i].second << ' ';
		tarray[row][++colum_index] = local_colum[i].first;
		tarray[row][++colum_index] = local_colum[i].second;
		if (colum_index == 100) {
			break;
		}
	}
	//cout << endl;
	return colum_index;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			cin >> tarray[i][j];
		}
	}
	int trial = 0;
	while (trial <= 100) {
		if (tarray[r][c] == k) {
			break;
		}
		if (max_r >= max_c) {
			// R
			int local_max_len = 0;
			for (int j = 1; j <= max_r; j++) {
				local_max_len = max(sortColum(j), local_max_len);
			}
			max_c = local_max_len;
			//print_arr();
		}
		else {
			int local_max_len = 0;
			for (int i = 1; i <= max_c; i++) {
				local_max_len = max(sortRow(i), local_max_len);
			}
			max_r = local_max_len;
			//print_arr();
		}
		trial++;
		
	}


	if (trial > 100) {
		cout << -1;
	}
	else {
		cout << trial;
	}
	
}