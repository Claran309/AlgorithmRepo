#include <bits/stdc++.h>
using namespace std;

int main(){
	string c[8] = {"1s","2s","2p","3s","3p","4s","3d","4p"};
	int num[8] = {2,2,6,2,6,2,10,6},a,flag;
	scanf("%d",&a);
	for(int i = 0;i <= 7;i++)
		if(a > num[i]) a -= num[i];
		else if(a <= num[i]){
			flag = i; num[i] -= (num[i] - a);
			break;
		}
	for(int i = 0;i < flag;i++)
		cout << c[i] << "^" << num[i] << " ";
	cout << c[flag] << "^" << num[flag] << endl << endl << endl << endl;
	system("pause");
	return 0;
} 
