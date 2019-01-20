#include <stdio.h>
#include <math.h>

int main(void) {
	int A, B, V, cumul, date;
	scanf("%d %d %d", &A, &B, &V);
	date = 1 + ceil(floor(V - A) / floor(A - B));
	printf("%d", date);
	return 0;

}
