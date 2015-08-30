#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n,m,k,a[100];

bool larger(int a, int b)
{
	return a > b;
}

void Greedy()
{
	sort(a, a + n, larger);
	int filters = 0, sockets = k;
	for(int i = 0; i<n; i++)
	{
		if(sockets >= m)
		{
			printf("%d", filters);
			return;
		}
		sockets += a[i] - 1;
		filters++;
	}

	if(sockets >= m) printf("%d",filters);
	else printf("-1");
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	Greedy();
}