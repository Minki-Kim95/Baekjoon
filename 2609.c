#include <stdio.h>
#include <math.h>

int main(void) {
	int A, a, B, b, med, GCD, LCM;
	scanf("%d %d", &A, &B);
	a = A;
	b = B;
	//GCD
	while (1) {
		med = abs(a - b);
		if (a == b) {
			GCD = a;
			break;
		}
		else if (a < b)
			b = med;
		else
			a = med;
	}
	//LCM
	LCM = A * B / GCD;
	printf("%d\n%d", GCD, LCM);
	return 0;

}