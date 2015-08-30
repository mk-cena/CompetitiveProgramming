#include <algorithm>
#include <stdio.h>

using namespace std;

int n,left,right,secs=0;

int main()
{
	scanf("%d",&n);

	for(int i=0,l,r;i<n;i++)
	{
		scanf("%d %d",&l, &r);
		if(l == 1) left++;
		if(r == 1) right++;
	}
	secs += min(left, n - left);
	secs += min(right, n - right);

	printf("%d\n",secs);
}