// IntQueue 헤더파일
#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
	int max;	// 큐 최대크기
	int num;	// 큐 현재요소개수
	int front;	// 큐 프런트
	int rear;	// 큐 리어
	int* que;	// 실제 큐 데이터의 맨 앞 요소의 포인터

} IntQueue;

/*====== 큐 초기화 ======*/
// parameter( IntQueue &(주소), 최대크기 )
// return -1(오류) 0(성공)
int Initialize(IntQueue* qu, int max);

/*====== 큐에 데이터 인큐 ======*/
// parameter( IntQueue &(주소), 들어갈 값 )
// return -1(오류) 0(성공)
int Enque(IntQueue* qu, int x);

/*====== 큐에 데이터 디큐 ======*/
// parameter( IntQueue &(주소), 디큐로 가져올 값 )
// return -1(오류) 0(성공)
int Deque(IntQueue* qu, int* x);

/*====== 큐에서 데이터 피크 ======*/
// parameter( const IntQueue &(주소) 변경불가 , 확인할 값 )
// return -1(오류) 0(성공)
int Peek(const IntQueue* qu, int* x);

/*====== 큐 클리어 ======*/
// parameter ( 전부 삭제할 큐 )
void Clear(IntQueue* qu);

/*====== 큐 최대 용량 ======*/
// parameter( 확인할 큐 )
// return -1(오류) 0~max
int Capacity(const IntQueue* qu);

/*====== 큐에 저장된 데이터 수 ======*/
// parameter( 확인할 큐 )
// return -1(오류) 0~num
int Size(const IntQueue* qu);

/*====== 큐가 비어있는지 체크 ======*/
// parameter( 확인할 큐 )
// return -1(오류) 0
int IsEmpty(const IntQueue* qu);

/*====== 큐가 가득 찼는지 체크 ======*/
// parameter( 확인할 큐 )
// return -1(오류) 0
int IsFull(const IntQueue* qu);

/*====== 큐 검색 ======*/
// parameter( 확인할 큐 )
// return -1(오류) 0~num
int Search(const IntQueue* qu, int x);

/*====== 큐 출력 ======*/
// parameter( 확인할 큐 )
void Print(const IntQueue* qu);

/*====== 큐 종료 ======*/
// parameter( 확인할 큐 )
void Terminate(IntQueue* qu);


#endif
