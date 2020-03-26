#include <bits/stdc++.h>
using namespace std;
struct node{
	double num;
	char op;
	bool flag;
};
string str;
stack<node> s;
queue<node> q;
map<char, int> op;
//中缀转后缀 
void Change()
{
	double num;
	node temp;
	for(int i = 0; i < str.length();)//暂不定义for执行后i的变化情况 
	{
		if(str[i] >= '0' && str[i] <= '9')//是操作数 
		{
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i < str.length() && str[i] >= '0' && str[i] <= '9')
			{
				temp.num = temp.num * 10 + str[i] - '0';
				i++;
			}
			q.push(temp);
		}
		else//是操作符 
		{
			temp.flag = false;
			temp.op = str[i];
			//关于括号 
			if(str[i] == '(')
			{
				s.push(temp);
				i++;
				continue;
			}
			if(str[i] == ')')
			{
				while(!s.empty() && s.top().op != '(')
				{
					q.push(s.top());
					s.pop();
				}
				s.pop();
				i++;
				continue;
			}
			while(!s.empty() && op[s.top().op] >= op[str[i]])
			{
				q.push(s.top());
				s.pop();
			} 	
			s.push(temp);
			i++;
		}
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	//输出后缀表达式 
	/*while(!q.empty())
	{		
		if(q.front().flag == true)
		{
			cout << q.front().num;
		}
		else
		{
			cout << q.front().op;
		}
		q.pop();
	}
	printf("\n");*/
}
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
double calculate()
{
	double temp1, temp2;
	node cur, temp;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		if(cur.flag == true)//是操作数 
		{
			s.push(cur);
		} 
		else
		{
			temp2 = s.top().num;
			s.pop();
			temp1 = s.top().num;
			s.pop();
			temp.flag = true;
			temp.num = compute(temp1, temp2, cur.op);
			s.push(temp);
		}
	}
	return s.top().num;
} 
int main(int argc, char *argv[]) {
	op['+'] = op['-'] = 1;
	op['*'] = op['/'] = 2;
	while(getline(cin, str), str != "0")
	{
		for(string::iterator it = str.end(); it != str.begin(); it--)//倒叙 
		{
			if(*it == ' ')
			{
				str.erase(it);
			}
		}
		while(!s.empty())//清空栈，初始化栈 
		{
			s.pop();
		}
		Change();
		double ans = calculate();
		printf("%.2f\n", ans);
	}
	return 0;
}
