#include<stdio.h>

int main(void)
{
	int num=0;
	/*
	// �����ﰢ�� ����� 1

	printf("�����Է� : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = i+1; j > 0; j--)
		{
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	// �����ﰢ�� ����� 2

	printf("�����Է� : ");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	*/

	printf("�����Է� : ");
	scanf("%d", &num);
	
	for (int i = 0; i < (num / 2) + 1; i++)						// ��µǴ� �� ���� ���� ((�Է¹��� Ȧ�� / 2) + 1)
	{

		for (int a = 0; a < (num / 2) - i; a++)					// �������	= ù�ٿ��� (num/2)���� ���� �̷� �����ٸ��� 1���� ������ ���δ�
		{
			printf(" ");
		}

		for (int b = 0; b < 1 + (2 * i); b++)					// "*"���	= ù�ٿ��� 1�� ���� �ٺ��� 2���� �ø���
		{ 
			printf("*");
		}		

		printf("\n");											
		
	}
	return 0;
}