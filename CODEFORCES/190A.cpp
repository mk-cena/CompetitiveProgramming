#include <stdio.h>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	int m,n;
	scanf("%d %d", &n, &m);
	if(n == 0 && m == 0)
		printf("0 0");
	else
		if(n == 0)
			printf("Impossible");
		else
			if(m >= n)
				printf("%d %d", ((m / n) * n) + (m % n), m + n -1);
			else
				printf("%d %d", n, max(m + n - 1, n));
}