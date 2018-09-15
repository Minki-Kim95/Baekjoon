#include <stdio.h>
#include <limits>

int m[501][501];

int main(void) {

	int T; //test data
	int K; //number of page
	int filesize[500]	//each size of file < 10,000
	int i, j, k, x, l;

	printf("adsf");
	scanf("%d", &T);

	for (x = 0; x < T; x++) {
		
		scanf("%d", &K);
		for (j = 0; j < K; j++)
			scanf("%d", &filesize[j]);
		for (j = 1; j < K; j++)
			m[j][j] = 0;
		for (l = 2; l < K; l++) {
			for (i = 1; i < K - l + 1; i++) {
				j = i + l - 1;
				m[i][j] = INT_MAX;
				for(k = i; )
			}
		}


	}


}