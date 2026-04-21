#include <iostream>
#include <ctime> //设rand（随机数）种子的 头文件 （time） 
#include <cstdlib> //所包含 rand 随机数的 头文件 
#include <algorithm>
using namespace std;
int a[100000],b[100000],c[100000];
int main(){
	system("color a");
	srand(time(0)/*当前时间距离1970年1月1日的秒数*/); //srand 用于设置 rand 种子 
	for(int i = 0;i < 100000;i++){
	    a[i] = rand()%10000+1;//产生1——10000的随机数 
	    b[i] = a[i];
	    c[i] = a[i];
	}
	int s1 = time(0);
    for(int i = 0;i < 100000-1;i++)
        for(int j = 0;j < 100000-1-i;j++)
    /* wait a minute......*/        if(a[j] > a[j+1]) swap(a[j],a[j+1]);
    int s2 = time(0); 
	cout << "冒泡排序100000数据用时：" << s2 - s1 << "秒" << endl; 
	int ss1 = time(0);
    for(int i = 0;i < 100000-1;i++){
    	int in = i;
    	for(int j = i + 1;j < 100000;j++){
    		if(b[in] > b[j]) in = j;
		}
        if(in != i) swap(b[in],b[i]);
	}
	int ss2 = time(0);
	cout << "选择排序100000数据用时：" << ss2 - ss1 << "秒" << endl; 
	int sss1 = time(0);
	sort(c,c+100000);
	int sss2 = time(0);
	cout << "sort排序100000数据用时：" << sss2 - sss1 << "秒" << endl; 
	return 0;
}
