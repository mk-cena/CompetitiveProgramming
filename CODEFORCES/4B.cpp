#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int d, sumTime, hours[250], q, rem;
pair<int, int>schedule[250];


/*
	- if the remainder (hours) is -ve, 
		take hours greedly from each day whose mintime < q,
		until the remainder is neutralized 
	- if the remainder (hours) is +ve, 
		add hours greedly to each day whose maxtime > q,
		until the remainder is neutralized
*/

void Greedy()
{
	for(int i=0;i<d;i++)
		if(q > schedule[i].first && rem < 0 || 
		   q < schedule[i].second && rem > 0)
		{
			int x = hours[i] - (rem < 0?schedule[i].first:schedule[i].second);
			if(abs(rem) > abs(x))
			{
				hours[i] = (rem < 0?schedule[i].first:schedule[i].second);
				rem += x;
			}
			else
			{
				hours[i] += rem; 
				rem = 0;
				return;
			}
		}
}

/* 
	- distribute the total hours naively over all the days q = sumTime/d
	- store the remainder rem = sumTime % d
	- add to the remainder if the maxtime of the day is less than q
	- subtract from the remainder if the mintime of the day is greater than q
	- Call Greedy to distribute the remainder
*/

void Naive()
{
	q = sumTime / d;
	rem = sumTime % d;
	for(int i=0;i<d;i++)
	{
		scanf("%d %d", &schedule[i].first, &schedule[i].second);
		if(schedule[i].first > q)
		{
			hours[i] = schedule[i].first;
			rem -= (schedule[i].first - q);
		}
		else
			if(schedule[i].second < q)
			{
				hours[i] = schedule[i].second;
				rem += (q - schedule[i].second);
			}
			else
				hours[i] = q;
	}
}

void Print()
{
	if(rem == 0)
	{
		printf("YES\n");
		for(int i=0;i<d;i++)
			printf("%d ",hours[i]);
	}
	else
		printf("NO");
}

int main()
{
	scanf("%d %d", &d, &sumTime);
	Naive();
	Greedy();
	Print();
}