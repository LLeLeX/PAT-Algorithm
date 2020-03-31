#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) ((i) & (-i))
const int maxn = 1e5 + 5;
int T;
int c[maxn];
stack<int> st;
void update(int x, int v)
{
	for(int i = x; i < maxn; i += lowbit(i))
	{
		c[i] += v;
	}
}
int getSum(int x)
{
	int sum = 0;
	for(int i = x; i > 0; i -= lowbit(i))
	{
		sum += c[i];
	}
	return sum;
}
int getKth(int K)//二分查找，寻找第一个满足getSum(i) >= K的i 
{
	int l = 1, r = maxn, mid;
	while(l < r)
	{
		mid = (l + r) / 2;
		if(getSum(mid) >= K)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}
int main(int argc, char *argv[]) {
	scanf("%d", &T);
	while(T--)
	{
		char query[20];
		int key;
		scanf("%s", query);
		if(query[1] == 'u')//push
		{
			scanf("%d", &key);
			st.push(key);
			update(key, 1);
		}
		else if(query[1] == 'o')//pop
		{
			if(st.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				key = st.top();
				st.pop();
				update(key, -1);//减去 
				printf("%d\n", key);
			}
		}
		else//peekMedian
		{
			if(st.empty())
			{
				printf("Invalid\n");
			}
			else
			{
				int K = st.size();
				if(K & 1 == 1)
				{
					K = (K + 1) / 2;
				}
				else
				{
					K = K / 2;
				}
				printf("%d\n", getKth(K));
			}	
		}
	}
	return 0;
}
