// app01.c
// 큐 구현

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntQueue.h"

int main() {
	IntQueue que;

	// 큐 생성
	if (Initialize(&que, 8) == -1) {
		puts("큐 생성 실패");
		return 1;	// exit(1);
	}

	int menu, x, ch;

	while (1) {

		menu = -1;

		printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)ENQUE, (2)DEQUE, (3)PEEK, (4)OUTPUT, (0)EXIT >> ");
		scanf("%d", &menu);
		
		// 잘못된 키보드 입력 버퍼 제거
		// 기초 프로그래밍 주소록 토이프로젝트 소스 참조함.
		while ((ch = getchar()) != '\n' && ch != EOF) {}

		if (menu == 0) break;

		switch (menu) {
		case 1:	// enque
			printf("데이터 입력 > ");
			scanf("%d", &x);

			if (Enque(&que, x) == -1) {
				puts("\a오류 >> ENQUE 실패.");
			}
			break;
		case 2:	// deque
			if (Deque(&que, &x) == -1) {
				puts("\a오류 >> DEQUE 실패");
			}
			else{
				printf("DEQUE 데이터 : %d\n", x);
			}

			break;
		case 3:	// peek
			if ( Peek(&que, &x) == -1) {
				puts("\a오류 >> PEEK 실패.");
			}
			else {
				printf("PEEK 데이터 : %d\n", x);
			}
			break;
		case 4:	// output
			Print(&que);
			break;
		default:
			puts("입력 오류.");
			break;
		}
	}

	// 큐 종료
	Terminate(&que);

	return 0;
}