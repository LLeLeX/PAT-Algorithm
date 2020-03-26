#include <bits/stdc++.h>
using namespace std;
struct Node{
	double num;
	char op;
	bool flag;//true:nums false:op
};
map<char, int> mp; 
string str; 
double compute(double n1, double n2, char c)
{
	switch(c)
	{
		case '+':
			return n1 + n2; 
			break;
		case '-':
			return n1 - n2;
			break;
		case '*':
			return n1 * n2;
			break;
		case '/':
			return n1 / n2;
			break;
	}
}
int main(int argc, char *argv[]) {
	//������������ȼ� 
	mp['*'] = mp['/'] = 1;
	mp['+'] = mp['-'] = 0; 
	while(getline(cin, str), str != "0")
	{
		queue<Node> q;//��ź�׺���ʽ
		stack<Node> ops;
		int len = str.length();
		for(int i = 0; i < len; i++)
		{
			if(str[i] == ' ')
			{
				str.erase(i, 1);
			}
		}
		//�ַ���ת��Ϊ����
		len = str.length(); 
		string tempstr;
		Node tempnode;
		for(int i = 0; i <= len; i++)//i <= len �����һλ��Ϊ�������һ��������� 
		{
			if(str[i] >= '0' && str[i] <= '9')//�������������ָ� 
			{
				tempstr += str[i]; 
			}
			else//���������� 
			{
				//�Ƚ��ָ�õĲ�������� 
				int tempnum;
				sscanf(tempstr.c_str(), "%d", &tempnum);
				tempnode.num = tempnum * 1.00;
				tempnode.flag = true;
				q.push(tempnode);
				tempstr.clear();
				tempnode.op = str[i];
				tempnode.flag = false;
				//�ٴ��������
				if(!ops.empty())//��ջ�ǿ�ʱ 
				{
					if(mp[str[i]] > mp[ops.top().op])//��ǰ���������ȼ�����ջ�����ȼ�ʱ 
					{
						ops.push(tempnode);//�����ȼ��Ĳ�������ջ 
					}
					else//��ǰ���������ȼ����ڻ����ջ�����ȼ�ʱ 
					{
						while(!ops.empty() && mp[ops.top().op] >= mp[str[i]])//ջ��Ԫ�ز��ϳ�ջ��ֱ������str[i]�����ȼ� 
						{
							q.push(ops.top());
							ops.pop();
						}
						ops.push(tempnode); 
					}
				} 
				else//��ǰջΪ�� 
				{	
					ops.push(tempnode);
				}		
			}
		}
		while(!ops.empty())
		{
			q.push(ops.top());
			ops.pop();
		}
		int qlen = q.size() - 1;
		//cout << qlen << endl;
		//�����׺���ʽ 
		/*while(!q.empty())
		{		
			if(q.front().flag == true)
			{
				cout << q.front().num << " " << q.front().flag << endl;
			}
			else
			{
				cout << q.front().op << " " << q.front().flag << endl;
			}
			q.pop();
		}
		printf("\n");*/
		double num1, num2;//��¼�������ĸ��� 
		Node tempans;
		stack<Node> nums;
		while(qlen--)
		{
			if(q.front().flag == true)//�ǲ����� 
			{
				nums.push(q.front());
				q.pop();
			}
			else//��ǰ�ǲ����� 
			{
				num2 = nums.top().num;
				nums.pop();
				num1 = nums.top().num;
				nums.pop();
				tempans.num = compute(num1, num2, q.front().op);
				tempans.flag = true;
				nums.push(tempans);
				q.pop();
			}
		} 
		printf("%.2f\n", nums.top().num);
	}
	return 0;
}
