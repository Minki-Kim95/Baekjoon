#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack <char> galho;

string input_c;

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int result = 0;
	int temp = 1;

	cin >> input_c;

	int len_input = input_c.size();

	for (int i = 0; i < len_input; i++) {

		//cout << input_c[i];

		if (input_c[i] == '(') {
			temp *= 2;
			galho.push('(');
		}
		else if (input_c[i] == '[') {
			temp *= 3;
			galho.push('[');
		}


		else if (input_c[i] == ')') {
			if (galho.empty() || galho.top() != '(') {
				cout << 0;
				return 0;
			}
			else {
				if (input_c[i - 1] == '(') {
					result += temp;
				}
				temp /= 2;
				galho.pop();
			}
		}
		else if (input_c[i] == ']') {
			if (galho.empty() || galho.top() != '[') {
				cout << 0;
				return 0;
			}
			else {
				if (input_c[i - 1] == '[') {
					result += temp;
				}
				temp /= 3;
				galho.pop();
			}
		}
	}
	if (galho.empty()) {
		cout << result;
	}
	else {
		cout << 0;
	}

}