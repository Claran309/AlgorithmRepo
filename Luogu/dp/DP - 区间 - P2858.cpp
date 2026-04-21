#include<bits/stdc++.h>
using namespace std;
int f[10001][10001],n,m,s[10001];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        f[i][i]=s[i];
        s[i]+=s[i-1];
    }
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            f[i][j]=max(f[i+1][j],f[i][j-1])+s[j]-s[i-1];
        }
    }
    cout<<f[1][n];
    return 0;
}
