#include<stdio.h>


int main(void)
{
	/*
	// 1) 5���� ���ڸ� �Է¹޾Ƽ� ���� ū ���� ã�� ���α׷�
	int a, b, c, d, e;
	int max1, max2, max3;
	int res;

	// �Էº�
	printf("�ټ����� ������ �Է� : ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	// ū �� ã�� - ������ 1:1 ��ʸ�Ʈ�� ����.
	max1 = (a > b) ? a : b;						// a �� b�� ���� ū ���� max1�� ����
	max2 = (c > d) ? c : d;						// c �� d�� ���� ū ���� max2�� ���� 
	max3 = (max1 > max2) ? max1 : max2;			// max1 �� max2�� ���� ū ���� max3�� ����
	res = (max3 > e) ? max3 : e;				// max3 �� e�� ���� ������ res�� ����

	printf("���� ū ���� %d�Դϴ�.\n", res);		// res ���
	*/

	// 2) �̸��� ���̸� �Է¹޾� ���
	char name[20];
	int age;

	printf("�̸� : ");
	scanf("%s", name);
	printf("���� : ");
	scanf("%d", &age);

	printf("�̸� : %s, ���� : %d", name, age);

	return 0;
}