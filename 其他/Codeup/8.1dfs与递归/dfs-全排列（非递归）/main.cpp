#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
vector<int> ans;
bool vis[15];
void generate()
{
	int tag = 0;//����1~n�����֣�0����ʾ�Ѿ��γ�һ�������ˣ����˵�һ���ֲ�� 
	bool cmplt = false;//����Ƿ����һ������ 
	while(!s.empty())//ջ���� 
	{
		if(ans.size() == n)//���ڣ����һ�����У���� 
		{
			for(int i = 0; i < ans.size(); i++)
			{
				printf("%d ", ans[i]);
			}
			cmplt = true; 
			printf("\n");
		}
		for(int i = 1; i <= n; i++)
		{
			if(vis[i] == false)//������δ�����ʹ� 
			{
				tag = i;
				break;	
			}	
		} 
		if(tag == 0)//���һ������
		{
			int temp = s.top();
			vis[temp] = false;
			s.pop();//ջ��Ԫ�س�ջ 
			ans.pop_back();
			cmplt = true;
			continue;
		}
		if(cmplt)//��ǰ�Ѿ����һ������ 
		{
			bool flag = false;//???
			for(int i = s.top() + 1; i<= n; i++)//ջ��Ԫ�ؼ��������� 
			{
				if(vis[i] == false)//��Ԫ��δ�����ʹ� 
				{
					flag = true;//�ҵ���Ԫ�� 
					tag = i;//���� 
					break;
				}
			}
			//��ջ��Ԫ��pop,���˵���һ���ֲ�� 
			vis[s.top()] = false;
			s.pop();
			ans.pop_back(); 
			if(flag == false)//??
			{
				cmplt = true;
				continue;
			}
			else 
			{
				cmplt = false;
			}
		}
		if(tag != 0)//�洢������Ч���� 
		{
			vis[tag] = true;
			ans.push_back(tag);//����ans�� 
			s.push(tag);//��ջ 
		}
	}
}
int main(int argc, char** argv) {
	while(~scanf("%d", &n))
	{
		//��ʼ�� 
		s.push(1);
		ans.push_back(1);
		vis[1] = true;
		
		generate();
	}
	return 0;
}
