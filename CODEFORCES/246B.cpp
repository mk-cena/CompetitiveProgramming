#include <iostream>
#include <stdio.h>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int n, array[100005], avg = 0, rem = 0;

void Greedy()
{
	avg /= n;
	for(int i =0;i<n;i++)
		rem += array[i] - avg;
	printf("%d", rem == 0? n:n-1);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		avg += array[i];
	}
	Greedy();
}