#include <stdio.h>
#include <stdlib.h>

void find(int lotto[], int size, int s[], int k, int pointer)
{
	//printf("함수 시작\n");


	if (size >=6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", lotto[i]);
		}
		printf("\n");
		return;
	}
	for (int i = pointer; i < k; i++) {
		//printf("k:%d i:%d\n", k, i);
		lotto[size] = s[i];
		find(lotto, size+1, s, k, i+1);
	}
}

int main(void)
{
	int k;
	scanf("%d", &k);
	if (k == 0)
		return;
	//printf("k:%d\n", k);
	//while (getchar() != '\n');

	int* s = (int*)malloc(sizeof(int) * k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &s[i]);
	}

	//for (int i = 0; i < k; i++) {
	//	printf("%d ", s[i]);
	//}

	int lotto[15];
	for (int i = 0; i < 15; i++) {
		lotto[i] = 99999;
	}
	find(lotto, 0, s, k, 0);
	printf("\n");
	main();
}