// app03.c
// 스택 구현

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "IntStack.h"


int main() {

	IntStack st;

	// 스택 초기화
	if (Initialize(&st, 10) == -1) {
		puts("스택 초기화 실패.");
		return 1;	// exit(1);
	}

	// 무한 루프
	while (1) {
		// 스택 기능 구현
		int menu, x, ch;

		printf("현재 데이터 수 : %d / %d\n", Size(&st), Capacity(&st));
		printf("(1)PUSH, (2)POP, (3)PEEK, (4)OUTPUT, (5)SEARCH, (6)CLEAR, (0)EXIT > ");
		scanf("%d", &menu);

		// 잘못된 키보드 입력 버퍼 제거
		// 기초 프로그래밍 주소록 토이프로젝트 소스 참조함.
		while ((ch = getchar()) != '\n' && ch != EOF) {}

		// EXIT ( 종료 ) 처리
		if (menu == 0) break;

		switch (menu) {
		case 1:	// PUSH

			if (!IsFull(&st)) {
				printf("데이터 입력 > ");
				scanf("%d", &x);

				if (Push(&st, x) == -1)
					puts("\a오류 발생 >> PUSH 실패");
			}
			else {
				puts("\a스택이 가득 차있습니다.");
			}

			break;
		case 2:	// POP
			if (IsEmpty(&st)) {
				if (Pop(&st, &x) == -1)
					puts("\a오류 발생 >> POP 실패");
				else
					printf("POP 데이터는 %d\n", x);
			}
			else {
				puts("\a스택이 비어있습니다.");
			}

			break;
		case 3:	// PEEK
			if (Peek(&st, &x) == -1)
				puts("\a오류 발생 >> PEEK 실패");
			else
				printf("PEEK 데이터는 %d\n", x);

			break;
		case 4:	// OUTPUT
			Print(&st);
			break;
		case 5 : // SEARCH
			printf("검색할 수 입력 > ");
			scanf("%d", &x);

			int res = Search(&st, x);

			if (res == -1) {
				puts("검색 실패");
			}
			else {
				printf("검색 결과 : st[%d] = >%d\n", res, st.stk[res]);
			}

			break;
		case 6:	// CLEAR
			Clear(&st);
			puts("스택 클리어");
			break;
		default:
			break;
		}

	}

	Terminate(&st);

	return 0;
}