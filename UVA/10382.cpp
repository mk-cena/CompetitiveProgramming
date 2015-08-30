#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int n,l,w;
vector <pair <double, double> > intervals;

bool smaller(pair <double, double> a, pair <double, double> b)
{
	return a.first < b.first;
}

void Greedy()
{
	sort(intervals.begin(), intervals.end(), smaller);
	double end = 0, tmp=-1;
	int count = 0;
	for(int i=0;i>=0 && i<intervals.size();i++)
	{
		if(intervals[i].first <= end)
			tmp = max(tmp, intervals[i].second);
		else
		{
			if(end == tmp) break;
			end = tmp;
			i--;
			count++;
			if(end >= l)
			{
				printf("%d\n",count);
				return;
			}
		}
	}
	printf("-1\n");
}

int main()
{
	double r,x;
	pair<int, int> temp;
	while(cin >> n >> l >> w)
	{
		intervals.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x,&r);
			double range = sqrt((r * r) - (w * w / 4.0));
			temp.first = x - range;
			temp.second = x + range;
			intervals.push_back(temp);
		}
		temp.first = (double)INT_MAX;
		temp.second = (double)INT_MAX;
		intervals.push_back(temp);
		Greedy();
	}
}