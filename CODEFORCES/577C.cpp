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


bool prime[5000];
vector<int>primes;
vector<ll>ans;
int n;
ll m;

void build_primes()
{
	primes = vector<int>();
	rep(i, 2000) prime[i] = true;
	prime[0] = prime[1] = false;
	for(int i = 2;i<=100;i++)
		if(prime[i])
			for(int j = i * i; j<=1010; j+=i)
				prime[j] = false;
	rep(i, 1200) if(prime[i]) primes.push_back(i);
}

int main()
{
	build_primes();
	scanf("%d", &n);
	ans = vector<ll>();
	rep(i, primes.size())
	{
		m = primes[i];
		if(m > n) break;
		rep(j, 10) if(m <= n) ans.push_back(m), m *= primes[i];
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) printf("%I64d ", ans[i]);
	return 0;
}