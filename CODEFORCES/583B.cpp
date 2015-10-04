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

bool v[2000];
int n, a[2000], cnt = 0, info = 0, dir = 1;

int main()
{
	memclr(v);
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	int i = 0;
	while(true)
	{
		while(i >= 0 && i < n)
		{
			if(!v[i] && a[i] <= info) info++, v[i] = true;
			i += dir;
		}
		dir *= -1, i += dir;
		bool flag = true;
		rep(k, n) flag &= v[k];
		if(!flag) cnt++;
		else break;
	}
	printf("%d\n", cnt);
	return 0;
}