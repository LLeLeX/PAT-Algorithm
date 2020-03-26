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
	//设置运算符优先级 
	mp['*'] = mp['/'] = 1;
	mp['+'] = mp['-'] = 0; 
	while(getline(cin, str), str != "0")
	{
		queue<Node> q;//存放后缀表达式
		stack<Node> ops;
		int len = str.length();
		for(int i = 0; i < len; i++)
		{
			if(str[i] == ' ')
			{
				str.erase(i, 1);
			}
		}
		//字符串转换为数字
		len = str.length(); 
		string tempstr;
		Node tempnode;
		for(int i = 0; i <= len; i++)//i <= len 多出来一位，为了让最后一个数字入队 
		{
			if(str[i] >= '0' && str[i] <= '9')//遇到操作数，分割 
			{
				tempstr += str[i]; 
			}
			else//遇到操作符 
			{
				//先将分割好的操作数入队 
				int tempnum;
				sscanf(tempstr.c_str(), "%d", &tempnum);
				tempnode.num = tempnum * 1.00;
				tempnode.flag = true;
				q.push(tempnode);
				tempstr.clear();
				tempnode.op = str[i];
				tempnode.flag = false;
				//再处理操作符
				if(!ops.empty())//当栈非空时 
				{
					if(mp[str[i]] > mp[ops.top().op])//当前操作符优先级高于栈顶优先级时 
					{
						ops.push(tempnode);//高优先级的操作符入栈 
					}
					else//当前操作符优先级等于或低于栈顶优先级时 
					{
						while(!ops.empty() && mp[ops.top().op] >= mp[str[i]])//栈顶元素不断出栈，直到低于str[i]的优先级 
						{
							q.push(ops.top());
							ops.pop();
						}
						ops.push(tempnode); 
					}
				} 
				else//当前栈为空 
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
		//输出后缀表达式 
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
		double num1, num2;//记录操作数的个数 
		Node tempans;
		stack<Node> nums;
		while(qlen--)
		{
			if(q.front().flag == true)//是操作数 
			{
				nums.push(q.front());
				q.pop();
			}
			else//当前是操作符 
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
