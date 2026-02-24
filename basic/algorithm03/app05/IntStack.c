// IntStack.c
// 스택 자료구조 함수 구현파일

#include <stdio.h>
#include <stdlib.h>

#include "IntStack.h"

/*=======스택 초기화========*/
// return -1 : 초기화 실패, return 0 : 초기화 성공
int Initialize(IntStack* st, int max) {
	st->ptr = 0;

	// 동적 배열 생성 작업
	if ((st->stk = calloc(max, sizeof(int))) == NULL) {	
		st->max = 0;	// 실패
		return -1;
	}
	
	st->max = max;
	return 0;	// 오류없이 초기화 완료
}

/*=======스택에 데이터 push========*/
int Push(IntStack* st, int x) {

	if (st->ptr >= st->max) {
		return -1;	// 데이터 추가 불가
	}

	st->stk[st->ptr] = x;	// 이전 값 다음 스택에 데이터 추가
	st->ptr++;				// ptr 1 증가

	return 0;
}

/*=======스택에 데이터 pop========*/
int Pop(IntStack* st, int* x) {
	
	if (st->ptr <= 0) {
		return -1;	// 오류
	}

	// ptr 위치 값을 1 감소
	st->ptr--;
	*x = st->stk[st->ptr];

	return 0;
}

/*=======스택에 마지막 데이터 peek========*/
int Peek(const IntStack* st, int* x) {

	// 스택에 데이터가 없을 경우
	if (st->ptr <= 0) {
		return -1;
	}

	// st->ptr-- 와는 다름
	*x = st->stk[st->ptr - 1];

	return 0;
}

/*=======스택 비우기========*/
void Clear(IntStack* st) {
	// 다음에 데이터 푸시할 위치를 0으로 변경.
	// 포인터 배열 상에 데이터는 남아있음.
	st->ptr = 0;
}

/*=======스택 최대용량========*/
int Capacity(const IntStack* st) {
	return st->max;
}

/*=======스택 데이터 개수========*/
int Size(const IntStack* st) {
	return st->ptr;
}

/*=======스택 빈 여부확인========*/
int IsEmpty(const IntStack* st) {
	return st->ptr <= 0;	// 1 : true,  0 : false
}

/*=======스택 만실 여부확인========*/
int IsFull(const IntStack* st) {
	return st->ptr >= st->max;
}

/*=======스택 검색========*/
int Search(const IntStack* st, int x) {
	for (int i = st->ptr - 1; i >= 0; i--) {
		if (st->stk[i] == x) {
			return i;	// 값이 있는 인덱스 return
		}
	}

	return -1; // 인덱스 값 0도 데이터가 있기에 -1 반환
}

/*=======스택 모든 데이터 출력========*/
int Print(const IntStack* st) {
	for (int i = 0; i < st->ptr; i++) {
		printf("%d > ", st->stk[i]);
	}

	printf("\n");
}

/*=======스택 종료========*/
int Terminate(IntStack* st) {

	if (st->stk != NULL) {
		free(st->stk);	// 메모리 해제
	}

	// max, ptr 모두 0으로 해제
	st->max = st->ptr = 0;
}

// 스택용 함수 정의 완료



