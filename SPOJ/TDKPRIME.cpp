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

int primes[5000000];
bool is_prime[86028190];

void precompute_primes()
{
	is_prime[0]=is_prime[1]=false;
	for(int i =0;i<86028190;i++)
		is_prime[i] = true;

	for(int i=2;i<9279;i++)
		if(is_prime[i])
			for(int j=i*i;j<86028190;j+=i)
				is_prime[j] = false;
	int k = 1;
	for(int i=2;i<86028190;i++)
		if(is_prime[i])
			primes[k] = i,k++;
}

int main()
{
	int t,q;
	precompute_primes();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&q);
		printf("%d\n",primes[q]);
	}
	return 0;
}