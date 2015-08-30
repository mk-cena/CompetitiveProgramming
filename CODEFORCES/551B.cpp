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
#include <limits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define REP(i,N) for(int i=0;i<N;i++)
#define MAXPRIME 1000000007

bool compare(int a, int b)
{
	return a > b;
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
#define MAX 100009
int main()
{
	int acnt[26], bcnt[26], ccnt[26], cnt_tmp[26], mnb = MAX, mnc, sum = 0, brep = 0, crep = 0;
	string final = "";
	char a[MAX], b[MAX], c[MAX];
	scanf("%s\n%s\n%s",a,b,c);
	int alen = strlen(a), blen = strlen(b), clen = strlen(c);
	REP(i, 26) acnt[i] = bcnt[i] = ccnt[i] = 0;
	REP(i, alen) acnt[a[i] - 'a']++;
	REP(i, blen) bcnt[b[i] - 'a']++;
	REP(i, clen) ccnt[c[i] - 'a']++; 
	REP(i, blen) mnb = min(mnb, acnt[ b[i] - 'a' ] / bcnt[ b[i] - 'a' ]);
	REP(i, mnb + 1)
	{
		mnc = MAX;
		memcpy(cnt_tmp, acnt, 26 * sizeof(int));
		REP(j, 26) cnt_tmp[j] -= i * bcnt[j];
		REP(j, clen) mnc = min(mnc, cnt_tmp[ c[j] - 'a'] / ccnt[ c[j] - 'a']);
		if(sum < mnc + i) sum = i + mnc, brep = i, crep = mnc;
	}
	REP(i, brep) REP(j, blen) final += b[j], acnt[b[j] - 'a']--;
	REP(i, crep) REP(j, clen) final += c[j], acnt[c[j] - 'a']--;
	REP(i, 26) REP(j, acnt[i]) final += char(i + 'a');
	printf("%s\n",final.c_str());
	return 0;
}