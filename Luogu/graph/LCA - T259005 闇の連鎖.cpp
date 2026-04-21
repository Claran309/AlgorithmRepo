//lca & 树上查分
//ps:边权变点权 
//1.对于每个附加边及lca进行树上差分(x-1,y-1,lca+2) 
//2.处理运算点被覆盖的次数(树上前缀和(dp)) 
//3.扫一遍点加在ans 0+nm,1+1,2+0
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10,M=N*2;
int n,m;
int h[N], e[M], ne[M], idx;
int fa[N][18];
int d[N];
int cnt[N];
int res=0;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}
void bfs(){
    memset(d,0x3f,sizeof d);
    d[0]=0,d[1]=1;
    queue<int>q;
    q.push(1);
    while(q.size()){
        int t=q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j=e[i];
            if(d[j]>d[t]+1){
                d[j]=d[t]+1;
                fa[j][0]=t;
                for(int k=1;k<18;k++){
                    fa[j][k]=fa[ fa[j][k-1] ][k-1];
                }
                q.push(j);
            }
        }

    }
}
int lca(int a,int b){
    if(d[a]<d[b])swap(a,b);
    for(int k=17;k>=0;k--){
        if(d[fa[a][k]]>=d[b]){
            a=fa[a][k];
        }
    }
    if(a==b)return a;
    for(int k=17;k>=0;k--){
        if(fa[a][k]!=fa[b][k]){
            a=fa[a][k];
            b=fa[b][k];
        }
    }
    return fa[a][0];
}
int dfs(int u,int fa){
    int ans=cnt[u];
    for(int i=h[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        int s=dfs(j,u);
        if(s==0)res+=m;
        if(s==1)res+=1;
        if(s>1)res+=0;
        ans+=s;
    }
    return ans;
}

int main(){
    cin>>n>>m;
    memset(h, -1, sizeof h);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    bfs();
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        int t=lca(a,b);
        cnt[a]++,cnt[b]++,cnt[t]-=2;
    }
    dfs(1,-1);
    cout<<res;
    return 0;
}

