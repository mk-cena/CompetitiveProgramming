#include <stdio.h>

int main()
{
	int count, n, a;
	scanf("%d",&n);
	while(n != 0)
	{
		count = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a == 0) continue;
			if(count > 0) printf(" ");
			printf("%d",a);
			count++;
		}

		if(count == 0) printf("0");
		printf("\n");
		scanf("%d",&n);
	}	
}