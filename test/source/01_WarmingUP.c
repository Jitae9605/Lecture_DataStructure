#include<stdio.h>


int main(void)
{
	int a, b, c, d, e;
	int max1, max2, max3;
	int res;

	printf("�ټ����� ������ �Է� : ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	max1 = (a > b) ? a : b;
	max2 = (c > d) ? c : d;
	max3 = (max1 > max2) ? max1 : max2;
	res = (max3 > e) ? max3 : e;

	printf("���� ū ���� %d�Դϴ�.\n", res);

	return 0;
}