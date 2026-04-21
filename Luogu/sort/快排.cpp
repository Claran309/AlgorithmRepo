//QuickSort 快速排序 
#include <iostream>
#include <algorithm>
using namespace std;

void q_sort(int a[],int left,int right){ 
    if(left < right){//才进行排序 
    	//1. 找到枢纽元
    	int mid = (left+right)/2;
    	swap(a[mid],a[right]);
    	int i = left,j = right-1;
    	//2. 在i和j不错位的情况下重复
		while(i <= j){ 
			//1. i重复向前跳
			while(a[i] < a[right]) i++;
			//2. j重复向前跳
			while(a[j] > a[right]) j--;
			if(i <= j){ 
				swap(a[i],a[j]);
				i++;
				j--;
			} 
		} 
		swap(a[right],a[i]);
		q_sort(a,left,i-1);
		q_sort(a,i+1,right);
	} 	
} 

int main(){ 
	int a[10];
	for(int i = 0;i < 10;i++) cin >> a[i];
	q_sort(a,0,9);
	for(int i = 0;i <= 9;i++){ 
		cout << a[i] << " ";
	} 
	return 0;
} 
