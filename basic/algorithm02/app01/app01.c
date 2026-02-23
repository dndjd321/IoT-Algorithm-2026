// app01.c
// 검색 알고리즘
// 선형 검색

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// search int[]가 const인 이유 : 함수 내에서 원본 배열 내용을 변경하면 안되기 때문.
int search(const int[], int, int);

int main() {

	int nx, key = 0;

	puts("선형 검색.\n");

	printf("요소 개수 > ");
	scanf("%d", &nx);	// 총 배열크기 입력

	int* x = calloc(nx, sizeof(int));

	for (int i = 0; i < nx; i++) {
		printf("x[%d] > ", i);
		scanf("%d", &x[i]);
	}

	// 검색 시작
	printf("검색 값 > ");
	scanf("%d", &key);
	int idx = search(x, nx, key);	// 배열 x에 값이 key인 요소를 선형검색

	if (idx == -1) {
		puts("찾는 값이 없습니다.");
		return 1; 
	}
	else {
		printf("%d은(는) x[%d]에 있습니다.\n", key, idx);
	}

	free(x);

	return 0;
}

// a[] : 검색할 요소가 들어간 배여
// n : 배열의 크기
// key : 배열에서 찾을 값
int search(const int a[], int n, int key) {

	int i = 0;

	//while (1) {

	//	if (i == n) return -1;

	//	if (a[i] == key) return i;

	//	i++;
	//}

	for (i = 0; i < n; i++) {
		// 검색 성공 
		if (a[i] == key) return i;
	}


	return -1;
}

// return 0 == false
// return 1 == true
// return -1 == error