// 포인터 01 - 주소개념

#include <stdio.h>

int main() {
	int a = 10;
	int* pa = &a;

	/*int* pa;
	pa = &a;*/


	printf("a의 값 : %d\n", a);
	printf("a의 주소 : %p\n", &a);
	//printf("a의 주소 : %u\n", &a);
	printf("pa의 값(저장된 주소) : %p\n", pa);
	printf("pa가 가리키는 값 : %d\n", *pa);


	return 0;
}


// pa 는 주소저장, 변수 a의 주소를 담을수도 있고 다른 정수형 변수의 주소도 담을 수 있다.
// *pa 는 그 주소에 있는 실제값 => a변수의 값
// * 는 값을 직접 들고다니는게 아니라 주소를 들고 다니는 것. 