#include <stdio.h>

int main(void)
{
	char a[1000000] = { 0 };
	scanf("%s", a);

	int alpha[26] = { 0 };
	//대문자 검사
	for (int i = 65; i < 91; i++)
	{
		char asci;
		asci = i;
		for (int k = 0; k < 1000000; k++) {
			if (a[k] == 0)
				break;
			if (a[k] == asci)
				alpha[i - 65]++;
		}
	}
	//소문자 검사
	for (int i = 97; i < 123; i++)
	{
		char asci;
		asci = i;
		for (int k = 0; k < 1000000; k++) {
			if (a[k] == 0)
				break;
			if (a[k] == asci)
				alpha[i - 97]++;
		}

	}
	/*
	for (int i = 65; i < 91; i++)
	{
		printf("%c : %d\n", i, alpha[i - 65]);
	}
	*/

	int max_alpha = 0;
	int max_alpha_count = 0;
	for (int i = 0; i < 26; i++) {
		//printf("i : %d, max_alpha: %d, max_alpha_count: %d\n", i, max_alpha, max_alpha_count);
		if (max_alpha_count < alpha[i]) {
			max_alpha = i;
			max_alpha_count = alpha[i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (max_alpha_count == alpha[i])
			cnt++;
		if (cnt >= 2)
			break;
	}

	if (cnt>=2)
		printf("?");
	else {
		printf("%c", max_alpha + 65);
	}
	return 0;
}