#include <bits/stdc++.h>
using namespace std;
int N, K;
struct Student{
	char name[15];
	int height;
}stu[10005];
int matrix[100][10005];
bool cmp(Student s1, Student s2)
{
	if(s1.height != s2.height)
		return s1.height > s2.height;
	else
		return strcmp(s1.name, s2.name) < 0;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	getchar();
	for(int i = 0; i < N; ++i)
	{
		scanf("%s %d", stu[i].name, &stu[i].height);
		getchar();
	}
	sort(stu, stu + N, cmp);
	
	int col = N / K;//正常一排人数 
	int lastcol = N - (col * (K - 1));
	int x = 1, y = 1;//矩阵的行列
	int cnt = 0, mid = 0;//一排已经排列的人数,中间位置 
	int dir = 0;//表示左右方向 
	
	col = lastcol;
	for(int i = 0; i < N; ++i)
	{	
		if(x > 1) 
			col = N / K;
		if(cnt == col)//一行排满 
		{
			x++;
			cnt = 0;
			dir = 0; 
			i--;
			continue;
		}
		if(cnt == 0)
		{
			mid = (col / 2) + 1;
			y = mid;
		}
		else if(cnt % 2 == 1)//先往右排 
		{
			dir++;
			y = mid - dir;
		}
		else
		{
			y = mid + dir;
		}
		matrix[x][y] = i;
		cnt++;		
	}
	
	col = lastcol;
	for(int i = 1; i <= K; i++)
	{
		if(i > 1)
			col = N / K;
		for(int j = 1; j <= col; j++)
		{
			int index = matrix[i][j];
			printf("%s", stu[index].name);
			if(j < col)
				printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
