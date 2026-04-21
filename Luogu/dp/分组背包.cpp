#include<bits/stdc++.h>
using namespace std;
int v,n,tnum,x,m[205][205],c[10001],w[10001],t[10001],dp[10001];
int main(){
    cin >> v >> n;
    for(int i = 1;i <= n;i++){
        cin >> c[i] >> w[i] >> x;
        tnum = max(tnum,x);
        t[x]++;
        m[x][t[x]] = i;
    }
    for(int i = 1;i <= tnum;i++)
        for(int j = v;j >= 0;j--)
            for(int k = 1;k <= t[i];k++)
                if(j >= c[m[i][k]])
                    dp[j] = max(dp[j],dp[j-c[m[i][k]]]+w[m[i][k]]);
    cout << dp[v];
    return 0;
}
