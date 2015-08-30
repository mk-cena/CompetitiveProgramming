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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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
	int n,l,r,x,c[20],cnt = 0, limit = 0;
	scanf("%d %d %d %d",&n,&l,&r,&x);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	sort(c, c+n);
	for(int i=0;i<n;i++)
		limit |= (1 << i);
	for(int i=0;i<=limit;i++)
	{
		bool flag = false;
		int tn = 0, first, last, tc = 0, mask = i, j=0;
		while(mask > 0)
		{
			if(mask & 1)
			{
				tn++;
				tc += c[j];
				if(!flag)
					first = c[j],flag = true;
				last = c[j];
			}
			mask >>= 1;
			j++;
		}
		if(tn >= 2 && tc >= l && tc <= r && last - first >= x)
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}