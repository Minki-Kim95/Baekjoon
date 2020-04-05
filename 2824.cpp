#include <iostream>
#include <vector>

using namespace std;

bool visited[40000];

vector<int> prime;


void Eratos() {

	for (int prime_num = 2; prime_num  < 40000; prime_num++) {	// i : prime
		if (visited[prime_num]) {
			continue;
		} 
		else{
			visited[prime_num] = true;
			prime.push_back(prime_num);
			for (int prime_process = prime_num * prime_num; prime_process  < 40000; prime_process += prime_num) {	// loc
				visited[prime_process] = true;

			}
		}
		
	}
}



int miin(int a, int b) {
	if (a >= b)
		return b;
	else
		return a;
}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	


	Eratos();

	vector<int> nprime(prime.size(), 0);
	vector<int> mprime(prime.size(), 0);

	
	int N, M, temp;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> temp;
		int prime_size = prime.size();

		for (int i = 0; i < prime_size; i++){
			while (temp%prime[i] == 0) {
				nprime[i]++;
				temp /= prime[i];
			}
		}

		if (temp != 1) {
			prime.push_back(temp);
			nprime.push_back(1);
			mprime.push_back(0);
		}

	}
		

	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp;

		int prime_size = prime.size();

		for (int i = 0; i < prime_size; i++) {
			while (temp%prime[i] == 0) {
				mprime[i]++;
				temp /= prime[i];
			}
		}
		//필요없음
		/*if (temp != 1) {
			prime.push_back(temp);
			mprime.push_back(1);
		}*/
	}
		
	
	int min_prime;
	long long gdb = 1;
	bool is_over = false;
	int num_size = nprime.size();
	for (int i = 0; i < num_size; i++) {

		if (nprime[i] > 0 && mprime[i] > 0) {
			min_prime = miin(nprime[i], mprime[i]);
			for (int j = 0; j < min_prime; j++) {
				gdb *= prime[i];
				if (gdb >= 1000000000) {
					gdb %= 1000000000;
					is_over = true;
				}
			}

			
		}
	}
	if (is_over) {
		cout.width(9);
		cout.fill('0');
	}

	cout << gdb;
}