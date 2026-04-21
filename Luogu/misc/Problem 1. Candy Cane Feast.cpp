#include <bits/stdc++.h>
using namespace std;
long long n,m,cow[500001],head,tail,cnt;
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> cow[i];
	for(int i = 1;i <= m;i++){
		cin >> head;
		tail = 1;//°üÀ¨tail
		for(int j = 1;j <= n;j++){
			if(cow[j] >= tail){
				if(cow[j] >= head){
					cow[j]+=(head-tail+1);
					break;
				}
				cnt = cow[j];
				cow[j]+=(cow[j]-tail+1);
				tail = cnt+1;
			}
		}
	}
	for(int i = 1;i <= n;i++)
		cout << cow[i] << endl;	
	return 0;
} 
