// IntStack.h
// 스택 자료구조 헤더파일

#ifndef ___IntStack // 이름 지정에는 큰 의미 없긴함.
#define ___IntStack

// 스택을 구현하는 구조체 생성
typedef struct {
	int max;	// stack 용량
	int ptr;	// stack 포인터
	int* stk;	// stack 첫 요소에 대한 포인터
} IntStack;

// 스택용 함수 선언

/*=======스택 초기화========*/
int Initialize(IntStack* st, int max);

/*=======스택에 데이터 push========*/
int Push(IntStack* st, int x);

/*=======스택에 데이터 pop========*/
int Pop(IntStack* st, int* x);

/*=======스택에 마지막 데이터 peek========*/
int Peek(const IntStack* st, int* x);

/*=======스택 비우기========*/
void Clear(IntStack* st);

/*=======스택 최대용량========*/
int Capacity(const IntStack* st);

/*=======스택 데이터 개수========*/
int Size(const IntStack* st);

/*=======스택 빈 여부확인========*/
int IsEmpty(const IntStack* st);

/*=======스택 만실 여부확인========*/
int IsFull(const IntStack* st);

/*=======스택 검색========*/
int Search(const IntStack* st, int x);

/*=======스택 모든 데이터 출력========*/
int Print(const IntStack* st);

/*=======스택 종료========*/
int Terminate(IntStack* st);


#endif 
