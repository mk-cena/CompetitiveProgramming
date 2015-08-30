#include <stdio.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int k;
long long n,day[55];
vector<int> backtrack;

int Greedy()
{
	for(int i=k-1;i>=0 && n >= 0;i--)
		if(day[i] <= n)
		{ 
			backtrack.push_back(i + 1);
			n-=day[i];
		}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		backtrack.clear();
		day[-1] = 0;
		scanf("%lli %d",&n,&k);
		for(int i=0,coef;i<k;i++)
		{
			scanf("%d",&coef);
			day[i] = coef + (day[i-1] * 2);
		}

		Greedy();
		if(n != 0) printf("-1");
		for(int i=backtrack.size()-1;n == 0 && i>=0 ;i--)
			printf("%d ", backtrack[i]);
		printf("\n");
	}
}