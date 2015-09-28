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

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

class Compare
{
	public:
		bool operator()(int a, int b)
		{
			return a < b;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}

int n, k, ans = 0;
pair<int, int> a[100009];
int main()
{
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i].second), a[i].first = 10 - (a[i].second % 10);
	sort(a, a + n, compare);
	rep(i, n)
	{
		if(a[i].second < 100 && k - a[i].first >= 0) k -= a[i].first, a[i].second += a[i].first;
		ans += a[i].second / 10;
	}
	int r;
	rep(i, n) if(k > 0 && a[i].second < 100) r = min(k, 100 - a[i].second), k -= r, ans += r / 10;
	printf("%d\n", ans);
	return 0;
}