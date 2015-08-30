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
int n, x[101], y[101];
double f(double rad)
{
	double mn_x = 1000000, mn_y = 1000000, mx_x = -1000000, mx_y = -1000000, x_rot, y_rot;
	rep(i, n)
	{
		x_rot = x[i] * cos(rad) - y[i] * sin(rad);
		y_rot = x[i] * sin(rad) + y[i] * cos(rad);
		mx_x = max(mx_x, x_rot);
		mx_y = max(mx_y, y_rot);

		mn_x = min(mn_x, x_rot);
		mn_y = min(mn_y, y_rot);
	}
	return fabs(mx_x - mn_x) + fabs(mx_y - mn_y);
}
int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d %d", &x[i], &y[i]);
	double l = 0, r = PI, m1, m2;

	rep(i, 100)
	{
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(f(m1) > f(m2)) l = m1;
		else r = m2;
	} 
	printf("%.10lf ",f(m1));

	l = 0, r = PI, m1, m2;
	rep(i, 100)
	{
		m1 = l + (r - l) / 3;
		m2 = r - (r - l) / 3;
		if(f(m1) > f(m2)) r = m2;
		else l = m1;
	} 
	printf("%.10lf\n",f(m1));

	return 0;
}