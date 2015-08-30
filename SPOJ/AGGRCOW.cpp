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

#define rep(i,N) for(int i=0;i<N;i++)
#define memclr(ARRAY) memset(ARRAY,0,sizeof(ARRAY))
#define MAXPRIME 1000000007
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745

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
int t,n,c,location[100005];
int main()
{
	scanf("%d",&t);
	rep(i,t)
	{
		scanf("%d %d",&n,&c);
		rep(j,n) scanf("%d",&location[j]);
		sort(location, location + n);
		int ub = 2000000000, lb = 0, mid, count, last;
		rep(j, 35)
		{
			mid = (ub - lb) / 2 + lb, count = 0, last = -1000000000;
			rep(k, n)
			{
				if(location[k] - last >= mid)
				{
					count ++;
					last = location[k];
				}
			}
			if(count >= c) lb = mid;
			else ub = mid;
		}
		printf("%d\n", mid);
	}
	return 0;
}