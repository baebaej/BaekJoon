#include <stdio.h>

int main(void)
{
	int N ;
	scanf("%d", &N);
	int seat[100] = { 0 };
	int cnt = 0;
	int buf=0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &buf);
		buf--;
		if (seat[buf] == 0)
			seat[buf] = 1;
		else if(seat[buf]==1)
			cnt++;
	}

	printf("%d", cnt);

	return 0;
}