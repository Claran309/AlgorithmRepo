//Selection Sort    时间复杂度：O(N^2) 
//Sort思路演示网址 ：  https://visualgo.net/zh/sorting          可进去选择各种排序演示（eg：Selection Sort ...） 
#include <iostream>
#include <algorithm>
#define green system("color a")
using namespace std;

int main(){
	green;
	int b;
	cin >> b;
	int a[b];
	for(int i = 0;i < b/*b可改*/;i++) 
		cin >> a[i];
	system("CLS");
	cout << "选择排序前：";
	for(int i = 0;i < b/*b可改*/;i++) 
		cout << a[i] << " ";
	cout << endl;
	//此处Selection sort 可以用算法函数 sort 函数一行解决（混合排序） 详见“Sort 黑科技排序.cpp” 
    //sort(a,a+b);  一行可代替21至27行的代码！！！qwq 
	for(int i = 0;i < b - 1;i++){//次数 
		int index = i;//index 保存假设最小下标 
		for(int j = i+1;j < b;j++){ 
			if(a[j] < a[index]) index = j;//index 永远是最小元素的下标 
		}
		if(index != i) swap(a[index],a[i]);//将最小数字与第一个数交换 （假设错了才交换） 
		// if(index != i) 是优化选择排序的优化版本 意思为：假设对了就不交换 
	}//但是还是太慢太慢（对于时长限制的题目）  用上面的sort好一点(比赛可能会禁用哦~)
	cout << "选择排序后：";
	for(int i = 0;i < b/*b可改*/;i++) 
		cout << a[i] << " ";
	return 0;
} 
//Selection Sort 思想: 
//第0次 假设a[0]最小 找[1，7]到最小的和第0号位置交换 
//第1次 假设a[1]最小 找[2，7]到最小的和第1号位置交换 
//第2次 假设a[2]最小 找[3，7]到最小的和第2号位置交换 
//第3次 假设a[3]最小 找[4，7]到最小的和第3号位置交换 
//第4次 假设a[4]最小 找[5，7]到最小的和第4号位置交换 
//第5次 假设a[5]最小 找[6，7]到最小的和第5号位置交换 
//第6次 假设a[6]最小 找[7，7]到最小的和第6号位置交换 
/*理解化：
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[8] = {2,5,1,7,4,2,7,3};
	for(int i = 0;i < 8-1;i++){
		int in = i;
		for(int j = i+1;j<8;j++)
		if(a[in] > a[j]) in = j;
		if(in != i) swap(a[in],a[i]);
	}
	for(int i = 0;i<8;i++) cout << a[i] << " ";
	
	return 0;
}
*/
