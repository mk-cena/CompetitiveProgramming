#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <set>
#include <fstream>
#include <limits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i,N) for(int i=0;i<N;i++)
#define MAXPRIME 1000000007

bool compare(int a, int b)
{
	return a > b;
}

class Compare
{
	public:
		bool operator()(int a, int b)
		{
			return a > b;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

int main()
{
	int k,v,mirror;
	vector<pair<int, int> > edges;
	scanf("%d",&k);
	mirror = k + 2;
	if(k == 1)
	{
		printf("YES\n");
		printf("2 1\n");
		printf("1 2\n");
		return 0;
	}
	if(k & 1)
	{
		printf("YES\n");
		v = 2 * k + 4;
		edges.push_back(pair<int,int>(1, 1 + mirror));
		edges.push_back(pair<int,int>(k + 1, mirror));
		edges.push_back(pair<int,int>(k + 1 + mirror, k + 2 + mirror));
		for(int i = 2;i<=k;i++)
		{
			edges.push_back(pair<int, int>(1, i));
			edges.push_back(pair<int, int>(1 + mirror, i + mirror));
		}
		for(int i=2;i<=k;i++)
		{
			edges.push_back(pair<int,int>(k + 1, i));
			edges.push_back(pair<int,int>(k + 2, i));

			edges.push_back(pair<int,int>(k + 1 + mirror, i + mirror));
			edges.push_back(pair<int,int>(k + 2 + mirror, i + mirror));
		}
		for(int i=2;i<=k;i++)
			for(int j=i+1+!(i&1);j<=k;j++)
			{
				edges.push_back(pair<int,int>(i, j));
				edges.push_back(pair<int,int>(i + mirror, j + mirror));
			}

		printf("%d %d\n",v,(int)edges.size());
		REP(i, edges.size())
			printf("%d %d\n",edges[i].first, edges[i].second);
	}
	else
		printf("NO\n");
	return 0;
}