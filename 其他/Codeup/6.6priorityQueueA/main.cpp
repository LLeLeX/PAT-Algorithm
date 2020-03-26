#include <bits/stdc++.h>
using namespace std;
int n;
map<string, int> prioTask;
struct task{
	string name;
	int priority;
	friend bool operator < (task t1, task t2)
	{
		if(t1.priority != t2.priority)
		{
			return t1.priority < t2.priority;
		}
		else
		{
			return t1.name > t2.name;
		}
	}
}t[100005];
string preProcess(string &str)//字符串分割与优先级设置 
{
	string tempstr;
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(str[i] == '(')
		{
			prioTask.insert(make_pair(tempstr, 0)); 
			break;	
		}
		tempstr += str[i];
	}
	int j = 5;
	while(j < len - 1)
	{
		if(str.substr(j + 1, 4) != "NULL")
		{
			prioTask[tempstr]++;
			j += 6;
		}
		else if(str.substr(j + 1, 4) == "NULL")
		{
			break;
		}
	} 
	return tempstr;
}
int main(int argc, char *argv[]) {
	while(scanf("%d", &n) != EOF)
	{
		priority_queue<task> q;
		prioTask.clear();
		for(int i  = 0; i < n; i++)
		{
			string str;
			cin >> str;
			preProcess(str);
			t[i].name = preProcess(str);
			t[i].priority = prioTask[t[i].name];
			q.push(t[i]);
		}
		while(!q.empty())
		{
			cout << q.top().name << " ";
			q.pop();
		}
		printf("\n");
		/*for(int i = 0; i < n; i++)
		{
			cout << t[i].name << " " << t[i].priority << endl;
		}*/
		/*cout << prioTask["Task0"] << endl;
		cout << prioTask["Task1"] << endl;
		cout << prioTask["Task2"] << endl;
		cout << prioTask["Task3"] << endl;*/
	}
	return 0;
}
