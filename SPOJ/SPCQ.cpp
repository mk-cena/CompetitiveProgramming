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

int sum_of_digits(ll i)
{
	int s = 0;
	while(i > 0)
	{
		s += i%10;
		i/=10;
	}
	return s;
}

int main()
{
	ll n;
	int t,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		while(true)
		{
			s = sum_of_digits(n);
			if(n % s == 0)
				break;
			n++;
		}
		printf("%lld\n",n);
	}
	return 0;
}