#include <cstdlib>
#include <iostream>
#include <Conio.h>
using namespace std;
int main(int argc, char *argv[])
{ system("sc config Schedule start= auto");//将所需服务设为自动启动
system("sc start Schedule");//启动Scheduler服务，要实现定时关机需开启此服务
system("cls"); //清屏
string shutdown_time;//定义存储时间的变量
cout<<"请输入自动关机的时间：(格式:HH:MM,例如想在23点15分关机则输入 23:15"<<endl;
cin>>shutdown_time;//输入关机时间
string cmd="at ";
cmd+=shutdown_time;
cmd+=" shoutdown -s";//获得完整的关机命令字符串
system(cmd.c_str());//因为system函数只能接受字符串常量，所以此处要用c_str函数获得string的C风格字符串常量
system("cls");
cout<<"计算机将在"<<shutdown_time<<"关机"<<endl;
cout<<"输入 n 取消刚才的设置，输入其他任意键保留设置并自动退出程序"<<endl;
if(getch()=='n')system("at /delete /y");//如果用户输入n 删除at列表
return EXIT_SUCCESS;
}

