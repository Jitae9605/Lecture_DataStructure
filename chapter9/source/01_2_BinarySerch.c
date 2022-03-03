/*이진탐색*/
// !!! 이진탐색은 탐색하는 대상이 정렬되어 있어야한다 !!!
#include <stdio.h>

int BSearch(int* ary, int alen, int akey)
{
	int first = 0;
	int last = alen - 1;
	int mid;

	while (first <= last)
	{
		mid = (first + last) / 2;
		if (ary[mid] == akey) return mid;
		else
		{
			if (ary[mid] > akey)
			{
				last = mid-1;
			}
			else
			{
				first = mid+1;
			}
		}
	}
	return -1;
}

int main(void)
{
	int ary[] = { 1,3,4,5,7,8,9 };
	int len = sizeof(ary) / sizeof(ary[0]);
	int key, idx;

	printf("검색값 입력 : ");
	scanf("%d", &key);

	idx = BSearch(ary, len, key);
	if (idx == -1) printf("없습니다.\n");
	else printf("key index : %d", idx);

	return 0;
}