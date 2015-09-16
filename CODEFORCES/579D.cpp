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
#define memclr(elements) memset(elements,0,sizeof(elements))
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

int n, k, x;
ll a[200009], suffix[200009], prefix[200009], xk = 1, ans = 0;

int main()
{
	scanf("%d %d %d", &n, &k, &x);
	rep(i, n) scanf("%I64d", &a[i]);
	rep(i, k) xk *= x;
	for(int i = 0; i < n; i++) prefix[i] = (i==0?0:prefix[i - 1]) | a[i];
	for(int i = n - 1; i >= 0; i--) suffix[i] = (i==n-1?0:suffix[i + 1]) | a[i];
	rep(i,n) ans = max(ans, a[i] * xk | (i==0?0:prefix[i - 1]) | (i==n-1?0:suffix[i + 1]));
	printf("%I64d\n", ans);
	return 0;
}