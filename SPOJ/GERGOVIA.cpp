#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
	int n, x;
	long long cost, sum;
	for(;scanf("%d", &n) && n!=0;)
	{
		cost = x = sum = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d", &x);
			sum += x;
			cost += abs((float)sum);
		}
		printf("%lld\n", cost);
	}
}