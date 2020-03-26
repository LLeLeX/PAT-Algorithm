#include <bits/stdc++.h>
using namespace std;
string str;
stack<double> nums;
stack<char> ops;
int convert(string s)
{
	int len = s.length();
	int num = 0;
	for(int i = 0; i < len; i++)
	{
		num = num * 10 + str[i] - '0';
	}
	return num;
} 
double compute(int num1, int num2, char op)
{
	double ans = 0;
	switch(op)
	{
		case '+':
					ans = num1 + num2;
					break;
		case '-':
					ans = num1 - num2;
					break;
		case '/':
					ans = num1 / num2;
					break;
		case '*':
					ans = num1 * num2;
					break;		
	} 
	return ans;
}
int main(int argc, char *argv[]) {
	while(getline(cin, str), str != "0")
	{
		int len = str.length();
		//ȥ�ո� 
		for(int i = 0; i < len; i++)
		{
			if(str[i] == ' ')
			{
				str.erase(i, 1);
			}
		}
		//ת�����ֺͲ����������� 
		string tempStr;//��Ų��������ַ�����ʽ 
		for(int i = 0; i < len; i++)
		{
			if(str[i] >= '0' && str[i] <= '9')//�ַ��ָ� 
			{
				tempStr += str[i];
			}
			else
			{
				int tempNum = convert(tempStr);
				nums.push(tempNum);//��������ջ 
				//ops.push(str[i]);
				tempStr.clear();
				if(str[i] != '+' && str[i] != '/')
				{
					if(nums.size() >= 2)
					{
						if(ops.top() == '*' || ops.top() == '/')
						{
							int num2 = nums.top();
							nums.pop();
							int num1 = nums.top();
							nums.pop();
							int ans = compute(num1, num2, ops.top());
							nums.push(ans);
							ops.pop();
						}
					}
					ops.push(str[i]);
				}
				else
				{
					if(nums.size() >= 2)
					{
						char op = ops.top();
						ops.pop();
						int num2 = nums.top();
						nums.pop();
						int num1 = nums.top();
						nums.pop();
						int ans = compute(num1, num2, op);
						nums.push(ans);
					}
					ops.push(str[i]);
				} 
			}
			if(i == len - 1)
			{
				int tempNum = convert(tempStr);
				nums.push(tempNum);
			}
		}
		//cout << str << endl;
		while(!ops.empty())
		{
			char op = ops.top();
			int num2 = nums.top();
			nums.pop();
			int num1 = nums.top();
			nums.pop();
			int ans = compute(num1, num2, op);
			nums.push(ans);
			ops.pop();
		}
		cout << nums.top() << endl;	
	}
	return 0;
}
