#include <bits/stdc++.h>
using namespace std;
int np, ng;
struct mouse{
	int wei;
	int rank;
}mice[1005];
queue<int> q;
int main(int argc, char *argv[]) {
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++)
	{
		scanf("%d", &mice[i].wei);
	}
	for(int i = 0; i < np; i++)
	{
		int temp;
		scanf("%d", &temp);
		q.push(temp);
	}
	while(q.size() >= 1)
	{
		//cout << "***" << q.size() << endl;
		//分组
		int group;
		int cntnp = q.size();
		if(q.size() == 1)
		{
			mice[q.front()].rank = 1;
			break;
		}
		if(q.size() % ng == 0)
		{
			group = q.size() / ng;
		} 
		else
		{
			group = q.size() / ng + 1;
		}
		//比较
		for(int i = 0; i < group; i++)
		{
			int indexMax = q.front();
			for(int j = 0; j < ng; j++)
			{
				int index = q.front();
				if(i * ng + j >= cntnp)//处理最后一组不满的情况 
				{
					break;
				}
				if(mice[indexMax].wei < mice[index].wei)
				{
					indexMax = index;
				}
				mice[index].rank = group + 1;
				q.pop();
			} 
			q.push(indexMax);
		} 	
	}
	for(int i = 0; i < np; i++)
	{
		printf("%d", mice[i].rank);
		if(i < np - 1)
		{
			printf(" ");
		}
	}
	return 0;
}
