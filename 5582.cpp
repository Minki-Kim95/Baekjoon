#include<iostream>
#include<string>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

string str1;
string str2;

int common_str[4001][4001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str1;
	cin >> str2;

	int len1 = str1.size();
	int len2 = str2.size();

	int max_common = 0;

	for (int j = 0; j < len2; j++) {
		if (str2[j] == str1[0]) {
			common_str[1][j + 1] = 1;
			max_common = 1;
		}
	}

	for (int i = 1; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (str2[j] == str1[i]) {
				common_str[i + 1][j + 1] = common_str[i][j] + 1;
				max_common = max(max_common, common_str[i + 1][j + 1]);
			}
		}
	}

	cout << max_common;
}