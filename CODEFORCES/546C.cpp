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
	bool flag = false;
	int n,na,nb,tmp,rounds = 0;
	list<int>a,b;
	vector<pair<ll,ll> >vec;
	scanf("%d",&n);
	ll ahash = 0, bhash = 0;
	scanf("%d",&na);
	ll POW[100];
	POW[0] = 1;
	for(int i=1;i<14;i++)
	{
		POW[i] = POW[i - 1] * 11;
	}

	for(int i=0;i<na;i++)
	{
		scanf("%d",&tmp);
		a.push_back(tmp);
		ahash = ahash * 11 + tmp;
	}
	scanf("%d",&nb);
	for(int i=0;i<nb;i++)
	{
		scanf("%d",&tmp);
		b.push_back(tmp);
		bhash = bhash * 11 + tmp;
	}
	while(a.size() > 0 && b.size() > 0)
	{
		for(int i=0;i<vec.size();i++)
			if(vec[i].first == ahash && 
			   vec[i].second == bhash)
			{
				flag = true;
				break;
			}
		if(flag) break;
		vec.push_back(pair<ll, ll>(ahash,bhash));
		if(a.front() > b.front())
		{
			ahash -= POW[a.size() - 1] * a.front();
			bhash -= POW[b.size() - 1] * b.front();
			ahash = ahash * 11 + b.front();
			ahash = ahash * 11 + a.front();
			a.push_back(b.front());
			a.push_back(a.front());
		}
		else
		{	
			ahash -= POW[a.size() - 1] * a.front();
			bhash -= POW[b.size() - 1] * b.front();
			bhash = bhash * 11 + a.front();
			bhash = bhash * 11 + b.front();
			b.push_back(a.front());
			b.push_back(b.front());
		}
		a.pop_front();
		b.pop_front();
		rounds++;
	}
	if(flag)
		printf("%d\n",-1);
	else
		printf("%d %d\n", rounds, a.size()?1:2);
	return 0;
}