#include <stdio.h>
#include <limits.h>


typedef struct {
	int rank;
	int problem;
	int penalty;
}score;

void insertionSort(score* arr, int length) {
	int i, j;
	int temp;
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (arr[i].problem < arr[j].problem) {
				temp = arr[i].rank;
				arr[i].rank = arr[j].rank;
				arr[j].rank = arr[i].rank;
			}
		}
	}
}
score people[66];

int main(void) {
	// 6 univ, 1~5 pride, 
	//input N(5<= N <= 66)
	//0<= 문제수 <= 8
	//0<= 페널티 <= 100000
	//5등은 무조건 한문제는 풀었음
	//한문제 이상 푼애들중 패널티 같은 애들없음
	//5등과 문제수 같지만 수상x인 애들 뽑기

	int num, i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &people[i].problem, &people[i].penalty);
		people[i].rank = i + 1;
	}


}