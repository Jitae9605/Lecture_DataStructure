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

	/*
	// 2) 버퍼오류에 의한 입출력 오류
	int age = 0;
	char ch;

	printf("해결전 1번\n");
	printf("나이 : ");
	scanf("%d", &age);
	printf("기호 : ");
	scanf("%c", &ch);

	printf("기호 : %c, 나이 : %d\n\n",ch, age);		// 제대로 입/출력이 작동하지 않는다.


	printf("해결전 2번\n");							// 입력받는 순서를 바꿈
	printf("기호 : ");
	scanf("%c", &ch);
	printf("나이 : ");
	scanf("%d", &age);


	printf("기호 : %c, 나이 : %d\n\n", ch, age);						// 제대로 출력된다.

	// 숫자를 입력받을때는 상관이 없지만.
	// 문자열/문자를 입력받고 출력할때는 입출력에서 문제가 된다. => ENTER가 버퍼에 남아있어서 그렇다!

	// <해결방법>
	// 버퍼를 비운다 -> getchar();를 사용해 한개의 문자를 읽어오고 그냥 버리면 버퍼가 비워진다!

	printf("해결후\n");
	printf("나이 : ");
	scanf("%d", &age);
	getchar();
	printf("기호 : ");
	scanf("%c", &ch);

	printf("기호 : %c, 나이 : %d\n\n", ch, age);		// 제대로 입/출력이 작동하지 않는다.
	*/

	/*
	// 3) 입력받은 숫자까지의 합을 구하는 프로그램
	int num_3;
	int sum_3 = 0;

	printf("정수를 입력하세요 : ");
	scanf("%d", &num_3);

	for (int i = 0; i <= num_3; i++)
	{
		sum_3 += i;
	}
	printf("입력받은 정수 %d까지의 정수 합은 %d입니다.\n", num_3, sum_3);

	*/

	// 4)

	return 0;
}