#include <bits/stdc++.h>
using namespace std;
int N;
string A, B;
int expA, expB;
string preProcess(string s, int &exp)
{
	int index = 0;
	while(s.length() > 0 && s[0] == '0')
	{
		s.erase(0, 1);//ȥ��ǰ��0 
	}
	if(s[0] == '.')//��һλ��С���㣬ԭ����С��1������ 
	{
		s.erase(0, 1);//ȥ��С����
		while(s.length() > 0 && s[0] == '0')//С������0 
		{
			exp--;
			s.erase(0, 1);
		} 
	}
	else//ԭ������1��Ѱ��С���� 
	{
		while(index < s.length() && s[index] != '.')
		{
			index++;
			exp++;
		}
		if(index < s.length())//С������ԭ���м䣬˵��ԭ����С������ 
		{
			s.erase(index, 1);
		}//����ԭ����Ϊ���� 
	} 
	if(s.length() == 0)//��ȥǰ��0֮�󣬳���Ϊ0����ԭ����Ϊ0 
	{
		exp = 0;
	} 
	int validnum = 0;
	index = 0;
	string res;
	while(validnum < N)
	{
		if(index < s.length())
		{
			res += s[index++];
		}
		else
		{
			res += '0';
		}
		validnum++;
	}
	return res;
}
int main(int argc, char *argv[]) {
	cin >> N >> A >> B;
	string resA = preProcess(A, expA);
	string resB = preProcess(B, expB);
	if(resA == resB && expA == expB)
	{
		cout << "YES 0." << resA << "*10^" << expA;
	}
	else
	{
		cout << "NO 0." << resA << "*10^" << expA << " 0." << resB << "*10^" << expB;
	}
	return 0;
}
