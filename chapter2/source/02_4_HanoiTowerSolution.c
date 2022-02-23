#include<stdio.h>

// �ϳ���ž ����
// ��Ģ	- �ѹ��� �ϳ��� ���ݸ� �ű��
//		- ������ ū���� ������ ���� �ö󰥼� ����


void HanoiTowerMove(int num, char from, char by, char to)
{
	// num = ���ݰ���, from = ���ݽ��۱��, by = �������, to = ��ǥ���
	
	if (num == 1)											// ������ �ϳ��� �ٷ� ��ǥ������� ������.
	{
		printf("���� 1�� %c ���� %c�� �̵�\n", from, to);
	}

	else													// ������ �ϳ��� �ƴҶ�
	{
		HanoiTowerMove(num - 1, from, to, by);						// 1�ܰ� - ���ȣ�� (���ݰ��� 1�� ���̰� to�� by�� ���� �ٲ㼭)
		printf("����%d��(��) %c���� %c�� �̵�\n", num, from, to);		// 2�ܰ� - ������ ������ ��ǥ�������
		HanoiTowerMove(num - 1, by, from, to);						// 3�ܰ� - ���ȣ��(���ݰ��� 1�� ���̰� from�� by�� ���� �ٲ�)

	}
}

int main(void)
{
	// ����A�� ���� 3����  ���� C�� �ű��
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}