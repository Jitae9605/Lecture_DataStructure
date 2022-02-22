#include <stdio.h>

int LSearch(int ar[], int len, int target)		// 순차탐색알고리즘
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;							// 찾은 대상의 인뎃스값 반환
	}
	return -1;									// 찾지못했음을 의미하는 값 반환

}

int main(void)
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);		// arr배열에서 4를 찾고 4의 배열위치를 반환해 idx에 저장
	if (idx == -1)
	{
		printf("탐색실패 \n");
	}

	else
	{
		printf("타겟 저장 인덱스 : %d \n", idx);
	}

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);		// arr배열에서 7을 찾고 찾지못했으니 -1을 반환해 idx에 저장하고 탐색실패메세지를 출력
	if (idx == -1)
	{
		printf("탐색실패 \n");
	}
	else
	{
		printf("타겟 저장 인덱스 : %d \n", idx);
	}

	return 0;
}