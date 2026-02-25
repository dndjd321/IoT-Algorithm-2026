// ct02.c

//2. 1부터 N까지 적힌 카드가 있습니다. 다음 과정을 카드가 1장 남을 때까지 반복합니다. 마지막 카드번호를 출력하는 소스를 작성하세요. 
//-맨 위 카드 1장을 버린다
//- 그 다음 맨 위 카드 1장을 맨 아래로 옮긴다
//
//예) 입력 6->결과 4

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int num;
	int front;
	int rear;
	int* data;
} NumCard;

int DelNum(NumCard* nc, int* x);
void GotoBottomNum(NumCard* nc, int* x);
void AddNum(NumCard* nc, int x);

int main() {

	NumCard nc;

	int n;
	int x;

	printf("입력 > ");
	scanf("%d", &n);

	nc.num = nc.rear = nc.front = 1;
	// 동적배열할당 오류 체크
	if ((nc.data = (int*)calloc(n, sizeof(int))) == NULL) {
		nc.max = 0;
		return -1;
	}

	nc.max = n;

	// 1~n까지 nc.num에 추가
	for (int i = 1; i <= n; i++) {
		//nc.num++;
		//nc.data[nc.rear] = i;
		//nc.rear++;

		AddNum(&nc, i);
	}

	//int cnt = 1;

	// 카드 버리기와 맨밑이동 반복
	while (1) {
		if (nc.num == 1) break;
		if (DelNum(&nc, &nc.data[0]) == -1) break;

		if (nc.num == 1) break;
		GotoBottomNum(&nc, &nc.data[0]);

		//printf("%d번째 사이클\n", cnt++);
	}

	printf("결과 > %d", nc.data[0]);

	return 0;
}

void AddNum(NumCard* nc, int x) {
	if (nc->num >= nc->max) {
		return;
	}

	nc->num++;
	nc->data[nc->rear] = x;
	nc->rear++;

	if (nc->rear == nc->max) {
		nc->rear = 1;
	}
}


int DelNum(NumCard* nc, int* x) {
	
	if (nc->max <= 1) {
		return -1;
	}
	else {
		nc->num--;
		*x = nc->data[nc->front];
		nc->front++;

		if (nc->front == nc->max) {
			nc->front = 1;
		}

		return 0;
	}
}

void GotoBottomNum(NumCard* nc, int* x) {
	NumCard n;
	n.data = nc->data;
	n.rear = nc->rear;
	DelNum(nc, x);
	AddNum(nc, n.data[n.rear]);
}