#include <iostream>
#include <algorithm>
#include <stdio.h>


using namespace std;

int n,m,tv[1000];

void Greedy()
{
	int money = 0,tmp;
	sort(tv, tv + n);
	for(int i=0;i<m;i++)
	{
		tmp = money - tv[i];
		if(tmp < money) break;
		money = tmp;
	}
	printf("%d",money);
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d", &tv[i]);
	Greedy();
}