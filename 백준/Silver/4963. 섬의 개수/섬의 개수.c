#include <stdio.h>
#include <stdlib.h>

void printMap(int w, int h, int** map) {	//지도 상태 출력하는 함수
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int count = 2;
void findIsland(int w, int h, int**map, int myLocation_w, int myLocation_h)
{
	//myLocation 주변 9개 블럭을 순차적으로 돌면서 붙어있는 곳 중 가지않은 곳을 찾는다
	for (int i = myLocation_h-1; i <= myLocation_h+1; i++) {
		//범위 초과 방지
		if (i < 0)
			i = 0;
		if (i >= h)
			break;
		for (int j = myLocation_w-1; j <= myLocation_w+1; j++) {
			//범위 초과 방지
			if (j < 0)
				j = 0;
			if (j >= w)
				break;
			//printf("%d %d : %d\n", i, j);
			if (map[i][j] == 1) {	//붙어있으면서 가지않은 곳이 있으면
				map[i][j] = count;	//해당 위치 값을 바꾸고
				findIsland(w, h, map, j, i);	//그 위치에서 재탐색
			}
		}
	}
}

int main(void)
{
	int w, h;
	scanf("%d %d", &w, &h);
	if (w == 0 && h==0) {	//입력이 0이면 종료
		return 0;
	}
	
	int** map = (int**)malloc(sizeof(int*) * h);
	for (int i = 0; i < h; i++) {
		map[i] = (int*)malloc(sizeof(int) * w);
	}
	//지도 입력받기
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &map[i][j]);
		}
		while (getchar() != '\n');
	}

	////지도출력
	//printf("\n");
	//printMap(w, h, map);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) {	//붙어있으면서 가지않은 곳이 있으면
				findIsland(w, h, map, j, i);	//그 위치에서 재탐색
				count++;
			}
		}
	}

	////지도출력
	//printMap(w, h, map);

	printf("%d\n", count - 2);

	//동적할당 해제 및 count 값 초기화
	for (int i = 0; i < h; i++) {
		free(map[i]);
	}
	free(map);
	count = 2;

	//반복
	main();
}