#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isSqrt(double n)
{
	double tmp = sqrt(n);
	if (tmp - (int)tmp == 0) {	//제곱수인 경우
		return 1;
	}
	else
		return 0;
}


int SearchCount(int x, int y, int currLoc, int lastDist, int count)
{

	int n = y - x;
	for (int i = n; i <= n; i++) {
		if (isSqrt(i)) {	//제곱수인 경우
			//printf("%d\t제곱수입니다.\n", i);
			printf("%d\n", (int)sqrt(i) * 2 - 1);
		}
		else {	//제곱수가 아닌 경우
			int mid = (int)sqrt(i) * (int)sqrt(i) + (int)sqrt(i);
			//printf("중간수는 %d\n", mid);
			if (i <= mid) {	//중간수보다 작은 경우
				printf("%d\n", (int)sqrt(i) * 2);
			}
			else {	//중간수보다 큰 경우
				printf("%d\n", (int)sqrt(i) * 2 + 1);
			}
		}
	}


}

int main(void)
{
	int T; //테스트 케이스의 개수

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int x, y;	//현재 위치 x, 목표 위치 y
		scanf("%d %d", &x, &y);
		int lastDist = 0;	//직전 이동 거리
		int count = 0;	//이동 횟수
		int result = SearchCount(x, y, x, lastDist, count);
	}
}