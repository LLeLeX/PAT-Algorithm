#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005; 
int start1, start2, N, ans = maxn;
bool vis[maxn];//对五位数的地址做标记 
struct Node{
	int addr;
	char data;
	int next;
	Node(){}
	Node(int aa, char dd, int nn){
		addr = aa;
		data = dd;
		next = nn;
	}
}nodes[maxn];
int main(int argc, char** argv) {
	scanf("%d%d%d", &start1, &start2, &N);
	for(int i = 0; i < N; i++)
	{
		int aa, nn;
		char dd;
		scanf("%d %c %d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn); 
	}
	
	//遍历第一个单词 
	int s1 = start1, s2 = start2;
	while(nodes[s1].next != -1)
	{
		vis[s1] = true;
		s1 = nodes[s1].next;
	}
	vis[s1] = true;//标记最后一个节点，即-1
	
	//遍历第二个单词 ，不能用while循环 
	/*while(nodes[s2].next != -1)
	{
		if(vis[s2])//已经被标记了，说明有公共部分 
		{
			ans = s2;
			break;
		}
		//s2 = nodes[s2].next;
		else
		{
			//vis[s2] = true;//有则错误，无则超时 
			s2 = nodes[s2].next;
		}
	}*/
	for(int p = s2; p != -1; p = nodes[p].next)
	{ 
		if(vis[p])//已经被标记了，说明有公共部分 
		{
			ans = p;
			break;
		}
	}
	if(ans < maxn)
		printf("%05d", ans);
	else
		printf("-1");
	return 0;
}
