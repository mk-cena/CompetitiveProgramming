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

#define REP(i,N) for(int i=0;i<N;i++)
#define MAXPRIME 1000000007

bool compare(int a, int b)
{
	if(a == b)
	{
		printf(":(\n");
		exit(0);
	}
	return a < b;
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

int n, line[200009];

int main()
{
	scanf("%d",&n);
	REP(i, n)
	{
		scanf("%d",&line[i]);
		line[i] += i;
	}
	sort(line, line + n, compare);
	REP(i, n) line[i] -= i;
	REP(i, n) printf("%d ", line[i]);
	printf("\n");
	return 0;
}