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

char str[1000009];
stack <int> s;

int main()
{
	int n,i=0,j=1,rem,a,b;
	scanf("%d",&n);
	scanf("%s",str);
	rem = n;
	while(j < n)
	{
		a = str[i] - '0';
		b = str[j] - '0';
		if(a ^ b == 1)
		{
			rem -= 2;
			if(s.empty()) i = ++j, j++;
			else i = s.top(), s.pop(), j++;
		}
		else s.push(i), i = j, j++;
	}
	printf("%d\n",rem);
	return 0;
}