#include <stdio.h>
#include <stdlib.h>


int cnt = 2;
int isAdjst(int** banner, int m, int n, int loc1, int loc2, int status) {
	//printf("%d %d 탐색\n", loc1, loc2);
	int tmp = 0;
	for (int i = loc1-1; i <= loc1+1; i++) {
		if (i < 0)
			i = 0;
		if (i >= n) {
			break;
		}
		for (int j = loc2 - 1; j <= loc2+1; j++) {
			//printf("%d %d\n", i, j);
			if (j < 0)
				j = 0;
			if (j >= m)
				break;
			if (banner[i][j] == 1) {
				banner[i][j] = cnt;
				isAdjst(banner, m, n, i, j, 1);
			}
		}
	}

}

int main(void)
{
	int m, n;
	scanf("%d %d", &n, &m);

	int** banner = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		banner[i] = (int*)malloc(sizeof(int) * m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &banner[i][j]);
		}
	}

	//현수막 출력
	//printf("현수막\n");
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%d ", banner[i][j]);
	//	}
	//	printf("\n");
	//}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (banner[i][j] == 1) {
				//printf("%d %d 에서 1발견\n", i, j);
				isAdjst(banner, m, n, i, j, 0);
				cnt++;
				}
			}
		}


	//현수막 출력
	//printf("현수막\n");
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		printf("%d ", banner[i][j]);
	//	}
	//	printf("\n");
	//}

	printf("%d", cnt-2);
}