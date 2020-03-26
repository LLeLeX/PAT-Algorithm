#include <bits/stdc++.h>
#include <windows.h> 
using namespace std;
int cnt, dir[4] = {-3, 3, 1, -1};//在1维字符串中的移动，相当于3*3矩阵的上下左右移动 
struct Node{
	string status;//存储当前状态 
	int step;//步数 
	Node(){}
	Node(string ss, int s){
		status = ss;
		step = s;
	}
};
string strswap(string s, int x, int y)//执行状态转移 
{
	char temp = s[x];
	s[x] = s[y];
	s[y] = temp;
	return s;
}
int main(int argc, char *argv[]) {
	while(1)
	{
		queue<Node> q;
		map<string, bool> inq;//状态与bool的映射，表示是否入队 
		string origin, result;//初始状态和结果状态 
		DWORD startTime, endTime;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				char s;
				scanf(" %c", &s);//初始状态压缩 
				origin += s;
			}
		}
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				char s;
				scanf(" %c", &s);//结果状态压缩 
				result += s;
			}
		}
		//bfs
		startTime = GetTickCount();
		Node node = Node(origin, 1);
		q.push(node);
		inq[origin] = true;
		while(!q.empty())
		{
			Node top = q.front();
			q.pop();
			if(top.status == result)//与结果状态一致
			{
				printf("%d\n", top.step); 
				break;
			}
			int index0 = top.status.find("0");
			for(int i = 0; i < 4; i++)
			{
				int tindex = index0 + dir[i];//上下左右移动后的下标
				if(tindex < 0 || tindex >= 9)//判断是否合法 
					continue; 
				string tstatus = strswap(top.status, index0, tindex);//做交换
				if(!inq[tstatus])//尚未入队
				{
					Node temp = Node(tstatus, top.step + 1);
					inq[tstatus] = true;
					q.push(temp);//该节点入队 
				} 	
			} 
		}
		endTime = GetTickCount();
		cout << endTime - startTime << "ms" << endl;
	}
	return 0;
}
