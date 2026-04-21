#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	if(a > b) return true;
	else return false;
}

int main(){
	system("color 0a");
	int a[10] = {1,5,3,2,4,6,9,10,9,12};
	sort(a,a+10,cmp);
	for(int i = 0;i < 10;i++) cout << a[i] << " ";
	return 0;
}
