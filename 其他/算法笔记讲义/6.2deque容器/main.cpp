#include <bits/stdc++.h>
using namespace std;
deque<int> q;
void display()
{
	for(int i = 0; i < q.size(); i++)
	{
		printf("%d ", q[i]);
	}
	printf("\n");
}
int main(int argc, char *argv[]) {
	for(int i = 0; i < 5; i++)
	{
		q.push_back(i);
	}
	display();
	q.pop_front();
	display();
	printf("***%d", q[0]);
	/*auto it = q.begin() + 3;
	printf("%d", *it);*/
	return 0;
	
}
