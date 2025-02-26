#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int h, w;
	scanf("%d %d", &h, &w);
	int* block = (int*)malloc(sizeof(int) * w);
	for (int i = 0; i < w; i++) {
		int tmp;
		scanf("%d", &tmp);
		block[i] = tmp;
	}

	//공간 생성 후 0으로 초기화
	int** space = (int**)malloc(sizeof(int*) * h);
	for (int i = 0; i < h; i++) {
		space[i] = (int*)malloc(sizeof(int) * w);
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			space[i][j] = 0;
		}
	}

	//block을 순회하면서 값만큼 블록을 쌓는다.
	for (int i = 0; i < w; i++) {
		if (block[i] !=0) {
			for (int j = h-1; j >= h-block[i]; j--) {
				space[j][i] = 1;
			}
		}
	}

	////쌓은 결과 출력
	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		printf("%d ", space[i][j]);
	//	}
	//	printf("\n");
	//}

	int res = 0;	//결과
	int status = 0;	//양쪽이 블록으로 막힌 구간인지 확인하는 상태 변수
	int tmp = 0;	//블록 사이 빈 공간을 임시로 카운트

	//int line = 0;

	//공간을 가로 방향으로 순회해나감
	for (int i = 0; i < h; i++) {	
		for (int j = 0; j < w; j++) {
			if (space[i][j] == 0)	//빈 공간을 일단 카운트
				tmp++;
			if (space[i][j] == 1)	//블록이 쌓여있으면 상태 변수 증가
			{
				if (status == 0) {
					tmp = 0;
				}
				status++;
			}

			if (status == 2 && tmp == 0) {	//양쪽이 블록으로 쌓여있지만 사이에 빈공간이 없으면 한 블록은 버린다.
				status--;
				continue;
			}
			if (status == 2) {	//양쪽이 블록으로 쌓여있으면서 빈공간이 사이에 있으면 결과에 더함
				res += tmp;
				//line = tmp;
				tmp = 0;
				status = 1;
			}

		}
		status = 0;
		tmp = 0;
		//printf("line%d : %d\n", i, line);
		//line = 0;
	}

	printf("%d\n", res);
}