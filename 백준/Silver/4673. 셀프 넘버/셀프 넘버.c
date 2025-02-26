#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int list[11000];
	for (int p = 1; p < 10000; p++) {
		int i = p;
		while (i <= 10000) {
			int tmp = 0;
			char strtmp[6];
			sprintf(strtmp, "%d", i);
			int length = strlen(strtmp);
			//printf("변환된문자: %c, 길이:%d\n", strtmp[0], length);
			for (int j = length - 1; j >= 0; j--) {
				//printf("추가숫자:%d\n", strtmp[j]-'0');
				tmp += strtmp[j] - '0';
			}
			tmp += i;
			//printf("%d\n", tmp);
			list[tmp] = 1;
			i = tmp;
		}

	}

	for (int i = 1; i <= 10000; i++) {
		if (list[i] != 1) {
			printf("%d\n", i);
		}
		//printf("%d\n", list[i]);
	}
	//printf("----------------\n");
}