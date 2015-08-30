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

#define PI 3.14159265358979323846264338327950
double vs[10010],mx;
int t,n,f,r;

int main()
{
	scanf("%d",&t);
	REP(i,t)
	{
		scanf("%d %d",&n,&f);
		f++,mx=-1.0;
		REP(j,n)
		{
			scanf("%d",&r);
			vs[j] = PI * r * r;
			mx = max(vs[j], mx);
		}

		int count;
		double ub = mx, lb = 0, mid;
		REP(k,1000)
		{
			mid = (ub - lb) / 2.0 + lb;
			count = f;
			REP(j,n) count -= (int)(vs[j]/mid);
			if(count <= 0) lb = mid;
			else ub = mid;
		}

		printf("%.4lf\n",mid);
	}
	return 0;
}