#include <bits/stdc++.h>
using namespace std;
int N, K;
int maxAns = -1;
map<string, int> parkTime;
struct records{
	char num[15];
	int hh, mm, ss;
	int time;//以秒为单位方便比较询问的时间点 
	bool status;//true:in;false:out
	bool valid;//此条记录是否有效，true有效 
	records(){}
}rec[10005], validRec[10005];
bool cmpTime(records r1, records r2)//先按车牌排序，再按时间排序 
{
	if(strcmp(r1.num, r2.num))
	{
		return strcmp(r1.num, r2.num) < 0;
	}
	else if(r1.hh != r2.hh)
	{
		return r1.hh < r2.hh;
	}
	else if(r1.mm != r2.mm)
	{
		return r1.mm < r2.mm;
	}
	else
	{
		return r1.ss < r2.ss;
	}
}
bool cmpByTime(records r1, records r2)
{
	return r1.time < r2.time;
}
bool judge(int i, int t)//判断该车在这个时间点是否在校园内 
{
	records start = validRec[i];
	records endd = validRec[i + 1];
	if(start.time <= t && endd.time > t)//在校园内 
	{
		return true;
	}
	else//不在校园内 
	{
		return false;
	}
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	for(int i = 0; i < N; i++)//输入及初始化 
	{
		char stat[5];
		scanf("%s %d:%d:%d %s", rec[i].num, &rec[i].hh, &rec[i].mm, &rec[i].ss, stat);
		if(!strcmp(stat, "in"))
		{
			rec[i].status = true;
		}
		if(!strcmp(stat, "out"))
		{
			rec[i].status = false;
		}
		parkTime[rec[i].num] = 0; 
		rec[i].valid = false;//初始化全为false 
		rec[i].time = rec[i].hh * 3600 + rec[i].mm * 60 + rec[i].ss;
	}
	sort(rec, rec + N, cmpTime);
	//查找并标记有效记录 
	/*int in = 0, out = 0, next = 0, cnt = 0, index = 0;
	while(in < N)
	{
		next = in;
		cnt = 0;
		//此处查找可能存在有效记录 
		while(next < N && !strcmp(rec[in].num, rec[next].num))//车牌相同
		{
			if(cnt == 0 && rec[next].status == true)//找到第一个in 
			{
				cnt = 1;
			}
			else if(cnt == 1 && rec[next].status == false)
			{
				cnt = 2;
			}
			next++;
		}
		if(cnt < 2)//说明没有有效记录 
		{
			in = next;
			continue; 
		}
		while(in < next)
		{
			while(in < next - 1 && !(rec[in].status == true && rec[in + 1].status == false)) 
			{
				in++;
			}
			rec[in].valid = true;
			out = in + 1;
			rec[out].valid = true;
			validRec[index++] = rec[in];
			validRec[index++] = rec[out]; 
			parkTime[rec[in].num] += rec[out].time - rec[in].time;
			maxAns = max(maxAns, parkTime[rec[in].num]);
			if(out == next)
			{
				in = next;
				break;
			}
			in = out + 1; 
		}
	}*/
	int index = 0;
	for(int i = 0; i < N - 1; i++)
	{
		if(!strcmp(rec[i].num, rec[i + 1].num) && rec[i].status && !rec[i + 1].status)
		{
			validRec[index++] = rec[i];
			validRec[index++] = rec[i + 1];
			int inTime =  rec[i + 1].time - rec[i].time;
			/*if(parkTime.count(rec[in].num) == 0)
            {
                parkTime[rec[in].num] = 0;
            }*/
			parkTime[rec[i].num] += inTime;
			maxAns = max(maxAns, parkTime[rec[i].num]);
		}
	}
	//K次询问输入 
	sort(validRec, validRec + index, cmpByTime);
	int now = 0, cntCars = 0;
	bool isfir = false;
	while(K--)
	{
		int h, m, s, quesTime;
		scanf("%d:%d:%d", &h, &m, &s);
		quesTime = h * 3600 + m * 60 + s;
		while(now < index && validRec[now].time <= quesTime)
		{
			if(validRec[now].status)
			{
				cntCars++;
			}
			else
			{
				cntCars--;
			}
			now++;
		}
		/*for(int i = 0; i < index; i++)
		{
			if(validRec[i].valid)//是有效的   这辆车in的位置 
			{
				if(!isfir && validRec[i].status) 
				{
					parkTime[validRec[i].num] += validRec[i + 1].time - validRec[i].time;
					maxAns = max(maxAns, parkTime[validRec[i].num]);
				}
				if(judge(i, quesTime) && validRec[i].status)//对进入的记录时判断 
				{
					cntCars++;
					i++;
				}
			}
		}*/
		printf("%d\n", cntCars); 
		isfir = true;
	}
		
	/*cout << "********" << endl;
	for(map<string, int>::iterator it = parkTime.begin(); it != parkTime.end(); it++)
	{
		cout << it -> first << " " << it -> second << endl;
		//cout << rec[i].num << " " << rec[i].hh << " " << rec[i].mm << " " << rec[i].ss << " " << rec[i].status << " " << rec[i].valid << " " << rec[i].maxTime << endl;
	}
	cout << "********" << endl;*/
	
	for(map<string, int>::iterator it = parkTime.begin(); it != parkTime.end(); it++)
	{
		if(it->second == maxAns)
		{
			printf("%s ", it->first.c_str()); 
		}
	}
	printf("%02d:%02d:%02d\n", maxAns / 3600, maxAns % 3600 / 60, maxAns % 60);
	return 0;
}
