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
	ll n, ppl[100005], t = 0, satisfied = 0;
	scanf("%I64d",&n);
	for(ll i =0;i<n;i++)
		scanf("%I64d",&ppl[i]);
	sort(ppl, ppl + n);
	for(ll i = 0;i<n;i++)
	{
		if(t > ppl[i]) continue;
		t += ppl[i];
		satisfied++;
	}
	printf("%I64d\n",satisfied);
	return 0;
}