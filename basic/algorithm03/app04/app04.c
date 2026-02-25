// app04
// 재귀 알고리즘 분석
// 하향식 방법 분석

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// 함수호출횟수 카운트 변수
int callCount = 0;

/*====== 재귀함수 recur 선언과 정의 ======*/
void recur(int n) {

	callCount++;	// 함수호출횟수 증가

	// 종료 조건 : n이 0이하로 떨어지면 종료
	if (n > 0) {	
		recur(n - 1);	// n이 1 이하가 될때까지 반복
		printf("%d\n", n);
		recur(n - 2);	// n이 2 이하가 될때까지 반복
	}
}

int main() {

	int x;

	while (1) {

		printf("정수 입력 > ");
		scanf("%d", &x);

		if (x <= 0) break;
		
		callCount = 0;	// 입력 받을 때마다 초기화
		recur(x);
		printf("함수 총 호출 횟수 : %d\n\n",callCount);
	}



	return 0;
}