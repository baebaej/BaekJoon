#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(x, y) (x) < (y) ? (x) : (y)

int isExist(int arr[], int size, int find)
{
	for (int i = 0; i < size; i++) {
		if (arr[i] == find) {
			return 1;
		}
	}
	return 0;
}

int findNearButtonMinus(int arr[], int center, int size)
{
	for (int i = center-1; i >= 0; i--) {	//센터값보다 작은 번호들 순회하면서
		if (!isExist(arr, size, i)) {	//고장난 번호가 아닌 번호 발견시
			return i;	//해당 번호 return
		}
	}
	return -9999;	//모든 번호가 고장난 경우
}

int findNearButtonPlus(int arr[], int center, int size)
{
	for (int i = center + 1; i <=9; i++) {	//센터값보다 큰 번호들 순회하면서
		if (!isExist(arr, size, i)) {	//고장난 번호가 아닌 번호 발견시
			return i;	//해당 번호 return
		}
	}
	return 9999;	//모든 번호가 고장난 경우
}

int findMaxButton(int arr[], int size) {
	for (int i = 9; i >= 0; i--) {	//9번부터 순회하면서
		if (!isExist(arr, size, i)) {	//고장난 번호가 아닌 번호 발견시
			return i;	//해당 번호 return
		}
	}
	return -1;	//모든 번호가 고장난 경우
}

int findMinButton(int arr[],int size) {
	for (int i = 0; i <=9; i++) {	//0번부터 순회하면서
		if (!isExist(arr, size, i)) {	//고장난 번호가 아닌 번호 발견시
			return i;	//해당 번호 return
		}
	}
	return -1;	//모든 번호가 고장난 경우
}

int find(int broken[], char numpad[], int i)
{

}


int main(void)
{
	int n;	//이동하려는 채널
	int m;	//고장난 버튼의 개수
	scanf("%d", &n);
	scanf("%d", &m);
	int* brokenButton = (int*)malloc(sizeof(int) * m);	//고장난 버튼 목록 동적할당
	for (int i = 0; i < m; i++) {	//고장난 버튼 등록
		scanf("%d", &brokenButton[i]);
	}

	int current = 100;	//현재 보고 있는 채널 번호
	

	//+,-버튼만을 통해 이동하는 횟수 구하기
	int plusminus;
	if (n > current) {	//현재 채널보다 목표 채널이 큰 경우
		plusminus = n - current;
	}
	else if (n < current) {	//현재 채널이 목표 채널보다 큰 경우
		plusminus = current - n;
	}
	else {	//현재 채널이 목표 채널인 경우
		printf("0");
		return 0;	//조작이 필요 없음
	}

	//모든 번호가 고장난 경우
	if (m == 10) {
		printf("%d", plusminus);	//+,-버튼을 통한 이동이 최선값
		return 0;
	}

	//숫자키패드를 통한 가장 근접 번호 찾기
	char nstr[10];	//이동하려는 채널
	sprintf(nstr, "%d", n);	//int인 n(이동하려는 채널)을 문자열로 변환
	char nearNumber[10] = { "" };	//근접 채널 번호 결과값
	int min = 9999999;
	int tmpres=0;
	int status = 0;
	
	for (int i = 0; i < 1000000; i++) {
		int tmp = abs(n - i);	//이동하려는 채널과의 거리
		sprintf(nearNumber, "%d", i);	//현재 번호를 문자열로 바꿔서
		for (int j = 0; j < strlen(nearNumber); j++) {
			if (isExist(brokenButton, m, nearNumber[j]-'0')) {	//고장난 버튼이 하나라도 있으면
				//printf("%d는 고장난 버튼 \n", nearNumber[j]-'0');
				status = 1;
				break;
			}
		}
		if (status == 0 && (tmp < min)) {	//알던 거리보다 작으면
			min = tmp;
			tmpres = i;	//update
		}
		status = 0;
	}
	//printf("tmpres : %d\n", tmpres);
	sprintf(nearNumber, "%d", tmpres);

	//버튼 누른 횟수 세기
	int press = strlen(nearNumber);

	if (atoi(nearNumber) < n) {
		press = press + (n - atoi(nearNumber));
		//printf("press:%d\n", press);

	}
	else {
		press = press + (atoi(nearNumber) - n);
	}

	//printf("plusminus : %d	  nearnumber : %s   press : %d\n", plusminus, nearNumber, press);
	printf("%d", min(plusminus, press));
}