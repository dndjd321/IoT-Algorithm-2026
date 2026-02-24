// app05.c
// 재귀 알고리즘 비재귀로 변경

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntStack.h"

/*====== 재귀함수 호출부분 제거 ======*/
void recur(int n) {

	IntStack stk;
	Initialize(&stk, 100);

Top:

	// 종료 조건 : n이 0이하로 떨어지면 종료
	if (n > 0) {
		//recur(n - 1);	// 머리 재귀 제거
		// n 값을 스택에 푸시
		Push(&stk, n);
		n = n - 1;
		goto Top;
	}
	
	// stk이 비어있지 않을 경우 ( 데이터가 있는 경우 )
	if (!IsEmpty(&stk)) {	
		// 임시 저장한 n값 팝
		Pop(&stk, &n);
		printf("%d\n", n);

		//recur(n - 2);	// 꼬리 재귀 제거
		n = n - 2;
		goto Top;
	}

	Terminate(&stk);
}

int main() {

	int x;

	while (1) {

		printf("정수 입력 > ");
		scanf("%d", &x);

		if (x <= 0) break;

		recur(x);

	}

	return 0;
}