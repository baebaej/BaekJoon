#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findMonth(char find[])
{
	if (strcmp(find, "January")==0)
		return 1;
	else if (strcmp(find, "February")==0)
		return 2;
	else if (strcmp(find, "March")==0)
		return 3;
	else if (strcmp(find, "April")==0)
		return 4;
	else if (strcmp(find, "May")==0)
		return 5;
	else if (strcmp(find, "June")==0)
		return 6;
	else if (strcmp(find, "July")==0)
		return 7;
	else if (strcmp(find, "August")==0)
		return 8;
	else if (strcmp(find, "September")==0)
		return 9;
	else if (strcmp(find, "October")==0)
		return 10;
	else if (strcmp(find, "November")==0)
		return 11;
	else if (strcmp(find, "December")==0)
		return 12;
}

int main(void)
{
	char month_str[15];
	int month;
	int day;
	int year;
	char time[10];
	int time_H;
	int time_M;

	char inputdate[100];
	scanf("%[^\n]s", inputdate);

	for (int i = 0; i < 100; i++) {
		if (inputdate[i] == ',') {
			inputdate[i] = ' ';
		}
	}

	//printf("%s\n", inputdate);

	char* result;
	result = strtok(inputdate, " ");
	int i = 0;
	while (result != NULL) {
		//printf("반복문\n");
		if (i == 0) {
			strcpy(month_str, result);
		}
		else if (i == 1) {
			day = atoi(result);
		}
		else if (i == 2) {
			year = atoi(result);
		}
		else if (i == 3) {
			strcpy(time, result);
		}
		i++;
		result = strtok(NULL, " ");
	}
	month=findMonth(month_str);

	result = strtok(time, ":");
	i = 0;
	while (result != NULL) {
		if (i == 0) {
			time_H = atoi(result);
		}
		else if (i == 1) {
			time_M = atoi(result);
		}
		i++;
		result = strtok(NULL, ":");
	}
	//printf("월 : %d  일 : %d  년:%d  시간: %d : %d\n", month, day, year, time_H, time_M);

	//날짜 쪼개기 완료


	int isNormalYear=1;	//평년이면 1, 윤년이면 0
	//윤년 검사
	if (year % 400==0) {
		isNormalYear = 0;
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		isNormalYear = 0;
	}

	int monthSetNormal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int monthSetLeap[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int* monthSet;
	if (isNormalYear) {	//평년이면
		//printf("평년입니다.\n");
		monthSet = monthSetNormal;
	}
	else {	//윤년이면
		//printf("윤년입니다.\n");
		monthSet = monthSetLeap;
	}

	double amountTime = 0.0;	//1년 총 시간
	for (i = 0; i < 12; i++) {
		amountTime += (monthSet[i] * 24 * 60);
	}

	double amountTimeToday = 0.0;	//입력받은 날까지의 시간
	for (i = 0; i < month-1; i++) {
		amountTimeToday += (monthSet[i] * 24 * 60);	//직전 달까지의 시간을 더하고
	}
	amountTimeToday += ((day - 1)*24*60);	//직전일까지의 시간을 더한뒤
	amountTimeToday += (time_H * 60);	//당일의 시간을 분으로 계산하여 더하고
	amountTimeToday += (time_M);	//분을 더한다.

	//printf("%f  %f\n", amountTime, amountTimeToday);

	long double res = (long double)amountTimeToday / amountTime * 100.0;
	printf("%.20Lf", res);

}