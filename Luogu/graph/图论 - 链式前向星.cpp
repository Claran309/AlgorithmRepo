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
