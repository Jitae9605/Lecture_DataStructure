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
		p[i].name = (char*)malloc(sizeof(char) * 20);				// ����ü�� �����͸�� name�� �����Ҵ� ( + 1 ��
		if (p[i].name == NULL)										// �޸� ������ �߻�
		{
			return -1;
		}
	}

	printf("��������� �Է����ּ���.\n\n");

	for (int i = 0; i < 5; i++)
	{
		printf(" %d�� ����� ��ȣ : ", i + 1);
		scanf("%d", &p[i].num);

		printf(" %d�� ����� �̸� : ", i + 1);
		scanf("%s", (p + i)->name);

		printf(" %d�� ����� �޿� : ", i + 1);
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

	printf(" �Էµ� ������� ��ձ޿��� %.1lf �� �̰� �ѱ޿����� %d �� �Դϴ�.\n", avg, sum);

}