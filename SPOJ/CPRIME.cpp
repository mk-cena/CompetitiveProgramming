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

#define MAXN 100000009
#define SQRTN 10009

bool is_prime[MAXN];
ll pcount[MAXN];

void precompute_primes()
{
	is_prime[0] = is_prime[1] = false;

	for(ll i =2;i<MAXN;i++)
		is_prime[i] = true;

	for(ll i=2;i<SQRTN;i++)
		if(is_prime[i])
			for(int j=i*i;j<MAXN;j+=i)
				is_prime[j] = false;

	pcount[0] = pcount[1] = 0;
	for(ll i=2;i<MAXN;i++)
		pcount[i] = pcount[i-1] + is_prime[i];
}

int main()
{
	ll n;
	precompute_primes();
	while(true)
	{
		scanf("%lld",&n);
		if(n == 0) break;
		double c = n / log((double)n);
		double a = fabs(pcount[n] - c)/pcount[n];
		printf("%.1lf\n", a * 100.0);
	}
	return 0;
}