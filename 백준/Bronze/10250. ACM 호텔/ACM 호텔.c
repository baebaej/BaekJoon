#include <stdio.h>

int main(void)
{
	int t, h, w, n;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		int quotient, remainder;
		quotient = n / h;
		remainder = n % h;
		if (remainder == 0) {	//나머지가 0인 경우
			printf("%d%02d\n", h, quotient);
		}
		else {
			printf("%d%02d\n", remainder, quotient + 1);
		}
	}
}