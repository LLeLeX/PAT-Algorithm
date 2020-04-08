//完全二叉树的判断依据是：层序遍历该二叉树，1、若当前节点的左孩子为空，右孩子不为空，则非完全二叉树；
//2、若发现某个节点没有右孩子则进行标记，在这之后入队的节点如果不是叶子节点那么就不是完全二叉树。
#include <bits/stdc++.h>
using namespace std;
int hashtable[25];//寻找根节点 
bool inq[25];
int N, root;
struct Node{
	int data;
	int left, right;
	Node(){}
	Node(int d, int l, int r)
	{
		data = d;
		left = l;
		right = r;
	}
}nodes[105];
int bfs(int cnt)
{
	bool isleaf = false;
	queue<Node> q;
	q.push(nodes[root]);
	inq[root] = true;
	while(!q.empty())
	{
		Node now = q.front();
		q.pop();
		cnt++;//出队时方才计数，不能在入队时计数 
		//判断 
		if(isleaf == true)
		{
			if(now.left != -1 || now.right != -1)
				return -1;
		}
		if(now.left == -1 && now.right != -1)//左孩子为空，右孩子不空 
			return -1;
			
		//if(now.left == -1 && now.right == -1)！！！此条件错误 
		if(now.right == -1)//左孩子不空，右孩子空 
		{
			isleaf = true;//后面入队的均为叶子节点 
		}
		if(cnt == N)
			return now.data;
		//入队
		if(now.left != -1)
		{
			q.push(nodes[now.left]);
			inq[now.left] = true;
		}
		if(now.right != -1)
		{
			q.push(nodes[now.right]);
			inq[now.right] = true;
		}
		/*if(q.empty())//与cnt == N均可作为判断条件，二选一 
			return now.data;*/
	}
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	//getchar();
	for(int i = 0; i < N; ++i)
	{
		char l[3], r[3];//注意数据范围是0~20，因此不能用单个字符接收，否则无法接收12,13等两位数数据 
		int ll, rr;
		//getchar();
		scanf("%s %s", l, r);
		if(l[0] == '-')
			ll = -1;
		else
			sscanf(l, "%d", &ll);
		if(r[0] == '-')
			rr = -1;
		else
			sscanf(r, "%d", &rr);
		nodes[i] = Node(i, ll, rr);
		hashtable[ll] = hashtable[rr] = 1;
	}
	for(int i = 0; i < N; ++i)
	{
		if(hashtable[i] == 0)
		{
			root = i;
			break;
		}
	}
	int flag = bfs(0);
	if(flag == -1)//不是完全二叉树 
	{
		printf("NO %d", root);
	}
	else
	{
		printf("YES %d", flag);
	}
	return 0;
}
