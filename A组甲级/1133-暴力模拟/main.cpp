#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int head, N, K;
vector<int> valid, v1, v2, v3;
struct Node{
	int addr;
	int data;
	int next;
	int level = maxn;
	Node(){}
	Node(int a, int d, int n)
	{
		addr = a;
		data = d;
		next = n;
	}
}nodes[maxn];
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &head, &N, &K);
	for(int i = 0; i < N; ++i)
	{
		int aa, dd, nn;
		scanf("%d%d%d", &aa, &dd, &nn);
		nodes[aa] = Node(aa, dd, nn);
	}
	int index = head;
	while(index != -1)//寻找有效节点 
	{
		valid.push_back(nodes[index].addr);
		index = nodes[index].next;
	}
	for(int i = 0; i < valid.size(); ++i)
	{
		int pos = valid[i];
		if(nodes[pos].data < 0)
			v1.push_back(nodes[pos].addr);
		else if(nodes[pos].data <= K)
			v2.push_back(nodes[pos].addr);
		else
			v3.push_back(nodes[pos].addr);
	}
	for(int i = 0; i < v2.size(); ++i)
	{
		v1.push_back(v2[i]);
	} 
	for(int i = 0; i < v3.size(); ++i)
	{
		v1.push_back(v3[i]);
	} 
	for(int i = 0; i < v1.size(); ++i)
	{
		int pos = v1[i];
		if(i < v1.size() - 1)
		{
			int nextpos = v1[i + 1];
			printf("%05d %d %05d\n", nodes[pos].addr, nodes[pos].data, nodes[nextpos].addr);
		}
		else
			printf("%05d %d %d\n", nodes[pos].addr, nodes[pos].data, -1);
	} 
	return 0;
}
