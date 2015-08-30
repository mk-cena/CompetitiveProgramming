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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

int n, rating[3000], sorted[3000];
map<int,int> ranks;
int main()
{
	scanf("%d",&n);
	for(int i =0;i<n;i++)
		scanf("%d",&rating[i]),sorted[i] = rating[i];
	sort(sorted, sorted + n, compare);

	ranks[sorted[0]] = 1;
	for(int i=1,rank = 1;i<n;i++)
	{
		if(sorted[i] != sorted[i - 1])
			rank = i + 1;
		ranks[sorted[i]] = rank;
	}
	for(int i=0;i<n;i++)
		printf("%d ",ranks[rating[i]]);	
	printf("\n");
	return 0;
}