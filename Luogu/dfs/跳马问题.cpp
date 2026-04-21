
#include<iostream>

#include<cstring>

#include<string>

#include<cstdio>

#include<algorithm>

#include<cmath>

#include<iomanip>

using namespace std;

int total,g[6][6];  //g[i][j]代表第几步跳到点（i，j）

bool p[6][6]; //记录点（i，j）是否走过

int dx[8]={1,2,2,1,-1,-2,-2,-1};

int dy[8]={-2,-1,1,2,2,1,-1,-2};

void print()

{

    total++;

    if(total>5) return;

    for(int i=1;i<=5;i++)

    {

        for(int j=1;j<=5;j++)

            cout<<setw(5)<<g[i][j];

        cout<<endl;

    }

    cout<<endl;

}

void dfs(int i,int j,int s)

{

    int k;

    for(k=0;k<8;k++)

    {

        if((i+dx[k])<=5&&(i+dx[k])>0&&(j+dy[k])<=5&&(j+dy[k]>0)) //未越界

        {

            if(!p[i+dx[k]][j+dy[k]]) //未走过

            {

                p[i+dx[k]][j+dy[k]]=true; //标记走过，

                g[i+dx[k]][j+dy[k]]=s; //记录第s步走在哪个点

                if(s==25) print(); //已经走了25步，输出

                else dfs(i+dx[k],j+dy[k],s+1); //寻找下一步落点

                p[i+dx[k]][j+dy[k]]=false; //回溯

            }

        }

    }

}

int main()

{

    total=0;

    memset(p,false,sizeof(p));

    g[1][1]=1; p[1][1]=true;

    dfs(1,1,2); //从(1,1)开始搜第2步怎么走

    cout<<"总方案数total:"<<total<<endl;

    return 0;

}
