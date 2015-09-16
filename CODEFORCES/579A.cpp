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

ll log2(ll x)
{
	ll tmp = x, c = 0;
	while(tmp > 1) tmp /= 2, c++;
	return c;
}

ll pow2(ll x)
{
	ll tmp = 1;
	rep(i, x) tmp *= 2;
	return tmp;
}

int main()
{
	ll x, total = 0, y, p;
	scanf("%I64d", &x);
	while(x > 0) y = log2(x), p = pow2(y), x -= p, total ++;
	printf("%I64d\n", total);
	return 0;
}