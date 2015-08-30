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

bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
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
	ll n, last = LLONG_MIN, trees = 0;
	pair <ll, ll> tree[100005];
	scanf("%I64d",&n);
	for(ll i = 0;i<n;i++)
		scanf("%I64d %I64d",&tree[i].first, &tree[i].second);
	tree[n].first = LLONG_MAX;
	for(ll i=0;i<n;i++)
		if(tree[i].first - tree[i].second > last) last = tree[i].first, trees++;
		else if(tree[i].first + tree[i].second < tree[i + 1].first) 
				last = tree[i].first + tree[i].second, trees++;
			 else last = tree[i].first;
	printf("%I64d\n",trees);
	return 0;
}