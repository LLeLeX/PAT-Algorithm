#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int cnt, dir[4] = {-3, 3, 1, -1};//��1ά�ַ����е��ƶ����൱��3*3��������������ƶ� 
struct Node{
	string status;//�洢��ǰ״̬ 
	int step;//���� 
	int pos0; //���0��λ�����滻find() 
	Node(){}
	Node(string ss, int s, int p){
		status = ss;
		step = s;
		pos0 = p;
	}
}node, resultNode;
string strswap(string s, int x, int y)//ִ��״̬ת�� 
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
		map<string, bool> inq;//״̬��bool��ӳ�䣬��ʾ�Ƿ���� 
		string origin, result;//��ʼ״̬�ͽ��״̬ 
		DWORD startTime, endTime;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				char s;
				scanf(" %c", &s);//��ʼ״̬ѹ�� 
				origin += s;
				if(s == '0')
					node.pos0 = 3 * i + j;
			}
		}
		node.status = origin;
		node.step = 1;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				char s;
				scanf(" %c", &s);//���״̬ѹ�� 
				result += s;
				if(s == '0')
					resultNode.pos0 = 3 * i + j;
			}
		}
		resultNode.status = result;
		resultNode.step = -1;
		//bfs
		startTime = GetTickCount();
		q.push(node);
		inq[origin] = true;
		while(!q.empty())
		{
			Node top = q.front();
			q.pop();
			if(top.pos0 == resultNode.pos0)//����0��λ��Ҫһ�� 
			{
				if(top.status == result)//����״̬һ��
				{
					printf("%d\n", top.step); 
					break;
				}
			}			
			int index0 = top.pos0;
			for(int i = 0; i < 4; i++)
			{
				int tindex = index0 + dir[i];//���������ƶ�"0"����±�
				if(tindex < 0 || tindex >= 9)//�ж��Ƿ�Ϸ� 
					continue; 
				string tstatus = strswap(top.status, index0, tindex);//������
				if(!inq[tstatus])//��δ���
				{
					Node temp = Node(tstatus, top.step + 1, tindex);
					inq[tstatus] = true;
					q.push(temp);//�ýڵ���� 
				} 	
			} 
		}
		endTime = GetTickCount();
		cout << endTime - startTime << "ms" << endl;
	}
	return 0;
}
