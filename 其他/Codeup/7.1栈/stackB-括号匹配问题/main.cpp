#include <bits/stdc++.h>
using namespace std;
int N;
string str;
int main(int argc, char *argv[]) {
	while(scanf("%d", &N) != EOF)
	{
		while(N--)
		{
			stack<char> s;
			bool cmplt = true;
			cin >> str;
			int len = str.length();
			if(len & 1)
			{
				cmplt = false;
			}
			for(int i = 0; i < len; i++)
			{
				if(!cmplt)
				{
					break;
				}
				if(str[i] == '(' || str[i] == '[' || str[i] == '{')
				{
					s.push(str[i]);
				}
				else if(str[i] == ')')
				{
					//������û������������ 
					while(!s.empty() && s.top() != '(')
					{
						s.pop();
					}
					if(s.empty())//ջ�� 
					{
						cmplt = false;
					}
					else//�ҵ������� 
					{
						s.pop();//�����ŵ��� 
						continue;
					}
				}
				else if(str[i] == ']')
				{
					while(!s.empty() && s.top() != '[')
					{
						s.pop();
					}
					if(s.empty())//ջ�� 
					{
						cmplt = false;
					}
					else//�ҵ������� 
					{
						s.pop();//�����ŵ��� 
						continue;
					}
				}
				else if(str[i] == '}')
				{
					while(!s.empty() && s.top() != '{')
					{
						s.pop();
					}
					if(s.empty())//ջ�� 
					{
						cmplt = false;
					}
					else//�ҵ������� 
					{
						s.pop();//�����ŵ��� 
						continue;
					}
				}
			}
			if(!cmplt)
			{
				printf("no\n");
			}
			else
			{
				printf("yes\n");
			}
		}
	}
	
	return 0;
}
