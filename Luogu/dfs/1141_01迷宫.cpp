#include<bits/stdc++.h>
using namespace std;
long long m,ans;
long long n,x,y;
bool a[1005][1005],f[1005][1005];
const long long dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
void dfs(long long xx,long long yy,bool b){
    if(xx>n||yy>n||xx<1||yy<1||a[xx][yy]!=b||f[xx][yy]==1) return;
    ans++;
    f[xx][yy]=1;
    for(long long i=0;i<4;i++){
        dfs(xx+dx[i],yy+dy[i],!b);
    } 
}
int main(){
    cin >> n >> m;
    for(long long i=1;i<=n;i++)
        for(long long j=1;j<=n;j++)
             scanf("%1d", &a[i][j]);
    for(long long i=0;i<m;i++){
        cin >> x >> y;
        dfs(x,y,a[x][y]);
        cout << ans << endl;
        ans=0;
        memset(f,0,sizeof(f));
    }
    return 0;
}
