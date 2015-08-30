#include <stdio.h>
#include <algorithm>
using namespace std;

int n, k, dp[1005][1005], array[1005];

inline void fastRead_int(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
 
    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());
 
    if(c=='-') {
     neg = 1;
     c = getchar_unlocked();
    }
 
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
     x = (x<<1) + (x<<3) + c - 48;
    }
 
    if(neg)
     x = -x;
}

bool DP(int index, int s)
{
	if(s == 0)
		return true;
	if(index >= n)
		return false;

	bool q = DP(index + 1, s);
	if(s >= array[index])
		q = q || DP(index + 1, s - array[index]);

	return q;
}

int main()
{
	int t;
	fastRead_int(t);

	for(int i=0;i<t;i++)
	{
		fastRead_int(n);
		fastRead_int(k);
		for(int j=0;j<n;j++)
			fastRead_int(array[j]);
		printf("%d\n", DP(0,k));
	}
	return 0;
}