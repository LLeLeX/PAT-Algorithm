#include <bits/stdc++.h>
using namespace std;
const double INF = 0x3fffffff;
double C, D, DA;
double cost, nowCapa, hereDist, herePrice, maxEachDist, maxTravelDist, betwDist;
int N;
struct stations{
	double price;
	double dist;
}sta[505];
bool cmp(stations s1, stations s2)
{
	return s1.dist < s2.dist;
}
int main(int argc, char *argv[]) {
	scanf("%lf%lf%lf%d", &C, &D, &DA, &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lf%lf", &sta[i].price, &sta[i].dist);
	}
	//对终点的处理 
	sta[N].dist = D;
	sta[N].price = 0.00;
	sort(sta, sta + N, cmp);
	maxEachDist = C * DA;
	bool cmplt = true;//标记最后是否能到达终点 
	if(sta[0].dist != 0)//无法出发 
	{
		cmplt = false;
		maxTravelDist = 0; 
	}
	else//可出发 
	{	
		
		int nextIndex, lastIndex, beforeIndex;//记录下一站下标和可行范围内最后一站下标,加油的那一站 
		
		
		
		for(int i = 0; i < N; i++)
		{
			if(i == 0)
			{
				herePrice = sta[i].price;
				hereDist = sta[i].dist;
				beforeIndex = i;
			}
			else if(i == nextIndex)
			{
				herePrice = sta[i].price;
				hereDist = sta[i].dist;
				nowCapa -= (hereDist - sta[beforeIndex].dist) / DA;
				beforeIndex = i;
			}
			else
			{
				continue;
			}
			//0：没有合适的加油站且中间也无法加油 1：中间可加油但油价并不低 2：中间有油价更低的 
			int isLower = 0;//标记是否存在比现在低的油价
			//遍历之后是否存在价钱更低的 
			for(int j = i + 1; j <= N; j++)
			{
				if(sta[j].dist <= hereDist + maxEachDist)
				{
					if(sta[j].price < herePrice)
					{
						betwDist = sta[j].dist - hereDist;
						//判断当前油量是否能到达 
						double need = (betwDist - nowCapa * DA) / DA;
						if(need > 0)//不够到达需要加油 
						{
							nowCapa += need;
							cost += need * sta[i].price;
						}
						nextIndex = j;
						isLower = 2;
						break;
					}
					else
					{
						isLower = 1;
						lastIndex = j;
					}
				}
				else
				{
					if(isLower == 1)
					{
						double tempPrice = INF;
						for(int k = i + 1; k <= lastIndex; k++)//寻找价格相对较低的 
						{
							if(sta[k].price < tempPrice)
							{
								nextIndex = k;
								tempPrice = sta[k].price;
							}
						}
						cost += (50 - nowCapa) * sta[i].price;
						nowCapa += 50 - nowCapa;
						break;
					}
					else if(isLower == 0)
					{
						cmplt = false;
						maxTravelDist = hereDist + maxEachDist;
						break;
					}
				}	
			}
			if(!cmplt)
			{
				break;
			}
		}
	}
	if(!cmplt)//到达不了终点 
	{
		printf("The maximum travel distance = %.2f", maxTravelDist);
	}
	else
	{
		printf("%.2f", cost);
	}
	return 0;
}
