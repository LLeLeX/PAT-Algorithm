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
	if(strcmp(r1.name, r2.name))//���ֲ�ͬ 
	{
		return strcmp(r1.name, r2.name) < 0;
	}
	else//������ͬ 
	{
		if(r1.month != r2.month)//�·ݲ�ͬ 
		{
			return r1.month < r2.month;
		}
		else
		{
			if(r1.day != r2.day)//���ڲ�ͬ 
			{
				return r1.day < r2.day;
			}
			else
			{
				if(r1.hour != r2.hour)//Сʱ��ͬ 
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
		if(start.minute >= 60)//���ӽ�λ 
		{
			start.minute = 0;
			start.hour++;
		}
		if(start.hour >= 24)//Сʱ��λ 
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
	//next��һ���û���cnt��¼�Ϸ�������ļ�¼��on��off��ǺϷ���¼�Ŀ�ʼ�������λ�� 
	int next = 0, cnt = 0, on = 0, off = 0;
	//ʼ������next�ڱ���ÿһ���û��������˵� 
	while(on < N)//һ��ѭ��һ���û� 
	{
		next = on;
		cnt = 0;
		while(next < N && !strcmp(rec[next].name, rec[on].name))//�ж��û����Ƿ���ͬ(��ͬһ���û���¼��ѭ��) 
		{
			if(cnt == 0 && rec[next].status == true)//�ҵ���һ��online 
			{
				cnt = 1; 
				//on = next;//��¼һ��online��λ�� !!!!!���Ͻ� 
			} 
			else if(cnt == 1 && rec[next].status == false)//���ҵ���һ��online�����ҵ���offline 
			{
				cnt = 2;
				//off = next;//��¼һ��offline ��λ�� !!!!���Ͻ� 
			}
			next++;
		}
		if(cnt < 2)//û�кϷ���¼ 
		{
			on = next;//next��ʱ�Ѿ�����һ���û��ĵ�һ����¼��λ�� 
			continue;
		}
		printf("%s %02d\n", rec[on].name, rec[on].month);
		int totalMoney = 0;
		while(on < next)//��ʱon�Ѿ���ʾ��һ��online 
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
			//����ʱ�� 
			int startTime = rec[on].day * 24 * 60 + rec[on].hour * 60 + rec[on].minute;
			int endTime = rec[off].day * 24 * 60 + rec[off].hour * 60 + rec[off].minute;
			totalTime = endTime - startTime;
			printf("%d ", totalTime);
			//����,����ת��Ϊ��Ԫ 
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
