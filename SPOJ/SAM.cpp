#include <iostream>
#include <cstdio>
#include <map>
#include <climits>
#include <queue>
#include <vector>
#include <list>

using namespace std;

int t;
long long i, k, n, p, shelf, car[500005], sz;
bool cached[100005];
list <long long> positions[100005];

class CompareLL {
public:
    bool operator()(pair<long long, long long> a, pair<long long, long long> b)
    {
    	return a.second < b.second;
    }
};

priority_queue<pair<long long, long long>, vector <pair<long long, long long> >, CompareLL>cache;

int main()
{
	// Farther in the Future
	scanf("%d",&t);
	while(t--)
	{
		shelf = sz = 0;
		for(i = 0;i<100005;i++)
			cached[i] = false, positions[i].clear();
		cache = priority_queue<pair<long long, long long>, vector <pair<long long, long long> >, CompareLL>();

		scanf("%lld %lld %lld",&n,&k,&p);

		for(i = 0;i<p;i++)
			scanf("%lld",&car[i]),positions[car[i]].push_back(i + 1);
		for(i = 0;i<n;i++)
			positions[car[i]].push_back(p + 1);

		for(i = 0;i<p;i++)
		{	
			if(cached[car[i]])
			{
				positions[car[i]].pop_front();
				cache.push(pair<long long, long long>(car[i], positions[car[i]].front()));
				continue;
			}
			if(sz >= k)
			{
				cached[cache.top().first] = false;
				cache.pop();
			}
			else sz++;
			positions[car[i]].pop_front();
			cache.push(pair<long long, long long>(car[i], positions[car[i]].front()));
			cached[car[i]] = true;
			shelf++;
		}
		printf("%lld\n",shelf);
	}	
	return 0;
}