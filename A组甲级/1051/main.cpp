#include <bits/stdc++.h>
using namespace std;
int m, n, k;
int main(int argc, char *argv[]) {
	scanf("%d%d%d", &m, &n, &k);
	while(k--)
	{
		stack<int> s;
		int arr[1005] = {0};
		int num = 1, index = 0;
		bool cmplt = true;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}
		s.push(num++);//1入栈 
		for(int j = 0; j < n; j++)
		{
			if(s.empty())
			{
				s.push(num++);
			}
			if(s.top() == arr[j])//输出序列和栈顶元素相同 
			{
				//cout << "***" << s.top() << endl;
				s.pop();
			}
			else
			{
				if(num <= n)
				{
					s.push(num++);
					j--;
				}
				else
				{
					cmplt = false;
					break;
				}
			}
			if(s.size() > m)
			{
				cmplt = false;
				break;
			} 
		}	
		if(cmplt)
		{
			printf("YES\n");
		}		
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
