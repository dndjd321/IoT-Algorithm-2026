// app02 
// 팩토리얼 재귀방식
// result를 int로 하면 12자리까지 계산 가능
// unsigned long long 으로 하면 20!까지 계산가능

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned long long factorial(int n);

int main() {
	int x;
	unsigned long long result = 0;

	puts("팩토리얼 재귀호출");

	while (1) {

		printf("정수 입력 > ");
		scanf("%d", &x);

		if (x == 0) break;

		result = factorial(x);

		printf("%d! = %llu \n", x, factorial(x));
	}

	return 0;
}

// factorial
// 0!, 1! = 1
// n! = n x (n - 1)!
unsigned long long factorial(int n) {
	if (n > 0) {
		return (unsigned long long)n * factorial(n - 1);
	}
	else {
		return 1;
	}
}