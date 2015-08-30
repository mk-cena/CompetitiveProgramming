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

#define ll long long
#define ull unsigned long long
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

#define MAXN 1000000005
#define SQRTMAXN 31628
#define DIFF 100015

bool is_prime[DIFF], base[SQRTMAXN];

void precompute_primes()
{

	base[0] = base[1] = false;

	for(ll i = 2;i<SQRTMAXN;i++)
		base[i] = true;

	for(ll i = 2;i<SQRTMAXN;i++)
		if(base[i])
			for(ll j = i * i;j<SQRTMAXN;j+=i)
				base[j] = false;
}

int main()
{
	ll t,a,b;
	scanf("%lld",&t);
	precompute_primes();
	while(t--)
	{
		scanf("%lld %lld",&a,&b);
		for(ll i = 0;i<DIFF;i++)
			is_prime[i] = true;

		for(ll i = 2;i<=SQRTMAXN;i++)
			if(base[i])
			{
				for(ll j = ((a + i - 1)/ i) * i;j<=b;j+=i)
				{
					if(j == i) continue;
					is_prime[j - a] = false;
				}
			}

		
		if(a == 1) is_prime[0] = false;
		if(b == 1) is_prime[b-a] = false;

		for(ll i = 0;i<=b-a;i++)
		{
			if(is_prime[i])
				printf("%lld\n",i + a);
		}
		printf("\n");
	}
	return 0;
}