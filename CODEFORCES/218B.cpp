#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,seats[2000];

long long  minimum()
{
	int tmp = n;
	long long cost = 0;
	sort(seats, seats + m);

	for(int i=0;i<m && tmp > 0;i++)
	{
		if(seats[i] < tmp)
		{
			cost += (seats[i] * (seats[i] + 1)) / 2;
			tmp -= seats[i];
		}
		else
		{
			cost += ((seats[i] * (seats[i] + 1)) / 2) - 
					(((seats[i] - tmp) * (seats[i] - tmp + 1)) / 2);
			tmp = 0;
		}
	}

	return cost;
}

long long maximum()
{
	int mx = 0;
	long long cost = 0;
	for(;n > 0;n--)
	{
		for(int i=0;i<m;i++)
			mx = seats[mx] < seats[i]?i:mx;
		cost += seats[mx];
		seats[mx]--;
		mx = -1;
	}
	return cost;
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&seats[i]);
	printf("%I64d %I64d",maximum(),minimum());
}