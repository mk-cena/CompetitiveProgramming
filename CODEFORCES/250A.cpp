#include <stdio.h>
#include <iostream>
using namespace std;

int n,a[1000],folder[1000];

void Greedy()
{
	int neg = 0,index = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] < 0 && neg == 2)
		{
			index++;
			neg = 1;
		}
		else if(a[i] < 0) neg++;
		folder[index]++;
	}

	printf("%d\n",index+1);
	for(int i=0;i<=index;i++)
		printf("%d ",folder[i]);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	Greedy();
}