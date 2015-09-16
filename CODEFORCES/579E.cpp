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

int n, a[200009];


double f(double x)
{
    double g_mx = -100000000000, l_mx = 0, l_mn = 0;
    rep(i,n)
    {
    	double q = a[i] - x, p1 = l_mx + q, p2 = l_mn + q;
    	l_mx = max(q, p1), l_mn = min(q, p2);
        g_mx = max(g_mx, max(fabs(l_mn), fabs(l_mx)));
    }
    return g_mx;
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	double l = -100000.0, r = 100000.0, m1, m2;
	rep(i, 250)
	{
		m1 = l + (r - l) / 3.0;
		m2 = r - (r - l) / 3.0;
		if(f(m1) > f(m2)) l = m1;
		else r = m2;
	}
	printf("%.12lf\n", f(m1));
	return 0;
}