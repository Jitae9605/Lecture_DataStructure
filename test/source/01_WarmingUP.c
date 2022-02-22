#include<stdio.h>


int main(void)
{
	/*
	// 1) 5개의 숫자를 입력받아서 가장 큰 수를 찾는 프로그램
	int a, b, c, d, e;
	int max1, max2, max3;
	int res;

	// 입력부
	printf("다섯개의 정수를 입력 : ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	// 큰 수 찾기 - 원리는 1:1 토너먼트와 같다.
	max1 = (a > b) ? a : b;						// a 와 b를 비교해 큰 수를 max1에 저장
	max2 = (c > d) ? c : d;						// c 와 d를 비교해 큰 수를 max2에 저장 
	max3 = (max1 > max2) ? max1 : max2;			// max1 와 max2를 비교해 큰 수를 max3에 저장
	res = (max3 > e) ? max3 : e;				// max3 과 e를 비교해 최종인 res에 저장

	printf("가장 큰 수는 %d입니다.\n", res);		// res 출력
	*/

	// 2) 이름과 나이를 입력받아 출력
	char name[20];
	int age;

	printf("이름 : ");
	scanf("%s", name);
	printf("나이 : ");
	scanf("%d", &age);

	printf("이름 : %s, 나이 : %d", name, age);

	return 0;
}