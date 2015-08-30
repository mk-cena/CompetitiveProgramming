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

int main()
{
	char str[2000];
	int k;
	scanf("%s",str);
	scanf("%d",&k);
	int n = strlen(str);
	int l = n/k;
	int cnt = 0;
	bool flag;
	int i =0;
	while(i<n && l>0)
	{
		flag = true;
		for(int j=i,m=i+l-1;j<=m;j++,m--)
		{
			if(str[j] != str[m])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cnt++;
			i+=l;
		}
		else
		{
			break;
		}
	}
	if(flag && cnt == k)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}