#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int cntAsc[130];
int main(int argc, char *argv[]) {
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	//��ǵ�һ���������Ӽ����� 
	for(int i = 0; i < len1; i++)
	{
		cntAsc[s1[i]]++;
	}
	//�˶Եڶ���
	int cntUse = 0;//��¼�����õ��ĸ���
	int cntLost = 0;//��¼ȱ���ӵĸ��� 
	for(int i = 0; i < len2; i++)
	{
		if(cntAsc[s2[i]] > 0)//��������� 
		{
			cntAsc[s2[i]]--;
			cntUse++; 
		}
		else//��ʱȱ���� 
		{
			cntLost++;
		}
	}
	if(cntLost == 0)
	{
		printf("Yes %d", len1 - cntUse);
	}
	else
	{
		printf("No %d", cntLost);
	}
	return 0;
}
