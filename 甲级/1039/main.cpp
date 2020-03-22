#include <bits/stdc++.h>
using namespace std;
const int MAXN = 26 * 26 * 26 * 10 + 5;
int N, K;
char stuName[10];
int hashTable[MAXN];//学生名字的散列 
vector<int> stuClass[MAXN];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	//memset(hashTable, -1, sizeof(hashTable));
	int classID, stuNum, stuIndex = 1;
	while(K--)
	{
		scanf("%d%d", &classID, &stuNum);
		for(int i = 0; i < stuNum; i++)
		{				
			int hashName = 0;	
			scanf("%s", stuName);
			for(int i = 0; i <= 3; i++)
			{
				if(i == 3)
				{
					hashName = hashName * 10 + stuName[i] - '0';
				}
				else
				{
					hashName = hashName * 26 + stuName[i] - 'A';
				}	
			}
			if(hashTable[hashName] == 0)//尚未录入该同学 
			{
				stuClass[stuIndex].push_back(classID);
				hashTable[hashName] = stuIndex;
				++stuIndex;
			}
			else//该同学之前已经录入过 
			{
				int tempIndex = hashTable[hashName];
				stuClass[tempIndex].push_back(classID);
			}
		}
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%s", stuName);
		printf("%s ", stuName);
		int hashName = 0;	
		for(int i = 0; i <= 3; i++)
		{
			if(i == 3)
			{
				hashName = hashName * 10 + stuName[i] - '0';
			}
			else
			{
				hashName = hashName * 26 + stuName[i] - 'A';
			}	
		}
		int tempIndex = hashTable[hashName];
		if(tempIndex == 0)
		{
			printf("0");
		}
		else
		{
			sort(stuClass[tempIndex].begin(), stuClass[tempIndex].end());
			int len = stuClass[tempIndex].size();
			printf("%d", len);
			for(vector<int>::iterator it = stuClass[tempIndex].begin(); it != stuClass[tempIndex].end(); it++)
			{
				printf(" %d", *it);
			}
		}
		printf("\n");
	}
	/*for(int i = 0; i < N; i++)
	{
		for(vector<int>::iterator it = stuClass[i].begin(); it != stuClass[i].end(); it++)
		{
			printf("%d ", *it);
		}
		printf("\n");
	}*/
	return 0;
}
