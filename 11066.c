#include <stdio.h>

int m[500][500];

int main(void) {

	int T; //test data
	int K; //number of page
	int filesize[500]	//each size of file < 10,000
	int i, j;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &K);
		for (j = 0; j < K; j++)
			scanf("%d", &filesize[j]);
		for (j = 1; j < K; j++)
			m[j][j] = 0;
		for


	}


}