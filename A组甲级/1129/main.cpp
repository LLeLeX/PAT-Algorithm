#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int N, K;
struct Rec{
	int data;
	int cnt;
	bool operator < (const Rec &r1)const
	{
		if(r1.cnt != cnt)
			return cnt > r1.cnt;//cnt大的排在前面 
		else
			return data < r1.data;//data小的排在前面 
	}
	/*friend bool operator < (Rec r1, Rec r2)
	{
		if(r1.cnt != r2.cnt)
			return r1.cnt < r2.cnt;//cnt大的排在前面 
		else
			return r1.data > r1.data;//data小的排在前面 
	}*/
	Rec(){}
	Rec(int dd, int cc)
	{
		data = dd;
		cnt = cc;
	}
};
set<Rec> st; 
int cntAccess[maxn];
int main(int argc, char *argv[]) {
	scanf("%d%d", &N, &K);
	int data;
	scanf("%d", &data);
	cntAccess[data]++;
	st.insert(Rec(data, cntAccess[data]));
	for(int i = 1; i < N; ++i)
	{
		scanf("%d", &data);
		printf("%d:", data);
		int num = 0;
		for(set<Rec>::iterator j = st.begin(); j != st.end(); ++j)
		{
			if(num < K)
				printf(" %d", j->data);
			else
				break;
			num++;
		}
		printf("\n");
		set<Rec>::iterator it = st.find(Rec(data, cntAccess[data]));
		if(it != st.end())//集合中存在当前数据 
			st.erase(it);//删除重新插入更新
		cntAccess[data]++;
		st.insert(Rec(data, cntAccess[data]));//直接插入 	
	}
	return 0;
}
