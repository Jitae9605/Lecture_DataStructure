#include<stdio.h>

// 하노이탑 게임
// 규칙	- 한번에 하나의 원반만 옮긴다
//		- 원반은 큰것이 작은것 위에 올라갈수 없다


void HanoiTowerMove(int num, char from, char by, char to)
{
	// num = 원반갯수, from = 원반시작기둥, by = 경유기둥, to = 목표기둥
	
	if (num == 1)											// 원반이 하나면 바로 목표기둥으로 본낸다.
	{
		printf("원반 1을 %c 에서 %c로 이동\n", from, to);
	}

	else													// 원반이 하나가 아닐때
	{
		HanoiTowerMove(num - 1, from, to, by);						// 1단계 - 재귀호출 (원반갯수 1개 줄이고 to와 by를 서로 바꿔서)
		printf("원반%d를(을) %c에서 %c로 이동\n", num, from, to);		// 2단계 - 맨위의 원반을 목표기둥으로
		HanoiTowerMove(num - 1, by, from, to);						// 3단계 - 재귀호출(원반갯수 1개 줄이고 from과 by를 서로 바꿈)

	}
}

int main(void)
{
	// 막대A의 원반 3개를  막대 C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}