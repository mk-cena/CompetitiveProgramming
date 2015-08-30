#include <algorithm>
#include <stdio.h>
#include <iostream>

using namespace std;

int n,counter;
pair <int,int> pairs[2000];

bool custom(pair<int,int> a, pair<int,int>b)
{
	return a.second == b.second ? a.first > b.first : a.second > b.second;
}

void Greedy()
{
	long long points = 0;
	sort(pairs, pairs+n, custom);
	for(int i=0;i<n && counter > 0;i++)
	{
		counter--;
		points += pairs[i].first;
		counter += pairs[i].second;
	}
	printf("%I64d",points);
}

int main()
{
	counter = 1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&pairs[i].first,&pairs[i].second);
	Greedy();
}