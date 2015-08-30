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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

char num[200];
int dp[205][205][205], backtrack[205][205][205];
bool rm[205];

int getN(int i)
{
    if(i < 0) return 0;
    return num[i] - '0';    
}

int DP(int i, int j, int k)
{
    if(i < 0 && j < 0 && k < 0)
        return 0;
        
    if((getN(i) * 100 + getN(j) * 10 + getN(k)) % 8 == 0)
        return 1;
        
    if(dp[mod(i,205)][mod(j,205)][mod(k,205)] != -999)
        return dp[mod(i,205)][mod(j,205)][mod(k,205)];
    
    backtrack[mod(i,205)][mod(j,205)][mod(k,205)] = k;
    int tmp,q =  DP(i - 1, i, j); /** removing third digit **/

    if(i >= 0)
    {
        tmp = DP(i - 1, j, k); /** removing first digit **/
        if(q < tmp)
            q = tmp, backtrack[mod(i,205)][mod(j,205)][mod(k,205)] = i;
    }
    if(j >= 0)
    {
        tmp = DP(i - 1, i, k); /** removing second digit **/
        if(q < tmp)
            q = tmp, backtrack[mod(i,205)][mod(j,205)][mod(k,205)] = j;
    }
    
    dp[mod(i,205)][mod(j,205)][mod(k,205)] = q;
    
    return q;
}

void Backtrack(int i, int j, int k)
{
	int r = backtrack[mod(i,205)][mod(j,205)][mod(k,205)];
    if(r == -999)
        return;
    rm[r] = true;
    if(r == i && i >= 0)
        Backtrack(i-1,j,k);
    if(r == j && j >= 0)
        Backtrack(i-1,i,k);
    if(r == k && k >= 0)
        Backtrack(i-1,i,j);
}

int main()
{
    
    scanf("%s",num);
    int n = strlen(num);
    for(int i=0;i<205;i++)
        for(int j=0;j<205;j++)
            for(int k=0;k<205;k++)
                dp[i][j][k]= backtrack[i][j][k] = -999;
    int flag = DP(n - 3, n - 2, n - 1);
    printf(flag?"YES\n":"NO\n");
    if(flag)
    {
        Backtrack(n - 3, n - 2, n - 1);
        for(int i=0;i<n;i++)
            if(!rm[i])
                printf("%c",num[i]);
        printf("\n");
    }
    return 0;
}