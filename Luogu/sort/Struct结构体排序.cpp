#include <iostream>
#include <algorithm>
#define green system("color 0a")
using namespace std;

struct score{
	int chinese,math,english,zong;
} f[10];

bool cmp(score a,score b){
	if(a.zong > b.zong) return true;
	else return false;
}

int main(){
	green;
	int a;
	cin >> a;
	for(int i = 0;i < a;i++){
		cin >> f[i].chinese >> f[i].math >> f[i].english;
		f[i].zong = f[i].chinese+f[i].english+f[i].math;
	}
	sort(f,f+a,cmp);
	system("CLS");
	for(int i = 0;i < a;i++) cout << f[i].chinese << " " << f[i].math << " " << f[i].english << endl;
}
