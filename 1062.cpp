#include<iostream>
#include<string>

using namespace std;

int N, K;

bool is_alpha[26];
string woord[50];
int num_possible = 0;

void dfs(int alpha, int deep) {

	if (deep == K) {

		int len_word, word_possible = 0;
		bool is_poss;

		for (int i = 0; i < N; i++) {

			is_poss = true;
			len_word = woord[i].size();

			for (int j = 0; j < len_word; j++) {
				if (is_alpha[woord[i][j] - 'a'] != true) {
					is_poss = false;
					break;
				}
			}
			if (is_poss) {
				word_possible++;
			}

		}

		if (word_possible > num_possible) {
			num_possible = word_possible;
		}

	}

	for (int i = alpha; i < 26; i++) {

		if (!is_alpha[i]) {

			is_alpha[i] = true;
			dfs(i, deep + 1);
			is_alpha[i] = false;
		}

	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	if (K < 5) {
		cout << 0;
		return 0;
	}
	else if (K == 26) {
		cout << N;
		return 0;
	}
	int len_word;

	for (int i = 0; i < N; i++) {
		
		cin >> woord[i];

		len_word = woord[i].size();

		woord[i] = woord[i].substr(4, len_word - 8);
		

	}
	/*for (int i = 0; i < N; i++) {

		cout << woord[i] << endl;


	}*/

	is_alpha['a' - 'a'] = true;
	is_alpha['n' - 'a'] = true;
	is_alpha['t' - 'a'] = true;
	is_alpha['i' - 'a'] = true;
	is_alpha['c' - 'a'] = true;

	K -= 5;

	dfs(0, 0);

	cout << num_possible;


	

}