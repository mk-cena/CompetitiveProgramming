#include <stdio.h>

int xp[105], current, goal;

int Greedy()
{
	int needed = 0;

	for(int i = current; i<goal;i++)
		needed += xp[i];

	return needed;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d",&xp[i]);
	scanf("%d %d", &current, &goal);
	printf("%d",Greedy());
}