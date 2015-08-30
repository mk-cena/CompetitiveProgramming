#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

long long n,m,closed,bclosed;
int fcaps[1005],fmarkers[1005];
map<pair<int,int>,int> bmatch;

int main()
{
	pair<int,int> tmp;
	closed = 0, bclosed = 0;
	scanf("%I64d %I64d",&n,&m);

	for(long long i=0;i<n;i++)
	{
		scanf("%d %d",&tmp.first,&tmp.second);
		fmarkers[tmp.second]++;
		bmatch[tmp]++;
	}

	for(long long i=0;i<m;i++)
	{
		scanf("%d %d",&tmp.first,&tmp.second);
		fcaps[tmp.second]++;
		if(bmatch[tmp] > 0)
		{
			bmatch[tmp]--;
			bclosed++;
		}
	}

	for(int i=0;i<1005;i++)
		closed += min(fcaps[i],fmarkers[i]);

	printf("%I64d %I64d",closed,bclosed);
}