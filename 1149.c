#include <stdio.h>
/* color cost inf */
int color[1001][3];
/* cumulated data */
int m[1001][3];

int min(int a, int b) {
	if (a >= b)
		return b;
	else
		return a;
}

int main(void) {
	int N, i, mincost;
	m[0][0] = 0;
	m[0][1] = 0;
	m[0][2] = 0;
	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d %d %d", &color[i][0], &color[i][1], &color[i][2]);

	for (i = 1; i <= N; i++) {
		m[i][0] = color[i][0] + min(m[i - 1][1], m[i - 1][2]);
		m[i][1] = color[i][1] + min(m[i - 1][0], m[i - 1][2]);
		m[i][2] = color[i][2] + min(m[i - 1][0], m[i - 1][1]);
	}
	mincost = m[N][0];
	if (mincost > m[N][1])
		mincost = m[N][1];
	if (mincost > m[N][2])
		mincost = m[N][2];
	printf("%d", mincost);

	return 0;
}