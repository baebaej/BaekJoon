#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct OrbitInfo {
	int cx, cy;	//행성계의 중점
	int r; //반지름
	int p1, p2;	//점이 이 행성계 안에 있는지 나타내는 플래그
}OrbitInfo;

void isLocatedInOrbit(OrbitInfo* a, int x, int y, int p) {

	int dist = (x - a->cx) * (x - a->cx) + (y - a->cy) * (y - a->cy);
	//printf("dist:%d\n", dist);
	if (dist < (a->r*a->r)) {
		if (p == 1)
			a->p1 = 1;
		else
			a->p2 = 1;
	}
}

int main(void)
{
	int T; //테스트 케이스의 개수
	int x1, y1, x2, y2; //출발점과 도착점의 좌표
	int n;	//행성계의 개수



	scanf("%d", &T);

	for (int loop = 0; loop < T; loop++) {
		//printf("%dloop\n", loop);
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		OrbitInfo* arr = (OrbitInfo*)malloc(sizeof(OrbitInfo) * n); //행성계 정보 배열

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &arr[i].cx, &arr[i].cy, &arr[i].r);
			arr[i].p1 = 0;
			arr[i].p2 = 0;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			isLocatedInOrbit(&arr[i], x1, y1, 1);
			isLocatedInOrbit(&arr[i], x2, y2, 2);
		}


		//for (int i = 0; i < n; i++) {
		//	printf("%d ", arr[i].p1);
		//}
		//printf("\n");
		//for (int i = 0; i < n; i++) {
		//	printf("%d ", arr[i].p2);
		//}

		for (int i = 0; i < n; i++) {
			if (arr[i].p1 ^ arr[i].p2) {
				cnt++;
				//printf("다름\n");
			}
		}
		printf("%d\n", cnt);
	}
}