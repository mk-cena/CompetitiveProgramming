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

class f
{
	public:
		int m,s;
		f(){}
		bool operator<(f b)const
		{
			return m < b.m;
		}
};
int n, d;
ll prefix[100009], ans = 0;
f a[100009];
int main()
{
	scanf("%d %d", &n, &d);
	rep(i, n) scanf("%d %d", &(a[i].m), &(a[i].s));

	sort(a, a + n);
	rep(i, n) prefix[i] = a[i].s + (i != 0) * prefix[i - 1];
	int i = 0, j = 0;
	while(j < n)
	{
		if(a[j].m - a[i].m >= d) i++;
		else ans = max(ans, prefix[j] - (i != 0) * prefix[i - 1]), j++;
	}
	printf("%I64d\n", ans);
	return 0;
}