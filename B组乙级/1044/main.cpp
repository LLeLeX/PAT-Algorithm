//���븴�ӣ����鿴A1100 
#include <bits/stdc++.h>
using namespace std;
string low[15] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[15] = {" ", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int N;
map<string, int> MtoE_low;
map<string, int> MtoE_high;
map<int, string> EtoM_low;
map<int, string> EtoM_high;
stack<string> mars;
int getNum(string s)
{
	int len = s.length();
	int ans = 0;
	for(int i = 0; i < len; ++i)
	{
		ans = ans * 10 + (s[i] - '0');
	}
	return ans;
}
int main(int argc, char *argv[]) {
	scanf("%d", &N);
	for(int i = 0; i < 13; ++i)
	{
		MtoE_low.insert(make_pair(low[i], i));
		MtoE_high.insert(make_pair(high[i], i));
		EtoM_low.insert(make_pair(i, low[i]));
		EtoM_high.insert(make_pair(i, high[i]));
	}
	getchar();
	while(N--)
	{
		string str;
		getline(cin, str);
		int len = str.length();
		if(str[0] >= '0' && str[0] <= '9')//����������� 
		{	
			int num = getNum(str);
			if(num < 13)//�޽�λ 
				cout << EtoM_low[num] << endl;
			else//����λ 
			{
				while(num)
				{
					int ret = num % 13;
					num /= 13; 
					len--;
					if(ret == 0)
						continue;
					if(num != 0)
						mars.push(EtoM_low[ret]);
					else
						mars.push(EtoM_high[ret]);
				}
				cout << mars.top();
				mars.pop();
				while(!mars.empty())
				{
					cout << " " << mars.top();
					mars.pop();
				}
				cout << endl;
			}
		}
		else//������ǻ����� 
		{
			if(len <= 3)//ֻ��һ���ַ��� 
			{
				string first = str.substr(0, 3);
				//�ж����ڸ�λ���ǵ�λ
				if(MtoE_low.count(first) == 1)//��13���ڵ����� 
				{
					cout << MtoE_low[first] << endl;
				}
				else//������λ 
				{
					cout << MtoE_high[first] * 13 << endl;
				}
			}
			else
			{
				string first = str.substr(0, 3);
				string second = str.substr(4, 3);
				int ans = MtoE_high[first] * 13 + MtoE_low[second];
				cout << ans << endl;
			}
		}
	}
	return 0;
}
