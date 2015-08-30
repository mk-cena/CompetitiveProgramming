#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

long long n,m,x,y,a[100005],b[100005];
vector <pair<int, int> > pairwise;

void Greedy()
{
	int equipped = 0, j = 0;
	pair <int, int> tmp;
	for(int i=0;i<n;i++)
		while(j<m)
			if(b[j] >= a[i] - x && b[j] <= a[i] + y )
			{
				equipped++;
				tmp.first = i + 1;
				tmp.second = j + 1;
				pairwise.push_back(tmp);
				j++;
				break;
			}
			else
				if(b[j] > a[i] + y) break;
				else j++;

	printf("%d\n", equipped);
	for(int i=0;i<pairwise.size();i++)
		printf("%d %d\n",pairwise[i].first, pairwise[i].second);
}

int main()
{
	scanf("%I64d %I64d %I64d %I64d",&n,&m,&x,&y);
	for(int i = 0;i<n;i++)
		scanf("%I64d",&a[i]);
	for(int i=0;i<m;i++)
		scanf("%I64d",&b[i]);
	Greedy();
}