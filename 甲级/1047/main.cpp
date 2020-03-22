#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> stuClass[2510];
void getName(int id, char s[])
{
	s[3] = '0' + id % 10;
	id /= 10;
	for(int i = 2; i >= 0; i--)
	{
		s[i] = 'A' + id % 26;
		id /= 26;
	}
}
int getid(char s[])
{
	int id = 0;
	for(int i = 0; i <= 3; i++)
	{
		if(i == 3)
		{
			id = id * 10 + s[i] - '0';
		}
		else
		{
			id = id * 26 + s[i] - 'A';
		}	
	}
	return id;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	while(N--)
	{
		char name[5];
		int numClass;
		scanf("%s %d", name, &numClass);
		int id = getid(name);
		for(int i = 0; i < numClass; i++)
		{
			int classID;
			scanf("%d", &classID);
			stuClass[classID].push_back(id);
		}
	}
	for(int i = 1; i <= K; i++)
	{
		int len = stuClass[i].size();
		printf("%d %d\n", i, len);
		sort(stuClass[i].begin(), stuClass[i].end());
		for(int j = 0; j < len; j++)
		{
			int id = stuClass[i][j];
			char s[5];
			getName(id, s);
			printf("%s\n", s);
		}	
	}
	return 0;
}
