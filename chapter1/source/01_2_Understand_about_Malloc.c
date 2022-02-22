#include <stdio.h>
#include <stdlib.h>



int main(void)
{
	int size;
	int* arr;

	printf("방의 갯수를 입력하세요 : ");
	scanf("%d", &size);

	printf("%d개의 방을 갖는 배열을 만듭니다.\n", size);

	// 배열생성 코드
	arr = (int*)malloc(sizeof(int) * size);				// 동적할당
	if (arr == NULL)										// 메모리 부족시 발생
	{
		return -1;
	}

	// 배열에 값을 입력하는 코드
	printf("%d개의 정수를 입력하세요.\n", size);
	for (int i = 0; i < size; i++)
	{
		printf("%d번 : ", i + 1);
		// scanf("%d", &arr[i]);							// 배열형태
		scanf("%d", (arr + i));								// 포인터형태
	}														//	arr		==	arr + 0 == &arr[0]
															//			->	arr + i == &arr[i]

	for (int i = 0; i < size; i++)
	{
		// printf("%d ", arr[i]);							// 배열형태
		printf("%d ", *(arr + i));							// 포인터형태
	}														// *(arr + i)	==	*(&arr[i]) == arr[i]

	free(arr);

	return 0;
}