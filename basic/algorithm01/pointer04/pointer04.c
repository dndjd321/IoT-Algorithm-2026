// 포인터 04 - 포인터 변수의 주소와 이중 포인터

#include <stdio.h>

// 변수를 전달해서 값을 교환하는 함수
void swap01(int* a, int* b) {
	int temp = *a;	// a가 가리키는 값을 temp에 저장
	*a = *b;
	*b = temp;
}

// 포인터 변수를 전달해서 주소를 교환하는 함수
void swap02(int** a, int** b) {
	int* temp = *a;	// a가 가리키는 주소를 temp에 저장
	*a = *b;
	*b = temp;
}

int main() {
	int x = 25, y = 52;
	
	printf("변경 전 x = %d, y = %d\n", x, y);
	swap01(&x, &y);
	printf("변경 후 x = %d, y = %d\n", x, y);

	int* px = &x;
	int* py = &y;

	printf("포인터 변수로 변경 전 x = %d, y = %d, *px = %d, *py = %d\n", x, y, *px, *py);
	swap01(&px, &py);
	printf("포인터 변수로 변경 후 x = %d, y = %d, *px = %d, *py = %d\n", x, y, *px, *py);

	return 0;
}

// int* 변수의 주소
// int** 포인터의 주소
// 포인터를 바꾸려면 이중 포인터가 필요