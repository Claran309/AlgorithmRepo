#include <bits/stdc++.h>
using namespace std;
const int maxn=10000000;
const int inf=10000000;
long long n,m,ans;
long long idx=1,prem[inf];
bool fl[inf],ins[inf];
int main(){
	scanf("%lld%lld",&n,&m);
	fl[1]=0;
	for(int i=2;i<=50005;i++){
		if(fl[i]==0){
			prem[idx]=i;
			idx++;
		}
		for(int j=1;j<idx&&prem[j]*i<=50005;j++){
			fl[i*prem[j]]=1;
			if(i%prem[j]==0) break;
		}
	}
	long long p,q;
    for(int i=1;i<=idx;i++){
        if(prem[i]>m)break;
        p=ceil(n*1.0/prem[i]),q=ceil(m*1.0/prem[i]);
        if(p==1)p=2;
        for(int j=p;j<=q&&prem[i]*j<=m;j++)
            ins[prem[i]*j-n+1]=1;
    }
    int tot=0;
    for(int i=1;i<=m-n+1;i++) if(!ins[i]) tot++;
	if(n == 1) tot--;
    cout<<tot;
	return 0;
}
