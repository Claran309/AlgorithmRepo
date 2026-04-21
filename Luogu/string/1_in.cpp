#include <bits/stdc++.h>
using namespace std;
int main(){
	string c;
	getline(cin,c);
	int n,s=0,a,i;
	cin >> n >> a;
	int a2 = c.find("You Are Really");
	if(a2 != -1){
		for(int i =1;i <= n;i++){
			s+=a; 
		}
		cout << s;
		return 0;
	}else if(a2 == -1){
		cout << "NOPE";
	}
	
	return 0;
} 
