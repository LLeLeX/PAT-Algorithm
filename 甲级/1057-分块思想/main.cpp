#include <bits/stdc++.h>
using namespace std;
int T, blockNum, eleNum; 
stack<int> s;
int range = 100000;
int block[500], table[100005];
int getKth(int K)
{
	int ans = 0, sum = 0, idx = 0;//idx¿éºÅ 
	bool cmplt = false;
	while(sum + block[idx] < K)
	{
		sum += block[idx++];
	}
	int num = idx * eleNum;
	while(sum + table[num] < K)
	{
		sum += table[num++];
	}
	return num;
}


int main(int argc, char *argv[]) {
	scanf("%d", &T);
	getchar();
	blockNum = (int)sqrt(1.0 * range) + 1;
	eleNum = (int)sqrt(1.0 * range + 1);
	while(T--)
	{
		char query[50];
		int key;
		scanf("%s", query);
		//fgets(query, 50, stdin);
		if(query[1] == 'u')//push
		{
			scanf("%d", &key);
			//key = query[5] - '0';
			//cout << "Key:" << key << endl;
			table[key]++;
			block[key / eleNum]++;
			s.push(key);
		}
		else if(query[1] == 'o')//pop
		{
			if(s.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				key = s.top();
				s.pop();
				table[key]--;
				block[key / eleNum]--;
				printf("%d\n", key);
			}
		}
		else//peekMedian
		{
			if(s.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				if(s.size() % 2 == 1)
				{
					int temp = (s.size() + 1) / 2;
					printf("%d\n", getKth(temp));
				}
				else
				{
					int temp = s.size() / 2;
					printf("%d\n", getKth(temp));
				}
			}
		}
	}
	return 0;
}
