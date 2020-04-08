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

//���鼯
int father[maxn];//��ʾ��ͥ 
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
		int fmin = min(fx, fy);//�����С��Ϊ���ڵ� 
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
	for(int i = 0; i < N; ++i)//�������� 
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
	//��ʱ������ͥ��δ�ϲ���λ��ֻ�ҵ��ֲ��ĸ��ڵ� 
	
	int familyNum = 0;//ͳ�Ƽ�ͥ������¼�±� 
	for(int i = 0; i < maxn; ++i)//��һ�����¸��ڵ㣬�����к������� 
	{
		if(people[i].ID == -1)
			continue;
		int id = findFather(people[i].ID);//�õ�ȫ�ָ��ڵ� 
		//���� 
		if(family[id].isvalid == false)
		{
			family[id].isvalid = true;
			family[id].ID = id;
			family[id].avgArea = 0.0;//��ʼ�� 
			familyNum++;
		}
		family[id].member++;
		family[id].avgArea += people[i].area;
		family[id].avgSet += people[i].estateNum;
		//printf("%04d %04d\n", people[i].ID, father[i]);
	}
	printf("%d\n", familyNum);
	sort(family, family + maxn, cmp);//�������ƽ��ֵ������-1 break�����ٱ������� 
	for(int i = 0; i < maxn; ++i)//��family����������ƽ��ֵ 
	{
		if(family[i].avgArea == -1)
			break;
		family[i].avgArea /= family[i].member;
		family[i].avgSet /= family[i].member;
	}
	sort(family, family + maxn, cmp); //����ÿ����ͥ������ͬ���ٴ����� 
	for(int i = 0; i < maxn; ++i)//��family����������ƽ��ֵ 
	{
		if(family[i].avgArea == -1)
			break;
		printf("%04d %d %.3f %.3f\n", family[i].ID, family[i].member, family[i].avgSet, family[i].avgArea);
	}
	return 0;
}
