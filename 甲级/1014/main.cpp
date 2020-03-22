#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3fffffff;
const int maxn = 1005;
int N, M, K, Q;
int serveTime[maxn], customer[maxn];//处理时间,客户结束时间 
int open = 8 * 60, close = 17 * 60;
struct Window{
	int frontTime = open;//队首客户结束时间 
	int endTime = open;//窗口结束时间 
	queue<int> q;
}windows[25];//初始化，由于是结构体数组，需要初始化 
//结束时间m，服务时间d 
void display(int m, int d)//输出结束时间 
{
	if(m - d < close)
	{
		int hh = m / 60;
		int mm = m % 60;
		printf("%02d:%02d\n", hh, mm);
	}
	else//结束时间超过17:00输出sorry 
		printf("Sorry\n");
}

int main(int argc, char *argv[]) {
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	//下标全从0开始 
	for(int i = 0; i < K; ++i)
	{
		scanf("%d", &serveTime[i]);
	}
	
	
	int index = 0;//当前为入队的客户下标
	//由于取模，窗口下标从0开始 
	for(int i = 0; i < min(N * M, K); ++i)//先把所有队列填满,如果K较小，会出现队列不满的情况 
	{
		int winID = index % N;
		windows[winID].q.push(index);//客户入队
		windows[winID].endTime += serveTime[index];
		if(index < N)//判断队首客户 
			windows[winID].frontTime =  windows[winID].endTime;
		customer[index] = windows[winID].endTime;
		++index;
	} 
	//所有队满，仍有尚未入队的客户 
	for(; index < K; ++index)
	{
		int winID = -1, minFrontTime = inf;
		for(int i = 0; i < N; ++i)//找结束最早的队伍 
		{
			if(windows[i].frontTime < minFrontTime)
			{
				winID = i;
				minFrontTime = windows[i].frontTime;
			}
		}
		windows[winID].q.pop();//队首出队  
		int cusID = windows[winID].q.front();
		windows[winID].frontTime = customer[cusID];//更新队首结束时间 
		windows[winID].q.push(index);//入队
		windows[winID].endTime += serveTime[index];//更新窗口结束时间
		customer[index] = windows[winID].endTime;//
	}
	
	
	for(int i = 1; i <= Q; ++i)
	{
		int query;
		scanf("%d", &query);
		display(customer[query - 1], serveTime[query - 1]);//下标从0开始 
	}
	return 0;
}
