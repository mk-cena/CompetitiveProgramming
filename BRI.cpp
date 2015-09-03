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

int a,b,c,h,s1,s2,t;

inline double solve(double theta)
{
	return atan((c - (h  / tan(theta))) / (a + b));
}

inline double cost(double alpha, double theta)
{
	double c1 = (a * s1) / cos(alpha);
	double c2 = (h * s2) / sin(theta);
	double c3 = (b * s1) / cos(alpha);

	return c1 + c2 + c3;
}

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

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		a = readInt(), b = readInt(), c = readInt(), h = readInt(), s1 = readInt(), s2 = readInt();
		double l = 0, r = PI, m1 = 0, m2 = 10, alpha1, alpha2;
		rep(i, 25)
		{
			m1 = l + (r - l) / 3.0;
			m2 = r - (r - l) / 3.0;

			alpha1 = solve(m1);
			alpha2 = solve(m2);

			if(cost(alpha1, m1) > cost(alpha2, m2)) l = m1;
			if(cost(alpha1, m1) <= cost(alpha2, m2)) r = m2;
		} 
		printf("%.2lf\n", cost(alpha1, m1));
	}
	return 0;
}