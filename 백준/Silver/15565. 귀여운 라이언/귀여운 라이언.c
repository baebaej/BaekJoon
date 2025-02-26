#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int* lionLoc = (int*)malloc(sizeof(int) * n+1);
	int* doll = (int*)malloc(sizeof(int) * n+1);
	int p = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &doll[i]);
		if (doll[i] == 1) {
			lionLoc[p++] = i;
		}
	}

	//for (int i = 0; i < n; i++) {
	//	printf("%d ", doll[i]);
	//}
	//printf("\n");
	//for (int i = 0; i < p; i++) {
	//	printf("%d ", lionLoc[i]);
	//}
	//printf("\n");

	long min = 1000001;
	p--;
	for (int i = 0; i <= p-(k-1); i++) {
		if ((lionLoc[i + k-1] - lionLoc[i] + 1) < min) {
			//printf("%d %d %d  update\n", lionLoc[i + k - 1], lionLoc[i], lionLoc[i + k - 1] - lionLoc[i] + 1);
			min = lionLoc[i + k-1] - lionLoc[i] + 1;
		}
	}

	if (min == 1000001) {
		printf("-1");

	}
	else
		printf("%ld", min);
}