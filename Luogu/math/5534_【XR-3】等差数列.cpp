#include <iostream>
using namespace std;
int n,f,l,sum; 
int main(){
	cin >> f >> l >> n;
	if(f < l)
		for(int i = f;i <= (l-f)*n;i+=l-f) sum+=i;
	else
		for(int i = f;i >= (l-f)*n;i+=l-f) sum+=i;
	cout << sum;
	return 0;
}
