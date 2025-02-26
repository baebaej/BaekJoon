#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}coordinate;

int compare(const void*first, const void *second) {
	coordinate A = *(coordinate*)first;
	coordinate B = *(coordinate*)second;

	if (A.x > B.x) {	//x좌표 먼저 비교해서 앞쪽 x가 더 크면 swap
		return 1;
	}
	else if (A.x == B.x) {	//앞뒤 x가 같으면 
		if (A.y > B.y) {	//y값을 비교한다
			return 1;
		}
		else
			return -1;
	}
	return -1;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	coordinate* c = (coordinate*)malloc(sizeof(coordinate) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &(c[i].x), &(c[i].y));
	}

	qsort(c, n, sizeof(coordinate), compare);


	for (int i = 0; i < n; i++) {
		printf("%d %d\n", c[i].x, c[i].y);
	}

}