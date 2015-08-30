#include <iostream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

int n,d,times[2010];
pair<int,int>msgs[2010];
map<string,int>id;
string name[2010];
bool friends[2010][2010];
vector<int> sol;

void Greedy()
{
	for(int i=0;i<n-1;i++)
		for(int j = i + 1;j<n;j++)
		{
			if(times[j] - times[i] == 0) continue;

			if(times[j] - times[i] > d) break;

			if(msgs[i].first == msgs[j].second && 
			   msgs[i].second == msgs[j].first &&
			   times[j] - times[i] > 0 &&
			   times[j] - times[i] <= d &&
			   !friends[msgs[i].first][msgs[i].second])
			{
				friends[msgs[i].first][msgs[i].second] = friends[msgs[i].second][msgs[i].first] = true;
				sol.push_back(i);
				break;
			}

		}
}

int main()
{
	int index = 0;
	char x[25],y[25];
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%s %s %d",x,y,&times[i]);
		if(!id[x])
		{
			index++;
			name[index] = x;
			id[x] = index;
		}
		if(!id[y])
		{
			index++;
			name[index] = y;
			id[y] = index;
		}
		msgs[i].first = id[x];
		msgs[i].second = id[y];
	}
	Greedy();

	printf("%d\n",(int)sol.size());
	for(int i=0;i<sol.size();i++)
		printf("%s %s\n",name[msgs[sol[i]].first].c_str(),name[msgs[sol[i]].second].c_str());
}