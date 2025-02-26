#include <stdio.h>

int main(void)
{
	int t, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum);
	}
}