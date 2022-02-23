#include <stdio.h>

int main(void)
{
	// 입력받은 값이 1보다 작을때까지 값을 입력받아서 마지막에 이때까지 입력받은 값들을 출력하는 프로그램
	//	단, 최대 입력가능한 수가 처음 설정한 배열의 크기를 벗어나지 못함!
	int arr[10];
	int readCount = 0;
	int readData;
	int i;

	while (1)
	{
		printf("자연수 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; i++)
		printf("%d ", arr[i]);



	return 0;
}