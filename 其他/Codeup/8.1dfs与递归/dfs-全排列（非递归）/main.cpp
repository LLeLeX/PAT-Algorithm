#include <bits/stdc++.h>
using namespace std;
int n;
stack<int> s;
vector<int> ans;
bool vis[15];
void generate()
{
	int tag = 0;//遍历1~n各数字，0：表示已经形成一个排列了，回退到一个分叉点 
	bool cmplt = false;//标记是否完成一组排列 
	while(!s.empty())//栈不空 
	{
		if(ans.size() == n)//出口，完成一组排列，输出 
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
			if(vis[i] == false)//该数字未被访问过 
			{
				tag = i;
				break;	
			}	
		} 
		if(tag == 0)//完成一组排列
		{
			int temp = s.top();
			vis[temp] = false;
			s.pop();//栈顶元素出栈 
			ans.pop_back();
			cmplt = true;
			continue;
		}
		if(cmplt)//当前已经完成一组排列 
		{
			bool flag = false;//???
			for(int i = s.top() + 1; i<= n; i++)//栈顶元素继续向后遍历 
			{
				if(vis[i] == false)//该元素未被访问过 
				{
					flag = true;//找到新元素 
					tag = i;//重新 
					break;
				}
			}
			//将栈顶元素pop,回退到上一个分叉点 
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
		if(tag != 0)//存储的是有效数字 
		{
			vis[tag] = true;
			ans.push_back(tag);//插入ans中 
			s.push(tag);//入栈 
		}
	}
}
int main(int argc, char** argv) {
	while(~scanf("%d", &n))
	{
		//初始化 
		s.push(1);
		ans.push_back(1);
		vis[1] = true;
		
		generate();
	}
	return 0;
}
