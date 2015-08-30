#include <algorithm>
#include <stdio.h>

using namespace std;

int mornings[101], afternoons[101], d, r, n;

bool greater(int a, int b)
{
	return a > b;
}

unsigned long long Greedy()
{
	sort(mornings, mornings + n);
	sort(afternoons, afternoons + n, greater);
	unsigned long long overcost = 0;
	for(int i=0,overtime;i<n;i++)
		if((overtime = afternoons[i] + mornings[i]) > d)
			overcost += ((overtime - d) * r);
	return overcost;
}

int main()
{
	while(true)
	{
		scanf("%d %d %d",&n,&d,&r);
		if((n | d | r) == 0)
			return 0;
		for(int i=0;i<n;i++)
			scanf("%d",&mornings[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&afternoons[i]);

		printf("%llu\n",Greedy());
	}
}