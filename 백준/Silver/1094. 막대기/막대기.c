#include <stdio.h>

int main(void)
{
	int x, makdae=64;
	int sum=0;	//나뉘어진 막대 길이의 합
	int count = 0;
	scanf("%d", &x);

	if (makdae == x) {	//막대길이와 입력이 같으면 1 출력후 종료
		printf("1");
		return 0;
	}

	while (sum != x) {	//sum과 x가 같지 않으면 반복
		makdae = makdae/2;
		if ((sum + makdae) <= x) {
			sum += makdae;
			count++;
		}
	}
	printf("%d", count);

	return 0;
}