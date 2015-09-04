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

int t, n, s[3000], a[3000], h[3000], c;
double sin_alpha[3000];

inline bool satisfy(double theta)
{
	bool flag = false;
	double base = s[0] * sin(theta), predicted_c = a[n] * tan(theta);
	rep(i, n)
	{
		sin_alpha[i] = base / s[i + 1];
		if(sin_alpha[i] > 1)
		{
			flag = true;
			break;
		}
		predicted_c +=  h[i] * tan(asin(sin_alpha[i])) + a[i] * tan(theta);
	}
	return flag || c <= predicted_c;
}

inline double cost(double theta)
{
	double final_cost = (s[0] * a[n]) / cos(theta);
	rep(i, n)
	{
		final_cost += (s[0] * a[i]) / cos(theta) + 
					  (s[i + 1] * h[i]) / cos(asin(sin_alpha[i]));
	}
	return final_cost;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		rep(i, n + 1) scanf("%d", &a[i]);
		rep(i, n) scanf("%d", &h[i]);
		scanf("%d", &c);
		rep(i, n + 1) scanf("%d", &s[i]);
		double ub = PI/2, lb = 0, mid;
		rep(i, 50)
		{
			mid = lb + (ub - lb) / 2;
			if(satisfy(mid)) ub = mid;
			else lb = mid;
		}
		printf("%.2lf\n", cost(mid));
	}
	return 0;
}