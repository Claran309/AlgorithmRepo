#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,max,min;
	cin >> a;
	int b[a];
	for(int i = 0;i <= a-1;i++){
		cin >> b[i];
		if(i >= 1){
			if(b[i-1] > b[i]){
				max = b[i-1];
				min = b[i];
			}else{
				max = b[i];
				min = b[i-1];
			}
		}
	} 
	if(a == 1){
		max = b[0];
		min = b[0];
	}
	cout << max << " " << min;
	
	return 0;
}


