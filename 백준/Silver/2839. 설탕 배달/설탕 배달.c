#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int bag[2] = { 5,3 };
	int k = 2;
	scanf("%d", &n);
	n++;

	int* kg = (int*)malloc(sizeof(int) * n);	//킬로그램 배열 동적생성
	for (int i = 0; i < n; i++) {	//무한으로 초기화
		kg[i] = 10000;
	}

	kg[0] = 0;
	for (int j = 0; j < n; j++) {	//0kg부터 1kg씩 증가하며 순회
		for (int i = 0; i < k; i++) {	//코인 종류 5, 3 대입하며 비교
			//printf("bag[i]=%d, j=%d\n", bag[i], j);
			//printf("kg[j - bag[i]] + 1) : %d     kg[j] : %d\n", kg[j - bag[i]] + 1, kg[j]);
			if (bag[i] <= j && ((kg[j - bag[i]] + 1) < kg[j])) {	//현재 kg가 bag의 크기(5,3)보다 작으면서 알던 값보다 새 값이 작으면
				//printf("update\n");
				kg[j] = kg[j - bag[i]] + 1;	//update
			}
		}
	}
	
	//for (int i = 0; i < n; i++) {
	//	printf("%d ", kg[i]);

	//}
	if (kg[n - 1] == 10000)
		printf("-1");
	else
		printf("%d ", kg[n-1]);
}