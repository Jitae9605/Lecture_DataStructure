/*�������� - p383*/
// �ռ� ���ĵ�� �ٸ���
// ���ĵ� ���¿��� ���ο� ��Ұ� �������� �����ϴ� ���
#include <stdio.h>

void InsertSort(int arr[], int n)
{

}

int main(void)
{
	int arr[10] = { 3,2,10,9,4,1,8 ,5,7,6 };
	int i;
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}