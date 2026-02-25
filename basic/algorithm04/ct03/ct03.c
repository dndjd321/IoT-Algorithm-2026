// ct03.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

static int result = 0;

void refunc(int n);

int main() {

	int n;

	printf("입력 > ");
	scanf("%d", &n);

	refunc(n);

	printf("결과 > %d", result);

	return 0;
}

void refunc(int n) {

	if (n > 1) {
		refunc(n - 1);
	}
	
	result += n;
}