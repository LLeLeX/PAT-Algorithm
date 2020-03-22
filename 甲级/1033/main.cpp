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
	//���յ�Ĵ��� 
	sta[N].dist = D;
	sta[N].price = 0.00;
	sort(sta, sta + N, cmp);
	maxEachDist = C * DA;
	bool cmplt = true;//�������Ƿ��ܵ����յ� 
	if(sta[0].dist != 0)//�޷����� 
	{
		cmplt = false;
		maxTravelDist = 0; 
	}
	else//�ɳ��� 
	{	
		
		int nextIndex, lastIndex, beforeIndex;//��¼��һվ�±�Ϳ��з�Χ�����һվ�±�,���͵���һվ 
		
		
		
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
			//0��û�к��ʵļ���վ���м�Ҳ�޷����� 1���м�ɼ��͵��ͼ۲����� 2���м����ͼ۸��͵� 
			int isLower = 0;//����Ƿ���ڱ����ڵ͵��ͼ�
			//����֮���Ƿ���ڼ�Ǯ���͵� 
			for(int j = i + 1; j <= N; j++)
			{
				if(sta[j].dist <= hereDist + maxEachDist)
				{
					if(sta[j].price < herePrice)
					{
						betwDist = sta[j].dist - hereDist;
						//�жϵ�ǰ�����Ƿ��ܵ��� 
						double need = (betwDist - nowCapa * DA) / DA;
						if(need > 0)//����������Ҫ���� 
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
						for(int k = i + 1; k <= lastIndex; k++)//Ѱ�Ҽ۸���Խϵ͵� 
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
	if(!cmplt)//���ﲻ���յ� 
	{
		printf("The maximum travel distance = %.2f", maxTravelDist);
	}
	else
	{
		printf("%.2f", cost);
	}
	return 0;
}
