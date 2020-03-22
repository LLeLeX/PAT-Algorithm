#include <bits/stdc++.h>
using namespace std;
int nc, np; 
int cou[100005];
int pro[100005];
int ans;
bool cmp(int a, int b)
{
	return a > b;
}
int main(int argc, char *argv[]) 
{
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++)
	{
		scanf("%d", &cou[i]);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; i++)
	{
		scanf("%d", &pro[i]);
	}
	int longIndex;//记录较长的数组的下标 
	int shortIndex;//记录较短的数组的下标 
	int cur;//记录停止计算时的位置的下标 
	bool flag = true;//标记此时相乘得数是否为正数了 
	int status;//1:nc > np 2:np > nc
	if(np > nc)
	{
		longIndex = np - 1;
		shortIndex = nc - 1;
		status = 2;
	}
	else
	{
		longIndex = nc - 1;
		shortIndex = np - 1;
		status = 1;
	}
	sort(cou, cou + nc, cmp);
	sort(pro, pro + np, cmp);
	if(np == nc)
	{
		for(int i = 0, j = 0; i < nc, j < np; i++, j++)
		{
			if(cou[i] * pro[j] > 0)
			{
				ans += cou[i] * pro[j];
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		for(int i = 0; i < shortIndex + 1; i++)
		{
			if(flag == false)
			{
				break;
			}
			if(cou[i] * pro[i] > 0)
			{
				ans += cou[i] * pro[i];
			} 
			else
			{
				cur = i; 
				flag = false;
			}
		}
	}
	if(flag == false)
	{
		if(status == 1)//nc > np
		{
			for(int i = shortIndex; i >= cur; i--)
			{
				if(pro[i] * cou[longIndex] > 0)
				{
					ans += pro[i] * cou[longIndex--];
				}
			}
		}
		else if(status == 2)//np > nc
		{
			for(int i = shortIndex; i >= cur; i--)
			{
				if(cou[i] * pro[longIndex] > 0)
				{
					ans += cou[i] * pro[longIndex--];
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
