#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	int n = 0;

	scanf("%d", &n);


	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		char nStr[10];
		sprintf(nStr, "%d", i);
		
		
		if (i < 100) {
			cnt++;
			continue;
		}
		int isNotHan = 0;
		int gap = ((nStr[1] - 48) - (nStr[0] - 48));
		for (int j = 2; j < strlen(nStr); j++) {
			if (gap != ((nStr[j] - 48) - (nStr[j - 1] - 48))) {
				//printf("%d는 한수가 아님\n", i);
				isNotHan = 1; //한수가 아님으로 플래그
				break;
			}
			gap = ((nStr[j] - 48) - (nStr[j - 1] - 48));
		}
		if (!isNotHan) { //한수이면 카운트 증가
			cnt++;
		}
	}

	printf("%d\n", cnt);
}