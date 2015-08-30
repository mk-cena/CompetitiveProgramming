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

bool compare(pair<ll, int> a, pair<ll, int>b)
{
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
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
int n, q, type, l, r, x, y, root, segs,cnt,seg,end_seg,first,last;
pair<ll,int> a[1000000];

int binary_search(int s, bool dir)
{
	int lb = s * root, ub = min(root + s * root - 1, n - 1), mid, result = -1;
	while(ub >= lb)
	{
		mid = lb + (ub - lb) / 2;
		if(a[mid].first == y)
		{
			result = a[mid].second;
			if(dir) ub = mid - 1;
			else lb = mid + 1;
		}
		else if(a[mid].first > y)
			ub = mid - 1;
			else
				lb = mid + 1;
	}
	return result;
}

void sort_segs()
{
	for(int i=0;i<segs;i++)
		sort(a + root * i, a + min(root + i * root, n));
}

int main()
{
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%I64d",&a[i].first),a[i].second = i;
	root = sqrt(n) + 1;
	segs = n / root + 1;
	sort_segs();
	while(q--)
	{
	 	scanf("%d",&type);
	 	if(type == 1)
	 	{
	 		scanf("%d %d %d",&l,&r,&x);
	 		l--,r--;
	 		seg = l/root, end_seg = r/root;
	 		while(seg <= end_seg)
	 		{
	 			if(a[seg * root].first > 1000000000)
	 			{
	 				seg++;
	 				continue;
	 			}
	 		 	cnt = 0;
	 			for(int j = seg * root; j < min(root + seg * root,n);j++)
	 			{
	 				if(a[j].second >= l && a[j].second <= r)
	 					cnt++, a[j].first += x;
	 			}
	 			if(cnt != root)
	 				sort(a + seg * root, a + min(seg * root + root, n), compare);
	 			seg++;
	 		}
	 	}
	 	else
	 	{
	 		scanf("%d",&y);
	 		first = last = -1;
	 		for(int i=0;i<segs;i++)
	 		{
	 			if(first != -1 && last != -1) break;
	 			if(first == - 1)
	 				first = binary_search(i, true);
	 			if(last == -1)
	 				last = binary_search(segs - i - 1, false);
	 		}
	 		if(first == -1) printf("-1\n");
	 		else if(first != -1 && last != -1) printf("%d\n",last - first);
	 	}
	 }
	return 0;
}