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
	//0<= ������ <= 8
	//0<= ���Ƽ <= 100000
	//5���� ������ �ѹ����� Ǯ����
	//�ѹ��� �̻� Ǭ�ֵ��� �г�Ƽ ���� �ֵ����
	//5��� ������ ������ ����x�� �ֵ� �̱�

	int num, i;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &people[i].problem, &people[i].penalty);
		people[i].rank = i + 1;
	}


}