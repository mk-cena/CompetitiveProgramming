#include <algorithm>
#include <stdio.h>

using namespace std;

int s[5002],n;

int Greedy()
{
	int count=0;
	sort(s + 1, s + n + 1);
	for(int i=1;i<=n;i++)
		if(s[i] == s[i + 1] || s[i] > n)
			count++;
	return count;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	printf("%d\n",Greedy());
}