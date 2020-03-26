#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int cnt, dir[4] = {-3, 3, 1, -1};//在1维字符串中的移动，相当于3*3矩阵的上下左右移动 
int factorial[15] {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};//0-10阶乘 
int garray[10];
void arraycpy(int a[], int b[])//将数组a赋值给数组b 
{
	for(int i = 0; i < 9; i++)
	{
		b[i] = a[i];
	}
}
struct Node{
	int array[10];
	int status;//存储当前数组状态对应的康托展开 
	int step;//步数 
	int pos0; //标记0的位置来替换find() 
	Node(){}
	Node(int arr[], int ss, int s, int p){
		status = ss;
		step = s;
		pos0 = p;
		arraycpy(arr, array);
	}
}originNode, resultNode;
int cantor(int a[])//康托展开 
{
	int ans = 0, sum = 0;
	for(int i = 0; i < 8; ++i)
	{
		for(int j = i + 1; j <= 8; ++j)
		{
			if(a[j] < a[i])
			{
				sum++;
			}
		}
		ans += sum * factorial[8 - i];
		sum = 0;
	}
	return ans + 1;
} 
int arrswap(int a[], int x, int y)//0与其他数字交换位置 
{
	int temp = a[x];
	a[x] = a[y];
	a[y] = temp;
	return cantor(a);
}
int main(int argc, char *argv[]) {
	while(1)
	{
		DWORD startTime, endTime;
		
		
		queue<Node> q;
		map<int, bool> inq;//状态与bool的映射，表示是否入队 
		int origin[10], result[10];//初始状态和结果状态 
		int cnt = 0, pos0; 
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				scanf("%d", &origin[cnt++]);//初始状态压缩 
				if(origin[cnt - 1] == 0)
					pos0 = 3 * i + j;
			}
		}
		originNode = Node(origin, cantor(origin), 1, pos0);
		cnt = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				scanf("%d", &result[cnt++]);//结果状态压缩 
				if(result[cnt - 1] == 0)
					pos0 = 3 * i + j;
			}
		}
		resultNode = Node(result, cantor(result), 1, pos0);
		//bfs
		startTime = GetTickCount();
		q.push(originNode);
		inq[originNode.status] = true;
		while(!q.empty())
		{
			Node top = q.front();
			q.pop();
			if(top.status == resultNode.status)//与结果状态一致
			{
				printf("%d\n", top.step); 
				break;
			}			
			int index0 = top.pos0;
			for(int i = 0; i < 4; i++)
			{
				int tindex = index0 + dir[i];//上下左右移动"0"后的下标
				if(tindex < 0 || tindex >= 9)//判断是否合法 
					continue; 
				arraycpy(top.array, garray);
				int tstatus = arrswap(garray, index0, tindex);//做交换后的康托展开 
				if(!inq[tstatus])//尚未入队
				{
					Node temp = Node(garray, tstatus, top.step + 1, tindex);
					inq[tstatus] = true;
					q.push(temp);//该节点入队 
				} 	
			} 
		}
		endTime = GetTickCount();
		//printf("%dms\n", endTime - startTime);
		cout << endTime - startTime << "ms" << endl;
	}
	return 0;
}
