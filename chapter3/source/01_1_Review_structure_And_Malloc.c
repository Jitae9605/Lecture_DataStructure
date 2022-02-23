#include<stdio.h>
#include<stdlib.h>

struct employee
{
	char* name;
	int salerly;
	int num;
};

int main(void)
{


	struct employee p[5] = {0,};
	int sum = 0;
	double avg = 0;

	for (int i = 0; i < 5; i++)
	{
		p[i].name = (char*)malloc(sizeof(char) * 20);				// 구조체의 포인터멤버 name을 동적할당 ( + 1 은
		if (p[i].name == NULL)										// 메모리 부족시 발생
		{
			return -1;
		}
	}

	printf("사원정보를 입력해주세요.\n\n");

	for (int i = 0; i < 5; i++)
	{
		printf(" %d번 사원의 번호 : ", i + 1);
		scanf("%d", &p[i].num);

		printf(" %d번 사원의 이름 : ", i + 1);
		scanf("%s", (p + i)->name);

		printf(" %d번 사원의 급여 : ", i + 1);
		scanf("%d", &p[i].salerly);

		printf("\n");
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", p[i].name);
		sum += p[i].salerly;
	}
	avg = sum / 5.0;

	for (int i = 0; i < 5; i++)
	free(p[i].name);

	printf(" 입력된 사원들의 평균급여는 %.1lf 원 이고 총급여액은 %d 원 입니다.\n", avg, sum);

}