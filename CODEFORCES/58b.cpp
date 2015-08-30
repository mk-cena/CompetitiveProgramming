#include <stdio.h>

int n;

void Greedy()
{
	while(n!=1)
	{
		printf("%d ",n);
		for(int i=n/2;i>0;i--)
			if(n%i == 0)
			{
				n=i;
				break;
			}
	}
	printf("1");
}

int	main()
{
	scanf("%d",&n);
	Greedy();
}