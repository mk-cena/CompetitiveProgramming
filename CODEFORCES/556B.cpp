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
	int n, g;
	scanf("%d",&n);
	scanf("%d",&g);
	int turns = (n - g) % n;
	for(int i=1;i<n;i++)
	{ 
		scanf("%d", &g);
		if(i & 1)
		{
			if(mod(g - turns, n) != i)
			{
				printf("No\n");
				return 0;
			}
		}
		else
		{
			if((g + turns) % n != i)
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}