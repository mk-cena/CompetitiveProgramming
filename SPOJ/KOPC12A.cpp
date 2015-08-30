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
int height[10001], cost[10001], n, t;
ll f(int h)
{
	ll total_cost = 0;
	rep(i, n) total_cost += abs(h - height[i]) * cost[i];
	return total_cost;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		rep(i, n) scanf("%d", &height[i]);
		rep(i, n) scanf("%d", &cost[i]);
		float r = 10000, l = 0, m1, m2;
		rep(i, 30)
		{
			m1 = l + (r - l) / 3;
			m2 = r - (r - l) / 3;
			if(f(m1) > f(m2)) l = m1;
			if(f(m2) > f(m1)) r = m2;
		}
		printf("%lld\n",f(m1));
	}
	return 0;
}