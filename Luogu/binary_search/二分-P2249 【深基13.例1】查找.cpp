#include <bits/stdc++.h>
using namespace std;
struct o{
	int v;
	int p;
};
int main(){
	int flag = 0,a,ask,used = 0,position = 0; cin >> a >> ask;
	int /*num[a],*/need; o num[a];
	int left = 0,right = a - 1,mid;
	cin >> num[0].v; used = num[0].v; num[0].p = 1; 
	for(int i = 1;i < a;i++){ 
		cin >> num[i].v;
		if(num[i].v != used){
			used = num[i].v;
			position = i + 1;
		}
		num[i].p = position;
	} 
	/*int p[num[a-1]];
	memset(p,0,sizeof(p));
	p[used] = 1;
	for(int i = 1;i < a;i++){
		if(num[i] != used){
			used = num[i];
			p[used] = i + 1;
		}
	}*/
	for(int i = 0;i < ask;i++){
		cin >> need;
		while(left <= right){
			mid = (left + right) / 2;
			if(num[mid].v > need) right = mid - 1;
			else if(num[mid].v < need) left = mid + 1;
			else if(num[mid].v == need){
				flag = mid + 1; break;
			}
		}
		left = 0; right = a - 1;
		if(flag == 0){
			cout << -1 << " ";
			continue;
		}
		flag = flag - 1;
		if(flag == 0){
			cout << 1 << " "; continue;
		}
		cout << num[flag].p << " ";
		//cout << p[num[flag]] << " ";
		/*
		for(int j = flag;j >= 0;j--)
			if(num[j] != num[flag]){
				cout << j + 2 << " "; break;
			}*/
		flag = 0;
	}
	return 0;
} 
 
/*
5 3
1 2 3 4 5
1 5 6 
*/
