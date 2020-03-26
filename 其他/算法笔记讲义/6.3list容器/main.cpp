#include <bits/stdc++.h>
using namespace std;
list<int> nums;
void display()
{
	for(list<int>::iterator it = nums.begin(); it != nums.end(); it++)
	{
		printf("%d ", *it);
	}
	printf("\n");
} 
int main(int argc, char *argv[]) {
	for(int i = 0; i <10; i++)
	{
		nums.emplace_back(i);
	}
	display();
	//首部添加 
	/*for(int i = 10; i < 20; i++)
	{
		nums.push_front(i);
	}*/
	//任意位置添加 
	/*auto iter = end(nums);
	advance(iter, -3);//对迭代器增加或减少 
	nums.insert(iter, 3, 22);*/
	
	//任意位置插入一段元素
	vector<int> data(5, 88);
	//nums.insert(--(--end(nums)), begin(data) + 2, end(data));
	nums.insert(--(nums.end()), data.begin() + 3, data.end()); 
	display();
	//删除 
	nums.remove(88);
	display();
	return 0;
}
