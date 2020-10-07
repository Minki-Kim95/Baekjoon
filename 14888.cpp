#include<iostream>
#include<cstring>

using namespace std;
int n;
int num_list[11];
int cal_list[4];

int cur_counter[4];
int cal_order_list[10];
int cal_order_num;

int max_value = -100000000;
int min_value = 100000000;

void print_cal(void) {
	for (int i = 0; i < n - 1; i++) {
		cout << cal_order_list[i] << ' ';
	}
	cout << '\n';
}

int calcul(void) {
	int result = num_list[0];
	for (int i = 1; i < n; i++) {
		if (cal_order_list[i - 1] == 0) {
			result = result + num_list[i];
		}
		else if (cal_order_list[i - 1] == 1) {
			result = result - num_list[i];
		}
		else if (cal_order_list[i - 1] == 2) {
			result = result * num_list[i];
		}
		else {
			result = result / num_list[i];
		}
	}
	return result;
}

void dfs(int deep) {
	if (deep == n - 1) {
		int cal_result = calcul();
		
		//print_cal();
		//cout << cal_result << '\n';
		if (max_value < cal_result) {
			max_value = cal_result;
			/*cout << "max value\n";
			print_cal();*/
		}
		if (min_value > cal_result) {
			min_value = cal_result;
			/*cout << "min value\n";
			print_cal();*/
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cur_counter[i] < cal_list[i]) {
			cur_counter[i]++;
			cal_order_list[cal_order_num++] = i;
			dfs(deep + 1);
			cal_order_num--;
			cur_counter[i]--;
		}
	}
}




int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num_list[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> cal_list[i];
	}

	//cur_list[4] = {0};
	for (int i = 0; i < 4; i++) {
		memset(cur_counter, 0, sizeof(cur_counter));
		cal_order_num = 0;
		if (cur_counter[i] < cal_list[i]) {
			cur_counter[i]++;
			cal_order_list[cal_order_num++] = i;
			dfs(1);
		}
	}
	cout << max_value << '\n' <<min_value;



}