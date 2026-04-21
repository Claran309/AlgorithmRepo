#include<bits/stdc++.h>
using namespace std;
set<int> s;
long long a[10005],b[10005],c[10005],d[10005];
long long n;
int main(){
	cin >> n;
	for(long long i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != b[i]) {
		b[i] = a[i];
		c[b[i]]++;
		a[i] = a[i+1];
		}
	}
	sort(b+1,b+n+1);
	for(long long i = 1;i <= n;i++) s.insert(b[i]);
	int j = 1;
	while(!s.empty()){
		d[j] = *s.begin();
		s.erase(s.begin());
		j++;
	}
	j--;
	for(long long i = 1;i <= j;i++){
		cout<<d[i]<<" "<<c[d[i]]<<endl;
	}
	return 0; 
} 
