#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
const int inf = 0x3fffffff;
int N, K, M;
int open = 8 * 3600, close = 21 * 3600;
struct Player{
	int arrive;//����ʱ�� 
	int start = close;//��ʼʱ�䣬��ʼ��Ϊclose 
	int serve;//�˶�ʱ�� 
	bool isvip;//true:vip
}p;
struct Table{
	int count = 0;
	int endTime = open;//����ʱ��
	bool isvip = false;//true:vip 
}tables[105];
vector<Player> player;

int getSec(int h, int m, int s)
{
	return h * 3600 + m * 60 + s;
}
bool cmpArrive(Player p1, Player p2)
{
	return p1.arrive < p2.arrive;
}
bool cmpStart(Player p1, Player p2)
{
	return p1.start < p2.start;
}
int nextVIP(int x)
{
	x++;
	while(x < player.size() && player[x].isvip == false)
		x++;
	return x;
} 
void allotTable(int pid, int tid)
{
	if(player[pid].arrive <= tables[tid].endTime)//��Ա�����磬�Ŷӵ�̨�� 
	{
		player[pid].start = tables[tid].endTime;
	}
	else//��Ա����ֱ�ӿ��� 
	{
		player[pid].start = player[pid].arrive;
	}
	//cout << player[pid].arrive << " " << player[pid].serve << " " << player[pid].start << endl; 
	tables[tid].endTime = player[pid].start + player[pid].serve;
	tables[tid].count++;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		int h, m, s, ser, flag;
		scanf("%d:%d:%d %d %d", &h, &m, &s, &ser, &flag);
		int arrive = getSec(h, m, s);
		if(ser > 120)//+++ѹ��ʱ�� 
			ser = 120;
		if(arrive >= close)
			continue;
		p.arrive = arrive;
		p.isvip = flag;
		p.serve = ser * 60;
		player.push_back(p);
	}
	scanf("%d%d", &K, &M);
	for(int i = 1; i <= M; ++i)//���vip 
	{
		int tabID;
		scanf("%d", &tabID);
		tables[tabID].isvip = true;
	}
	sort(player.begin(), player.end(), cmpArrive);
	
	int i = 0, vipi= -1;
	vipi = nextVIP(vipi);//�ҵ���һ��VIP��Ա 
	//����������Ա 
	while(i < player.size())
	{
		int tabID = -1, minEndTime = inf;
		for(int j = 1; j <= K; ++j)//Ѱ�������������̨ 
		{
			if(tables[j].endTime < minEndTime)
			{
				tabID = j;
				minEndTime = tables[j].endTime;
			}
		}
		if(tables[tabID].endTime >= close)//�Ѿ����� 
			break;
		if(player[i].isvip == true && i < vipi)//i����vip��Ա����vipi>i��˵��i���Ѿ��μ�ѵ�� 
		{
			i++;//˵����vip�ǳ��ֲ�ӵ���� 
			continue;
		}
		//������vip����ǰ��vip 
		if(tables[tabID].isvip == true && player[i].isvip == true)
		{
			allotTable(i, tabID);
			if(vipi == i)//��ǰ��vip 
				vipi = nextVIP(vipi);//����һ��vip 
			i++;
		}
		//������vip����ǰ����vip 
		else if(tables[tabID].isvip == true && player[i].isvip == false)
		{
			if(vipi < player.size() && player[vipi].arrive <= tables[tabID].endTime)
			{
				allotTable(vipi, tabID);
				vipi = nextVIP(vipi);
			}
			else
			{
				allotTable(i, tabID);
				i++;
			}
		}
		//���Ӳ���vip����ǰ����vip 
		else if(tables[tabID].isvip == false && player[i].isvip == false)
		{
			allotTable(i, tabID);
			i++; 
		}
		//���Ӳ���vip����ǰ��vip 
		else if(tables[tabID].isvip == false && player[i].isvip == true)
		{
			int tabvip = -1, minvipEndTime = inf;
			for(int j = 1; j <= K; ++j)//�����������vip�� 
			{
				if(tables[j].isvip == true && tables[j].endTime < minvipEndTime)
				{
					minvipEndTime = tables[j].endTime;
					tabvip = j;
				}
			}
			if(tabvip != -1 && player[i].arrive >= tables[tabvip].endTime)
			{
				allotTable(i, tabvip);
				if(vipi == i)
					vipi = nextVIP(vipi);
				i++;
			}
			else
			{
				allotTable(i, tabID);
				if(vipi == i)
					vipi = nextVIP(vipi);
				i++;
			}
		}
	}
	
	
	sort(player.begin(), player.end(), cmpStart);
	for(int i = 0; i < player.size() && player[i].start < close; ++i)
	{
		int t1 = player[i].arrive;
		int t2 = player[i].start;
		printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n", round((t2 - t1) / 60.0));
	}
	for(int i = 1; i <= K; ++i)
	{
		printf("%d", tables[i].count);
		if(i < K)
			printf(" ");
	}
	return 0;
}
