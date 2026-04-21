#include<cstdlib>                                         //加入这个包才能使用随机函数rand()
#include<cstdio>
#include<ctime>                                           //加入这个包就能以时间为种子初始化随机函数
#include<iostream>
using namespace std;
int random(int n)
{
	return (long long)rand()*rand()%n;
}
int main()
{
    freopen("data.in","w",stdout);                        //注意：该程序生成的数据到data.in中
    srand((unsigned)time(0));                                          //重要：初始化随机函数，以时间为种子
    int n=random(5000)+1;                                 //生成一个1到10000之间的随机整数n
    printf("%d\n",n);
    printf("\n");
    for(int i=1;i<=n;i++)
    {
		   int y=random(1<<16)+1;                                 //保证生成的数据是x<=y
           printf("%d ",y);
    }
}

