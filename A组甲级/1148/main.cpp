#include <bits/stdc++.h>
using namespace std;
int N;
int said[110], status[110];//said:ÿ���˵Ĳ�����status��ÿ���˵���ݣ�0Ϊ����-1Ϊ���� 
vector<int> lie;
bool check(int a, int b)//a,b������ 
{
	for(int i = 1; i <= N; ++i)
	{
		if(said[i] < 0)//��Ϊ������ 
		{
			int pos = said[i] * -1;
			if(status[pos] == 0)//ʵ���Ǵ���
			{
				lie.push_back(i);
			} 
		}
		if(said[i] > 0)//��Ϊ�Ǵ��� 
		{
			int pos = said[i];
			if(status[pos] == -1)//ʵ��������
			{
				lie.push_back(i);
			} 
		}
	}
	if(lie.size() != 2)
		return false;
	if(status[lie[0]] == 0 && status[lie[1]] == -1)
		return true;
	else if(status[lie[1]] == 0 && status[lie[0]] == -1)
		return true;
	else
		return false;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &said[i]);
	}
	bool cmplt = false;
	int ansi, ansj;
	for(int i = 1; i <= N; ++i)//����ö���������� 
	{
		if(cmplt == true)
			break;
		for(int j = i + 1; j <= N; ++j)
		{
			lie.clear();
			memset(status, 0, sizeof(status));
			status[i] = status[j] = -1;
			if(check(i, j) == true)
			{
				cmplt = true;
				ansi = i;
				ansj = j;
				break;
			}
		}
	}
	if(cmplt == true)
		printf("%d %d\n", ansi, ansj);
	else
		printf("No Solution");
	return 0;
}
