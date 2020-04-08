#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int N;
struct Person{
	int ID = -1;
	int dad = -1, mom = -1;
	int kidNum = 0;
	vector<int> kids;
	double estateNum;
	double area;
	Person(){}
	Person(int id, int dd, int mm, int kk){
		ID = id;
		dad = dd;
		mom = mm;
		kidNum = kk;
	}
}people[maxn];
struct Family{
	bool isvalid = false;
	int ID = maxn; 
	int member = 0;
	double avgSet = 0.0;
	double avgArea = -1;
}family[maxn];

//并查集
int father[maxn];//表示家庭 
void init()
{
	for(int i = 0; i < maxn; ++i)
	{
		father[i] = i;
	}
}
int findFather(int x)
{
	if(x == father[x])
	{
		return x;
	}
	else
	{
		int f = findFather(father[x]);
		father[x] = f; 
		return f;
	}
} 
void unionFather(int x, int y)
{
	int fx = findFather(x);
	int fy = findFather(y);
	if(fx != fy)
	{
		int fmin = min(fx, fy);//编号最小的为根节点 
		father[fx] = father[fy] = fmin;
	}
}
bool cmp(Family f1, Family f2)
{
	if(f1.avgArea != f2.avgArea)
		return f1.avgArea > f2.avgArea;
	else
		return f1.ID < f2.ID;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	init();
	for(int i = 0; i < N; ++i)//输入数据 
	{
		int id, dd, mm, kk;
		scanf("%d%d%d%d", &id, &dd, &mm, &kk);
		people[id] = Person(id, dd, mm, kk);
		if(dd != -1) 
		{
			people[dd].ID = dd;
			unionFather(id, dd);
		}
		if(mm != -1)
		{ 
			people[mm].ID = mm;	
			unionFather(id, mm);
		} 
		for(int j = 0; j < kk; ++j)
		{
			int kidID;
			scanf("%d", &kidID);
			people[id].kids.push_back(kidID);
			people[kidID].ID = kidID;
			unionFather(id, kidID);
		}
		scanf("%lf%lf", &people[id].estateNum, &people[id].area);
	}
	//此时各个家庭尚未合并到位，只找到局部的根节点 
	
	int familyNum = 0;//统计家庭个数记录下标 
	for(int i = 0; i < maxn; ++i)//进一步更新根节点，并进行后续计算 
	{
		if(people[i].ID == -1)
			continue;
		int id = findFather(people[i].ID);//得到全局根节点 
		//计算 
		if(family[id].isvalid == false)
		{
			family[id].isvalid = true;
			family[id].ID = id;
			family[id].avgArea = 0.0;//初始化 
			familyNum++;
		}
		family[id].member++;
		family[id].avgArea += people[i].area;
		family[id].avgSet += people[i].estateNum;
		//printf("%04d %04d\n", people[i].ID, father[i]);
	}
	printf("%d\n", familyNum);
	sort(family, family + maxn, cmp);//排序计算平均值，遇到-1 break，减少遍历次数 
	for(int i = 0; i < maxn; ++i)//对family遍历，计算平均值 
	{
		if(family[i].avgArea == -1)
			break;
		family[i].avgArea /= family[i].member;
		family[i].avgSet /= family[i].member;
	}
	sort(family, family + maxn, cmp); //由于每个家庭人数不同，再次排序 
	for(int i = 0; i < maxn; ++i)//对family遍历，计算平均值 
	{
		if(family[i].avgArea == -1)
			break;
		printf("%04d %d %.3f %.3f\n", family[i].ID, family[i].member, family[i].avgSet, family[i].avgArea);
	}
	return 0;
}
