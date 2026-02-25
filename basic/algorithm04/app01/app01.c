// app01.c
// 메모이제이션 - 성능 향상 극대화 기법

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 저장할 배열 선언
static char memo[128][1024];	// 길이가 1024가 되는 문자열 128개 담을 수 있음.
int callCount = 0;

/*====== 메모이제이션 recur 함수 ======*/
void recur(int n) {

	callCount++;

	if (memo[n + 1][0] != '\0') {	// 배열에 상위값이 데이터가 있을 경우 
		printf("%s", memo[n + 1]);	// 메모 출력
	}
	else {	// 데이터가 없을 경우
		if (n > 0) {	// 재귀호출 진행
			recur(n - 1);
			printf("%d\n", n);
			recur(n - 2);

			// 메모리에 저장
			//printf("%s%d\n%s", memo[n], n, memo[n - 1]);
			sprintf(memo[n + 1], "%s%d\n%s", memo[n], n, memo[n - 1]);

		}
		else {
			// memo[0] recur(-1) 저장, memo[0] recur(0) 저장
			strcpy(memo[n + 1], "");
		}
	}

}

int main() {

	int x;

	while (1) {

		printf("정수 입력 > ");
		scanf("%d", &x);

		if (x <= 0) break;

		callCount = 0;

		recur(x);
		printf("함수 총 호출 횟수 : %d\n\n", callCount);

	}

	return 0;
}