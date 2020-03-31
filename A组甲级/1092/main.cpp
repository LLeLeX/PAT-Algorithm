#include <bits/stdc++.h>
using namespace std;
char need[1005], give[1005];
int hash1[200], hash2[200];
int len1, len2;
int main(int argc, char *argv[]) {
	scanf("%s", give);
	scanf("%s", need);
	len1 = strlen(give);
	len2 = strlen(need);
	bool cmplt = true;
	for(int i = 0; i < len1; ++i)
	{
		int index = give[i];
		hash1[index]++;
	}
	for(int i = 0; i < len2; ++i)
	{
		int index = need[i];
		hash2[index]++;
	}
	int cnt = 0;
	for(int i = 0; i < 135; i++)
	{
		if(hash1[i] >= hash2[i])
			continue;
		else
		{
			cmplt = false;
			cnt += hash2[i] - hash1[i];
		}
	}
	if(cmplt == true)
	{
		printf("Yes %d", len1 - len2);
	}
	else
	{
		printf("No %d", cnt);
	}
	return 0;
}
