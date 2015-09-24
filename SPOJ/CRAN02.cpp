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
#include <bitset>

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
ll t,n,a[1000009],c[1000009],sum,ans;
map<int, ll> mp;
int main()
{
	scanf("%lld", &t);
	while(t--)
	{
		memclr(c),sum=ans=0,mp=map<int,ll>();
		scanf("%lld", &n);
		rep(i, n) scanf("%lld", &a[i]);
		rep(i, n)
		{
			sum += a[i];
			if(mp[sum]) c[mp[sum]]++;
			else mp[sum] = i + 1;
		}
		if(mp[0]) c[mp[0]]++;
		rep(i, n + 1) ans += (c[i] * (c[i] + 1)) / 2;
		printf("%lld\n",ans);
	}
	return 0;
}