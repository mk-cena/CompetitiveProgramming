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
	string p = "";
	char s[100005],t[100005];
	scanf("%s %s", s, t);
	ll len = strlen(s), sdiff = 0, tdiff = 0;
	for(ll i =0;i<len;i++)
	{
		if(s[i] == t[i]) p += s[i];
		else if(sdiff > tdiff) p += s[i], tdiff++;
			 else p += t[i], sdiff++;
	}
	if(sdiff != tdiff)
		printf("impossible\n");
	else
		printf("%s\n",p.c_str());
	return 0;
}