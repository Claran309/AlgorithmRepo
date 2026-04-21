//vector存图 
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std; 
int v1,v2,w;
vector<int> g[100];
int main(){
    //以-1 -1 -1 为止 
    while(1){
        cin >> v1 >> v2 >> w;
        g[v1-1].push_back(v2);
        g[v2-1].push_back(v1); //{无向图}
        if(v1 == -1 && v2 == v1 && w == v2) break;
    }
    system("CLS");
    int v;
    while(cin >> v){
        if(!g[v-1].size()) {
            cout << "无点与" << v << "点相连" << endl;
            continue; 
        }
        cout << "与" << v << "点相连的点有：";
        for(int i = 0;i < g[v-1].size();i++)
            cout << g[v-1][i] << "点  ";
        cout << endl;
    }
    return 0;
}

//链式前向星  存图
#include <iostream>
#include <windows.h>
using namespace std;
int u,v,inw;
struct note{
    int to; int next; int w;
} edge[1000];
int head[100],cnt;
void add(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int main(){
    memset(head,-1,sizeof(head));
    while(1){
        cin >> u >> v >> inw;
        if(u == -1 && v == -1 && inw == -1) break;
        add(u,v,inw);
        add(v,u,inw);//无向图 
    }
    system("CLS");
    while(cin >> v){
        if(head[v] == -1){
            cout << "无点与" << v << "点相连" << endl << endl;
            continue;
        }
        cout << "与" << v << "点相连的点有：" << endl; 
        for(int i = head[v];i!=-1;i = edge[i].next)
            cout << edge[i].to << "点，权值为" << edge[i].w << endl;
        cout << endl;
    }
    return 0;
}

//前向星dfs（待修改）
#include <iostream>
#include <windows.h>
using namespace std;
int u,v,n,m;
struct note{
    int to; int next;
} edge[1000000];
int head[10001],cnt,p[10001];
void add(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int k){
    cout << k << " ";
    p[k] = 1;
    for(int i = head[k];i!=-1;i = edge[i].next)
    	dfs(edge[j].to);
    	/*
    { 
    for(int i = head[k];!p[edge[i].to];i = head[edge[i].to])
        for(int j = i;j!=-1,!p[edge[i].to];j = edge[j].next)
            dfs(edge[j].to);
	} 
	*/
	
}
int main(){
    memset(head,-1,sizeof(head));
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> u >> v;
        add(u,v);
        add(v,u);
    }
    dfs(1); 
    for(int i = 1;i <= n;i++) if(!p[i]) cout << i << " ";
    memset(p,0,sizeof(p)); 
    //bfs(1);
    return 0;
} 
