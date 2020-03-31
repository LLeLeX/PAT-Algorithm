#include <bits/stdc++.h>
using namespace std;
int N, K;
struct person{
	char name[10];
	int age;
	int worth;
	person(){}
	person(char *s, int a, int w)
	{
		strcpy(name, s);
		age = a;
		worth = w;
	}
}people[100005];
bool cmp(person p1, person p2)
{
	if(p1.worth != p2.worth)
	{
		return p1.worth > p2.worth;
	}
	else
	{
		if(p1.age != p2.age)
		{
			return p1.age < p2.age;
		}
		else
		{
			return strcmp(p1.name, p2.name) < 0;
		}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++)
	{
		char s[10];
		int a, w;
		scanf("%s %d %d", s, &a, &w);
		people[i] = person(s, a, w);
	}
	sort(people, people + N, cmp);
	for(int i = 1; i <= K; i++)
	{
		int cnt, minage, maxage;
		bool flag = false;
		scanf("%d%d%d", &cnt, &minage, &maxage);
		printf("Case #%d:\n", i);
		for(int j = 0; j < N; j++)
		{
			if(!cnt)
			{
				break;
			}
			if(people[j].age >= minage && people[j].age <= maxage)
			{
				printf("%s %d %d\n", people[j].name, people[j].age, people[j].worth);
				cnt--;
				flag = true;
			}
		}
		if(flag == false)
		{
			printf("None");
		}
	}
	return 0;
} 
