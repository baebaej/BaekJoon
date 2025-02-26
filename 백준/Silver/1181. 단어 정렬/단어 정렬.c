#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

char a[20000][51] = {""};
char result[20000][51] = { "" };
char mainresult[20000][51] = { "" };
char* merge(char arr[][51], int gaesoo, int cnt, int i, int j)
{
	if (cnt > gaesoo)
		return 0;

	int rescnt = 0;
	
	//비교하면서 mainresult로 오름차순으로 주입
	while (i < gaesoo && j < gaesoo) {
		int itmp = i+cnt;
		int jtmp = j+cnt;
		while (i < itmp && j < jtmp && i < gaesoo && j < gaesoo) {
			if (strlen(arr[i]) > strlen(arr[j])) {	//왼쪽 단어 길이가 더 긴 경우
				strcpy(mainresult[rescnt++], arr[j++]);
			}
			else if (strlen(arr[i]) == strlen(arr[j])) {	//길이가 같은 경우
				if (strcmp(arr[i], arr[j]) == 0) {	//같은 단어면
					strcpy(mainresult[rescnt++], "");	//하나는 공백넣고
					strcpy(mainresult[rescnt++], arr[i++]);	//하나만 갖고감
					j++;
				}
				else {//같은 단어가 아니면
					if (strcmp(arr[i], arr[j]) > 0) {
						strcpy(mainresult[rescnt++], arr[j++]);
					}
					else
						strcpy(mainresult[rescnt++], arr[i++]);
				}
			}
			else {	//오른쪽 단어 길이가 더 긴 경우
				strcpy(mainresult[rescnt++], arr[i++]);
			}
		}
		//남은 배열 그대로 뒤로 주입 코드
		while (i < itmp && i < gaesoo) {
			strcpy(mainresult[rescnt++], arr[i++]);
		}
		while (j < jtmp && j < gaesoo) {
			strcpy(mainresult[rescnt++], arr[j++]);
		}
		i = i + cnt;
		j = j + cnt;
	}

	if (mainresult[gaesoo - 1][0]=='\0') {	//끝에것 고려
		strcat(mainresult[gaesoo-1], arr[gaesoo - 1]);	//마지막 남은 데이터 결과에 넣어줌
	}

	cnt *= 2;
	i = 0;
	j = cnt;

	memcpy(result, mainresult, sizeof(mainresult));
	merge(result, gaesoo, cnt, i, j);
}


int main(void)
{
	int gaesoo;

	scanf("%d", &gaesoo);	//단어 개수 입력받기
	char* res;

	char tmp[55];
	for (int i = 0; i < gaesoo; i++) {	//단어 입력받아 배열에 저장
		scanf("%s", a[i]);	//tmp에 입력받은거 임시저장 후
	}

	int cnt = 1;
	int i = 0, j = 1;

	res = merge(a, gaesoo, cnt, i, j);

	for (int i = 0; i < gaesoo; i++) {
		if (i == gaesoo - 1) {
			if (mainresult[i][0] != '\0')//공백이 아닌 경우에만 출력
				printf("%s", mainresult[i]);
			break;
		}
		if (mainresult[i][0]!='\0')//공백이 아닌 경우에만 출력
			printf("%s\n", mainresult[i]);
	}

	return 0;
}	