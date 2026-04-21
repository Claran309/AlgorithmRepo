#include <algorithm>

#include <iostream>
using namespace std;
int main(){
	int a[10] = {4,12,2,7,3,6,3,6,3,6};
	for(int i = 0;i < 9;i++){
		for(int j = 0;j < 10 - 1 - i;j++){
			if(a[j]>a[j+1])
			    swap(a[j],a[j+1]);
		}
	}
	for(int i = 0;i < 10;i++){
		cout << a[i] << " ";
	}
	
	
	return 0;
}
