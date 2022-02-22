#include <stdio.h>

int BSearch(int ar[], int len, int target)	// 이진탐색
{
	int first = 0;						// 탐색대상의 시작인덱스값
	int last = len - 1;					// 탐색대상의 마지막 인덱스값
	int mid;							// 탐색대상의 중앙

	while (first <= last)				// 서로 교차될때까지 반복
	{
		mid = (first + last) / 2;		// 탐색대상의 중앙을 찾는다

		if (target == ar[mid])			// 찾은 중앙이 타겟인 경우
		{
			return mid;					// 중앙을 반환
		}
		else							// 타겟이 아니면 탐색대상을 반으로 줄인다
		{
			if (target < ar[mid])		// 정렬된 배열이므로 
				last = mid - 1;			// 타겟이 중앙보다 작으면 중앙 위는 모두 대상이 아님
			else
				first = mid + 1;		// 타겟이 중앙보다 크면 중앙 아래는 모두 대상이 아님
		}								// -1과 +1이 있는 이유는 탐색대상이 배열내에 없는경우 무한루프가 되기 때문

	}
	return -1;
}

int main(void)
{
	int arr[] = { 1,3,5,7,9 };
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("탐색실패\n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
	if (idx == -1)
		printf("탐색실패\n");
	else
		printf("타겟 저장 인덱스 : %d \n", idx);
	return 0;
}