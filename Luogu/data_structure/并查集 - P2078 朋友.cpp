#include <bits/stdc++.h>
using namespace std;
int f1[20010],f2[20010],a,b,fx,fy,q,n,m,p,male=0,fe=0;
void ms(int n,int f[]){
	for(int i=1;i<=n;i++)f[i]=i;
	return;
}
int find(int x,int f[]){
	if(x==f[x])return x;
	else f[x]=find(f[x],f);
	return f[x];
}
void unionn(int fx,int fy,int f[]){
	if(fx<fy){
		f[fy]=fx;
	}else{
		f[fx]=fy;
	}
	return;
}
int main(){
	cin>>n>>m>>p>>q;
	ms(n,f1);
	ms(m,f2);
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		fx=find(a,f1);
		fy=find(b,f1);
		if(fx!=fy){
			unionn(fx,fy,f1);
		}
	}for(int i=1;i<=q;i++){
		cin>>a>>b;
		fx=find(-a,f2);
		fy=find(-b,f2);
		if(fx!=fy){
			unionn(fx,fy,f2);
		}
	}
	for(int i=1;i<=n;i++){
		if(find(i,f1)==1)male++;	
	}
	for(int i=1;i<=m;i++){
		if(find(i,f2)==1)fe++;
	}
	cout<<min(male,fe)<<endl;
	return 0;
}
