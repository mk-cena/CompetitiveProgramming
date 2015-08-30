#include <iostream>
#include <cmath>

using namespace std;

int n,k;
char c[20001];

long long Greedy()
{
	c[n] = '0';
	bool flag = false;
	long long count = 0, lcount = 1;
	for(int i=1;i<=n;i++)
	{
		if(c[i] == c[i-1])
			lcount++;
		else
		{
			if(lcount >= k) flag = true;
			count += ceil((float)lcount/k);
			lcount = 1;
		}
	}
	if(!flag) count = -1;
	return count;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d %d\n%s",&n, &k,c);
		printf("%lli\n",Greedy());
	}
}