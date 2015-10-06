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

ll mod(ll a, ll b)
{
	return ((a % b) + b) % b;
}

#define MOD 1000000007LL

int n;
ll POW(int b)
{
	ll ans = 1LL;
	rep(i, n) ans *= b, ans = mod(ans, MOD);
	return ans;
}

int main()
{
	scanf("%d", &n);
	printf("%I64d\n", mod(POW(27) - POW(7), MOD));
	return 0;
}