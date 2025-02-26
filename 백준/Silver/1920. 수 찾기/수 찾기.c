#include <stdio.h>
#include <stdlib.h>

int isExist(long N_numbers[], long key, int low, int high)
{
	int middle;
	while (low <= high) {
		middle = (low + high) / 2;
		if (key == N_numbers[middle])
			return 1;	//탐색 성공
		else if (key > N_numbers[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return 0;	//탐색 실패
}

int static compare(const void* first, const void* second)
{
	if (*(long*)first > *(long*)second)
		return 1;
	else if (*(long*)first < *(long*)second)
		return -1;
	else
		return 0;
}


int main(void)
{
	int n, m;
	scanf("%d", &n);
	long* N_numbers = (long*)malloc(sizeof(long) * n);
	for (int i = 0; i < n; i++) {
		scanf("%ld", &N_numbers[i]);
	}
	qsort(N_numbers, n, sizeof(long), compare);	//퀵소트로 정렬

	//for (int i = 0; i < n; i++) {
	//	printf("%ld ", N_numbers[i]);
	//}
	//printf("\n");

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		long tmp;
		scanf("%ld", &tmp);
		if (isExist(N_numbers, tmp, 0, n-1)) {
			printf("1\n");
		}
		else
			printf("0\n");
	}

	
}