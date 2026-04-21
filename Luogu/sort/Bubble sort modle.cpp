//Bubble Sort    时间复杂度：O(N^2) 
//Sort思路演示网址 ：  https://visualgo.net/zh/sorting          可进去选择各种排序演示（eg：Selection Sort ...） 
#include <bits/stdc++.h>
#include <algorithm>//    /ae'geri:them/
#define green system("color a")
using namespace std;

int main(){//  Bubble sort
	green;
	int b;
	cin >> b;
	int a[b];
	for(int i = 0;i < b/*b可改*/;i++) 
		cin >> a[i];
	system("CLS");
	cout << "冒泡排序前：";
	for(int i = 0;i < b/*b可改*/;i++) 
		cout << a[i] << " ";
	cout << endl;
	//此处Bubble sort 可以用算法函数 sort 函数一行解决（混合排序） 详见“Sort 黑科技排序.cpp” 
	//sort(a,a+b);  一行可代替20至30行的代码！！！qwq 
	bool s = false;//此bool用于减少已成功排序的次数，提高效率 
	for(int i = 0;i < b-1/*b可改*/;i++){
		s = false;//重置s判断条件 
	    for(int j = 0;j < b-1-i/*b可改*/;j++) //j < b-1亦可，但是b-1-i会提高效率 
	    	if(a[j] > a[j+1]) {
	    		swap(a[j],a[j+1]);
                s = true;//s为真 
	        }
	        if(s == false)//如果s依然为假，说明排序完毕，直接跳出循环 
	            break;
    }//但是还是太慢太慢（对于时长限制的题目）  用上面的sort好一点 (比赛可能会禁用哦~)
	cout << "冒泡排序后：";
	for(int i = 0;i < b/*b可改*/;i++) 
		cout << a[i] << " ";
	return 0;
} 
//Sort思路演示网址 ：  https://visualgo.net/zh/sorting          可进去选择各种排序演示（eg：Bubble Sort ...） 
