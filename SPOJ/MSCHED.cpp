#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int n;
pair<int,int> cow[10005];
bool spots[10005];

bool bigger(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first;
}

void Greedy()
{
	long long gallons = 0;
	sort(cow, cow + n, bigger);
	for(int i=0;i<n;i++)
		for(int j=cow[i].second;j>0;j--)
			if(!spots[j])
			{
				spots[j] = true,gallons += cow[i].first;
				break;
			}
	printf("%lld",gallons);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&cow[i].first,&cow[i].second);
	Greedy();
}