#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct o{
	ll v;
	ll times;
};
bool cmp(o a,o b){
	if(a.v > b.v) return true;
	else return false;
}
int main(){
	ll m,used,n,c,l,r,ans = 0; cin >> n >> c;
	ll left = 0,right = n - 1,mid; o num[n];
	//cin >> num[0].v; used = num[0].v; m++; l = 1;
	for(ll i = 0;i < n;i++){
		cin >> num[i].v;// m++; right = i;
		/*if(used != num[i].v){
			for(int j = l;j < right;j++) num[j].times = m;
			l = i; m = 1;
		}*/
	}
	//
	sort(num,num+n,cmp);
	m = 0;
	used = num[0].v; l = 0; m++; bool d = 1;
	for(ll i = 0;i < n;i++){
		right = i;
		if(used != num[i].v){
			used = num[i].v;
			for(int j = l;j < right;j++) num[j].times = m;
			l = i; m = 1; d = 1;
		}
		if(d != 1) m++;
		d = 0;
	}
	for(ll i = l;i <= right;i++) num[i].times = m;
	//1
	/*
	for(int i = 0;i < n;i++){
		cout << endl << num[i].v << " " << num[i].times << endl;
	}*/
	//1
	for(ll i = 0;i < n;i++){
		//cout << "---------------" << endl << "ones = " << num[i].v << endl;
		while(left <= right){
			mid = (left + right) / 2;
			//2
			//for(int j = left;j <= right;j++) cout << num[j].v << " ";
			//cout << endl;
			//2
			if((num[i].v - num[mid].v) > c) right = mid - 1;//²î>c£¬Íù×ó±ßËõĞ¡ 
			else if(num[i].v - num[mid].v < c) left = mid + 1;
			else if(num[i].v - num[mid].v == c){
				ans += num[mid].times;
				//cout << endl << "num = " << num[i].v << "-" << num[mid].v << endl;
				break;
			}
		}
		left = 0; right = n - 1;
	}
	cout << ans;
	return 0;
} 
/*
8 2
1 5 7 9 9 10 8 1
*/
