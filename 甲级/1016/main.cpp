#include <bits/stdc++.h>
using namespace std;
int rate[30];
int N;
struct records{
	char name[25];
	int month, day, hour, minute;
	bool status;//true:online,false:offline
	records(){}
}rec[1005];
bool cmpNameTime(records r1, records r2)
{
	if(strcmp(r1.name, r2.name))//名字不同 
	{
		return strcmp(r1.name, r2.name) < 0;
	}
	else//名字相同 
	{
		if(r1.month != r2.month)//月份不同 
		{
			return r1.month < r2.month;
		}
		else
		{
			if(r1.day != r2.day)//日期不同 
			{
				return r1.day < r2.day;
			}
			else
			{
				if(r1.hour != r2.hour)//小时不同 
				{
					return r1.hour < r2.hour;
				}
				else
				{
					return r1.minute < r2.minute;
				}
			}
		}
	}
}
void getMoney(int on, int off, int& money)
{
	records start = rec[on];
	records endd = rec[off];
	while(start.day < endd.day || start.hour < endd.hour || start.minute < endd.minute)
	{
		money += rate[start.hour];
		start.minute++;
		if(start.minute >= 60)//分钟进位 
		{
			start.minute = 0;
			start.hour++;
		}
		if(start.hour >= 24)//小时进位 
		{
			start.hour = 0;
			start.day++;
		}
	}
}
int main(int argc, char *argv[]) {
	for(int i = 0; i < 24; i++)
	{
		scanf("%d", &rate[i]);
	}
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		char sta[20];
		scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].month, &rec[i].day, &rec[i].hour, &rec[i].minute, sta);
		if(!strcmp(sta, "on-line"))
		{
			rec[i].status = true;
		}
		if(!strcmp(sta, "off-line"))
		{
			rec[i].status = false;
		}
	}
	sort(rec, rec + N, cmpNameTime);
	//next下一个用户，cnt记录合法可输出的记录，on，off标记合法记录的开始与结束的位置 
	int next = 0, cnt = 0, on = 0, off = 0;
	//始终是用next在遍历每一个用户的所有账单 
	while(on < N)//一次循环一个用户 
	{
		next = on;
		cnt = 0;
		while(next < N && !strcmp(rec[next].name, rec[on].name))//判断用户名是否相同(在同一个用户记录中循环) 
		{
			if(cnt == 0 && rec[next].status == true)//找到第一个online 
			{
				cnt = 1; 
				//on = next;//记录一下online的位置 !!!!!不严谨 
			} 
			else if(cnt == 1 && rec[next].status == false)//在找到第一个online后又找到了offline 
			{
				cnt = 2;
				//off = next;//记录一下offline 的位置 !!!!不严谨 
			}
			next++;
		}
		if(cnt < 2)//没有合法记录 
		{
			on = next;//next此时已经到下一个用户的第一条记录的位置 
			continue;
		}
		printf("%s %02d\n", rec[on].name, rec[on].month);
		int totalMoney = 0;
		while(on < next)//此时on已经表示第一个online 
		{
			while(on < next - 1 && !(rec[on].status == true && rec[on + 1].status == false))
			{
				on++;
			}
			off = on + 1; 
			if(off == next)
			{
				on = next;
				break;
			}
			printf("%02d:%02d:%02d %02d:%02d:%02d ", rec[on].day, rec[on].hour, rec[on].minute, rec[off].day, rec[off].hour, rec[off].minute);
			int money = 0, totalTime = 0;
			//求总时间 
			int startTime = rec[on].day * 24 * 60 + rec[on].hour * 60 + rec[on].minute;
			int endTime = rec[off].day * 24 * 60 + rec[off].hour * 60 + rec[off].minute;
			totalTime = endTime - startTime;
			printf("%d ", totalTime);
			//求金额,美分转化为美元 
			getMoney(on, off, money);
			totalMoney += money;
			printf("$%.2f\n", money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", totalMoney / 100.0);
	}
	
	/*for(int i = 0; i < N; i++)
	{
		cout << rec[i].name << " " << rec[i].month << " " << rec[i].day << " " << rec[i].hour << " " << rec[i].minute << " " << rec[i].status << endl;
	} */
	return 0;
}
