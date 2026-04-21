#include<iostream>
#include <stdlib.h>
#include<string>
#include <fstream>
using namespace std;
int main()
{
string time,c,d;
ofstream file("c:\\1.bat");
cout<<"请设定关机时间---";
cin>>time;
c="shutdown -s -t ";
file<<c<<time;
file.close();
system("\"c:\\1.bat\"");
cout<<"需要取消关机请输入数字0"<<endl;
cin>>d;
if(d=="0")
{
system("shutdown -a");
}
return 0;
}


