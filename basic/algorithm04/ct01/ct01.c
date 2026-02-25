// ct01.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char s[100];
} StackString;

int main() {
	char st[] = { 'h','e','l','l','o'};
	
	StackString ss;
	
	int n = 0;
	// "hello"라는 문자를 끝에서부터 하나씩 ss에 넣고 마지막까지 다 넣으면 출력하기
	for (int i = sizeof(st) - 1; i >= 0; i--) {
		ss.s[n] = st[i];
		n++;
	}

	for (int i = 0; i < n; i++) {
		printf("%c", ss.s[i]);
	}

	return 0;
}