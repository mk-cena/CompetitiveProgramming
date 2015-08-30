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

#define rep(i,N) for(int i=0;i<N;i++)
#define memclr(ARRAY) memset(ARRAY,0,sizeof(ARRAY))
#define MAXPRIME 1000000007
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745

bool compare(int a, int b)
{
	return a > b;
}

class Compare
{
	public:
		bool operator()(int a, int b)
		{
			return a < b;
		}
};

class Compare2
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

int n,s,p,q;
char type;
priority_queue <int, vector<int>, Compare> buy_orders;
priority_queue <int, vector<int>, Compare2> sell_orders;
map<int, int> buy_map, sell_map;
stack<int> reverse_stack1, reverse_stack2;

int main()
{
	scanf("%d %d",&n,&s);
	rep(i,n)
	{
		cin >> type;
		scanf("%d %d",&p,&q);
		if(type == 'B') buy_orders.push(p), buy_map[p] += q;
		else sell_orders.push(p), sell_map[p] += q;
	}

	int buy_count = 0, sell_count = 0;

	while(!sell_orders.empty())
	{
		if(sell_count == s) break;
		int price = sell_orders.top();sell_orders.pop();
		if(sell_map[price] == -999) continue;
		reverse_stack1.push(price);
		reverse_stack2.push(sell_map[price]);
		sell_map[price] = -999;
		sell_count++;
	}

	while(!reverse_stack1.empty())
	{
		int v1 = reverse_stack1.top();reverse_stack1.pop();
		int v2 = reverse_stack2.top();reverse_stack2.pop();
		printf("S %d %d\n", v1, v2);
	}

	while(!buy_orders.empty())
	{
		if(buy_count == s) break;
		int price = buy_orders.top();buy_orders.pop();
		if(buy_map[price] == -999) continue;
		printf("B %d %d\n",price, buy_map[price]);
		buy_map[price] = -999;
		buy_count++;
	}
	return 0;
}