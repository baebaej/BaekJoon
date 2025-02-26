#include <stdio.h>
#include <string.h>
int main(void)
{
	int N;
	scanf("%d", &N);
	char name[100][500];
	
	for (int i = 0; i < N; i++) {
		scanf("%s",name[i]);
	}
	int len = strlen(name[0]);
	int stop[100] = { 0 };
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < N; j++) {
			if (name[0][i] != name[j][i]) {
				stop[i] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		if (stop[i]==1)
			printf("?");
		else
			printf("%c", name[0][i]);
	}

	return 0;
}