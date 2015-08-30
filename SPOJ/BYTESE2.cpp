#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
	unsigned int testcases;
	scanf("%d",&testcases);

	for(unsigned int i=0;i<testcases;i++)
	{
		unsigned int start,end,people;
		scanf("%d",&people);
		vector<unsigned int> starts,ends,all;
		for(unsigned int j=0;j<people;j++)
		{
			scanf("%d %d",&start,&end);
			starts.push_back(start);
			ends.push_back(end);
			all.push_back(start);
			all.push_back(end);
		}

		unsigned long long max_people = 0;
		unsigned long long temp = 0;
		for(unsigned int j=0;j<all.size();j++)
		{
			temp=0;
			for(unsigned int k=0;k<starts.size();k++)
				if(all[j]>=starts[k] && all[j]<ends[k])
					temp++;
			max_people = max(max_people, temp);
		}
		cout << max_people << endl;
	}
}