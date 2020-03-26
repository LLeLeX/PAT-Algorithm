#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
	int n;
	while(scanf("%d", &n) != EOF)
	{
		while(n--)
		{
			int N;
			int arr[100];
			scanf("%d", &N);
			for(int i = 0; i < N; i++)
			{
				scanf("%d", &arr[i]);
			}
			for(int i = 0; i < N; i++)
			{
				if(i == 0)
				{
					if(arr[i] != arr[i + 1])
					{
						printf("%d ", i);
					}
				}
				else if(i == N - 1)
				{
					if(arr[i] != arr[i - 1])
					{
						printf("%d ", i);
					}
				}
				else
				{
					if(arr[i] < arr[i + 1] && arr[i] < arr[i - 1])
					{
						printf("%d ", i);
					}
					else if(arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
					{
						printf("%d ", i);
					}
				}
			}
			printf("\n");
		}	
	}
	return 0;
}
