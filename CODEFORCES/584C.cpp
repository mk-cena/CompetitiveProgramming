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
int n, t, eqsz = 0;
char a[100005], b[100005], c[100005];
bool eq[100005];

char diff(char x, char y)
{
	rep(i, 26) if('a' + i != x && 'a' + i != y) return 'a' + i;
}

int main()
{
	memclr(eq);
	scanf("%d %d", &n, &t);
	scanf("%s %s", a, b);
	rep(i, n) if(a[i] == b[i]) eq[i] = true, eqsz++;
	if(eqsz >= n - t)
	{
		int cnt = 0;
		rep(i, n)
		{
			if(eq[i] && cnt < n - t) cnt++, c[i] = a[i];
			else c[i] = diff(a[i], b[i]);
		}
	}
	else
	{
		int rem = n - t - eqsz;
		if(rem * 2 > n - eqsz) {printf("-1"); return 0;}
		else
		{
			int cnt1 = rem, cnt2 = rem;
			rep(i, n)
			{
				if(eq[i]) c[i] = a[i];
				else
				{
					if(cnt1 > 0) cnt1--, c[i] = a[i];
					else if(cnt2 > 0) cnt2--, c[i] = b[i];
					else c[i] = diff(a[i], b[i]);
				}
			}
		}
	}
	rep(i, n) printf("%c", c[i]);
	return 0;
}