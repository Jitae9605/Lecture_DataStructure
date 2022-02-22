#include <stdio.h>

int BSearch(int ar[], int len, int target)	// ����Ž��
{
	int first = 0;						// Ž������� �����ε�����
	int last = len - 1;					// Ž������� ������ �ε�����
	int mid;							// Ž������� �߾�

	while (first <= last)				// ���� �����ɶ����� �ݺ�
	{
		mid = (first + last) / 2;		// Ž������� �߾��� ã�´�

		if (target == ar[mid])			// ã�� �߾��� Ÿ���� ���
		{
			return mid;					// �߾��� ��ȯ
		}
		else							// Ÿ���� �ƴϸ� Ž������� ������ ���δ�
		{
			if (target < ar[mid])		// ���ĵ� �迭�̹Ƿ� 
				last = mid - 1;			// Ÿ���� �߾Ӻ��� ������ �߾� ���� ��� ����� �ƴ�
			else
				first = mid + 1;		// Ÿ���� �߾Ӻ��� ũ�� �߾� �Ʒ��� ��� ����� �ƴ�
		}								// -1�� +1�� �ִ� ������ Ž������� �迭���� ���°�� ���ѷ����� �Ǳ� ����

	}
	return -1;
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("Ž������\n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("Ž������\n");
	else
		printf("Ÿ�� ���� �ε��� : %d \n", idx);
	return 0;
}