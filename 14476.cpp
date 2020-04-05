#include <iostream>
#include <vector>
#include <cmath>

//1 000 000
using namespace std;

int N;

int segment_tree[2097152];
int input_int[1000000];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

int find_idx() {
	int value = 1,index = 0;
	while (value < N) {
		value *= 2;
		index++;
	}

	return index;
}



int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input_int[i];
	}

	int first_idx = find_idx();
	int first_loc = (int)pow(2, first_idx);

	for (int i = 0; i < N; i++) {
		segment_tree[first_loc + i] = input_int[i];
	}

	int start_loc = first_loc;
	/*cout << start_loc << ' ' << (start_loc >> 1) << endl;*/
	for (int i = first_idx - 1; i >= 0; i--) {
		start_loc /= 2;	//2·Î³ª´®
		for (int j = start_loc; j < 2 * start_loc; j++) {
			segment_tree[j] = gcd(segment_tree[2 * j], segment_tree[2 * j + 1]);
		}
	}

	//Æ®¸®Ãâ·Â
	/*for (int i = 0 ; i <= first_idx; i++) {
		int start_range = (int)pow(2, i);
		for (int j = start_range; j < 2 * start_range ; j++) {
			cout << segment_tree[j] << ' ';
		}
		cout << endl;
	}*/

	int max_gcd = 0;
	int loc_max_gcd = -1;
	int now_loc;

	for (int i = 0; i < N; i++) {

		now_loc = first_loc + i;
		segment_tree[now_loc] = 0;

		while (now_loc > 0) {
			now_loc >>= 1; //2·Î³ª´®
			segment_tree[now_loc] = gcd(segment_tree[2 * now_loc], segment_tree[2 * now_loc + 1]);
		}


		//
		/*for (int i = 0; i <= first_idx; i++) {
			int start_range = (int)pow(2, i);
			for (int j = start_range; j < 2 * start_range; j++) {
				cout << segment_tree[j] << ' ';
			}
			cout << endl;
		}*/
		//

		//cout << "segment_tree[1]: " << segment_tree[1] << " max_gcd: " << max_gcd << " input_int[i]: " << input_int[i] << endl;
		if (segment_tree[1] > max_gcd && input_int[i] % segment_tree[1] != 0) {
			max_gcd = segment_tree[1];
			loc_max_gcd = i;
		}

		now_loc = first_loc + i;
		segment_tree[now_loc] = input_int[i];

		while (now_loc > 0) {
			now_loc >>= 1; //2·Î³ª´®
			segment_tree[now_loc] = gcd(segment_tree[2 * now_loc], segment_tree[2 * now_loc + 1]);
		}
	}

	if (max_gcd) {
		cout << max_gcd << ' ' << input_int[loc_max_gcd];
	}
	else {
		cout << -1;
	}







}

