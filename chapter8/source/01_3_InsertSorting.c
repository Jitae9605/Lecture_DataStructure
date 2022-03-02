/*삽입정렬 - p383*/
// 앞선 정렬들과 다르다
// 정렬된 상태에서 새로운 요소가 들어왔을때 정렬하는 방법
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