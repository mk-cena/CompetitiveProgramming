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

int gcd(int a, int b)
{
	if(!b) return a;
	return gcd(b, a % b);
}

int tmp, n, ai, aij;
map<int, int> cnts;
set<int> g;
vector<int> a;

int main()
{
	scanf("%d", &n);
	rep(i, n * n) scanf("%d", &tmp), cnts[tmp]++, g.insert(tmp);

	rep(i, n)
	{
		ai = *(--g.end()), cnts[ai]--;
		if(!cnts[ai]) g.erase(ai);

		rep(j, a.size())
		{
			aij = gcd(ai, a[j]), cnts[aij] -= 2;
			if(!cnts[aij]) g.erase(aij);
		}
		a.push_back(ai);
	}

	rep(i, n) printf("%d ", a[i]);

	return 0;
}