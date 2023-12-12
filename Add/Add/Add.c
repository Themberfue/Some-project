#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n, m;
	scanf_s("%d %d", &m, &n);

	int sum = m + n;
	printf("sum = %d", sum);

	return 0;
}