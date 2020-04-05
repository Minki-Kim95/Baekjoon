#include<iostream>
#include<string>

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

string str1;
string str2;

int common_str[1002][1002];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str1;
	cin >> str2;
	//str1 = '0' + str1;
	//str2 = '0' + str2;

	int len1 = str1.size();
	int len2 = str2.size();
	
	for (int i = 0; i < len1; i++) {
		for (int j = 0; j < len2; j++) {
			if (str1[i] == str2[j]) {
				common_str[i + 1][j + 1] = common_str[i][j] + 1;
			}
			else {
				common_str[i + 1][j + 1] = max(common_str[i][j + 1], common_str[i + 1][j]);
				
			}
		}
	}
	int total_len = common_str[len1][len2];
	cout << total_len << '\n';

	string result;
	int i = len1;
	int j = len2;
	
	while (common_str[i][j]) {
		// left
		if (common_str[i][j] == common_str[i][j - 1]) {
			j--;
		}
		//up
		else if (common_str[i][j] == common_str[i - 1][j]) {
			i--;
		}
		else {
			result.push_back(str1[i - 1]);
			i--;
			j--;
		}

	}
	if (total_len != 0) {
		for (int i = result.size() - 1; i >= 0; i--) {
			cout << result[i];
		}
		
	}


}