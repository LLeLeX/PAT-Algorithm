#include <bits/stdc++.h>
using namespace std;
void changePointer(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void changeRefer(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main(int argc, char *argv[]) {
	int a = 1, b = 2;
	printf("a = %d, b = %d\n", a, b);
	
	
	cout << "changePointer" << endl;
	int *p1 = &a, *p2 = &b;
	changePointer(p1, p2);
	printf("a = %d, b = %d\n", a, b);
	
	cout << "changeReference" << endl;
	changeRefer(a, b);
	printf("a = %d, b = %d\n", a, b);
	return 0;
}
