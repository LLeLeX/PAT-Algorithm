#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
int N, M, K;
struct Person{
	int id;
	int gender = 1;//0:女，1:男 
	vector<int> mate;
}people[maxn];
struct Helper{
	int firid;
	int secid;
	Helper(){}
	Helper(int fid, int sid)
	{
		firid = fid;
		secid = sid;
	}
};
vector<Helper> ans;
unordered_map<int ,bool> gendermp;
void findFriend(int A, int B)
{
	for(int i = 0; i < people[A].mate.size(); ++i)//遍历A的朋友 
	{
		int pid = people[A].mate[i];//A的朋友id 
		if(people[pid].gender == people[A].gender && pid != B)//与A同性的朋友C 
		{
			for(int j = 0; j < people[pid].mate.size(); ++j)//遍历C的朋友 
			{
				int qid = people[pid].mate[j];//C的朋友id 
				if(people[qid].gender == people[B].gender && qid != B && qid != A)//与A,C异性，与B同性的朋友D 
				{
					for(int k = 0; k < people[qid].mate.size(); ++k)//遍历D的朋友 
					{
						int rid = people[qid].mate[k];//D的朋友id 
						if(people[rid].id == B)//找到B 
						{
							ans.push_back(Helper(pid, qid));
						}
					}
				}
			}
		}
	}
}
bool cmp(Helper h1, Helper h2)
{
	if(h1.firid != h2.firid)
		return h1.firid < h2.firid;
	else
		return h1.secid < h2.secid;
}
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &M);
	//getchar();
	for(int i = 0; i < M; ++i)
	{
		char s1[10], s2[10];
		scanf(" %s %s", s1, s2);
		int p1, p2;
		sscanf(s1, "%d", &p1);
		sscanf(s2, "%d", &p2);

		if(s1[0] == '-')
		{
			p1 *= -1;
			people[p1].gender = 0;
		}
		if(s2[0] == '-')
		{
			p2 *= -1;
			people[p2].gender = 0;
		}
		people[p1].id = p1;
		people[p1].mate.push_back(p2);
		people[p2].id = p2;
		people[p2].mate.push_back(p1);
	}
	scanf("%d", &K);
	while(K--)
	{
		int A, B;
		ans.clear();
		scanf("%d%d", &A, &B);
		A = abs(A);
		B = abs(B);
		findFriend(A, B);
		printf("%d\n", ans.size());
		sort(ans.begin(), ans.end(), cmp);
		for(int i = 0; i < ans.size(); ++i)
		{
			Helper h = ans[i];
			printf("%04d %04d\n", h.firid, h.secid);
		}
	}
	return 0;
}
