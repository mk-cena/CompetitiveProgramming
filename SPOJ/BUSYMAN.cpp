#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

pair<long long, long long> intervals[100001];
int n;

bool compare(const pair<long long, long long> &a, const pair<long long, long long> &b)
{
	return a.second < b.second;
}

int Greedy()
{
	long long last = intervals[0].second;
	int activities = 1;
	for(int i=1;i<n;i++)
		if(intervals[i].first >= last)
		{
			last=intervals[i].second;
			activities++;
		}
	return activities;
}

int main()
{
	int cases;
	scanf("%d",&cases);
	for(int c=0;c<cases;c++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lli %lli",&intervals[i].first,&intervals[i].second);
		}
		sort(intervals, intervals + n, compare);
		printf("%d\n",Greedy());
	}

}