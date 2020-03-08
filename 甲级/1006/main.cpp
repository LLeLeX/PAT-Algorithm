#include <bits/stdc++.h>
using namespace std;
int M;
struct person{
	char id[20];
	int h1, h2, m1, m2, s1, s2;
	person(){}
}peo[10005];
bool cmpEarly(person p1, person p2)
{
	if(p1.h1 != p2.h1)
	{
		return p1.h1 < p2.h1;
	}
	else if(p1.m1 != p2.m1)
	{
		return p1.m1 < p2.m1;
	}
	else
	{
		return p1.s1 < p2.s1;
	}
}
bool cmpLast(person p1, person p2)
{
	if(p1.h2 != p2.h2)
	{
		return p1.h2 > p2.h2;
	}
	else if(p1.m2 != p2.m2)
	{
		return p1.m2 > p2.m2;
	}
	else
	{
		return p1.s2 > p2.s2;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	{
		scanf("%s", peo[i].id);
		scanf("%d:%d:%d", &peo[i].h1, &peo[i].m1, &peo[i].s1);
		scanf("%d:%d:%d", &peo[i].h2, &peo[i].m2, &peo[i].s2);
	}
	sort(peo, peo + M, cmpEarly);
	printf("%s ", peo[0].id);
	sort(peo, peo + M, cmpLast);
	printf("%s", peo[0].id);
	return 0;
}
