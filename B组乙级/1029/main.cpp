#include <bits/stdc++.h>
using namespace std;
string s1, s2;
bool asc[130];

int main(int argc, char *argv[]) {
	cin >> s1 >> s2;
	int len1 = s1.length();
	int len2 = s2.length();
	//ת����Сд 
	for(int i = 0; i < len1; i++)
	{
		if(s1[i] >= 'a' && s1[i] <= 'z')
		{
			s1[i] = s1[i] - 32;
		}
		if(s2[i] >= 'a' && s2[i] <= 'z' && i < len2)
		{
			s2[i] = s2[i] - 32;
		}
	}
	//�ȶ�
	int index2 = 0;
	for(int i = 0; i < len1; i++)
	{
		if(s1[i] != s2[index2])//�м��̻���,ԭ�����ƣ�ʵ�ʴ����� 
		{
			if(!asc[s1[i]])
			{
				printf("%c", s1[i]);
				asc[s1[i]] = true;
			}	
		}
		else//��ͬ ��ԭ����ʵ�ʴ�һͬ���� 
		{
			index2++;
		}
	} 
	return 0;
}
