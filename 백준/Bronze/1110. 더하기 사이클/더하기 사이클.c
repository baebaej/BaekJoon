#include <stdio.h>
#include <string.h>

int main(void)
{
	char N[10];
	scanf("%s", &N);

	char stn[10] ;
	if (atoi(N) < 10) {
		strcpy(stn, "0");
		strcat(stn, N);
	}
	else {
		strcpy(stn, N);
	}
	char original[10];
	strcpy(original, stn);

	int combined=0;
	char newnum[10] = { "" };
	int cnt = 0;
	while (1) {
		char first[5] = { stn[0] }, second[5] = { stn[1] };
		combined = atoi(first) + atoi(second);
		strcpy(first, second);
		char combined_str[10];
		sprintf(combined_str,"%d", combined);
		
		if (combined >= 10)
			sprintf(second, "%c", combined_str[1]);
		else
			sprintf(second, "%d", combined);
		strcpy(stn, first);
		strcat(stn, second);
		if (strcmp(stn, original) == 0)
			break;
		cnt++;

	}
	printf("%d", cnt+1);

	return 0;
}