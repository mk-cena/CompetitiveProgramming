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

using namespace std;

#define ll long long
#define ull unsigned long long
#define MAXPRIME 1000000007

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

int main()
{
	ll k,n,w,total;
	scanf("%I64d %I64d %I64d", &k, &n, &w);
	total = (k * w * (w+1))/2;
	if(total > n)
		printf("%I64d\n", total - n);
	else
		printf("0\n");
	return 0;
}