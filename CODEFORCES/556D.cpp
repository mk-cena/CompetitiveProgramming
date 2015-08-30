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

#define REP(i,N) for(ll i=0;i<N;i++)
#define MAXPRIME 1000000007

bool compare(const pair<ll, pair<ll, ll> > &a, const pair<ll, pair<ll, ll> > &b)
{
	return a.first < b.first;
}

class Compare
{
	public:
		bool operator()(const pair<ll, ll> &a, const pair<ll, ll> &b) const
		{
			if(a.first == b.first) return a.second < b.second;
			return a.first < b.first;
		}
};

int mod(int a, int b)
{
	return ((a % b) + b) % b;
}
ll n,m,tmp;
pair<ll, ll> island[1000009];
pair<ll, pair<ll, ll> > intervals[1000009];
set<pair <ll, ll>, Compare> bridge;
set<pair<ll, ll>, Compare>::iterator it;
vector <pair<ll, ll> > vec;
int main()
{
	scanf("%I64d %I64d",&n, &m);
	REP(i, n) 
	{ 
		scanf("%I64d %I64d", &island[i].first, &island[i].second);
		if(i > 0)
		{
			intervals[i - 1].first = island[i].second - island[i - 1].first;
			intervals[i - 1].second.first = island[i].first - island[i - 1].second;
			intervals[i - 1].second.second = i - 1;
		}
	}
	sort(intervals, intervals + n - 1, compare);
	REP(i, m) scanf("%I64d", &tmp), bridge.insert(pair<ll,ll>(tmp, i));
	REP(i, n - 1)
	{
		it = bridge.lower_bound(pair<ll,ll>(intervals[i].second.first, 0LL));
		if(it == bridge.end() || (*it).first > intervals[i].first)
		{
			printf("No\n");
			return 0;
		}
		vec.push_back(pair<ll,ll>(intervals[i].second.second, (*it).second));
		bridge.erase(it);
	}
	sort(vec.begin(), vec.end());
	printf("Yes\n");
	REP(i, vec.size()) printf("%I64d ",vec[i].second + 1);
	return 0;
}