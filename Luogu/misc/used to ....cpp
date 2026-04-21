#include <bits/stdc++.h>
//#include "c.hrsco.h"
#include <unistd.h>
using namespace std;

int main(){
	//green();
	int a,c=1;
	cin >> a;
	for(int i = 1;i <= a;i++){
	    for(int j = 1;j <= a;j++){
	    	if(c < 10){
	    		cout << "0" << c;
			}else{
				cout << c;
			}
			c++;
		}
		cout << endl;
	}
	c = 1;
	cout << endl;
	for(int i = 1;i <= a;i++){
	    for(int k = 1;k <= a-i;k++){
	    	cout << "  ";
		}
	    for(int j = 1;j <= i;j++){
	    	if(c < 10){
	    		cout << "0" << c;
			}else{
				cout << c;
			}
			c++;
		}
		cout << endl;
	}
	return 0;
}

