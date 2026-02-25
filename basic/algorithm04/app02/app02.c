// app02.c
// 버블정렬

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*====== 교환함수 ======*/
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*====== 버블정렬 ======*/
// n : 배열의 크기
void bubbleSort(int a[], int n) {

	// 배열의 마지막 요소는 사용하지 않음
	for (int i = 0; i < n - 1; i++) {
		int exchg = 0;	// 교환횟수
		// 배열의 마지막요소 전부터, 현재의 i값까지 반복하면서 줄어듬
		for (int j = n - 1; j > i; j--) {
			if (a[j -1] > a[j]) {
				swap(&a[j - 1], &a[j]);
				exchg++;	// 값을 변경했다는 의미
			}
		}

		// 값 변경이 한번도 일어나지 않았다면 이미 정렬이 되어있다는 상태이므로 break
		if (exchg == 0) break;
	}
}

int main() {
	int nx = 0; 

	printf("버블 정렬\n");
	printf("요소 개수 > ");
	scanf("%d", &nx);
	int* x = calloc(nx, sizeof(int));

	// 요소 개수만큼 입력
	for (int i = 0; i < nx; i++) {
		printf("x[%d] > ", i);
		scanf("%d", &x[i]);
	}

	bubbleSort(x, nx);
	puts("오름차순 정렬 완료.");

	for (int i = 0; i < nx; i++) {
		printf("x[%d] = %d \n", i, x[i]);
	}

	free(x);

	return 0;
}