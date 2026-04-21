#include <iostream>
#include <cmath>
using namespace std;
long long a[1001];
int main(){
	int n,s = 0;;
	cin >> n;
	for(int i = 0;i < n;i++) cin >> a[i];
	int tmp;
	for(int i = 0;i < n-1;i++){
	    tmp = abs(a[i] - a[i+1]);
		for(int j = i;j < n;j++){
			if(tmp == a[j]){
				break;
			}
			if(tmp != a[j]){
				s++;
				//cout << tmp << "  " << a[i] << " " << a[j] << endl;
			}
			if(s >= n){
				cout << "Not jolly";
				return 0;
			}
		}
		s = 0;
		//cout << endl;
	}
	cout << "Jolly";
	return 0;
}
