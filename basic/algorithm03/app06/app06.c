// app06.c
// goto 문 사용 예제
// goto문은 되도록 지양해야함

#include <stdio.h>

int main() {
	int i = 0;

	// start 라벨, 앵커 
start:
	printf("i = %d\n", i);
	i++;

	if (i < 5) {
		// start 라벨로 점프
		goto start;
	}

	printf("끝.\n");

	return 0;
}
