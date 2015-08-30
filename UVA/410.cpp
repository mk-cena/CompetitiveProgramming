#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <vector>

using namespace std;

int c,s,weight[1005],cases=1;
double am,total;
vector <int> chamber[200];

bool larger(int a, int b)
{
	return a > b;
}

void Greedy()
{
	int cm;
	double imbalance = 0;
	am = total/c;
	for(int i =0;i<c;i++) chamber[i].clear();

	sort(weight, weight + s, larger);

	for(int i=0;i<s;i++)
	{
		int mnindex = -1, mn = INT_MAX;
		for(int j=0;j<c;j++)
		{
			if(chamber[j].size() == 2) continue;
			cm = 0;
			for(int k=0;k<chamber[j].size();k++) cm += chamber[j][k];
			if(mn > cm)
			{
				mn = cm;
				mnindex = j;
			}

		}
		chamber[mnindex].push_back(weight[i]);
	}


/*############################ PRINT ############################*/

	printf("Set #%d\n",cases++);
	for(int i=0;i<c;i++)
	{
		printf("%2d:",i);
		cm = 0;
		for(int j=0;j<chamber[i].size();j++)
		{
			cm += chamber[i][j];
			printf(" %d",chamber[i][j]);
		}
		imbalance += fabs(cm - am);
		printf("\n");
	}
	printf("IMBALANCE = %.5lf\n\n",imbalance);
}

void Greedy2()
{
	int cm;
	double imbalance = 0;
	am = total / c;
	for(int i=s;i<2*c;i++) weight[i] = 0;
	sort(weight, weight + 2 * c);
	printf("Set #%d\n",cases++);
	for(int i=0;i<c;i++)
	{
		printf("%2d:",i);
		cm = 0;
		if(weight[i]) cm += weight[i], printf(" %d",weight[i]);
		if(weight[2*c - i - 1]) cm += weight[2*c - i - 1], printf(" %d",weight[2*c - i - 1]);
		imbalance += fabs(cm - am);
		printf("\n");
	}
	printf("IMBALANCE = %.5lf\n\n",imbalance);	
}

int main()
{
	while(cin >> c >> s)
	{
		total = am = 0;
		for(int i =0;i<s;i++)
		{
			scanf("%d",&weight[i]);
			total += weight[i];
		}
		Greedy();
		// Greedy2();

	}
}