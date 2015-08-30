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

int t, n;
double k, pos[100009];

bool satisfy(double total_time)
{
	double previous = pos[0] + total_time, current, diff;
	for(int i = 1;i < n ;i++)
	{
		current = pos[i];
		diff = current - previous;
		if(diff > k)
		{
			diff -= k;
			if(diff > total_time) return false;
			current -= diff;
		}
		else 
		{
			if(diff < 0) 
			{
				current += total_time, diff = current - previous;
				if(diff > k) current += k - diff;
			}
			else current += k - diff;
		}
		previous = current;
	}
	return true;
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf %d", &k, &n);
		rep(i, n) scanf("%lf", &pos[i]);
		double ub = 1000000.0, lb = 0, mid;
		rep(i, 30)
		{
			mid = lb + (ub - lb) / 2;
			if(satisfy(mid)) ub = mid;
			else lb = mid;
		}
		printf("%.6lf\n", mid);
	}
	return 0;
}