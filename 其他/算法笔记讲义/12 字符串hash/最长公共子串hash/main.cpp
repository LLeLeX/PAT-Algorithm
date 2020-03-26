#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll p = 1e7 + 19;
const ll maxn = 1005;
char a[maxn], b[maxn];
//powP���p^i%mod��hashA���a[]ÿһλhash��hashB���b[]ÿһλhash 
ll powP[maxn], hashA[maxn], hashB[maxn];
ll lena, lenb;
//subA���a[]�Ӵ���hash��subB���b[]�Ӵ���hash 
vector<pair<ll, int> > subA, subB;
vector<int> startPosA, startPosB;//��¼�Ӵ���ʼ�ַ�λ�� 
void init()
{
	powP[0] = 1;
	for(int i = 1; i < maxn; ++i)
	{
		powP[i] = (powP[i - 1] * p) % mod; 
	}
} 
void getHash(ll len, ll hash[], char str[])
{
	hash[0] = str[0];
	for(int i = 0; i < len; ++i)
	{
		hash[i] = (hash[i - 1] * p + str[i]) % mod;
	}
}
void getSubHash(ll len, ll hash[], vector<pair<ll, int> > &sub, vector<int> &startPos)
{
	for(int i = 0; i < len; ++i)
	{
		for(int j = i; j < len; ++j)
		{
			if(i == 0)
			{
				ll hashValue = hash[j];
				sub.push_back(make_pair(hashValue, j - i + 1));
			}
			else
			{
				ll hashValue = ((hash[j] - hash[i - 1] * powP[j - i + 1]) % mod + mod) % mod;
				sub.push_back(make_pair(hashValue, j - i + 1));
			}
			startPos.push_back(i);
		}
	}
}
int main(int argc, char *argv[]) {
	scanf("%s", a);
	scanf("%s", b);
	lena = (ll)strlen(a);
	lenb = (ll)strlen(b);
	init();
	getHash(lena, hashA, a);
	getHash(lenb, hashB, b);
	getSubHash(lena, hashA, subA, startPosA);
	getSubHash(lenb, hashB, subB, startPosB);
	int ans = 0, pos = -1;
	for(int i = 0; i < subA.size(); ++i)
	{
		for(int j = 0; j < subB.size(); ++j)
		{
			if(subA[i].first == subB[j].first && subA[i].second > ans)
			{
				ans = max(ans, subA[i].second);
				pos = startPosA[i];
			}
		}
	}
	//printf("%d\n", ans);//������Ӵ����� 
	for(int i = pos; i < pos + ans; ++i)//codeup2432��������Ӵ� 
	{
		printf("%c", a[i]);
	}
	return 0;
}
