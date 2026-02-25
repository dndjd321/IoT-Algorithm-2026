// ct04.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[10][10];
	int* score;
	int ptr;
} Info;

int main() {

	Info info;
	int num;
	char n[10];
	int s;

	int ch;

	// 입력 받을 학생과 점수 개수
	printf("입력 ");
	scanf("%d", &num);

	info.ptr = 0;
	info.score = (int*)calloc(num, sizeof(int));
	

	for (int i = 0; i < num; i++) {
		while ((ch = getchar()) != '\n' && ch != EOF) {}

		scanf("%s %d", n, &s);
		strcpy(info.name[info.ptr], n);
		info.score[info.ptr] = s;

		info.ptr++;
	}

	Info best_info;
	best_info.ptr = 0;

	for (int i = 0; i < num; i++) {
		if (i == 0) {
			strcpy(best_info.name[best_info.ptr], info.name[i]);
			best_info.score = (int*)info.score[i];
			best_info.ptr = i;

		}
		else if (best_info.score >= info.score[i]) {
			continue;
		}
		else {
			strcpy(best_info.name[best_info.ptr], info.name[i]);
			best_info.score = (int*)info.score[i];
		}
	}
	
	printf("%s %d", &best_info.name[best_info.ptr], (int*)best_info.score);

	free(info.score);

	return 0;
}