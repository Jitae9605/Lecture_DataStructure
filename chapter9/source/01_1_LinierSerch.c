/* ����Ž�� */
#include<stdio.h>

int LSerch(int* arr, int len, int adata)
{

	for (int i = 0; i < len; i++)
	{
		if (arr[i] == adata)
		{
			printf("���� ã�ҽ��ϴ�. %d��° �迭�� ����Ǿ� �ֽ��ϴ�.\n\n", i + 1);
			return 0;
		}
	}
	printf("�ش� ���� ã�� ���߽��ϴ�.\n\n");
	return 0;

}

int main(void)
{
	int ary[] = { 1,5,9,3,8,7,4,2 };
	int len = sizeof(ary) / sizeof(ary[0]);

	LSerch(ary, len, 1);
	LSerch(ary, len, 5);
	LSerch(ary, len, 11);
	LSerch(ary, len, 3);
	LSerch(ary, len, 12);


	return 0;
}