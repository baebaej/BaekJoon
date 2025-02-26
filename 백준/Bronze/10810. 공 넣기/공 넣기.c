#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int* basket = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {	//배열 0으로 초기화
		basket[i] = 0;
	}
	for (int p = 0; p < m; p++) {	
		int i, j, k;
		scanf("%d %d %d", &i, &j, &k);
		for (int loc = i-1; loc < j; loc++) { //공 넣기 수행
			basket[loc] = k;
		}
	}

	for (int i = 0; i < n; i++) {	//basket 출력
		printf("%d ", basket[i]);
	}
}