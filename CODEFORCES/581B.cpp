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
int a[100009], n, suffix[100009];
int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	suffix[n - 1] = n - 1;
	for(int i = n - 2;i >= 0;i--)
	{
		if(a[suffix[i + 1]] >= a[i]) suffix[i] = suffix[i + 1];
		else suffix[i] = i;
	}
	rep(i, n)
	{
		if(suffix[i] == i) printf("0 ");
		else printf("%d ", a[suffix[i]] - a[i] + 1);
	}
	return 0;
}