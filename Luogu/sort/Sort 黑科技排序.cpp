#include <iostream>
#include <algorithm> 
// 1 导入算法库 
#define green system("color a")//个人喜欢green 
using namespace std;
// 2 命名空间 
 
int main(){
	green;
	int b;
	cin >> b;
	int a[b];
	for(int i = 0;i < b/*b可改*/;i++) 
		cin >> a[i];
	system("CLS");
	cout << "混合排序(Sort)前：";
	for(int i = 0;i < b/*b可改*/;i++) 
		cout << a[i] << " ";
	cout << endl;
	// 3 sort 
	sort(a/*=a+0 从a[0] */,a+8/*到a[7]混合排序*/);//一行！！！ 
	cout << "混合排序(sort)后：";
	for(int i = 0;i < b/*b可改*/;i++){
		cout << a[i] << " ";
	} 
	return 0;
}//没了！！ 
