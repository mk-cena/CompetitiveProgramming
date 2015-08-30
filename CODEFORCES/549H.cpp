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

bool intersect(double a, double b, double c, double d)
{
	if(a >= c && a <= d)
		return true;
	if(c >= a  && c <= b)
		return true;
	return false;
}

int main()
{
	double a,b,c,d;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	double lb = 0,mid,ub = 1.0e+19;
	for(int i=0;i<1.0e+6;i++)
	{
		mid = ((ub - lb) / 2.0) + lb;
		double mxb1b4 = max((a-mid) * (d-mid), max((a+mid) * (d+mid), 
						max((a-mid) * (d+mid), (a+mid) * (d-mid))));
		double mnb1b4 = min((a-mid) * (d-mid), min((a+mid) * (d+mid), 
						min((a-mid) * (d+mid), (a+mid) * (d-mid))));
		double mxb2b3 = max((b-mid) * (c-mid), max((b+mid) * (c+mid), 
						max((b-mid) * (c+mid), (b+mid) * (c-mid))));
		double mnb2b3 = min((b-mid) * (c-mid), min((b+mid) * (c+mid), 
						min((b-mid) * (c+mid), (b+mid) * (c-mid))));
		if(intersect(mnb1b4,mxb1b4,mnb2b3,mxb2b3))
			ub = mid;
		else
			lb = mid;
	}
	printf("%.11lf",mid);
	return 0;
}