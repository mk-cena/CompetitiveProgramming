#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int t, na, nb, atrains, btrains;
vector<pair <int, int> > atrips, btrips;

bool smaller(pair<int, int> l, pair<int, int> m)
{
	// return l.second < m.second; 
									/* 	
										1
										0
										2 2
										
										01:00 04:00
										02:00 05:00

										04:00 07:00
										05:00 06:00
									*/
	return l.first < m.first;
}

void navigate(int end, bool a)
{
	int tmp = end;
	if(a)
	{
		for(int i=0;i<btrips.size();i++)
			if(end <= btrips[i].first)
			{
				tmp = btrips[i].second;
				btrips.erase(btrips.begin() + i);
				break;
			}
	}
	else
	{
		for(int i=0;i<atrips.size();i++)
			if(end <= atrips[i].first)
			{
				tmp = atrips[i].second;
				atrips.erase(atrips.begin() + i);
				break;
			}
	}
	if(end != tmp)
		navigate(tmp,!a);
}

void Greedy()
{
	atrains = btrains = 0;
	sort(atrips.begin(), atrips.end(), smaller);
	sort(btrips.begin(), btrips.end(), smaller);

	while(atrips.size() > 0 || btrips.size() > 0)
	{
		if(atrips.size() > 0 && (btrips.size() == 0 || smaller(atrips[0], btrips[0])))
		{
			atrains++;
			int end = atrips[0].second;
			atrips.erase(atrips.begin());
			navigate(end, true);
		}
		else
		{
			if(btrips.size() > 0)
			{
				btrains++;
				int end = btrips[0].second;
				btrips.erase(btrips.begin());
				navigate(end, false);
			}
		}
	}
}

int main()
{
	int cases;
	scanf("%d",&cases);
	for(int i=1;i<=cases;i++)
	{
		scanf("%d\n%d %d",&t,&na,&nb);
		for(int j=0,startm,starth,endm,endh;j<na;j++)
		{
			scanf("%d:%d %d:%d",&starth,&startm,&endh,&endm);
			pair<int, int>a;
			a.first = starth * 60 + startm;
			a.second = endh * 60 + endm + t;
			atrips.push_back(a);
		}
		for(int j=0,startm,starth,endm,endh;j<nb;j++)
		{
			scanf("%d:%d %d:%d",&starth,&startm,&endh,&endm);
			pair<int, int>b;
			b.first = starth * 60 + startm;
			b.second = endh * 60 + endm + t;
			btrips.push_back(b);
		}
		Greedy();
		printf("Case #%d: %d %d\n", i, atrains, btrains);
	}
}