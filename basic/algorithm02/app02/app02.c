// app02.c
// 이진 검색

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int bin_search(const int[], int, int);

int main() {
	int nx, key;

	puts("이진 검색");
	printf("요소 개수 > ");
	scanf("%d", &nx);

	int* x = calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");
	// 첫번째 요소만 먼저 입력
	printf("x[0] > ");
	scanf("%d", &x[0]);

	// 제대로 된 입력이 될 때까지 반복하는 로직.
	for (int i = 1; i < nx; i++) {
		do {
			printf("x[%d] > ",i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	// 검색 시작
	printf("검색 값 > ");
	scanf("%d", &key);

	int idx = bin_search(x, nx, key);
	if (idx == -1) {
		puts("찾는 값이 없습니다.");
	}
	else {
		printf("%d은(는) x[%d]에 있습니다.\n", key, idx);
	}

	free(x);

	return 0;
}

// n개 요소 배열에서 key와 일치하는 요소 이진검색 함수
int bin_search(const int a[], int n, int key) {
	int pl = 0;		// 검색범위 맨 앞 인덱스
	int pr = n - 1;	// 검색범위 맨 끝 인덱스

	do {
		// 검색범위 중앙 인덱스
		int pc = (pl + pr) / 2;
		if (a[pc] == key) return pc;	
		// 찾는 값이 중앙값 기준 오른쪽에 있을 경우
		else if (a[pc] < key) pl = pc + 1;	// 검색 범위를 뒤쪽 절반으로 줄임
		// 찾는 값이 중앙값 기준 왼쪽에 있을 경우
		else pr = pc - 1;	// 검색 범위를 앞쪽 절반으로 줄임
	} while (pl <= pr); 
	// 이진 검색에서 pl은 무조건 pr보다 왼쪽에 있어야함.

	// 검색 실패
	return -1;	
}
