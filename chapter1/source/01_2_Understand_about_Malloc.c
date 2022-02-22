#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int size;
	int* arr;

	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d", &size);

	printf("%d���� ���� ���� �迭�� ����ϴ�.\n", size);

	// �迭���� �ڵ�
	arr = (int*)malloc(sizeof(int) * size);				// �����Ҵ�
	if (arr == NULL)										// �޸� ������ �߻�
	{
		return -1;
	}

	// �迭�� ���� �Է��ϴ� �ڵ�
	printf("%d���� ������ �Է��ϼ���.\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d�� : ", i + 1);
		// scanf("%d", &arr[i]);							// �迭����
		scanf("%d", (arr + i));								// ����������
	}														//	arr		==	arr + 0 == &arr[0]
															//			->	arr + i == &arr[i]

	for (int i = 0; i < size; i++)
	{
		// printf("%d ", arr[i]);							// �迭����
		printf("%d ", *(arr + i));							// ����������
	}														// *(arr + i)	==	*(&arr[i]) == arr[i]

	free(arr);

	return 0;
}