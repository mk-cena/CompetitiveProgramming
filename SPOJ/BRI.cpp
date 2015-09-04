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

int t,a,b,c,h,s1,s2;

inline int readInt () 
{
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

inline bool satisfy(double theta)
{
	double sin_alpha = (sin(theta) * s2) / s1;
	double alpha = asin(sin_alpha);
	return sin_alpha > 1 || c <= (b * tan(alpha) + a * tan(alpha) + h * tan(theta));
}

inline double cost(double theta)
{
	double alpha = asin((sin(theta) * s2) / s1);
	return (s1 * a) / cos(alpha) +
		   (s2 * h) / cos(theta) +
		   (s1 * b) / cos(alpha);
}


int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d %d %d", &a, &b, &c, &h, &s1, &s2);
		double ub = PI/2, lb = 0, mid;
		rep(i, 30)
		{
			mid = lb + (ub - lb) / 2;
			if(satisfy(mid)) ub = mid;
			else lb = mid;
		} 
		printf("%.2lf\n", cost(mid));
	}
	return 0;
}